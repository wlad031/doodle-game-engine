#include "Mesh.h"

namespace systems {
namespace rendering {
namespace scene {
namespace components {

const std::vector<std::shared_ptr<MeshEntry>>&
Mesh::getEntries() const { return _entries; }

void Mesh::addEntry(const std::shared_ptr<MeshEntry>& entry) {
    _entries.push_back(entry);
}

}  // namespace components
}  // namespace scene
}  // namespace rendering
}  // namespace systems