#ifndef DOODLEGAMEENGINE_MODELS_COMPONENTS_TRANSFORM_H
#define DOODLEGAMEENGINE_MODELS_COMPONENTS_TRANSFORM_H

#include <mutex>

#include "common/math/Math.h"

///// ------------------------------------------------ class forward declaration
namespace models {
namespace components {
class Transform;
}  // namespace components
}  // namespace models

///// ------------------------------ JSON serialization rule forward declaration
namespace json_dto {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
template<typename JSON_IO>
void json_io(
        JSON_IO& io,
        std::shared_ptr<models::components::Transform>& transform
);
#pragma clang diagnostic pop
}  // namespace json_dto

////////////////////////////////////////////////////////////////////////////////
/////                     Transform component declaration                  /////
////////////////////////////////////////////////////////////////////////////////

namespace models {
namespace components {

///// ================================================================ Transform
class Transform {
public:

    ///// --------------------------------------------------------- constructors
    Transform() :
            Transform(
                    math::vec::NULL_V3,
                    math::vec::NULL_V3,
                    math::vec::IDENTITY_V3
            ) {}

    Transform(
            const math::vec::v3& position,
            const math::vec::v3& rotation,
            const math::vec::v3& scale
    ) : _position(position),
        _rotation(rotation),
        _scale(scale) {}

    Transform(const Transform& that) :
            Transform(
                    that.getPosition(),
                    that.getRotation(),
                    that.getScale()
            ) {}

    ///// -------------------------------------------------------------- getters
    const math::vec::v3& getPosition() const {
        return _position;
    }

    const math::vec::v3& getScale() const {
        return _rotation;
    }

    const math::vec::v3& getRotation() const {
        return _scale;
    }

    ///// -------------------------------------------------------------- setters
    void setPosition(const math::vec::v3& position) {
        _position = position;
    }

    void setRotation(const math::vec::v3& rotation) {
        _rotation = rotation;
    }

    void setScale(const math::vec::v3& scale) {
        _scale = scale;
    }

    const Transform& operator+(const Transform& that);

    ///// ---------------------------------------------- JSON serialization rule
    template<typename JSON_IO>
    friend void json_dto::json_io(
            JSON_IO& io,
            std::shared_ptr<models::components::Transform>& transform
    );

private:
    math::vec::v3 _position;
    math::vec::v3 _rotation;
    math::vec::v3 _scale;

    std::mutex _mtx; // TODO: synchronization
};

}  // namespace components
}  // namespace models

///// ================================================= JSON serialization rules
namespace json_dto {

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

template<typename JSON_IO>
void json_io(
        JSON_IO& io,
        std::shared_ptr<models::components::Transform>& transform
) {
    io
    & json::mandatory("position", transform->_position)
    & json::mandatory("rotation", transform->_rotation)
    & json::mandatory("scale", transform->_scale);
}

#pragma clang diagnostic pop
}  // namespace json_dto

#endif //DOODLEGAMEENGINE_MODELS_COMPONENTS_TRANSFORM_H
