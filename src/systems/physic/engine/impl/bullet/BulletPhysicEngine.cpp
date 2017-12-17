#include "BulletPhysicEngine.h"

#include <thread>

#include "common/Logger.hpp"

#include "systems/physic/scene/PhysicScene.h"

namespace systems {
namespace physic {
namespace engine {
namespace bullet {

BulletPhysicEngine::BulletPhysicEngine() {
    _btBroadphase   = std::make_shared<btDbvtBroadphase>();
    _btConfig       = std::make_shared<btDefaultCollisionConfiguration>();
    _btDispatcher   = std::make_shared<btCollisionDispatcher>(&*_btConfig);
    _btSolver       = std::make_shared<btSequentialImpulseConstraintSolver>();
    _btDynamicWorld = std::make_shared<btDiscreteDynamicsWorld>(
            &*_btDispatcher,
            &*_btBroadphase,
            &*_btSolver,
            &*_btConfig
    );

    _btDynamicWorld->setGravity(btVector3(0, -9.81f, 0)); // TODO: implement

    auto pObjects = systems::physic::scene::PhysicScene::instance()
            .getObjects();

    for (auto&& physicObject : pObjects) {
        auto bulletObject = std::make_shared<BulletObject>(physicObject);
        _objects[physicObject] = bulletObject;
        _btDynamicWorld->addRigidBody(&*bulletObject->getBtRigidBody());
    }
}

void BulletPhysicEngine::simulate() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // TODO: implement
    _btDynamicWorld->stepSimulation((btScalar) (1.0 / 60.0), 10); // TODO: implement

    // TODO: work with rotation

    for (auto&& item : _objects) {
        auto object       = item.first;
        auto bulletObject = item.second;

        btTransform transform;
        (&*bulletObject->getBtRigidBody())
                ->getMotionState()
                ->getWorldTransform(transform);

        object->update(
                utils::fromBullet(transform.getOrigin()),
                math::vec::IDENTITY_V3 // TODO: work with rotation
        );

        LOG(DEBUG) << "transform.position.Y = "
                   << transform.getOrigin().y();
    }
}

}  // namespace bullet
}  // namespace engine
}  // namespace physic
}  // namespace systems