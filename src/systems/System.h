#ifndef DOODLEGAMEENGINE_SYSTEMS_SYSTEM_H
#define DOODLEGAMEENGINE_SYSTEMS_SYSTEM_H

#include <functional>

namespace systems {
class System {
public:
    virtual std::function<void()> getTask() = 0;
};
}  // namespace systems

#endif //DOODLEGAMEENGINE_SYSTEMS_SYSTEM_H
