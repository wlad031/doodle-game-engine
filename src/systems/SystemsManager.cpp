#include "SystemsManager.h"

namespace systems {

SystemsManager::SystemsManager() :
        _renderSystem(rendering::RenderSystem::instance()),
        _physicSystem(physic::PhysicSystem::instance()) {
}

SystemsManager& SystemsManager::instance() {
    static SystemsManager _instance;
    return _instance;
}

}  // namespace systems