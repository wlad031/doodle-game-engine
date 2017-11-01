#ifndef DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_RENDERER_H
#define DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_RENDERER_H

namespace systems {
namespace rendering {
namespace engine {

class Renderer {
public:
    virtual void render() = 0;
};

}  // namespace engine
}  // namespace rendering
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_RENDERING_ENGINE_RENDERER_H
