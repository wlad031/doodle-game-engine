#ifndef DOODLEGAMEENGINE_COMMON_SCHEDULER_H
#define DOODLEGAMEENGINE_COMMON_SCHEDULER_H

#include <easylogging++.h>

#include "common/ThreadPool.hpp"

namespace schedule {

    // TODO: IT DOESN'T WORK WELL
    class Scheduler {
    public:

//        Scheduler() : _threadPool(concurrency::ThreadPool(4)) {}

        concurrency::ThreadPool _threadPool;
        std::vector<std::function<void()>> _tasks;

        void runTasks();

    };
}

#endif //DOODLEGAMEENGINE_COMMON_SCHEDULER_H
