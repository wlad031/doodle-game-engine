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
    void json_io(JSON_IO& io, model::component::Transform& transform);
}

namespace model {
    namespace component {

        class Transform : public AbstractComponent {
        public:
            Transform();
            Transform(const V3& position, const V3& rotation, const V3& scale);

            const V3& position() const;
            Transform& position(const V3& position);
            const V3& rotation() const;
            Transform& rotation(const V3& rotation);
            const V3& scale() const;
            Transform& scale(const V3& scale);

            template<typename JSON_IO>
            friend void json_dto::json_io(JSON_IO& io, model::component::Transform& transform);

        private:
            V3 _position;
            V3 _rotation;
            V3 _scale;
        };
    }
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
namespace json_dto {
    template<typename JSON_IO>
    void json_io(JSON_IO& io, model::component::Transform& transform) {
        io
        & json::mandatory("position", transform._position)
        & json::mandatory("rotation", transform._rotation)
        & json::mandatory("scale", transform._scale);
    }
}
#pragma clang diagnostic pop

#endif //DOODLEGAMEENGINE_TRANSFORM_H
