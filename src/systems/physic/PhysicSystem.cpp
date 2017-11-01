#include "PhysicSystem.h"

namespace systems {
namespace physic {

std::function<void()> PhysicSystem::getTask() {
    return [this]() { _engine.simulate(); };
}

} // namespace physic
} // namespace systems
