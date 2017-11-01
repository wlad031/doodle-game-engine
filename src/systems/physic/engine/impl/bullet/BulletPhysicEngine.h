#ifndef DOODLEGAMEENGINE_BULLETPHYSICENGINE_H
#define DOODLEGAMEENGINE_BULLETPHYSICENGINE_H

#include <map>
#include <memory>

#include <bullet/btBulletDynamicsCommon.h>

#include "systems/physic/scene/PhysicObject.h"

#include "systems/physic/engine/PhysicEngine.h"

namespace systems {
namespace physic {
namespace engine {
namespace bullet {

class BulletPhysicEngine : public systems::physic::engine::PhysicEngine {
public:

    BulletPhysicEngine();

    void simulate() override;

private:
    btBroadphaseInterface* broadphase;

    // Set up the collision configuration and dispatcher
    btDefaultCollisionConfiguration* collisionConfiguration;

    btCollisionDispatcher* dispatcher;

    // The actual physics solver
    btSequentialImpulseConstraintSolver* solver;

    btDiscreteDynamicsWorld* _world;

    std::map<
            std::shared_ptr<systems::physic::scene::PhysicObject>,
            btRigidBody*
    > _objects;
};

}  // namespace bullet
}  // namespace engine
}  // namespace physic
}  // namespace systems

#endif //DOODLEGAMEENGINE_BULLETPHYSICENGINE_H
