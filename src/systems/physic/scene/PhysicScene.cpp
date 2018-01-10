#include "PhysicScene.h"

#include "common/Logger.hpp"

namespace systems {
namespace physic {
namespace scene {

void PhysicScene::add(
        const std::shared_ptr<models::GameObject>& gameObject
) {
    LOG(INFO) << "PhysicScene :: adding object "
              //              << "#" << gameObject->getId() << " "
              << "<" << gameObject->getName() << ">";

    if (gameObject->isPhysic()) {
        auto physicObject = std::make_shared<PhysicObject>(gameObject);

        gameObject->setPhysicObject(physicObject);
        _objects.push_back(physicObject);

        LOG(INFO) << " -- physic object ";
    }
}

}  // namespace scene
}  // namespace physic
}  // namespace systems
