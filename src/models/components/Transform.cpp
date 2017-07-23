#include "Transform.h"

using namespace math;

#define DEFAULT_POSITION vec::_3(0.0)
#define DEFAULT_ROTATION vec::_3(0.0)
#define DEFAULT_SCALE vec::_3(1.0)

model::component::Transform::Transform() :
        position(DEFAULT_POSITION), rotation(DEFAULT_ROTATION), scale(DEFAULT_SCALE) {}

model::component::Transform::Transform(
        const vec::_3& position,
        const vec::_3& rotation,
        const vec::_3& scale
) :
        position(position), rotation(rotation), scale(scale) {}

const vec::_3& model::component::Transform::getPosition() const {
    return position;
}

void model::component::Transform::setPosition(const vec::_3& position) {
    Transform::position = position;
}

const vec::_3& model::component::Transform::getRotation() const {
    return rotation;
}

void model::component::Transform::setRotation(const vec::_3& rotation) {
    Transform::rotation = rotation;
}

const vec::_3& model::component::Transform::getScale() const {
    return scale;
}

void model::component::Transform::setScale(const vec::_3& scale) {
    Transform::scale = scale;
}
