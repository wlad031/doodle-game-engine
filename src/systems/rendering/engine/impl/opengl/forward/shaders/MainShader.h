#ifndef DOODLEGAMEENGINE_MAINSHADER_H
#define DOODLEGAMEENGINE_MAINSHADER_H

#include "systems/rendering/engine/impl/opengl/OpenGlProgram.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {
namespace forward {

class MainShader : public OpenGlProgram {
public:
    MainShader();

    enum class Attribute {
        POSITION,
        TEX_COORD,
        NORMAL,
        TANGENT,
        BITANGENT
    };

    enum class Uniform {
        MATRIX_MODEL,
        MATRIX_VIEW,
        MATRIX_PROJECTION,
        LIGHT_POSITION,
        LIGHT_AMBIENT,
        LIGHT_DIFFUSE,
        LIGHT_SPECULAR
    };

    gl::GLuint getAttribute(Attribute attribute);
    gl::GLuint getUniform(Uniform uniform);

private:
    gl::GLuint _positionAttribute;
    gl::GLuint _texCoordAttribute;
    gl::GLuint _normalAttribute;
    gl::GLuint _tangentAttribute;
    gl::GLuint _bitangentAttribute;

    gl::GLuint _matrixModelUniform;
    gl::GLuint _matrixViewUniform;
    gl::GLuint _matrixProjectionUniform;
    gl::GLuint _lightPositionUniform;
    gl::GLuint _lightAmbientUniform;
    gl::GLuint _lightDiffuseUniform;
    gl::GLuint _lightSpecularUniform;
};

}  // namespace forward
}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_MAINSHADER_H
