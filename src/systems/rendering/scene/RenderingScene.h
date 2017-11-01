#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_RENDERINGSCENE_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_RENDERINGSCENE_H

#include <vector>

#include "RenderingObject.h"

namespace systems {
namespace rendering {
namespace scene {

class RenderingScene {
public:

    static RenderingScene& instance() {
        static RenderingScene _instance;
        return _instance;
    }

    std::shared_ptr<RenderingObject>
    createObject(const std::shared_ptr<models::GameObject>& gameObject);

    const std::vector<std::shared_ptr<RenderingObject>>&
    getObjects() const { return _objects; }

private:

    RenderingScene() = default;

    std::vector<std::shared_ptr<RenderingObject>> _objects;
};

}  // namespace scene
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_RENDERINGSCENE_H
