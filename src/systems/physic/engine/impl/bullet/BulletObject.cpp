#include "BulletObject.h"

#include "BulletUtils.h"

namespace systems {
namespace physic {
namespace engine {
namespace bullet {

BulletObject::BulletObject(
        std::shared_ptr<systems::physic::scene::PhysicObject> physicObject
) {
    auto gameObject      = physicObject->getGameObject();
    auto transform       = gameObject->getTransform();
    auto rigidBody       = gameObject->getRigidBody();
    auto boxColliders    = gameObject->getBoxColliders();
    auto sphereColliders = gameObject->getSphereColliders();

    _btCollisionShape = std::make_shared<btCompoundShape>();

    for (auto&& collider : boxColliders) {
        btBoxShape shape(utils::toBullet(collider->getSize()));
        btTransform trans;
        trans.setOrigin(utils::toBullet(collider->getCenter()));
        _btCollisionShape->addChildShape(trans, &shape);
    }

    for (auto&& collider : sphereColliders) {
        btSphereShape shape(collider->getRadius());
        btTransform trans;
        trans.setOrigin(utils::toBullet(collider->getCenter()));
        _btCollisionShape->addChildShape(trans, &shape);
    }

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
