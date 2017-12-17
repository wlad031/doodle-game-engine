#include "PhysicScene.h"

namespace systems {
namespace physic {
namespace scene {

void PhysicScene::add(
        const std::shared_ptr<models::GameObject>& gameObject
) {
    if (gameObject->isPhysic()) {
        auto physicObject = std::make_shared<PhysicObject>(gameObject);

        gameObject->setPhysicObject(physicObject);
        _objects.push_back(physicObject);
    }
}

}  // namespace scene
}  // namespace physic
}  // namespace systems
