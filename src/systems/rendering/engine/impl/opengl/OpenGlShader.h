#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLSHADER_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLSHADER_H

#include <glbinding/gl/gl.h>

#include "common/exceptions/Exception.hpp"
#include "common/files/File.h"

////////////////////////////////////////////////////////////////////////////////
/////                    Representation of the OpenGL shader               /////
////////////////////////////////////////////////////////////////////////////////

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

///// =============================================== InvalidShaderTypeException
class InvalidOpenGlShaderTypeException : public Exception {
public:
    ///// --------------------------------------------------------- constructors
    explicit InvalidOpenGlShaderTypeException() = default;

    ///// ----------------------------------------------------------------- what
    const char* what() const throw() override {
        std::string s = "Invalid shader type";
        return s.c_str();
    }
};

///// =================================================================== Shader
class OpenGlShader {
public:

    ///// ---------------------------------------------------------- shader type
    enum class Type {
        VERTEX,
        FRAGMENT,
        GEOMETRY
    };

    ///// --------------------------------------------------------- constructors
    explicit OpenGlShader(Type type) :
            _type(matchShaderType(type)),
            _fileLoaded(false),
            _initializedFromFile(false) {
        _id = gl::glCreateShader(_type);
    }

    ///// ------------------------------------------------------ factory methods
    static std::unique_ptr<OpenGlShader> fromFile(
            Type type,
            const std::shared_ptr<files::File>& file
    );

    static std::unique_ptr<OpenGlShader> fromString(
            Type type,
            const std::string& string
    );

    ///// -------------------------------------------------------------- compile
    void compile();

    ///// --------------------------------------------------------------- reload
    void reload();

    ///// -------------------------------------------------------------- getters
    uint getId() const { return _id; }
    Type getType() const { return matchShaderType(_type); }
    bool getCompileStatus() const { return static_cast<bool>(_compileStatus); }
    const std::string& getSource() const { return _source; }
    const std::shared_ptr<files::File>& getFile() const { return _file; }

private:

    gl::GLuint    _id;
    gl::GLenum    _type;
    gl::GLboolean _compileStatus;
    std::string   _source;

    std::shared_ptr<files::File> _file;

    bool _initializedFromFile {};
    bool _fileLoaded {};

private:

    ///// ------------------------------------------------------------- loadFile
    void loadFile();

    ///// ------------------------------------------------------ matchShaderType
    static gl::GLenum matchShaderType(Type type) {
        switch (type) {
            case Type::VERTEX   : return gl::GL_VERTEX_SHADER;
            case Type::FRAGMENT : return gl::GL_FRAGMENT_SHADER;
            case Type::GEOMETRY : return gl::GL_GEOMETRY_SHADER;
        }
    }

    static Type matchShaderType(gl::GLenum type) {
        switch (type) {
            case gl::GL_VERTEX_SHADER   : return Type::VERTEX;
            case gl::GL_FRAGMENT_SHADER : return Type::FRAGMENT;
            case gl::GL_GEOMETRY_SHADER : return Type::GEOMETRY;
            default :throw InvalidOpenGlShaderTypeException();
        }
    }
};

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_OPENGLSHADER_H
