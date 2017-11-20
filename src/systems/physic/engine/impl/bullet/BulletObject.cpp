#include "BulletObject.h"

#include "BulletUtils.h"

namespace systems {
namespace physic {
namespace engine {
namespace bullet {

BulletObject::BulletObject(
        const std::shared_ptr<systems::physic::scene::PhysicObject>&
        physicObject
) {
    auto transform = physicObject->getGameObject()->getTransform();
    auto rigidBody = physicObject->getGameObject()->getRigidBody();

    _btCollisionShape = std::make_shared<btSphereShape>(1); // TODO: implement

    _btMotionState = std::make_shared<btDefaultMotionState>(
            btTransform(
                    btQuaternion(0, 0, 0, 1), // TODO: implement
                    utils::toBullet(transform->getPosition())
            )
    );

    btScalar  mass = rigidBody->getMass();
    btVector3 fallInertia(0, 0, 0); // TODO: implement
    _btCollisionShape->calculateLocalInertia(mass, fallInertia);

    _btConstructionInfo = std::make_shared<
            btRigidBody::btRigidBodyConstructionInfo
    >(
            mass,
            &*_btMotionState,
            &*_btCollisionShape,
            fallInertia
    );

    _btRigidBody = std::make_shared<btRigidBody>(*_btConstructionInfo);

    _btRigidBody->setIgnoreCollisionCheck(nullptr, true); // TODO: implement

//    _btRigidBody->setCollisionFlags(
//            _btRigidBody->getCollisionFlags() |
//            btCollisionObject::CF_KINEMATIC_OBJECT
//    );
//    _btRigidBody->setActivationState(DISABLE_DEACTIVATION);
}

}  // namespace bullet
}  // namespace engine
}  // namespace physic
}  // namespace systems
