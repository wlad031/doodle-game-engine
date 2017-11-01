#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_COMPONENTS_MESHENTRY_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_COMPONENTS_MESHENTRY_H

#include <vector>

namespace systems {
namespace rendering {
namespace scene {
namespace components {

class MeshEntry {
public:

    unsigned int getNElements()     const;
    unsigned int getNVertices()     const;
    unsigned int getNFaces()        const;
    unsigned int getMaterialIndex() const;

    const std::vector<float>&        getVertices()  const;
    const std::vector<float>&        getTexCoords() const;
    const std::vector<float>&        getNormals()   const;
    const std::vector<float>&        getTgs()       const;
    const std::vector<float>&        getBitgs()     const;
    const std::vector<unsigned int>& getIndices()   const;

    bool hasVertices()    const;
    bool hasTexCoords()   const;
    bool hasNormals()     const;
    bool hasTgsAndBitgs() const;
    bool hasIndices()     const;

    void setNElements    (unsigned int nElements);
    void setNVertices    (unsigned int nVertices);
    void setNFaces       (unsigned int nFaces);
    void setMaterialIndex(unsigned int materialIndex);

    void setVertices (const std::vector<float>& vertices);
    void setTexCoords(const std::vector<float>& texCoords);
    void setNormals  (const std::vector<float>& normals);
    void setTgs      (const std::vector<float>& tgs);
    void setBitgs    (const std::vector<float>& bitgs);
    void setIndices  (const std::vector<unsigned int>& indices);

    void setHasVertices   (bool hasVertices);
    void setHasTexCoords  (bool hasTexCoords);
    void setHasNormals    (bool hasNormals);
    void setHasTgsAndBitgs(bool hasTgsAndBitgs);
    void setHasIndices    (bool hasIndices);

private:

    unsigned int _nElements;
    unsigned int _nVertices;
    unsigned int _nFaces;

    std::vector<float>        _vertices;
    std::vector<float>        _texCoords;
    std::vector<float>        _normals;
    std::vector<float>        _tgs;
    std::vector<float>        _bitgs;
    std::vector<unsigned int> _indices;

    bool _hasVertices;
    bool _hasTexCoords;
    bool _hasNormals;
    bool _hasTgsAndBitgs;
    bool _hasIndices;

    unsigned int _materialIndex;
};

}  // namespace components
}  // namespace scene
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_SCENE_COMPONENTS_MESHENTRY_H
