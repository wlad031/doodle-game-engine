#include "OpenGlProgram.h"

#include <glbinding/gl/gl.h>

#include "common/Logger.hpp"
#include "OpenGlUtils.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

///// ------------------------------------------------------------- constructors
OpenGlProgram::OpenGlProgram() {
    _id = gl::glCreateProgram();
}

///// ------------------------------------------------------------- attachShader
void OpenGlProgram::attachShader(std::shared_ptr<OpenGlShader> shader) {
    gl::glAttachShader(_id, shader->getId());
}

///// --------------------------------------------------------------- addUniform
void OpenGlProgram::addUniform(const std::string& uniform) {
    auto id = static_cast<gl::GLuint>(
            gl::glGetUniformLocation(_id, uniform.c_str())
    );
    _uniforms.insert({uniform, id});
}

///// ------------------------------------------------------------- addAttribute
void OpenGlProgram::addAttribute(const std::string& attribute) {
    auto id = static_cast<gl::GLuint>(
            gl::glGetAttribLocation(_id, attribute.c_str())
    );
    _attributes.insert({attribute, id});
}

///// --------------------------------------------------------------------- link
void OpenGlProgram::link() {
    gl::glLinkProgram(_id);

    gl::glGetProgramiv(_id, gl::GL_LINK_STATUS, &_status);

    if (_status == gl::GL_FALSE) {
        LOG(ERROR) << std::string("Error linking shader program:\n")
                      + utils::getInfoLog(_id);
        gl::glDeleteProgram(_id);
    }
}

///// ---------------------------------------------------------------------- use
void OpenGlProgram::use() {
    gl::glUseProgram(_id);
}

///// -------------------------------------------------------------------- unuse
void OpenGlProgram::unuse() {
    gl::glUseProgram(0);
}

///// ----------------------------------------------------------- getAttributeId
gl::GLuint OpenGlProgram::getAttributeId(const std::string& name) {
    return _attributes[name];
}

///// ------------------------------------------------------------- getUniformId
gl::GLuint OpenGlProgram::getUniformId(const std::string& name) {
    return _uniforms[name];
}

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems