#include "MeshLoader.h"

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

namespace systems {
namespace rendering {

MeshLoader::MeshLoader() = default;

MeshLoader& MeshLoader::instance() {
    static MeshLoader _instance;
    return _instance;
}

std::unique_ptr<scene::components::Mesh>
MeshLoader::loadMesh(const std::shared_ptr<files::File>& file) {
    if (!file->isPlainFile()) throw files::FileLoadingException(file);

    auto importer    = Assimp::Importer();
    auto importFlags = aiProcess_CalcTangentSpace
                       | aiProcess_Triangulate
                       | aiProcess_GenSmoothNormals
                       | aiProcess_JoinIdenticalVertices
                       | aiProcess_SortByPType;

    auto scene = importer.ReadFile(file->getPath(), importFlags);

    if (scene == nullptr) throw files::FileLoadingException(file);

    auto mesh = std::make_unique<scene::components::Mesh>();

    if (scene->HasMeshes()) {
        for (auto i = 0; i < scene->mNumMeshes; ++i) {

            auto entry = std::make_shared<scene::components::MeshEntry>();
            auto am    = scene->mMeshes[i];

            entry->setNVertices(am->mNumVertices);
            entry->setNFaces(am->mNumFaces);
            entry->setNElements(am->mNumFaces * 3);
            entry->setMaterialIndex(am->mMaterialIndex);
            entry->setHasVertices(am->HasPositions());
            entry->setHasTexCoords(am->HasTextureCoords(0));
            entry->setHasNormals(am->HasNormals());
            entry->setHasTgsAndBitgs(am->HasTangentsAndBitangents());
            entry->setHasIndices(am->HasFaces());

            auto nVtxMult3 = am->mNumVertices * 3;
            auto nVtxMult2 = am->mNumVertices * 2;

            if (entry->hasVertices()) {
                std::vector<float> vertices(nVtxMult3);

                for (auto j = 0; j < am->mNumVertices; ++j) {
                    vertices[j * 3 + 0] = am->mVertices[j].x;
                    vertices[j * 3 + 1] = am->mVertices[j].y;
                    vertices[j * 3 + 2] = am->mVertices[j].z;
                }

                entry->setVertices(vertices);
            }

            if (entry->hasTexCoords()) {
                std::vector<float> texCoords(nVtxMult2);

                for (auto j = 0; j < am->mNumVertices; ++j) {
                    texCoords[j * 2 + 0] = am->mTextureCoords[0][j].x;
                    texCoords[j * 2 + 1] = am->mTextureCoords[0][j].y;
                }

                entry->setTexCoords(texCoords);
            }

            if (entry->hasNormals()) {
                std::vector<float> normals(nVtxMult3);

                for (auto j = 0; j < am->mNumVertices; ++j) {
                    normals[j * 3 + 0] = am->mNormals[j].x;
                    normals[j * 3 + 1] = am->mNormals[j].y;
                    normals[j * 3 + 2] = am->mNormals[j].z;
                }

                entry->setNormals(normals);
            }

            if (entry->hasTgsAndBitgs()) {
                std::vector<float> tangents(nVtxMult3);
                std::vector<float> bitangents(nVtxMult3);

                for (auto j = 0; j < am->mNumVertices; ++j) {
                    tangents[j * 3 + 0] = am->mTangents[j].x;
                    tangents[j * 3 + 1] = am->mTangents[j].y;
                    tangents[j * 3 + 2] = am->mTangents[j].z;

                    bitangents[j * 3 + 0] = am->mBitangents[j].x;
                    bitangents[j * 3 + 1] = am->mBitangents[j].y;
                    bitangents[j * 3 + 2] = am->mBitangents[j].z;
                }

                entry->setTgs(tangents);
                entry->setBitgs(bitangents);
            }

            if (entry->hasIndices()) {
                std::vector<unsigned int> indices(am->mNumFaces * 3);

                for (auto j = 0; j < am->mNumFaces; ++j) {
                    indices[j * 3 + 0] = am->mFaces[j].mIndices[0];
                    indices[j * 3 + 1] = am->mFaces[j].mIndices[1];
                    indices[j * 3 + 2] = am->mFaces[j].mIndices[2];
                }

                entry->setIndices(indices);
            }

            mesh->addEntry(entry);
        }
    }

//    if (scene.HasMaterials()) {
//        // TODO: implement
//        for (auto i = 0; i < scene.mNumMaterials; ++i) {
//
//            scene.mMaterials[i];
//        }
//    }
//
//    delete scene;

    return mesh;
}

}  // namespace rendering
}  // namespace systems