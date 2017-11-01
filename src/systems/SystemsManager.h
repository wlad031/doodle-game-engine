#ifndef DOODLEGAMEENGINE_SYSTEMS_SYSTEMSMANAGER_H
#define DOODLEGAMEENGINE_SYSTEMS_SYSTEMSMANAGER_H

#include <set>

#include "physic/PhysicSystem.h"
#include "rendering/RenderSystem.h"

namespace systems {

class SystemsManager {
public:
    static SystemsManager& instance();

private:

    SystemsManager();

    rendering::RenderSystem& _renderSystem;
    physic::PhysicSystem   & _physicSystem;
};

}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_SYSTEMSMANAGER_H
