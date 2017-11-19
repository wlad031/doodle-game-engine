#include "BulletPhysicEngine.h"

#include <thread>

#include <easylogging++.h>

#include "systems/physic/scene/PhysicScene.h"

namespace systems {
namespace physic {
namespace engine {
namespace bullet {

// TODO: invalid implementation

BulletPhysicEngine::BulletPhysicEngine() {
    // Initialize Bullet. This strictly follows http://bulletphysics.org/mediawiki-1.5.8/index.php/Hello_World,
    // even though we won't use most of this stuff.

    // Build the broadphase
    broadphase = new btDbvtBroadphase();

    // Set up the collision configuration and dispatcher
    collisionConfiguration = new btDefaultCollisionConfiguration();

    dispatcher = new btCollisionDispatcher(collisionConfiguration);

    // The actual physics solver
    solver = new btSequentialImpulseConstraintSolver();

    // The world.
    _world = new btDiscreteDynamicsWorld(
            dispatcher,
            broadphase,
            solver,
            collisionConfiguration
    );

    _world->setGravity(btVector3(0, -9.81f, 0));

    auto pObjects = systems::physic::scene::PhysicScene::instance()
            .getObjects();

    for (auto&& physicObject : pObjects) {
        _objects[physicObject] = std::make_shared<BulletObject>(_world);
    }
}

void BulletPhysicEngine::simulate() {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    _world->stepSimulation((btScalar) (1.0 / 60.0), 10);

    for (auto&& item : _objects) {
        auto object = item.first;
        auto bulletObject = item.second;

        auto v = bulletObject->getBtRigidBody()->getCenterOfMassPosition();

        btTransform transform;
        bulletObject->getBtRigidBody()->getMotionState()->getWorldTransform(transform);

//        LOG(DEBUG) << " x = " << transform.getOrigin().getX();
        LOG(DEBUG) << " Y = " << transform.getOrigin().getY();
//        LOG(DEBUG) << " Z = " << transform.getOrigin().getZ();
    }
}

}  // namespace bullet
}  // namespace engine
}  // namespace physic
}  // namespace systems