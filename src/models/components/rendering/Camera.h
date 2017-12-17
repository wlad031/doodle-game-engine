#ifndef DOODLEGAMEENGINE_MODELS_COMPONENTS_RENDERING_CAMERA_H
#define DOODLEGAMEENGINE_MODELS_COMPONENTS_RENDERING_CAMERA_H

///// ------------------------------------------------ class forward declaration
namespace models {
namespace components {
namespace rendering {
class Camera;
}  // namespace rendering
}  // namespace components
}  // namespace models

///// ------------------------------ JSON serialization rule forward declaration
namespace json_dto {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
template<typename JSON_IO>
void json_io(
        JSON_IO& io,
        models::components::rendering::Camera& camera
);
#pragma clang diagnostic pop
}  // namespace json_dto

////////////////////////////////////////////////////////////////////////////////
/////                      Camera component declaration                    /////
////////////////////////////////////////////////////////////////////////////////

namespace models {
namespace components {
namespace rendering {

///// =================================================================== Camera
class Camera {
public:

    ///// --------------------------------------------------- camera projections
    enum class Projection {
        PERSPECTIVE,
        ORTHOGRAPHIC
    };

    ///// -------------------------------------------------------- ClippingPlane
    struct ClippingPlane {
        float near;
        float far;

        ClippingPlane() : ClippingPlane(0.3, 100.0) {}
        ClippingPlane(float near, float far) : near(near), far(far) {}
    };

    ///// --------------------------------------------------------- constructors
    Camera() = default;

    ///// -------------------------------------------------------------- getters
    bool isActive() const { return _active; }
    Projection getProjection() const { return _projection; }
    const ClippingPlane& getClippingPlane() const { return _clippingPlane; }
    float getFieldOfView() const { return _fieldOfView; }
    float getSize() const { return _size; }

    ///// -------------------------------------------------------------- setters
    void setActive(bool active)  { _active = active; }
    void setProjection(Projection projection) { _projection = projection; }
    void setClippingPlane(const ClippingPlane& clippingPlane)
    { _clippingPlane = clippingPlane; }
    void setFieldOfView(float fieldOfView) { _fieldOfView = fieldOfView; }
    void setSize(float size) { _size = size; }

    ///// ---------------------------------------------- JSON serialization rule
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
    template<typename JSON_IO>
    friend void json_dto::json_io(
            JSON_IO& io,
            models::components::rendering::Camera& camera
    );
#pragma clang diagnostic pop

private:

    bool _active;

    // TODO: add filtering by layers

    Projection _projection;
    ClippingPlane _clippingPlane;

    float _fieldOfView; // for perspective projection
    float _size;        // for orthographic projection
};

}  // namespace rendering
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
        models::components::rendering::Camera& camera
) {
    io;
}

#pragma clang diagnostic pop
}  // namespace json_dto

#endif //DOODLEGAMEENGINE_MODELS_COMPONENTS_RENDERING_CAMERA_H
