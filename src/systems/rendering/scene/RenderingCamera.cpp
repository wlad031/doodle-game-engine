#include "RenderingCamera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

namespace systems {
namespace rendering {
namespace scene {

const math::mat::m4& RenderingCamera::getViewMatrix() {

    auto eye    = _gameObject->getTransform()->getPosition();
    auto center = math::vec::NULL_V3;
    auto up     = math::vec::v3(0.0, 1.0, 0.0);

    auto m = glm::lookAt(eye, eye + center, up); // TODO: fix this
    std::cout << m[1][1];
    return m;
}

const math::mat::m4& RenderingCamera::getProjectionMatrix() {
    // TODO: implement caching
    auto camera = _gameObject->getCamera();
    switch (camera->getProjection()) {
        case models::components::rendering::Camera::Projection::PERSPECTIVE:
            return glm::perspective(
                    glm::radians(camera->getFieldOfView()),
                    1.0f, // TODO: implement
                    camera->getClippingPlane().near,
                    camera->getClippingPlane().far
            );
//        case models::components::rendering::Camera::Projection::ORTHOGRAPHIC:
//            return glm::ortho(left, right, bottom, top, near, far);
    }
}

}  // namespace scene
}  // namespace rendering
}  // namespace systems