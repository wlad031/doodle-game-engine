#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLPROGRAM_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLPROGRAM_H

#include <map>
#include <set>

#include "OpenGlShader.h"
#include "common/Named.hpp"

////////////////////////////////////////////////////////////////////////////////
/////               Representation of the OpenGL shader program            /////
////////////////////////////////////////////////////////////////////////////////

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

///// ============================================================ ShaderProgram
class OpenGlProgram : public Named {
public:

    ///// --------------------------------------------------------- constructors
    OpenGlProgram();

    ///// --------------------------------------------------------- attachShader
    void attachShader(std::shared_ptr<OpenGlShader> shader);

    ///// ----------------------------------------------------------- addUniform
    gl::GLuint addUniform(const std::string& uniform);

    ///// --------------------------------------------------------- addAttribute
    gl::GLuint addAttribute(const std::string& attribute);

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


#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLPROGRAM_H
