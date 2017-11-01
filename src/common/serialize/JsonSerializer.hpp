#ifndef DOODLEGAMEENGINE_COMMON_SERIALIZE_JSONSERIALIZER_HPP
#define DOODLEGAMEENGINE_COMMON_SERIALIZE_JSONSERIALIZER_HPP

#include <string>

#include <json_dto/pub.hpp>

#include "common/types/Aliases.hpp"

namespace serialize {

class JsonSerializer {
public:

    template<typename T>
    static std::string serialize(const T& object, bool pretty = false) {
        return json_dto::to_json(object, pretty);
    }

    template<typename T>
    static T deserialize(const std::string& str) {
        return json_dto::from_json<T>(str);
    }
};

}  // namespace serialize

#endif //DOODLEGAMEENGINE_COMMON_SERIALIZE_JSONSERIALIZER_HPP
