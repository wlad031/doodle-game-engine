#include "PhysicEngine.h"

namespace systems {
namespace physic {
namespace engine {

PhysicEngine::PhysicEngine() {
    LOGGER = std::shared_ptr<el::Logger>(
            el::Loggers::getLogger("Physic")
    );
}

}  // namespace engine
}  // namespace physic
}  // namespace systems
