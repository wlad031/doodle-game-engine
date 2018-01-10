#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_RENDERSYSTEM_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_RENDERSYSTEM_H

#include <memory>

#include "systems/System.h"

#include "systems/rendering/engine/impl/opengl/forward/OpenGlForwardRenderer.h"

namespace systems {
namespace rendering {

class RenderSystem : public System {
public:

    static RenderSystem& instance() {
        static RenderSystem _instance;
        return _instance;
    }

    std::function<void()> getTask() override;

private:
    RenderSystem() {
        _renderer.initializeObjects();
    }

    engine::opengl::forward::OpenGlForwardRenderer _renderer;
};

}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_RENDERSYSTEM_H
