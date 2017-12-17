#ifndef DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_COLLIDER_BOXCOLLIDER_H
#define DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_COLLIDER_BOXCOLLIDER_H

#include "AbstractCollider.h"

///// ------------------------------------------------ class forward declaration
namespace models {
namespace components {
namespace physic {
class BoxCollider;
}  // namespace physic
}  // namespace components
}  // namespace models

///// ------------------------------ JSON serialization rule forward declaration
namespace json_dto {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
template<typename JSON_IO>
void json_io(
        JSON_IO& io,
        models::components::physic::BoxCollider& collider
);
#pragma clang diagnostic pop
}  // namespace json_dto

////////////////////////////////////////////////////////////////////////////////
/////                    BoxCollider component declaration                 /////
////////////////////////////////////////////////////////////////////////////////

namespace models {
namespace components {
namespace physic {

///// ============================================================== BoxCollider
class BoxCollider : public AbstractCollider {
public:

    ///// --------------------------------------------------------- constructors
    BoxCollider() = default;

    ///// -------------------------------------------------------------- getters
    const math::vec::v3& getSize() const { return _size; }

    ///// -------------------------------------------------------------- setters
    void setSize(const math::vec::v3& size) { _size = size; }

private:
    math::vec::v3 _size;

    ///// ---------------------------------------------- JSON serialization rule
    template<typename JSON_IO>
    friend void json_dto::json_io(
            JSON_IO& io,
            models::components::physic::BoxCollider& collider
    );
};

} // namespace physic
} // namespace components
} // namespace models

///// ================================================= JSON serialization rules
namespace json_dto {

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

template<typename JSON_IO>
void json_io(
        JSON_IO& io,
        models::components::physic::BoxCollider& collider
) {
    io;
}

#pragma clang diagnostic pop
}  // namespace json_dto

#endif //DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_COLLIDER_BOXCOLLIDER_H
