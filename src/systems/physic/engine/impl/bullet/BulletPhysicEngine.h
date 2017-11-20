#ifndef DOODLEGAMEENGINE_BULLETPHYSICENGINE_H
#define DOODLEGAMEENGINE_BULLETPHYSICENGINE_H

#include <map>
#include <memory>

#include <bullet/btBulletDynamicsCommon.h>

#include "systems/physic/engine/PhysicEngine.h"
#include "systems/physic/engine/impl/bullet/BulletObject.h"
#include "BulletUtils.h"
#include "systems/physic/scene/PhysicObject.h"

namespace systems {
namespace physic {
namespace engine {
namespace bullet {

class BulletPhysicEngine : public systems::physic::engine::PhysicEngine {
public:

    BulletPhysicEngine();

    void simulate() override;

private:
    std::shared_ptr<btBroadphaseInterface>               _btBroadphase;
    std::shared_ptr<btDefaultCollisionConfiguration>     _btConfig;
    std::shared_ptr<btCollisionDispatcher>               _btDispatcher;
    std::shared_ptr<btSequentialImpulseConstraintSolver> _btSolver;
    std::shared_ptr<btDiscreteDynamicsWorld>             _btDynamicWorld;

    std::map<
            std::shared_ptr<systems::physic::scene::PhysicObject>,
            std::shared_ptr<BulletObject>
    > _objects;
};

}  // namespace bullet
}  // namespace engine
}  // namespace physic
}  // namespace systems

#endif //DOODLEGAMEENGINE_BULLETPHYSICENGINE_H
