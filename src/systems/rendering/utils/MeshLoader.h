#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_UTILS_MESHLOADER_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_UTILS_MESHLOADER_H

#include "common/files/File.h"

#include "systems/rendering/scene/components/Mesh.h"

namespace systems {
namespace rendering {

class MeshLoader {
public:

    static MeshLoader& instance();

    std::unique_ptr<scene::components::Mesh>
    loadMesh(const std::shared_ptr<files::File>& file);

private:
    MeshLoader();
};

}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_UTILS_MESHLOADER_H
