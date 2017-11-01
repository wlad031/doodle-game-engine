#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_SHADERPROGRAM_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_SHADERPROGRAM_H

#include <map>

#include <glbinding/gl/gl.h>

#include "Shader.h"
#include "common/Named.hpp"

////////////////////////////////////////////////////////////////////////////////
/////               Representation of the OpenGL shader program            /////
////////////////////////////////////////////////////////////////////////////////

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

///// ============================================================ ShaderProgram
class ShaderProgram : public Named {
public:

    ///// --------------------------------------------------------- constructors
    ShaderProgram();

    ///// --------------------------------------------------------- attachShader
    void attachShader(const std::shared_ptr<Shader>& shader);

    ///// ----------------------------------------------------------- addUniform
    void addUniform(const std::string& uniform);

    ///// --------------------------------------------------------- addAttribute
    void addAttribute(const std::string& attribute);

    ///// ----------------------------------------------------------------- link
    void link();

    ///// ------------------------------------------------------------------ use
    void use();

    ///// ---------------------------------------------------------------- unuse
    void unuse();

    ///// ------------------------------------------------------- getAttributeId
    gl::GLuint getAttributeId(const std::string& name);

    ///// --------------------------------------------------------- getUniformId
    gl::GLuint getUniformId(const std::string& name);

private:

    std::map<std::string, gl::GLuint> _uniforms;
    std::map<std::string, gl::GLuint> _attributes;

    gl::GLuint    _id;
    gl::GLboolean _status;
};

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems


#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_SHADERPROGRAM_H
