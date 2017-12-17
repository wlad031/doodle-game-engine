#include "PhysicObject.h"

namespace systems {
namespace physic {
namespace scene {

void PhysicObject::update(
        const math::vec::v3& position,
        const math::vec::v3& rotation
) {
    _gameObject->getTransform()->setPosition(position);
    _gameObject->getTransform()->setRotation(rotation);
}

}  // namespace scene
}  // namespace physic
}  // namespace systems