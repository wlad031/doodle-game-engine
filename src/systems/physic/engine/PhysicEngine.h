#ifndef DOODLEGAMEENGINE_SYSTEMS_PHYSIC_ENGINE_PHYSICENGINE_H
#define DOODLEGAMEENGINE_SYSTEMS_PHYSIC_ENGINE_PHYSICENGINE_H

namespace systems {
namespace physic {
namespace engine {

class PhysicEngine {
public:
    virtual void simulate() = 0;
};

}  // namespace engine
}  // namespace physic
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_PHYSIC_ENGINE_PHYSICENGINE_H
