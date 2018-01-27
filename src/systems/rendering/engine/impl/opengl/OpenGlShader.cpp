#include "OpenGlShader.h"

#include "common/Logger.hpp"
#include "OpenGlUtils.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

///// ---------------------------------------------------------- factory methods

std::unique_ptr<OpenGlShader> OpenGlShader::fromFile(
        OpenGlShader::Type type,
        const std::shared_ptr<files::File>& file
) {
    auto shader = std::make_unique<OpenGlShader>(type);
    shader->_file                = file;
    shader->_initializedFromFile = true;
    shader->loadFile();
    return shader;
}

std::unique_ptr<OpenGlShader> OpenGlShader::fromString(
        OpenGlShader::Type type,
        const std::string& string
) {
    auto shader = std::make_unique<OpenGlShader>(type);
    shader->_source = string;
    return shader;
}

///// ------------------------------------------------------------------ compile
void OpenGlShader::compile() {
    if (_initializedFromFile && !_fileLoaded) {
        throw Exception("Shader is 'FileInitialized', but file wasn't loaded");
    }

    auto contentPtr = _source.c_str();
    gl::glShaderSource(_id, 1, &contentPtr, nullptr);
    gl::glCompileShader(_id);

    gl::glGetShaderiv(_id, gl::GL_COMPILE_STATUS, &_compileStatus);
    if (_compileStatus == gl::GL_FALSE) {
//        LOG(ERROR) << std::string("Error compiling shader:\n")
//                      + utils::getInfoLog(_id);
        gl::glDeleteShader(_id);
    }
}

///// ------------------------------------------------------------------- reload
void OpenGlShader::reload() {
    loadFile();
    compile();
}

///// ----------------------------------------------------------------- loadFile
void OpenGlShader::loadFile() {
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
