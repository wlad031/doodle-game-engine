#include "GameObject.h"

namespace models {

GameObject::GameObject() {}

std::shared_ptr<components::Transform>
GameObject::getTransform() const {
    return _transform;
}

std::shared_ptr<components::mesh::MeshFilter>
GameObject::getMeshFilter() const {
    return _meshFilter;
}

std::shared_ptr<systems::rendering::scene::RenderingObject>
GameObject::getRenderingObject() const {
    return _renderingObject;
}

std::shared_ptr<systems::physic::scene::PhysicObject>
GameObject::getPhysicObject() const {
    return _physicObject;
}

void GameObject::setTransform(
        const std::shared_ptr<components::Transform>& transform
) {
    _transform = transform;
}

void GameObject::setMeshFilter(
        const std::shared_ptr<components::mesh::MeshFilter>& meshFilter
) {
    _meshFilter = meshFilter;
}

void GameObject::setRenderingObject(
        const std::shared_ptr<systems::rendering::scene::RenderingObject>&
        renderingObject
) {
    _renderingObject = renderingObject;
}

void GameObject::setPhysicObject(
        const std::shared_ptr<systems::physic::scene::PhysicObject>&
        physicObject
) {
    _physicObject = physicObject;
}
}
