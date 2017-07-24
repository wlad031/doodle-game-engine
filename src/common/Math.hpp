#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "HidingNonVirtualFunction"
#pragma ide diagnostic ignored "IncompatibleTypes"

#ifndef DOODLEGAMEENGINE_MATH_H
#define DOODLEGAMEENGINE_MATH_H

#include "Types.hpp"

namespace math {

    namespace vec {

        class _2 {
        public:
            _2() :
                    x(0), y(0) {}

            _2(double x, double y) :
                    x(x), y(y) {}

            _2(double x) :
                    x(x), y(x) {}

            _2(std::initializer_list<double> l) {
                auto s = std::vector<double>(l);
                switch (s.size()) {
                    case 0:
                        break;
                    case 1:
                        x = s[0];
                        y = s[0];
                        break;
                    default:
                        x = s[0];
                        y = s[1];
                        break;
                }
            }

            double x;
            double y;

            glm::vec2 toGlm() {
                return glm::vec2(x, y);
            }
        };

        class _3 {
        public:
            _3() :
                    x(0), y(0), z(0) {}

            _3(double x, double y, double z) :
                    x(x), y(y), z(z) {}

            _3(double x) :
                    x(x), y(x), z(x) {}

            _3(std::initializer_list<double> l) {
                auto s = std::vector<double>(l);
                switch (s.size()) {
                    case 0:
                        break;
                    case 1:
                        x = s[0];
                        y = s[0];
                        z = s[0];
                        break;
                    case 2:
                        x = s[0];
                        y = s[1];
                        z = s[1];
                        break;
                    default:
                        x = s[0];
                        y = s[1];
                        z = s[2];
                        break;
                }
            }

            double x;
            double y;
            double z;

            glm::vec3 toGlm() {
                return glm::vec3(x, y, z);
            }
        };

        class _4 {
        public:
            _4() :
                    x(0), y(0), z(0), w(0) {}

            _4(double x, double y, double z, double w) :
                    x(x), y(y), z(z), w(w) {}

            _4(double x) :
                    x(x), y(x), z(x), w(x) {}

            _4(std::initializer_list<double> l) {
                auto s = std::vector<double>(l);
                switch (s.size()) {
                    case 0:
                        break;
                    case 1:
                        x = s[0];
                        y = s[0];
                        z = s[0];
                        w = s[0];
                        break;
                    case 2:
                        x = s[0];
                        y = s[1];
                        z = s[1];
                        w = s[1];
                        break;
                    case 3:
                        x = s[0];
                        y = s[1];
                        z = s[2];
                        w = s[2];
                        break;
                    default:
                        x = s[0];
                        y = s[1];
                        z = s[2];
                        w = s[3];
                        break;
                }
            }

            double x;
            double y;
            double z;
            double w;

            glm::vec4 toGlm() {
                return glm::vec4(x, y, z, w);
            }
        };
    }

    namespace color {

        class rgb : public vec::_3 {
        public:
            using vec::_3::_3;
        };

        class rgba : public vec::_4 {
        public:
            using vec::_4::_4;
        };
    }
}

namespace json_dto {

    template<typename JSON_IO>
    void json_io(JSON_IO& io, math::vec::_2 v) {
        io
        & json::mandatory("x", v.x)
        & json::mandatory("y", v.y);
    }

    template<typename JSON_IO>
    void json_io(JSON_IO& io, math::vec::_3 v) {
        io
        & json::mandatory("x", v.x)
        & json::mandatory("y", v.y)
        & json::mandatory("z", v.z);
    }

    template<typename JSON_IO>
    void json_io(JSON_IO& io, math::vec::_4 v) {
        io
        & json::mandatory("x", v.x)
        & json::mandatory("y", v.y)
        & json::mandatory("z", v.z)
        & json::mandatory("w", v.w);
    }

    template<typename JSON_IO>
    void json_io(JSON_IO& io, math::color::rgb c) {
        io
        & json::mandatory("r", c.x)
        & json::mandatory("g", c.y)
        & json::mandatory("b", c.z);
    }

    template<typename JSON_IO>
    void json_io(JSON_IO& io, math::color::rgba c) {
        io
        & json::mandatory("r", c.x)
        & json::mandatory("g", c.y)
        & json::mandatory("b", c.z)
        & json::mandatory("a", c.w);
    }
}

#endif //DOODLEGAMEENGINE_MATH_H

#pragma clang diagnostic pop