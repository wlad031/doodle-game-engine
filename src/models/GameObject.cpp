#include "GameObject.h"

namespace model {

    GameObject::GameObject() {
    }

    const component::Transform& GameObject::transform() const {
        return _transform;
    }

    GameObject& GameObject::transform(const component::Transform& transform) {
        _transform = transform;
        return *this;
    }
}
