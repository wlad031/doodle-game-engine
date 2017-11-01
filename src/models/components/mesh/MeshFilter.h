#ifndef DOODLEGAMEENGINE_MODELS_COMPONENTS_MESH_MESHFILTER_H
#define DOODLEGAMEENGINE_MODELS_COMPONENTS_MESH_MESHFILTER_H

#include <utility>

#include "common/files/File.h"
#include "common/math/Math.h"

///// ------------------------------------------------ class forward declaration
namespace models {
namespace components {
namespace mesh {
class MeshFilter;
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
        models::components::mesh::MeshFilter& meshFilter // NOLINT
);
#pragma clang diagnostic pop
}  // namespace json_dto

////////////////////////////////////////////////////////////////////////////////
/////                    MeshFilter component declaration                  /////
////////////////////////////////////////////////////////////////////////////////

namespace models {
namespace components {
namespace mesh {

///// =============================================================== MeshFilter
class MeshFilter {
public:

    ///// --------------------------------------------------------- constructors
    MeshFilter() = default;
    explicit MeshFilter(std::shared_ptr<files::File> file) :
            _file(std::move(file)) {}

    ///// -------------------------------------------------------------- getters
    const std::shared_ptr<files::File>& getFile() const { return _file; }

    ///// -------------------------------------------------------------- setters
    void setFile(const std::shared_ptr<files::File>& file) {
        _file = file;
    }

    ///// ---------------------------------------------- JSON serialization rule
    template<typename JSON_IO>
    friend void
    json_dto::json_io(
            JSON_IO& io,
            models::components::mesh::MeshFilter& meshFilter
    );

private:
    std::shared_ptr<files::File> _file;
};

}  // namespace mesh
}  // namespace components
}  // namespace models

///// ================================================= JSON serialization rules
namespace json_dto {

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

template<typename JSON_IO>
void json_io(
        JSON_IO& io,
        models::components::mesh::MeshFilter& meshFilter
) {
    io
    & json::mandatory("file", meshFilter._file);
}

#pragma clang diagnostic pop
}  // namespace json_dto

#endif //DOODLEGAMEENGINE_MODELS_COMPONENTS_MESH_MESHFILTER_H
