#ifndef DOODLEGAMEENGINE_SYSTEMS_PHYSIC_ENGINE_PHYSICENGINE_H
#define DOODLEGAMEENGINE_SYSTEMS_PHYSIC_ENGINE_PHYSICENGINE_H

#include <common/Logger.hpp>

namespace systems {
namespace physic {
namespace engine {

class PhysicEngine {
public:

    PhysicEngine();

    virtual void simulate() = 0;

protected:
    std::shared_ptr<el::Logger> LOGGER;
};

}  // namespace engine
}  // namespace physic
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_PHYSIC_ENGINE_PHYSICENGINE_H
