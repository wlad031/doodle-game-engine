#include "GameObject.h"

namespace models {

const std::shared_ptr<components::Transform>&
GameObject::getAbsoluteTransform() const {
    if (!_parent) return std::make_shared<components::Transform>(*_transform);

    auto newTransform = *_parent->getAbsoluteTransform() + *_transform;
    return std::make_shared<components::Transform>(newTransform);
}

} // namespace models
