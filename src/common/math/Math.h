#ifndef DOODLEGAMEENGINE_COMMON_MATH_MATH_H
#define DOODLEGAMEENGINE_COMMON_MATH_MATH_H

#include "common/types/Aliases.hpp"

////////////////////////////////////////////////////////////////////////////////
/////                         Math functions and types                     /////
////////////////////////////////////////////////////////////////////////////////

namespace math {

namespace vec {

///// ----------------------------------------------------------- vector aliases
using v2 = glm::vec2;
using v3 = glm::vec3;
using v4 = glm::vec4;

///// ---------------------------------------------------------- default vectors
extern const v2& NULL_V2;
extern const v3& NULL_V3;
extern const v4& NULL_V4;
extern const v2& IDENTITY_V2;
extern const v3& IDENTITY_V3;
extern const v4& IDENTITY_V4;

}  // namespace vec

namespace mat {

///// ----------------------------------------------------------- matrix aliases
using m2 = glm::mat2;
using m3 = glm::mat3;
using m4 = glm::mat4;

const m4& translate(vec::v3 position);
const m4& rotate(vec::v3 rotation);
const m4& scale(vec::v3 scale);

}  // namespace mat

namespace color {

///// ------------------------------------------------------------ color aliases
using rgb = glm::vec3;
using rgba = glm::vec4;

///// ----------------------------------------------------------- default colors
extern const rgb& BLACK;
extern const rgb& WHITE;
extern const rgb& RED;
extern const rgb& GREEN;
extern const rgb& BLUE;

///// --------------------------------------------------------- color converters
const rgb& rgba2rgb(const rgba& c);
const rgba& rgb2rgba(const rgb& c);

}  // namespace color
}  // namespace math

///// ================================================= JSON serialization rules

namespace json_dto {

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

///// --------------------------------------------------------------------- vec2
template<typename JSON_IO>
void json_io(JSON_IO& io, glm::vec2& v) {
    io
    & json_dto::mandatory("x", v.x)
    & json_dto::mandatory("y", v.y);
}

///// --------------------------------------------------------------------- vec3
template<typename JSON_IO>
void json_io(JSON_IO& io, glm::vec3& v) {
    io
    & json_dto::mandatory("x", v.x)
    & json_dto::mandatory("y", v.y)
    & json_dto::mandatory("z", v.z);
}

///// --------------------------------------------------------------------- vec4
template<typename JSON_IO>
void json_io(JSON_IO& io, glm::vec4& v) {
    io
    & json_dto::mandatory("x", v.x)
    & json_dto::mandatory("y", v.y)
    & json_dto::mandatory("z", v.z)
    & json_dto::mandatory("w", v.w);
}

#pragma clang diagnostic pop
}  // namespace json_dto

#endif //DOODLEGAMEENGINE_COMMON_MATH_MATH_H
