#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_COMPONENTS_MESH_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_COMPONENTS_MESH_H

#include <memory>
#include <vector>

#include "MeshEntry.h"

namespace systems {
namespace rendering {
namespace scene {
namespace components {

class Mesh {
public:

    const std::vector<std::shared_ptr<MeshEntry>>& getEntries() const;

    void addEntry(const std::shared_ptr<MeshEntry>& entry);

private:
    std::vector<std::shared_ptr<MeshEntry>> _entries;
};

}  // namespace components
}  // namespace scene
}  // namespace rendering
}  // namespace systems


#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_COMPONENTS_MESH_H
