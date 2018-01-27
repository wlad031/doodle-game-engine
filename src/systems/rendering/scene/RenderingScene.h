#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_RENDERINGSCENE_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_RENDERINGSCENE_H

#include <vector>
#include <iostream>

#include "RenderingCamera.h"
#include "RenderingLight.h"
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

    void add(const std::shared_ptr<models::GameObject>& gameObject);

    const std::vector<std::shared_ptr<RenderingObject>>&
    getObjects() const { return _objects; }

    const std::vector<std::shared_ptr<RenderingCamera>>&
    getCameras() const { return _cameras; }

    const std::vector<std::shared_ptr<RenderingLight>>&
    getLights() const { return _lights; }

private:

    RenderingScene() {
//        std::cout << "RenderingScene constructor called" << std::endl;
    }

    std::vector<std::shared_ptr<RenderingObject>> _objects;
    std::vector<std::shared_ptr<RenderingCamera>> _cameras;
    std::vector<std::shared_ptr<RenderingLight>> _lights;
};

}  // namespace scene
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_RENDERINGSCENE_H
