#ifndef DOODLEGAMEENGINE_CAMERA_H
#define DOODLEGAMEENGINE_CAMERA_H

#include "models/GameObject.h"

namespace models {
class GameObject;
}  // namespace models

namespace systems {
namespace rendering {
namespace scene {

class RenderingCamera {
public:

    RenderingCamera(std::shared_ptr<models::GameObject> gameObject) :
            _gameObject(std::move(gameObject)) {}

    const std::shared_ptr<models::GameObject>&
    getGameObject() const { return _gameObject; }

    const math::mat::m4& getViewMatrix();
    const math::mat::m4& getProjectionMatrix();

private:
    std::shared_ptr<models::GameObject> _gameObject;
};

}  // namespace scene
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_CAMERA_H
