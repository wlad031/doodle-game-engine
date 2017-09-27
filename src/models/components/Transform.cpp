#include "Transform.h"

#define DEFAULT_POSITION V3(0.0f)
#define DEFAULT_ROTATION V3(0.0f)
#define DEFAULT_SCALE V3(1.0)

namespace model {
    namespace component {

        Transform::Transform() :
                _position(DEFAULT_POSITION), _rotation(DEFAULT_ROTATION), _scale(DEFAULT_SCALE) {}

        Transform::Transform(
                const V3& position,
                const V3& rotation,
                const V3& scale
        ) :
                _position(position), _rotation(rotation), _scale(scale) {}

        const V3& Transform::position() const {
            return _position;
        }

        Transform& Transform::position(const V3& position) {
            Transform::_position = position;
            return *this;
        }

        const V3& Transform::rotation() const {
            return _rotation;
        }

        Transform& Transform::rotation(const V3& rotation) {
            Transform::_rotation = rotation;
            return *this;
        }

        const V3& Transform::scale() const {
            return _scale;
        }

        Transform& Transform::scale(const V3& scale) {
            Transform::_scale = scale;
            return *this;
        }
    }
}