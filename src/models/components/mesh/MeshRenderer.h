#ifndef DOODLEGAMEENGINE_MODELS_COMPONENTS_MESH_MESHRENDERER_H
#define DOODLEGAMEENGINE_MODELS_COMPONENTS_MESH_MESHRENDERER_H

///// ------------------------------------------------ class forward declaration
namespace models {
namespace components {
namespace mesh {
class MeshRenderer;
}  // namespace mesh
}  // namespace components
}  // namespace models

///// ------------------------------ JSON serialization rule forward declaration
namespace json_dto {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
template<typename JSON_IO>
void json_io(
        JSON_IO& io,
        models::components::mesh::MeshRenderer& meshRenderer // NOLINT
);
#pragma clang diagnostic pop
}  // namespace json_dto

////////////////////////////////////////////////////////////////////////////////
/////                   MeshRenderer component declaration                 /////
////////////////////////////////////////////////////////////////////////////////

namespace model {
namespace component {
namespace mesh {

///// ============================================================= MeshRenderer
class MeshRenderer {
public:

    ///// --------------------------------------------------------- constructors
    MeshRenderer() = default;

private:

    ///// ---------------------------------------------- JSON serialization rule
    template<typename JSON_IO>
    friend void
    json_dto::json_io(
            JSON_IO& io,
            models::components::mesh::MeshRenderer& meshRenderer
    );
};

}  // namespace mesh
}  // namespace component
}  // namespace model

///// ================================================= JSON serialization rules
namespace json_dto {

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

template<typename JSON_IO>
void json_io(
        JSON_IO& io,
        models::components::mesh::MeshRenderer& meshRenderer
) {
    io;
}

#pragma clang diagnostic pop
}  // namespace json_dto

#endif //DOODLEGAMEENGINE_MODELS_COMPONENTS_MESH_MESHRENDERER_H
