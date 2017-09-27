#ifndef DOODLEGAMEENGINE_STANDALONEENGINERUNNER_H
#define DOODLEGAMEENGINE_STANDALONEENGINERUNNER_H

#include <easylogging++.h>

#include "common/Runnable.hpp"

#include "GlfwWindowManager.h"

#include "serialize/JsonSerializer.hpp"
#include "models/GameObject.h"

namespace standalone {
    class StandaloneEngineRunner : public Runnable {
    public:
        void run() override;
    };
}

#endif //DOODLEGAMEENGINE_STANDALONEENGINERUNNER_H
