#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLRENDERER_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLRENDERER_H

#include "OpenGlObject.h"

#include "systems/rendering/engine/Renderer.h"
#include "systems/rendering/scene/RenderingCamera.h"
#include "systems/rendering/scene/RenderingObject.h"
#include "systems/rendering/scene/RenderingLight.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

class OpenGlRenderer : public Renderer {
public:
    OpenGlRenderer();

protected:

    void passUniform3fv(
            gl::GLuint uniformId,
            const math::vec::v3& vec
    );

    void passUniform4fv(
            gl::GLuint uniformId,
            const math::vec::v4& vec
    );

    void passUniformMatrix4fv(
            gl::GLuint uniformId,
            const math::mat::m4& matrix
    );

    std::map<
            std::shared_ptr<systems::rendering::scene::RenderingObject>,
            std::vector<OpenGlObject>
    > _objects;

    std::vector<std::shared_ptr<systems::rendering::scene::RenderingCamera>> _cameras;
    std::vector<
            std::shared_ptr<systems::rendering::scene::RenderingLight>
    > _directionalLights;
    std::vector<
            std::shared_ptr<systems::rendering::scene::RenderingLight>
    > _pointLights;
    std::vector<
            std::shared_ptr<systems::rendering::scene::RenderingLight>
    > _spotLights;
};

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLRENDERER_H
