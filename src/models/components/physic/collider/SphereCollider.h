#ifndef DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_COLLIDER_SPHERECOLLIDER_H
#define DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_COLLIDER_SPHERECOLLIDER_H

#include "AbstractCollider.h"

///// ------------------------------------------------ class forward declaration
namespace models {
namespace components {
namespace physic {
class SphereCollider;
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
        models::components::physic::SphereCollider& collider
);
#pragma clang diagnostic pop
}  // namespace json_dto

////////////////////////////////////////////////////////////////////////////////
/////                  SphereCollider component declaration                /////
////////////////////////////////////////////////////////////////////////////////

namespace models {
namespace components {
namespace physic {

///// =========================================================== SphereCollider
class SphereCollider : public AbstractCollider {
public:

    ///// --------------------------------------------------------- constructors
    SphereCollider() = default;

    ///// -------------------------------------------------------------- getters
    float getRadius() const { return _radius; }

    ///// -------------------------------------------------------------- setters
    void setRadius(float radius) { _radius = radius; }

private:
    float _radius;

    ///// ---------------------------------------------- JSON serialization rule
    template<typename JSON_IO>
    friend void json_dto::json_io(
            JSON_IO& io,
            models::components::physic::SphereCollider& collider
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
        models::components::physic::SphereCollider& collider
) {
    io;
}

#pragma clang diagnostic pop
}  // namespace json_dto

#endif //DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_COLLIDER_SPHERECOLLIDER_H
