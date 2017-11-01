#include "ShaderProgram.h"

#include <easylogging++.h>

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

///// ------------------------------------------------------------- constructors
ShaderProgram::ShaderProgram() {
    _id = gl::glCreateProgram();
}

///// ------------------------------------------------------------- attachShader
void ShaderProgram::attachShader(const std::shared_ptr<Shader>& shader) {
    gl::glAttachShader(_id, shader->getId());
}

///// --------------------------------------------------------------- addUniform
void ShaderProgram::addUniform(const std::string& uniform) {
    auto id = static_cast<gl::GLuint>(
            gl::glGetUniformLocation(_id, uniform.c_str())
    );
    _uniforms.insert({uniform, id});
}

///// ------------------------------------------------------------- addAttribute
void ShaderProgram::addAttribute(const std::string& attribute) {
    auto id = static_cast<gl::GLuint>(
            gl::glGetAttribLocation(_id, attribute.c_str())
    );
    _attributes.insert({attribute, id});
}

///// --------------------------------------------------------------------- link
void ShaderProgram::link() {
    gl::glLinkProgram(_id);

    gl::glGetProgramiv(_id, gl::GL_LINK_STATUS, &_status);

    if (_status == gl::GL_FALSE) {
        gl::GLint maxLength = 0;
        gl::glGetProgramiv(_id, gl::GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<char> errorLog(static_cast<uint64_t>(maxLength));
        gl::glGetProgramInfoLog(_id, maxLength, &maxLength, &errorLog[0]);

        LOG(ERROR) << std::string("Error linking shader:\n") + &(errorLog[0]);

        gl::glDeleteProgram(_id);
    }
}

///// ---------------------------------------------------------------------- use
void ShaderProgram::use() {
    gl::glUseProgram(_id);
}

///// -------------------------------------------------------------------- unuse
void ShaderProgram::unuse() {
    gl::glUseProgram(0);
}

///// ----------------------------------------------------------- getAttributeId
gl::GLuint ShaderProgram::getAttributeId(const std::string& name) {
    return _attributes[name];
}

///// ------------------------------------------------------------- getUniformId
gl::GLuint ShaderProgram::getUniformId(const std::string& name) {
    return _uniforms[name];
}

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems