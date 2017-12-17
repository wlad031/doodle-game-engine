#ifndef DOODLEGAMEENGINE_MODELS_GAMEOBJECT_H
#define DOODLEGAMEENGINE_MODELS_GAMEOBJECT_H

#include <memory>
#include <vector>

#include "models/AbstractModel.hpp"
#include "models/components/Transform.h"
#include "models/components/rendering/Camera.h"
#include "models/components/rendering/Light.h"
#include "models/components/mesh/MeshFilter.h"
#include "models/components/physic/RigidBody.h"
#include "models/components/physic/collider/BoxCollider.h"
#include "models/components/physic/collider/SphereCollider.h"

#include "systems/physic/scene/PhysicObject.h"
#include "systems/rendering/scene/RenderingObject.h"

///// ----------------------------------------------- class forward declarations
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

///// ------------------------------ JSON serialization rule forward declaration
namespace json_dto {
template<typename JSON_IO>
void json_io(JSON_IO& io, models::GameObject& gameObject);
}  // namespace json_dto

////////////////////////////////////////////////////////////////////////////////
/////                         GameObject declaration                       /////
////////////////////////////////////////////////////////////////////////////////

namespace models {

///// =============================================================== GameObject
class GameObject : public AbstractModel {
public:

    ///// --------------------------------------------------------- constructors
    GameObject() = default;

    ///// -------------------------------------------------------------- getters

    const std::shared_ptr<components::Transform>&
    getTransform() const { return _transform; }

    const std::shared_ptr<components::mesh::MeshFilter>&
    getMeshFilter() const { return _meshFilter; }

    const std::shared_ptr<components::physic::RigidBody>&
    getRigidBody() const { return _rigidBody; }

    const std::shared_ptr<systems::rendering::scene::RenderingObject>&
    getRenderingObject() const { return _renderingObject; }

    const std::shared_ptr<systems::physic::scene::PhysicObject>&
    getPhysicObject() const { return _physicObject; }

    const std::vector<std::shared_ptr<components::physic::BoxCollider>>&
    getBoxColliders() const { return _boxColliders; }

    const std::vector<std::shared_ptr<components::physic::SphereCollider>>&
    getSphereColliders() const { return _sphereColliders; }

    const std::shared_ptr<components::rendering::Camera>&
    getCamera() const { return _camera; }

    const std::shared_ptr<components::rendering::Light>&
    getLight() const { return _light; }

    ///// -------------------------------------------------------------- setters

    void setTransform(
            std::shared_ptr<components::Transform> transform
    ) { _transform = std::move(transform); }

    void setMeshFilter(
            std::shared_ptr<components::mesh::MeshFilter> meshFilter
    ) { _meshFilter = std::move(meshFilter); }

    void setRigidBody(
            std::shared_ptr<components::physic::RigidBody> rigidBody
    ) { _rigidBody = std::move(rigidBody); }

    void setRenderingObject(
            std::shared_ptr<systems::rendering::scene::RenderingObject>
            renderingObject
    ) { _renderingObject = std::move(renderingObject); }

    void setPhysicObject(
            std::shared_ptr<systems::physic::scene::PhysicObject>
            physicObject
    ) { _physicObject = std::move(physicObject); }

    void setBoxColliders(
            const std::vector<
                    std::shared_ptr<components::physic::BoxCollider>
            >& boxColliders
    ) { _boxColliders = boxColliders; }

    void setSphereColliders(
            const std::vector<
                    std::shared_ptr<components::physic::SphereCollider>
            >& sphereColliders
    ) { _sphereColliders = sphereColliders; }

    void setCamera(
            const std::shared_ptr<components::rendering::Camera>& camera
    ) { _camera = camera; }

    void setLight(
            const std::shared_ptr<components::rendering::Light>& light
    ) { _light = light; }

    ///// ----------------------------------------------------------- predicates

    bool canRender() const { return static_cast<bool>(_meshFilter); }
    bool isCamera()  const { return static_cast<bool>(_camera); }
    bool isLight()   const { return static_cast<bool>(_light); }

    bool isPhysic() const {
        return !(_boxColliders.empty() && _sphereColliders.empty());
    }

    ///// ------------------------------------------------- getAbsoluteTransform
    const std::shared_ptr<components::Transform>& getAbsoluteTransform() const;

    ///// ---------------------------------------------- JSON serialization rule
    template<typename JSON_IO>
    friend void json_dto::json_io(
            JSON_IO& io,
            models::GameObject& gameObject
    );

private:
    std::shared_ptr<GameObject> _parent;

    std::shared_ptr<components::Transform>         _transform;
    std::shared_ptr<components::mesh::MeshFilter>  _meshFilter;
    std::shared_ptr<components::physic::RigidBody> _rigidBody;
    std::vector<
            std::shared_ptr<components::physic::BoxCollider>
    > _boxColliders;
    std::vector<
            std::shared_ptr<components::physic::SphereCollider>
    > _sphereColliders;
    // TODO: add capsule colliders
    // TODO: add terrain colliders
    // TODO: add mesh colliders

    std::shared_ptr<components::rendering::Camera> _camera;
    std::shared_ptr<components::rendering::Light>  _light;

    std::shared_ptr<systems::rendering::scene::RenderingObject>
            _renderingObject;
    std::shared_ptr<systems::physic::scene::PhysicObject>
            _physicObject;
};

}  // namespace models

///// ================================================= JSON serialization rules
namespace json_dto {

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

template<typename JSON_IO>
void json_io(JSON_IO& io, models::GameObject& gameObject) {
    io
    & json::mandatory("transform", gameObject._transform)
    & json::mandatory("meshFilter", gameObject._meshFilter)
    & json::mandatory("rigidBody", gameObject._rigidBody);
}

#pragma clang diagnostic pop
}  // namespace json_dto

#endif //DOODLEGAMEENGINE_MODELS_GAMEOBJECT_H
