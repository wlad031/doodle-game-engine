#include "RenderingScene.h"

#include "systems/rendering/utils/MeshLoader.h"

namespace systems {
namespace rendering {
namespace scene {

std::shared_ptr<RenderingObject>
RenderingScene::createObject(
        const std::shared_ptr<models::GameObject>& gameObject
) {
    auto mesh = MeshLoader::instance()
            .loadMesh(gameObject->getMeshFilter()->getFile());

    auto renderingObject = std::make_shared<RenderingObject>(
            gameObject,
            std::move(mesh)
    );

    gameObject->setRenderingObject(renderingObject);
    _objects.push_back(renderingObject);

    return renderingObject;
}

}  // namespace scene
}  // namespace rendering
}  // namespace systems
