#ifndef DOODLEGAMEENGINE_ASSIMPMESHLOADER_H
#define DOODLEGAMEENGINE_ASSIMPMESHLOADER_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "MeshLoader.h"

namespace loader {
    class AssimpMeshLoader : public MeshLoader {

        model::asset::Mesh& load() override;
    };
}

#endif //DOODLEGAMEENGINE_ASSIMPMESHLOADER_H
