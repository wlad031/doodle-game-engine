#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_GRAPHICOBJECT_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_GRAPHICOBJECT_H

#include <map>

#include "ShaderProgram.h"

#include "systems/rendering/scene/components/MeshEntry.h"

namespace systems {
namespace rendering {
namespace scene {
namespace components {
class MeshEntry;
}  // namespace components
}  // namespace scene
namespace engine {
namespace opengl {

enum Buffers {
    VERTEX_BUFFER,
    TEXCOORD_BUFFER,
    NORMAL_BUFFER,
    TANGENT_BUFFER,
    BITANGENT_BUFFER,
    INDEX_BUFFER
};

class GraphicObject {
public:

    explicit GraphicObject(
            const std::shared_ptr<
                    systems::rendering::scene::components::MeshEntry
            >& meshEntry
    );

    void render(
            const std::shared_ptr<
                    systems::rendering::engine::opengl::ShaderProgram
            >& shaderProgram
    );

private:

    unsigned int _vao;
    std::map<Buffers, unsigned int> _vbo;

    unsigned int _nElements;
    unsigned int _nVertices;
    unsigned int _nFaces;

    bool _hasVertices;
    bool _hasTexCoords;
    bool _hasNormals;
    bool _hasTgsAndBitgs;
    bool _hasIndices;
};

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_IMPL_OPENGL_GRAPHICOBJECT_H
