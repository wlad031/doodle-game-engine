#include "Transform.h"

namespace models {
namespace components {

const Transform& Transform::operator+(const Transform& that) {

    auto newPosition = _position + that.getPosition();
    auto newRotation = _rotation + that.getRotation();
    auto newScale    = _scale    + that.getScale();

    return Transform(newPosition, newRotation, newScale);
}

}  // namespace components
}  // namespace models