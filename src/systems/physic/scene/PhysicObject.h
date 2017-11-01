#ifndef DOODLEGAMEENGINE_SYSTEMS_PHYSIC_SCENE_PHYSICOBJECT_H
#define DOODLEGAMEENGINE_SYSTEMS_PHYSIC_SCENE_PHYSICOBJECT_H

#include "models/GameObject.h"

namespace models {
class GameObject;
} // namespace models

namespace systems {
namespace physic {
namespace scene {

class PhysicObject {
public:

    PhysicObject(
            std::shared_ptr<models::GameObject> gameObject
    ) : _gameObject(std::move(gameObject)) {}

    const std::shared_ptr<models::GameObject>&
    getGameObject() const { return _gameObject; }

private:
    std::shared_ptr<models::GameObject> _gameObject;
};

}  // namespace scene
}  // namespace physic
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_PHYSIC_SCENE_PHYSICOBJECT_H
