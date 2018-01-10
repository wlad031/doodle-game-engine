#ifndef DOODLEGAMEENGINE_LIGHTSOURCE_H
#define DOODLEGAMEENGINE_LIGHTSOURCE_H

#include "models/GameObject.h"

namespace models {
class GameObject;
}  // namespace models

namespace systems {
namespace rendering {
namespace scene {

class RenderingLight {
public:

    explicit RenderingLight(
            const std::shared_ptr<models::GameObject>& gameObject
    ) : _gameObject(gameObject) {}

    const std::shared_ptr<models::GameObject>&
    getGameObject() const { return _gameObject; }



private:
    std::shared_ptr<models::GameObject> _gameObject;
};

}  // namespace scene
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_LIGHTSOURCE_H
