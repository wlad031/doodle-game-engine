#ifndef DOODLEGAMEENGINE_COMMON_COLOR_HPP
#define DOODLEGAMEENGINE_COMMON_COLOR_HPP

#include "common/math/Math.h"

////////////////////////////////////////////////////////////////////////////////
/////                  Complex color struct definition                     /////
////////////////////////////////////////////////////////////////////////////////

struct Color {
    math::color::rgb ambient;
    math::color::rgb diffuse;
    math::color::rgb specular;

    Color() : Color(
            math::color::rgb(0.2, 0.2, 0.2),
            math::color::rgb(0.5, 0.5, 0.5),
            math::color::rgb(0.8, 0.8, 0.8)
    ) {}

    Color(
            const math::color::rgb& ambient,
            const math::color::rgb& diffuse,
            const math::color::rgb& specular
    ) : ambient(ambient),
        diffuse(diffuse),
        specular(specular) {}
};

#endif //DOODLEGAMEENGINE_COMMON_COLOR_HPP
