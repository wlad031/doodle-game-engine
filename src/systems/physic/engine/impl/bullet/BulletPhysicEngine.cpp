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
    collisionConfiguration =
                                            new btDefaultCollisionConfiguration();

    dispatcher = new btCollisionDispatcher(
            collisionConfiguration
    );

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
        btBoxShape* boxCollisionShape = new btBoxShape(btVector3(1, 1, 1));

        btDefaultMotionState* motionstate = new btDefaultMotionState(btTransform(
                btQuaternion(1, 1, 1, 1),
                btVector3(1, 1, 1)
        ));

        btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(
                1000,                  // mass, in kg. 0 -> Static object, will never move.
                motionstate,
                boxCollisionShape,  // collision shape of body
                btVector3(1, 0, 0)    // local inertia
        );

        btRigidBody* rigidBody = new btRigidBody(rigidBodyCI);

        rigidBody->setCollisionFlags(rigidBody->getCollisionFlags() |
                                     btCollisionObject::CF_KINEMATIC_OBJECT);
        rigidBody->setActivationState(DISABLE_DEACTIVATION);

        _objects[physicObject] = rigidBody;
        _world->addRigidBody(rigidBody);
    }
}

void BulletPhysicEngine::simulate() {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    _world->stepSimulation((btScalar) (1.0 / 60.0));

    for (auto&& item : _objects) {
        auto object = item.first;
        auto rigidBody = item.second;

        auto v = rigidBody->getCenterOfMassPosition();

        btTransform transform;
        rigidBody->getMotionState()->getWorldTransform(transform);

        LOG(DEBUG) << " x = " << v.getX();
        LOG(DEBUG) << " Y = " << v.getY();
        LOG(DEBUG) << " Z = " << v.getZ();
    }
}

}  // namespace bullet
}  // namespace engine
}  // namespace physic
}  // namespace systems