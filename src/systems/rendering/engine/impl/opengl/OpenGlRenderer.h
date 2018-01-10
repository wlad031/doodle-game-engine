#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLRENDERER_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLRENDERER_H

#include "common/Logger.hpp"

#include "OpenGlObject.h"

#include "systems/rendering/engine/Renderer.h"
#include "systems/rendering/scene/RenderingCamera.h"
#include "systems/rendering/scene/RenderingLight.h"
#include "systems/rendering/scene/RenderingObject.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

class OpenGlRenderer : public Renderer {
public:
    OpenGlRenderer();

    void initializeObjects();

protected:

    std::shared_ptr<el::Logger> LOGGER;

    std::map<
            std::shared_ptr<systems::rendering::scene::RenderingObject>,
            std::vector<std::shared_ptr<OpenGlObject>>
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
};

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLRENDERER_H
