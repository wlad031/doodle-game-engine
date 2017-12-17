#ifndef DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_COLLIDER_ABSTRACTCOLLIDER_H
#define DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_COLLIDER_ABSTRACTCOLLIDER_H

#include "common/math/Math.h"

namespace models {
namespace components {
namespace physic {

class AbstractCollider {
public:

    const math::vec::v3& getCenter() const { return _center; }

    void setCenter(const math::vec::v3& center) { _center = center; }

protected:

// TODO:    Material
    math::vec::v3 _center;

};

} // namespace physic
} // namespace components
} // namespace models

#endif //DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_COLLIDER_ABSTRACTCOLLIDER_H
