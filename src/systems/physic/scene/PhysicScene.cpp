#include "PhysicScene.h"

namespace systems {
namespace physic {
namespace scene {

std::shared_ptr<PhysicObject> PhysicScene::createObject(
        const std::shared_ptr<models::GameObject>& gameObject
) {
    auto physicObject = std::make_shared<PhysicObject>(gameObject);

    gameObject->setPhysicObject(physicObject);
    _objects.push_back(physicObject);

    return physicObject;
}

}  // namespace scene
}  // namespace physic
}  // namespace systems
