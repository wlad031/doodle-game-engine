#include "OpenGlForwardRenderer.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {
namespace forward {

OpenGlForwardRenderer::OpenGlForwardRenderer() : OpenGlRenderer() {
    _mainShader = std::make_shared<MainShader>();
}

void OpenGlForwardRenderer::render() {
    _mainShader->use();

    for (auto&& camera : _cameras) {

        passUniformMatrix4fv(
                _mainShader->getUniform(MainShader::Uniform::MATRIX_VIEW),
                camera->getViewMatrix()
        );
        passUniformMatrix4fv(
                _mainShader->getUniform(MainShader::Uniform::MATRIX_PROJECTION),
                camera->getProjectionMatrix()
        );

        for (auto&& light : _directionalLights) {
            auto gameObject = light->getGameObject();

            passUniform3fv(
                    _mainShader->getUniform(MainShader::Uniform::LIGHT_POSITION),
                    gameObject->getTransform()->getRotation()
            );

            passUniform4fv(
                    _mainShader->getUniform(MainShader::Uniform::LIGHT_AMBIENT),
                    math::color::rgb2rgba(gameObject->getLight()->getColor().ambient)
            );

            passUniform4fv(
                    _mainShader->getUniform(MainShader::Uniform::LIGHT_DIFFUSE),
                    math::color::rgb2rgba(gameObject->getLight()->getColor().diffuse)
            );

            passUniform4fv(
                    _mainShader->getUniform(MainShader::Uniform::LIGHT_SPECULAR),
                    math::color::rgb2rgba(gameObject->getLight()->getColor().specular)
            );

            for (auto&& object : _objects) {
                auto renderingObject = object.first;
                auto openGlObject    = object.second;

                auto transformMatrix = math::mat::m4(1.0);

                passUniformMatrix4fv(
                        _mainShader->getUniform(MainShader::Uniform::MATRIX_MODEL),
                        transformMatrix
                );

                for (auto&& graphicObject : openGlObject) {
                    graphicObject.render(_mainShader);
                }
            }
        }

        for (auto&& light : _pointLights) {
            // TODO: implement
        }

        for (auto&& light : _spotLights) {
            // TODO: implement
        }
    }

    _mainShader->unuse();
}

}  // namespace forward
}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems