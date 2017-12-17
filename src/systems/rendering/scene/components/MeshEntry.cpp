#include "MeshEntry.h"

namespace systems {
namespace rendering {
namespace scene {
namespace components {

unsigned int MeshEntry::getNElements()     const { return _nElements;     }
unsigned int MeshEntry::getNVertices()     const { return _nVertices;     }
unsigned int MeshEntry::getNFaces()        const { return _nFaces;        }
unsigned int MeshEntry::getMaterialIndex() const { return _materialIndex; }

const std::vector<float>&
MeshEntry::getVertices()  const { return _vertices;  }
const std::vector<float>&
MeshEntry::getTexCoords() const { return _texCoords; }
const std::vector<float>&
MeshEntry::getNormals()   const { return _normals;   }
const std::vector<float>&
MeshEntry::getTgs()       const { return _tgs;       }
const std::vector<float>&
MeshEntry::getBitgs()     const { return _bitgs;     }
const std::vector<unsigned int>&
MeshEntry::getIndices()   const { return _indices;   }

bool MeshEntry::hasVertices()    const { return _hasVertices;    }
bool MeshEntry::hasTexCoords()   const { return _hasTexCoords;   }
bool MeshEntry::hasNormals()     const { return _hasNormals;     }
bool MeshEntry::hasTgsAndBitgs() const { return _hasTgsAndBitgs; }
bool MeshEntry::hasIndices()     const { return _hasIndices;     }

void MeshEntry::setNElements(unsigned int nElements)
{ _nElements = nElements; }

void MeshEntry::setNVertices(unsigned int nVertices)
{ _nVertices = nVertices; }

void MeshEntry::setNFaces(unsigned int nFaces)
{ _nFaces = nFaces; }

void MeshEntry::setMaterialIndex(unsigned int materialIndex)
{ _materialIndex = materialIndex; }

void MeshEntry::setVertices(const std::vector<float>& vertices)
{ _vertices = vertices; }

void MeshEntry::setTexCoords(const std::vector<float>& texCoords)
{ _texCoords = texCoords; }

void MeshEntry::setNormals(const std::vector<float>& normals)
{ _normals = normals; }

void MeshEntry::setTgs(const std::vector<float>& tgs)
{ _tgs = tgs; }

void MeshEntry::setBitgs(const std::vector<float>& bitgs)
{ _bitgs = bitgs; }

void MeshEntry::setIndices(const std::vector<unsigned int>& indices)
{ _indices= indices; }

void MeshEntry::setHasVertices(bool hasVertices)
{ _hasVertices = hasVertices; }

void MeshEntry::setHasTexCoords(bool hasTexCoords)
{ _hasTexCoords = hasTexCoords; }

void MeshEntry::setHasNormals(bool hasNormals)
{ _hasNormals = hasNormals; }

void MeshEntry::setHasTgsAndBitgs(bool hasTgsAndBitgs)
{ _hasTgsAndBitgs = hasTgsAndBitgs; }

void MeshEntry::setHasIndices(bool hasIndices)
{ _hasIndices = hasIndices; }

}  // namespace components
}  // namespace scene
}  // namespace rendering
}  // namespace systems