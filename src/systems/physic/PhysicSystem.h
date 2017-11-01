#ifndef DOODLEGAMEENGINE_SYSTEMS_PHYSIC_PHYSICSYSTEM_H
#define DOODLEGAMEENGINE_SYSTEMS_PHYSIC_PHYSICSYSTEM_H

#include "systems/System.h"

#include "systems/physic/engine/impl/bullet/BulletPhysicEngine.h"

namespace systems {
namespace physic {

class PhysicSystem : public System {
public:

    static PhysicSystem& instance() {
        static PhysicSystem _instance;
        return _instance;
    }

    std::function<void()> getTask() override;

private:
    PhysicSystem() = default;

    engine::bullet::BulletPhysicEngine _engine;
};

} // namespace physic
} // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_PHYSIC_PHYSICSYSTEM_H
