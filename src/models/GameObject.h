#ifndef DOODLEGAMEENGINE_MODELS_GAMEOBJECT_H
#define DOODLEGAMEENGINE_MODELS_GAMEOBJECT_H

#include <memory>
#include <vector>

#include "models/components/Transform.h"
#include "models/components/mesh/MeshFilter.h"
#include "models/components/physic/RigidBody.h"

#include "systems/physic/scene/PhysicObject.h"
#include "systems/rendering/scene/RenderingObject.h"

namespace models {
class GameObject;
}  // namespace models

namespace systems {
namespace rendering {
namespace scene {

class RenderingObject;

}  // namespace scene
}  // namespace rendering

namespace physic {
namespace scene {

class PhysicObject;

}  // namespace scene
}  // namespace physic
}  // namespace systems

namespace json_dto {
template<typename JSON_IO>
void json_io(JSON_IO& io, models::GameObject& gameObject); // NOLINT
}  // namespace json_dto

namespace models {

class GameObject {
public:
    GameObject() = default;

    const std::shared_ptr<components::Transform>&
    getTransform() const {
        return _transform;
    }

    const std::shared_ptr<components::mesh::MeshFilter>&
    getMeshFilter() const {
        return _meshFilter;
    }

    const std::shared_ptr<components::physic::RigidBody>&
    getRigidBody() const {
        return _rigidBody;
    }

    const std::shared_ptr<systems::rendering::scene::RenderingObject>&
    getRenderingObject() const {
        return _renderingObject;
    }

    const std::shared_ptr<systems::physic::scene::PhysicObject>&
    getPhysicObject() const {
        return _physicObject;
    }

    void setTransform(std::shared_ptr<components::Transform> transform) {
        _transform = std::move(transform);
    }

    void setMeshFilter(
            std::shared_ptr<components::mesh::MeshFilter> meshFilter
    ) {
        _meshFilter = std::move(meshFilter);
    }

    void setRigidBody(
            std::shared_ptr<components::physic::RigidBody> rigidBody
    ) {
        _rigidBody = std::move(rigidBody);
    }

    void setRenderingObject(
            std::shared_ptr<systems::rendering::scene::RenderingObject>
            renderingObject
    ) {
        _renderingObject = std::move(renderingObject);
    }

    void setPhysicObject(
            std::shared_ptr<systems::physic::scene::PhysicObject>
            physicObject
    ) {
        _physicObject = std::move(physicObject);
    }

    template<typename JSON_IO>
    friend void json_dto::json_io(JSON_IO& io, models::GameObject& gameObject);

private:
    std::shared_ptr<components::Transform>         _transform;
    std::shared_ptr<components::mesh::MeshFilter>  _meshFilter;
    std::shared_ptr<components::physic::RigidBody> _rigidBody;

    std::shared_ptr<systems::rendering::scene::RenderingObject> _renderingObject;
    std::shared_ptr<systems::physic::scene::PhysicObject>       _physicObject;
};

}  // namespace models

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
namespace json_dto {
template<typename JSON_IO>
void json_io(JSON_IO& io, models::GameObject& gameObject) {
    io
    & json::mandatory("transform", gameObject._transform)
    & json::mandatory("meshFilter", gameObject._meshFilter)
    & json::mandatory("rigidBody", gameObject._rigidBody);
}
}  // namespace json_dto
#pragma clang diagnostic pop

#endif //DOODLEGAMEENGINE_MODELS_GAMEOBJECT_H
