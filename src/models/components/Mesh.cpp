#include "Mesh.h"

namespace model {
    namespace component {

        bool Mesh::MeshEntry::hasVertices() {
            return !_vertices.empty();
        }

        bool Mesh::MeshEntry::hasTexCoords() {
            return !_texCoords.empty();
        }

        bool Mesh::MeshEntry::hasNormals() {
            return !_normals.empty();
        }

        bool Mesh::MeshEntry::hasTangentsAndBitangents() {
            return !_tangents.empty() && !_bitangents.empty();
        }

        bool Mesh::MeshEntry::hasIndices() {
            return !_indices.empty();
        }
    }
}