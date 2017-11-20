#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLFORWARDRENDERER_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLFORWARDRENDERER_H

#include "systems/rendering/engine/impl/opengl/OpenGlRenderer.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

class OpenGlForwardRenderer : public OpenGlRenderer {
public:
    OpenGlForwardRenderer();

    void render() override;

private:
    std::shared_ptr<OpenGlProgram> _sp;
};

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLFORWARDRENDERER_H
