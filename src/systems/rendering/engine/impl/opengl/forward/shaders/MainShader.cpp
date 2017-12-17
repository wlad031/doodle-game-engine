#include "MainShader.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {
namespace forward {

MainShader::MainShader() : OpenGlProgram() {

    // TODO: implement relative paths

    auto vs = OpenGlShader::fromFile(
            OpenGlShader::Type::VERTEX,
            std::make_shared<files::File>(
                    "/home/wlad031/Documents/projects/game-engine/doodle-game-engine/shaders/shader.vert"
            )
    );
    auto fs = OpenGlShader::fromFile(
            OpenGlShader::Type::FRAGMENT,
            std::make_shared<files::File>(
                    "/home/wlad031/Documents/projects/game-engine/doodle-game-engine/shaders/shader.frag"
            )
    );

    vs->compile();
    fs->compile();

    attachShader(std::move(vs));
    attachShader(std::move(fs));

    link();

     _positionAttribute  = addAttribute("Position");
     _texCoordAttribute  = addAttribute("TexCoord");
     _normalAttribute    = addAttribute("Normal");
     _tangentAttribute   = addAttribute("Tangent");
     _bitangentAttribute = addAttribute("Bitangent");

     _matrixModelUniform      = addUniform("Matrix.Model");
     _matrixViewUniform       = addUniform("Matrix.View");
     _matrixProjectionUniform = addUniform("Matrix.Projection");
     _lightPositionUniform    = addUniform("Light.Position");
     _lightAmbientUniform     = addUniform("Light.Ambient");
     _lightDiffuseUniform     = addUniform("Light.Diffuse");
     _lightSpecularUniform    = addUniform("Light.Specular");
}

gl::GLuint MainShader::getAttribute(MainShader::Attribute attribute) {
    switch (attribute) {
        case Attribute::POSITION  : return _positionAttribute;
        case Attribute::TEX_COORD : return _texCoordAttribute;
        case Attribute::NORMAL    : return _normalAttribute;
        case Attribute::TANGENT   : return _tangentAttribute;
        case Attribute::BITANGENT : return _bitangentAttribute;
    }
}

gl::GLuint MainShader::getUniform(MainShader::Uniform uniform) {
    switch (uniform) {
        case Uniform::MATRIX_MODEL      : return _matrixModelUniform;
        case Uniform::MATRIX_VIEW       : return _matrixViewUniform;
        case Uniform::MATRIX_PROJECTION : return _matrixProjectionUniform;
        case Uniform::LIGHT_POSITION    : return _lightPositionUniform;
        case Uniform::LIGHT_AMBIENT     : return _lightAmbientUniform;
        case Uniform::LIGHT_DIFFUSE     : return _lightDiffuseUniform;
        case Uniform::LIGHT_SPECULAR    : return _lightSpecularUniform;
    }
}

}  // namespace forward
}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems
