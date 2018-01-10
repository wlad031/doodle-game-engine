#include "OpenGlRenderer.h"

#include <glbinding/Binding.h>
#include <glbinding/ContextInfo.h>
#include <glbinding/Meta.h>
#include <glbinding/Version.h>

#include <glm/gtc/type_ptr.hpp>

#include "common/Logger.hpp"
#include "systems/rendering/scene/RenderingScene.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

OpenGlRenderer::OpenGlRenderer() {
    LOGGER = std::shared_ptr<el::Logger>(
            el::Loggers::getLogger("OpenGL")
    );

    glbinding::Binding::initialize(false);

    auto ver = std::string("Available OpenGL versions: ");
    for (auto&& v : glbinding::Meta::versions()) ver += v.toString() + ", ";
    LOGGER->debug(ver);
    LOGGER->info("OpenGL Version:  %s", glbinding::ContextInfo::version());
    LOGGER->info("OpenGL Vendor:   %s", glbinding::ContextInfo::vendor());
    LOGGER->info("OpenGL Renderer: %s", glbinding::ContextInfo::renderer());
    LOGGER->info("OpenGL Revision: %s", glbinding::Meta::glRevision());

    glbinding::setCallbackMaskExcept(
            glbinding::CallbackMask::After |
                    glbinding::CallbackMask::ParametersAndReturnValue,
            {"glGetError"}
    );
    glbinding::setAfterCallback(
            [this](const glbinding::FunctionCall& call) {
                // TODO: refactor
                std::string log(call.function->name());
                log += "(";
                for (auto i = 0; i < call.parameters.size(); ++i) {
                    log += call.parameters[i]->asString();
                    if (i < call.parameters.size() - 1) log += ", ";
                }
                log += ")";

                if (call.returnValue != nullptr) {
                    log += " -> ";
                    log += call.returnValue->asString();
                }

                LOGGER->trace(log);

                const auto error = gl::glGetError();
                if (error != gl::GL_NO_ERROR)
                    LOG(ERROR) << "OpenGL error: " << error;
            }
    );

    glbinding::Binding::CreateProgram.setAfterCallback(
            [this](gl::GLuint id) {
                LOGGER->info("Created OpenGL program: %d", id);
            }
    );
    glbinding::Binding::CreateShader.setAfterCallback(
            [this](gl::GLuint id, gl::GLenum /*type*/) {
                LOGGER->info("Created OpenGL shader: %d", id);
            }
    );
    glbinding::Binding::DeleteProgram.setAfterCallback(
            [this](gl::GLuint id) {
                LOGGER->info("Deleted OpenGL program: %d", id);
            }
    );
    glbinding::Binding::DeleteShader.setAfterCallback(
            [this](gl::GLuint id) {
                LOGGER->info("Deleted OpenGL shader: %d", id);
            }
    );
}

void OpenGlRenderer::initializeObjects() {
    auto rObjects = systems::rendering::scene::RenderingScene::instance()
            .getObjects();
    auto cameras  = systems::rendering::scene::RenderingScene::instance()
            .getCameras();
    auto lights   = systems::rendering::scene::RenderingScene::instance()
            .getLights();

    for (auto&& renderingObject : rObjects) {

        for (auto&& meshEntry : renderingObject->getMesh()->getEntries()) {

            if (_objects.find(renderingObject) == _objects.end())
                _objects[renderingObject] =
                        std::vector<std::shared_ptr<OpenGlObject>>();

            auto o = std::make_shared<OpenGlObject>(meshEntry);

            _objects[renderingObject].push_back(o);
        }

    }

    for (auto&& camera : cameras) {
        if (camera->getGameObject()->getCamera()->isActive()) {
            _cameras.push_back(camera);
        }
    }

    for (auto&& light : lights) {
        switch (light->getGameObject()->getLight()->getType()) {
            case models::components::rendering::Light::Type::DIRECTIONAL:
                _directionalLights.push_back(light);
                break;
            case models::components::rendering::Light::Type::POINT:
                _pointLights.push_back(light);
                break;
            case models::components::rendering::Light::Type::SPOT:
                _spotLights.push_back(light);
                break;
        }
    }
}

void OpenGlRenderer::passUniform3fv(
        gl::GLuint uniformId,
        const math::vec::v3& vec
) {
    gl::glUniform3fv(
            uniformId,
            1,
            glm::value_ptr(vec)
    );
}

void OpenGlRenderer::passUniform4fv(
        gl::GLuint uniformId,
        const math::vec::v4& vec
) {
    gl::glUniform4fv(
            uniformId,
            1,
            glm::value_ptr(vec)
    );
}

void OpenGlRenderer::passUniformMatrix4fv(
        gl::GLuint uniformId,
        const math::mat::m4& matrix
) {
    gl::glUniformMatrix4fv(
            uniformId,
            1,
            gl::GL_FALSE,
            glm::value_ptr(matrix)
    );
}

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems
