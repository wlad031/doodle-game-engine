#ifndef DOODLEGAMEENGINE_GAMEOBJECT_H
#define DOODLEGAMEENGINE_GAMEOBJECT_H

#include <vector>

#include "models/components/Transform.h"

namespace model {
    class GameObject;
}

namespace json_dto {
    template<typename JSON_IO>
    void json_io(JSON_IO& io, model::GameObject gameObject);
}

namespace model {

    class GameObject {
    public:
        struct Components {
            std::vector<component::Transform> transforms;
        };

        Components& getComponents();

        template<typename JSON_IO>
        friend void json_dto::json_io(JSON_IO& io, model::GameObject gameObject);

    private:
        Components components;
    };
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
namespace json_dto {
    template<typename JSON_IO>
    void json_io(JSON_IO& io, model::GameObject gameObject) {
        io
        & json::mandatory(
                "transforms",
                gameObject.components.transforms
        );
    }
}
#pragma clang diagnostic pop

#endif //DOODLEGAMEENGINE_GAMEOBJECT_H
