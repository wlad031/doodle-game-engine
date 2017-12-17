#ifndef DOODLEGAMEENGINE_SYSTEMS_PHYSIC_ENGINE_IMPL_BULLET_BULLETOBJECT_H
#define DOODLEGAMEENGINE_SYSTEMS_PHYSIC_ENGINE_IMPL_BULLET_BULLETOBJECT_H

#include <memory>

#include <bullet/btBulletDynamicsCommon.h>

#include "systems/physic/scene/PhysicObject.h"

namespace systems {
namespace physic {
namespace engine {
namespace bullet {

class BulletObject {
public:

    explicit BulletObject(
            std::shared_ptr<systems::physic::scene::PhysicObject> physicObject
    );

    const std::shared_ptr<btRigidBody>& getBtRigidBody()
    { return _btRigidBody; }

private:

    std::shared_ptr<btCompoundShape> _btCollisionShape;
    std::shared_ptr<btDefaultMotionState> _btMotionState;
    std::shared_ptr<btRigidBody::btRigidBodyConstructionInfo> _btConstructionInfo;
    std::shared_ptr<btRigidBody> _btRigidBody;
};

}  // namespace bullet
}  // namespace engine
}  // namespace physic
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_PHYSIC_ENGINE_IMPL_BULLET_BULLETOBJECT_H
