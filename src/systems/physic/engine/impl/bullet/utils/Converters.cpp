#include "Converters.h"

namespace systems {
namespace physic {
namespace engine {
namespace bullet {
namespace utils {

btVector3 toBullet(const math::vec::v3& v) {
    return btVector3(v.x, v.y, v.z);
}

math::vec::v3 fromBullet(const btVector3& v) {
    return math::vec::v3(v.x(), v.y(), v.z());
}

}  // namespace utils
}  // namespace bullet
}  // namespace engine
}  // namespace physic
}  // namespace systems