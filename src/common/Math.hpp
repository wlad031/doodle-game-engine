#pragma clang diagnostic push
#pragma ide diagnostic ignored "CannotResolve"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "HidingNonVirtualFunction"
#pragma ide diagnostic ignored "IncompatibleTypes"

#ifndef DOODLEGAMEENGINE_MATH_H
#define DOODLEGAMEENGINE_MATH_H

#include "Types.hpp"

#define V2 math::vec::_2
#define V3 math::vec::_3
#define V4 math::vec::_4

namespace math {

    namespace vec {

        class _2 : public glm::vec2 {
        public:
            using glm::vec2::vec2;
        };

        class _3 : public glm::vec3 {
        public:
            using glm::vec3::vec3;
        };

        class _4 : public glm::vec4 {
        public:
            using glm::vec4::vec4;
        };
    }

    namespace color {

        class rgb : public glm::vec3 {
        public:
            using glm::vec3::vec3;
        };

        class rgba : public glm::vec4 {
        public:
            using glm::vec4::vec4;;
        };
    }
}

namespace json_dto {

    template<typename JSON_IO>
    void json_io(JSON_IO& io, math::vec::_2& v) {
        io
        & json::mandatory("x", v.x)
        & json::mandatory("y", v.y);
    }

    template<typename JSON_IO>
    void json_io(JSON_IO& io, math::vec::_3& v) {
        io
        & json::mandatory("x", v.x)
        & json::mandatory("y", v.y)
        & json::mandatory("z", v.z);
    }

    template<typename JSON_IO>
    void json_io(JSON_IO& io, math::vec::_4& v) {
        io
        & json::mandatory("x", v.x)
        & json::mandatory("y", v.y)
        & json::mandatory("z", v.z)
        & json::mandatory("w", v.w);
    }

    template<typename JSON_IO>
    void json_io(JSON_IO& io, math::color::rgb& c) {
        io
        & json::mandatory("r", c.x)
        & json::mandatory("g", c.y)
        & json::mandatory("b", c.z);
    }

    template<typename JSON_IO>
    void json_io(JSON_IO& io, math::color::rgba& c) {
        io
        & json::mandatory("r", c.x)
        & json::mandatory("g", c.y)
        & json::mandatory("b", c.z)
        & json::mandatory("a", c.w);
    }
}

#endif //DOODLEGAMEENGINE_MATH_H

#pragma clang diagnostic pop