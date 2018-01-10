#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_RENDERINGOBJECT_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_RENDERINGOBJECT_H

#include <memory>
#include <utility>

#include "models/GameObject.h"

#include "components/Mesh.h"

namespace models {
class GameObject;
}  // namespace models

namespace systems {
namespace rendering {
namespace scene {

class RenderingObject {
public:

    RenderingObject(
            const std::shared_ptr<models::GameObject>& gameObject,
            const std::shared_ptr<components::Mesh>& mesh
    ) : _gameObject(gameObject),
        _mesh(mesh) {
    }

    const std::shared_ptr<models::GameObject>&
    getGameObject() const { return _gameObject; }

    const std::shared_ptr<components::Mesh>&
    getMesh() const { return _mesh; }

private:
    std::shared_ptr<models::GameObject> _gameObject;
    std::shared_ptr<components::Mesh>   _mesh;
};

}  // namespace scene
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_RENDERINGOBJECT_H
