#ifndef DOODLEGAMEENGINE_ENGINERUNNER_H
#define DOODLEGAMEENGINE_ENGINERUNNER_H

#include <easylogging++.h>

#include "common/Runnable.hpp"

class EngineRunner : public Runnable {
public:
    void run() override;
};

#endif //DOODLEGAMEENGINE_ENGINERUNNER_H
