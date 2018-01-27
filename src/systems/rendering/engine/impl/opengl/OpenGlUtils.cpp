#include "OpenGlUtils.h"

#include <vector>

#include <glbinding/gl/gl.h>

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {
namespace utils {

///// --------------------------------------------------------------- getInfoLog
const std::string& getInfoLog(unsigned int id) {
    gl::GLint maxLength = 0;
    gl::glGetShaderiv(id, gl::GL_INFO_LOG_LENGTH, &maxLength);

    std::vector<char> errorLog(static_cast<unsigned int>(maxLength));
    gl::glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

    return std::string(errorLog.begin(), errorLog.end());
}

}  // namespace utils
}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems