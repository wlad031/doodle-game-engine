#ifndef DOODLEGAMEENGINE_OPENGLRENDERER_H
#define DOODLEGAMEENGINE_OPENGLRENDERER_H

#include "GraphicObject.h"

#include "systems/rendering/engine/Renderer.h"
#include "systems/rendering/scene/RenderingObject.h"

namespace systems {
namespace rendering {
namespace engine {
namespace opengl {

class OpenGlRenderer : public Renderer {
public:
    OpenGlRenderer();

protected:

    std::map<
            std::shared_ptr<systems::rendering::scene::RenderingObject>,
            std::vector<GraphicObject>
    > _objects;
};

}  // namespace opengl
}  // namespace engine
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_OPENGLRENDERER_H
