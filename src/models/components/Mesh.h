#ifndef DOODLEGAMEENGINE_MESH_H
#define DOODLEGAMEENGINE_MESH_H

#include "common/Math.hpp"

#include "AbstractComponent.h"

namespace model {
    namespace component {
        class Mesh;
    }
}

namespace json_dto {
    template<typename JSON_IO>
    void json_io(JSON_IO& io, model::component::Mesh transform);
}

namespace model {
    namespace component {
        using namespace math;

        class Mesh : public AbstractComponent {
        public:

        private:

            class MeshEntry {
            public:
                bool hasVertices();
                bool hasTexCoords();
                bool hasNormals();
                bool hasTangentsAndBitangents();
                bool hasIndices();

            private:
                std::vector<float>        _vertices;
                std::vector<float>        _texCoords;
                std::vector<float>        _normals;
                std::vector<float>        _tangents;
                std::vector<float>        _bitangents;
                std::vector<unsigned int> _indices;
            };

            std::vector<MeshEntry&> _meshEntries;
        };
    }
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
namespace json_dto {
    template<typename JSON_IO>
    void json_io(JSON_IO& io, model::component::Mesh transform) {
        io;
//        & json::optional("scale", transform.scale, math::vec::_3());
    }
}
#pragma clang diagnostic pop

#endif //DOODLEGAMEENGINE_MESH_H
