#ifndef DOODLEGAMEENGINE_JSONSERIALIZER_H
#define DOODLEGAMEENGINE_JSONSERIALIZER_H

#include <string>

#include <json_dto/pub.hpp>

#include "common/Types.hpp"

namespace serialize {

    class JsonSerializer {
    public:

        template<typename T>
        static std::string serialize(const T& object) {
            return json_dto::to_json(object);
        }

        template<typename T>
        static T deserialize(const std::string& str) {
            return json_dto::from_json<T>(str);
        }
    };
}

#endif //DOODLEGAMEENGINE_JSONSERIALIZER_H
