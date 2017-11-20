#ifndef DOODLEGAMEENGINE_CONVERTERS_H
#define DOODLEGAMEENGINE_CONVERTERS_H

#include <bullet/btBulletDynamicsCommon.h>

#include "common/math/Math.h"

namespace systems {
namespace physic {
namespace engine {
namespace bullet {
namespace utils {

btVector3 toBullet(const math::vec::v3& v);
math::vec::v3 fromBullet(const btVector3& v);

}  // namespace utils
}  // namespace bullet
}  // namespace engine
}  // namespace physic
}  // namespace systems

#endif //DOODLEGAMEENGINE_CONVERTERS_H
