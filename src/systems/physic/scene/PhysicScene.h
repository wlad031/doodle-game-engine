#ifndef DOODLEGAMEENGINE_SYSTEMS_PHYSIC_SCENE_PHYSICSCENE_H
#define DOODLEGAMEENGINE_SYSTEMS_PHYSIC_SCENE_PHYSICSCENE_H

#include <vector>

#include "PhysicObject.h"

namespace systems {
namespace physic {
namespace scene {

class PhysicScene {
public:

    static PhysicScene& instance() {
        static PhysicScene _instance;
        return _instance;
    }

    std::shared_ptr<PhysicObject> createObject(
            const std::shared_ptr<models::GameObject>& gameObject
    );

    const std::vector<std::shared_ptr<PhysicObject>>&
    getObjects() const { return _objects; }

private:

    PhysicScene() = default;

    std::vector<std::shared_ptr<PhysicObject>> _objects;
};

}  // namespace scene
}  // namespace physic
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_PHYSIC_SCENE_PHYSICSCENE_H
