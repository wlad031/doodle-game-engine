#ifndef DOODLEGAMEENGINE_STANDALONE_STANDALONEENGINERUNNER_H
#define DOODLEGAMEENGINE_STANDALONE_STANDALONEENGINERUNNER_H

#include "common/Logger.hpp"
#include "common/Runnable.hpp"

#include "GlfwWindowManager.h"

#include "common/serialize/JsonSerializer.hpp"
#include "models/GameObject.h"

namespace standalone {
    class StandaloneEngineRunner : public Runnable {
    public:
        virtual void run() override;
    };
}

#endif //DOODLEGAMEENGINE_STANDALONE_STANDALONEENGINERUNNER_H
