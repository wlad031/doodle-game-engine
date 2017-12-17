#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLFORWARDRENDERER_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLFORWARDRENDERER_H

#include "systems/rendering/engine/impl/opengl/OpenGlRenderer.h"
#include "shaders/MainShader.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {
namespace forward {

class OpenGlForwardRenderer : public OpenGlRenderer {
public:
    OpenGlForwardRenderer();

    void render() override;

private:
    std::shared_ptr<MainShader> _mainShader;
};

}  // namespace forward
}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLFORWARDRENDERER_H
