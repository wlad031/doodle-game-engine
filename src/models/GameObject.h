#ifndef DOODLEGAMEENGINE_GAMEOBJECT_H
#define DOODLEGAMEENGINE_GAMEOBJECT_H

#include <vector>

#include "models/components/Transform.h"

namespace model {
    class GameObject;
}

namespace json_dto {
    template<typename JSON_IO>
    void json_io(JSON_IO& io, model::GameObject& gameObject);
}

namespace model {

    class GameObject {
    public:
        GameObject();

        const component::Transform& transform() const;
        GameObject& transform(const component::Transform& transform);

        template<typename JSON_IO>
        friend void json_dto::json_io(JSON_IO& io, model::GameObject& gameObject);

    private:
        component::Transform _transform;
    };
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
namespace json_dto {
    template<typename JSON_IO>
    void json_io(JSON_IO& io, model::GameObject& gameObject) {
        io
        & json::mandatory("transform", gameObject._transform);
    }
}
#pragma clang diagnostic pop

#endif //DOODLEGAMEENGINE_GAMEOBJECT_H
