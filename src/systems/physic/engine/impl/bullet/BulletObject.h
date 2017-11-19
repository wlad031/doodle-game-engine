#ifndef DOODLEGAMEENGINE_BULLETOBJECT_H
#define DOODLEGAMEENGINE_BULLETOBJECT_H

#include <memory>

#include <bullet/btBulletDynamicsCommon.h>

namespace systems {
namespace physic {
namespace engine {
namespace bullet {

class BulletObject {
public:

    explicit BulletObject(btDiscreteDynamicsWorld* world);

    ~BulletObject() {
        _world->removeRigidBody(_btRigidBody);
        delete _btRigidBody->getMotionState();
        delete _btCollisionShape;
        delete _btMotionState;
        delete _btConstructionInfo;
        delete _btRigidBody;
    }

    btRigidBody* getBtRigidBody() { return _btRigidBody; }

private:

    btCollisionShape* _btCollisionShape;
    btDefaultMotionState* _btMotionState;
    btRigidBody::btRigidBodyConstructionInfo* _btConstructionInfo;
    btRigidBody* _btRigidBody;

    btDiscreteDynamicsWorld* _world;
};

}  // namespace bullet
}  // namespace engine
}  // namespace physic
}  // namespace systems

#endif //DOODLEGAMEENGINE_BULLETOBJECT_H
