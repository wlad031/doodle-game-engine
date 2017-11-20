#include "OpenGlForwardRenderer.h"

#include <glm/gtc/type_ptr.hpp>

#include "systems/rendering/scene/RenderingScene.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

OpenGlForwardRenderer::OpenGlForwardRenderer() : OpenGlRenderer() {

    auto vs = OpenGlShader::fromFile(
            OpenGlShader::Type::VERTEX,
            std::make_shared<files::File>(
                    "/home/wlad031/Documents/doodle-game-engine/shaders/shader.vert"
            )
    );
    vs->compile();
    auto fs = OpenGlShader::fromFile(
            OpenGlShader::Type::FRAGMENT,
            std::make_shared<files::File>(
                    "/home/wlad031/Documents/doodle-game-engine/shaders/shader.frag"
            )
    );
    fs->compile();

    _sp = std::make_shared<OpenGlProgram>();

    _sp->attachShader(std::move(vs));
    _sp->attachShader(std::move(fs));
    _sp->link();
    _sp->addAttribute("Position");
    _sp->addAttribute("TexCoord");
    _sp->addAttribute("Normal");
    _sp->addAttribute("Tangent");
    _sp->addAttribute("Bitangent");
    _sp->addUniform("Matrix.Model");
    _sp->addUniform("Matrix.View");
    _sp->addUniform("Matrix.Projection");
}

void OpenGlForwardRenderer::render() {
    _sp->use();

    for (auto&& object : _objects) {
        auto renderingObject = object.first;
        auto openGlObject    = object.second;

        auto transform       = renderingObject->getGameObject()->getTransform();
        auto transformMatrix = math::mat::m4(1.0);

        gl::glUniformMatrix4fv(
                _sp->getUniformId("Matrix.Model"),
                1,
                gl::GL_FALSE,
                glm::value_ptr(transformMatrix)
        );
        gl::glUniformMatrix4fv(
                _sp->getUniformId("Matrix.View"),
                1,
                gl::GL_FALSE,
                glm::value_ptr(transformMatrix)
        );
        gl::glUniformMatrix4fv(
                _sp->getUniformId("Matrix.Projection"),
                1,
                gl::GL_FALSE,
                glm::value_ptr(transformMatrix)
        );

        for (auto&& graphicObject : openGlObject) {
            graphicObject.render(_sp);
        }
    }
}

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems