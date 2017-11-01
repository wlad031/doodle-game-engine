#include "RenderSystem.h"

namespace systems {
namespace rendering {

std::function<void()> RenderSystem::getTask() {
    return [this]() { _renderer.render(); };
}

}  // namespace rendering
}  // namespace systems