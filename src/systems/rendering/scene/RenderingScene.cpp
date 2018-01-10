#include "RenderingScene.h"

#include "common/Logger.hpp"

#include "systems/rendering/utils/MeshLoader.h"

namespace systems {
namespace rendering {
namespace scene {

void RenderingScene::add(
        const std::shared_ptr<models::GameObject>& gameObject
) {
    LOG(INFO) << "RenderingScene :: adding object "
//              << "#" << gameObject->getId() << " "
              << "<" << gameObject->getName() << ">";

    if (gameObject->canRender()) {
        auto mesh = MeshLoader::instance()
                .loadMesh(gameObject->getMeshFilter()->getFile());

        auto renderingObject = std::make_shared<RenderingObject>(
                gameObject,
                std::move(mesh)
        );

        gameObject->setRenderingObject(renderingObject);
        _objects.push_back(renderingObject);

        LOG(INFO) << " -- render object ";
    }

    if (gameObject->isCamera()) {
        auto camera = std::make_shared<RenderingCamera>(gameObject);
        _cameras.push_back(camera);

        LOG(INFO) << " -- camera ";
    }

    if (gameObject->isLight()) {
        auto lightSource = std::make_shared<RenderingLight>(gameObject);
        _lights.push_back(lightSource);

        LOG(INFO) << " -- light source ";
    }
}

}  // namespace scene
}  // namespace rendering
}  // namespace systems
