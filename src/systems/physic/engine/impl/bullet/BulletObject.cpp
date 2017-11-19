#include "BulletObject.h"

namespace systems {
namespace physic {
namespace engine {
namespace bullet {

BulletObject::BulletObject(btDiscreteDynamicsWorld* world) {
    _world = world;

    _btCollisionShape = new btSphereShape(1);

    _btMotionState = new btDefaultMotionState(
            btTransform(
                    btQuaternion(0, 0, 0, 1),
                    btVector3(0, 50, 0)
            )
    );

    btScalar mass = 1;
    btVector3 fallInertia(0, 0, 0);
    _btCollisionShape->calculateLocalInertia(mass, fallInertia);

    _btConstructionInfo = new btRigidBody::btRigidBodyConstructionInfo(
            mass,                  // mass, in kg. 0 -> Static object, will never move.
            _btMotionState,
            _btCollisionShape,  // collision shape of body
            fallInertia    // local inertia
    );

    _btRigidBody = new btRigidBody(*_btConstructionInfo);

//    _btRigidBody->setCollisionFlags(
//            _btRigidBody->getCollisionFlags() |
//            btCollisionObject::CF_KINEMATIC_OBJECT
//    );
//    _btRigidBody->setActivationState(DISABLE_DEACTIVATION);

    world->addRigidBody(_btRigidBody);
}

}  // namespace bullet
}  // namespace engine
}  // namespace physic
}  // namespace systems
