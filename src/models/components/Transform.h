#ifndef DOODLEGAMEENGINE_TRANSFORM_H
#define DOODLEGAMEENGINE_TRANSFORM_H

#include "common/Math.hpp"

#include "AbstractComponent.h"

namespace model {
    namespace component {
        class Transform;
    }
}

namespace json_dto {
    template<typename JSON_IO>
    void json_io(JSON_IO& io, model::component::Transform transform);
}

namespace model {
    namespace component {
        using namespace math;

        class Transform : public AbstractComponent {
        public:
            Transform();
            Transform(const vec::_3& position, const vec::_3& rotation, const vec::_3& scale);

            const vec::_3& getPosition() const;
            void setPosition(const vec::_3& position);
            const vec::_3& getRotation() const;
            void setRotation(const vec::_3& rotation);
            const vec::_3& getScale() const;
            void setScale(const vec::_3& scale);

            template<typename JSON_IO>
            friend void json_dto::json_io(JSON_IO& io, model::component::Transform transform);

        private:
            vec::_3 position;
            vec::_3 rotation;
            vec::_3 scale;
        };
    }
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
namespace json_dto {
    template<typename JSON_IO>
    void json_io(JSON_IO& io, model::component::Transform transform) {
        io
        & json::mandatory("position", transform.position)
        & json::mandatory("rotation", transform.rotation)
        & json::mandatory("scale", transform.scale);
    }
}
#pragma clang diagnostic pop

#endif //DOODLEGAMEENGINE_TRANSFORM_H
