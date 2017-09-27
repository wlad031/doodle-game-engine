#include "MeshFilter.h"

namespace model {
    namespace component {
        namespace mesh {

            bool MeshFilter::MeshEntry::hasVertices() {
                return !_vertices.empty();
            }

            bool MeshFilter::MeshEntry::hasTexCoords() {
                return !_texCoords.empty();
            }

            bool MeshFilter::MeshEntry::hasNormals() {
                return !_normals.empty();
            }

            bool MeshFilter::MeshEntry::hasTangentsAndBitangents() {
                return !_tangents.empty() && !_bitangents.empty();
            }

            bool MeshFilter::MeshEntry::hasIndices() {
                return !_indices.empty();
            }
        }
    }
}