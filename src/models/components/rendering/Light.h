#ifndef DOODLEGAMEENGINE_MODELS_COMPONENTS_RENDERING_LIGHT_H
#define DOODLEGAMEENGINE_MODELS_COMPONENTS_RENDERING_LIGHT_H

#include "common/Color.hpp"

///// ------------------------------------------------ class forward declaration
namespace models {
namespace components {
namespace rendering {
class Light;
}  // namespace rendering
}  // namespace components
}  // namespace models

///// ------------------------------ JSON serialization rule forward declaration
namespace json_dto {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
template<typename JSON_IO>
void json_io(
        JSON_IO& io,
        models::components::rendering::Light& light
);
#pragma clang diagnostic pop
}  // namespace json_dto

////////////////////////////////////////////////////////////////////////////////
/////                       Light component declaration                    /////
////////////////////////////////////////////////////////////////////////////////

namespace models {
namespace components {
namespace rendering {

///// ==================================================================== Light
class Light {
public:

    ///// ---------------------------------------------------------- light types
    enum class Type {
        DIRECTIONAL,
        POINT,
        SPOT
        // TODO: add AREA light type
        // TODO: add AMBIENT light type
    };

    // TODO: add baking type
    // TODO: add shadow type

    ///// ---------------------------------------------------------- Attenuation
    struct Attenuation {
        float constant;
        float linear;
        float quadratic;

        Attenuation() : Attenuation(1.0, 1.0, 1.0) {}

        Attenuation(float constant, float linear, float quadratic) :
                constant(constant),
                linear(linear),
                quadratic(quadratic) {}
    };

    ///// ----------------------------------------------------------------- Spot
    struct Spot {
        float cutoff;
        float exponent;

        Spot() : Spot(10.0, 1.0) {}

        Spot(float cutoff, float exponent) :
                cutoff(cutoff),
                exponent(exponent) {}
    };

    ///// --------------------------------------------------------- constructors
    Light() = default;

    ///// -------------------------------------------------------------- getters
    Type getType() const { return _type; }
    const Color& getColor() const { return _color; }
    float getIntensity() const { return _intensity; }
    const Attenuation& getAttenuation() const { return _attenuation; }
    const Spot& getSpot() const { return _spot; }

    ///// -------------------------------------------------------------- setters
    void setType(Type type) { _type = type; }
    void setColor(const Color& color) { _color = color; }
    void setIntensity(float intensity) { _intensity = intensity; }
    void setAttenuation(const Attenuation& attenuation)
    { _attenuation = attenuation; }
    void setSpot(const Spot& spot) { _spot = spot; }

    ///// ---------------------------------------------- JSON serialization rule
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
    template<typename JSON_IO>
    friend void json_dto::json_io(
            JSON_IO& io,
            models::components::rendering::Light& light
    );
#pragma clang diagnostic pop

private:

    Type _type;
    Color _color;
    float _intensity;
    Attenuation _attenuation;
    Spot _spot;
};

} // namespace rendering
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
        models::components::rendering::Light& light
) {
    io;
}

#pragma clang diagnostic pop
}  // namespace json_dto

#endif //DOODLEGAMEENGINE_MODELS_COMPONENTS_RENDERING_LIGHT_H
