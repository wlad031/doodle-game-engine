#include "OpenGlRenderer.h"

#include "common/Logger.hpp"

#include <glbinding/Binding.h>
#include <glbinding/ContextInfo.h>
#include <glbinding/Meta.h>
#include <glbinding/Version.h>

#include "systems/rendering/scene/RenderingScene.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

OpenGlRenderer::OpenGlRenderer() {
    glbinding::Binding::initialize();

    auto ver = std::string("Available OpenGL versions: ");
    for (auto&& v : glbinding::Meta::versions()) ver += v.toString() + ", ";
    LOG(DEBUG) << ver;
    LOG(INFO) << "OpenGL Version:  " << glbinding::ContextInfo::version();
    LOG(INFO) << "OpenGL Vendor:   " << glbinding::ContextInfo::vendor();
    LOG(INFO) << "OpenGL Renderer: " << glbinding::ContextInfo::renderer();
    LOG(INFO) << "OpenGL Revision: " << glbinding::Meta::glRevision();

    glbinding::setCallbackMaskExcept(
            glbinding::CallbackMask::After,
            {"glGetError"}
    );
    glbinding::setAfterCallback(
            [](const glbinding::FunctionCall&) {
                const auto error = gl::glGetError();
                if (error != gl::GL_NO_ERROR)
                    LOG(ERROR) << "OpenGL error: " << std::hex << error;
            }
    );

    glbinding::Binding::CreateProgram.setAfterCallback(
            [](gl::GLuint id) {
                LOG(INFO) << "Created OpenGL program: " << id;
            }
    );
    glbinding::Binding::CreateShader.setAfterCallback(
            [](gl::GLuint id, gl::GLenum /*type*/) {
                LOG(INFO) << "Created OpenGL shader: " << id;
            }
    );
    glbinding::Binding::DeleteProgram.setAfterCallback(
            [](gl::GLuint id) {
                LOG(INFO) << "Deleted OpenGL program: " << id;
            }
    );
    glbinding::Binding::DeleteShader.setAfterCallback(
            [](gl::GLuint id) {
                LOG(INFO) << "Deleted OpenGL shader: " << id;
            }
    );

    auto rObjects = systems::rendering::scene::RenderingScene::instance()
            .getObjects();

    for (auto&& renderingObject : rObjects) {

        for (auto&& meshEntry : renderingObject->getMesh()->getEntries()) {

            if (_objects.find(renderingObject) == _objects.end())
                _objects[renderingObject] =
                        std::vector<OpenGlObject>();

            _objects[renderingObject].emplace_back(meshEntry);
        }

    }
}

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems
