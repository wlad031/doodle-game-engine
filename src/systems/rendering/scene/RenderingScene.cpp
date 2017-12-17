#include "RenderingScene.h"

#include "systems/rendering/utils/MeshLoader.h"

namespace systems {
namespace rendering {
namespace scene {

void RenderingScene::add(
        const std::shared_ptr<models::GameObject>& gameObject
) {
    if (gameObject->canRender()) {
        auto mesh = MeshLoader::instance()
                .loadMesh(gameObject->getMeshFilter()->getFile());

        auto renderingObject = std::make_shared<RenderingObject>(
                gameObject,
                std::move(mesh)
        );

        gameObject->setRenderingObject(renderingObject);
        _objects.push_back(renderingObject);
    }

    if (gameObject->isCamera()) {
        auto camera = std::make_shared<RenderingCamera>(gameObject);
        _cameras.push_back(camera);
    }

    if (gameObject->isLight()) {
        auto lightSource = std::make_shared<RenderingLight>(gameObject);
        _lights.push_back(lightSource);
    }
}

}  // namespace scene
}  // namespace rendering
}  // namespace systems
