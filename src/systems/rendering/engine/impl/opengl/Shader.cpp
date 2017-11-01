#include "Shader.h"

#include "common/Logger.hpp"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

///// ---------------------------------------------------------- factory methods

std::unique_ptr<Shader> Shader::fromFile(
        Shader::Type type,
        const std::shared_ptr<files::File>& file
) {
    auto shader = std::make_unique<Shader>(type);
    shader->_file                = file;
    shader->_initializedFromFile = true;
    shader->loadFile();
    return shader;
}

std::unique_ptr<Shader> Shader::fromString(
        Shader::Type type,
        const std::string& string
) {
    auto shader = std::make_unique<Shader>(type);
    shader->_source = string;
    return shader;
}

///// ------------------------------------------------------------------ compile
void Shader::compile() {
    if (_initializedFromFile && !_fileLoaded) {
        throw Exception("Shader is 'FileInitialized', but file wasn't loaded");
    }

    auto contentPtr = _source.c_str();
    gl::glShaderSource(_id, 1, &contentPtr, nullptr);
    gl::glCompileShader(_id);

    gl::glGetShaderiv(_id, gl::GL_COMPILE_STATUS, &_compileStatus);
    if (_compileStatus == gl::GL_FALSE) {
        gl::GLint maxLength = 0;
        gl::glGetShaderiv(_id, gl::GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<char> errorLog(static_cast<uint64_t>(maxLength));
        gl::glGetShaderInfoLog(_id, maxLength, &maxLength, &errorLog[0]);

        LOG(ERROR) << std::string("Error compiling shader:\n")
                      + &(errorLog[0]);

        gl::glDeleteShader(_id);
    }
}

///// --------------------------------------------------------------- getInfoLog
const std::string& Shader::getInfoLog() {
    gl::GLint maxLength = 0;
    gl::glGetShaderiv(_id, gl::GL_INFO_LOG_LENGTH, &maxLength);

    std::vector<char> errorLog(static_cast<uint64_t>(maxLength));
    gl::glGetShaderInfoLog(_id, maxLength, &maxLength, &errorLog[0]);

    return std::string(errorLog.begin(), errorLog.end());
}

///// ------------------------------------------------------------------- reload
void Shader::reload() {
    loadFile();
    compile();
}

///// ----------------------------------------------------------------- loadFile
void Shader::loadFile() {
    if (!_initializedFromFile) {
        throw Exception(
                "Shader isn't 'FileInitialized', but loadFile() was called"
        );
    }

    _source     = _file->read();
    _fileLoaded = true;
}

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems
