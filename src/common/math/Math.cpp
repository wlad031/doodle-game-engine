#include "Math.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>

namespace math {

namespace vec {

///// ---------------------------------------------------------- default vectors

const v2& NULL_V2 = v2(0.0);
const v3& NULL_V3 = v3(0.0);
const v4& NULL_V4 = v4(0.0);

const v2& UNIT_V2 = v2(1.0);
const v3& UNIT_V3 = v3(1.0);
const v4& UNIT_V4 = v4(1.0);

}  // namespace vec

namespace mat {

const m4& translate(vec::v3 position) {
    return glm::translate(glm::mat4(1.0), position);
}

const m4& rotate(vec::v3 rotation) {
    return glm::mat4(1.0); // TODO: implement
}

const m4& scale(vec::v3 scal) {
    return glm::scale(glm::mat4(1.0), scal);
}

}  // namespace mat

namespace color {

///// ----------------------------------------------------------- default colors
const rgb& BLACK = rgb(0.0);
const rgb& WHITE = rgb(1.0);
const rgb& RED   = rgb(1.0, 0.0, 0.0);
const rgb& GREEN = rgb(0.0, 1.0, 0.0);
const rgb& BLUE  = rgb(0.0, 0.0, 1.0);

///// --------------------------------------------------------- color converters
const rgb& rgba2rgb(const rgba& c) { return rgb(c.r, c.g, c.b); }
const rgba& rgb2rgba(const rgb& c) { return rgba(c.r, c.g, c.b, 1.0); }

}  // namespace color
}  // namespace math
