#ifndef DOODLEGAMEENGINE_MODELS_GAMEOBJECT_H
#define DOODLEGAMEENGINE_MODELS_GAMEOBJECT_H

#include <memory>
#include <vector>

#include "models/components/Transform.h"
#include "models/components/mesh/MeshFilter.h"

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
void json_io(JSON_IO& io, models::GameObject& gameObject);
}  // namespace json_dto

namespace models {

class GameObject {
public:
    GameObject();

    std::shared_ptr<components::Transform> getTransform() const;
    std::shared_ptr<components::mesh::MeshFilter> getMeshFilter() const;
    std::shared_ptr<systems::rendering::scene::RenderingObject>
    getRenderingObject() const;
    std::shared_ptr<systems::physic::scene::PhysicObject>
    getPhysicObject() const;

    void setTransform(const std::shared_ptr<components::Transform>& transform);
    void setMeshFilter(
            const std::shared_ptr<components::mesh::MeshFilter>& meshFilter
    );
    void setRenderingObject(
            const std::shared_ptr<systems::rendering::scene::RenderingObject>&
            renderingObject
    );
    void setPhysicObject(
            const std::shared_ptr<systems::physic::scene::PhysicObject>&
            physicObject
    );

    template<typename JSON_IO>
    friend void json_dto::json_io(JSON_IO& io, models::GameObject& gameObject);

private:
    std::shared_ptr<components::Transform>        _transform;
    std::shared_ptr<components::mesh::MeshFilter> _meshFilter;

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
    & json::mandatory("transform", gameObject._transform);
}
}  // namespace json_dto
#pragma clang diagnostic pop

#endif //DOODLEGAMEENGINE_MODELS_GAMEOBJECT_H
