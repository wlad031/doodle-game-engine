#include "Scheduler.h"

namespace schedule {

    void Scheduler::runTasks() {
        auto pFunction = [this](std::function<void()> t) -> std::future<void> {
            return _threadPool.submit(t);
        };

        std::vector<std::future<void>> futures;
//        std::transform(_tasks.begin(), _tasks.end(), std::back_inserter(futures), pFunction);

        while (true) {
            bool ready = true;

            for (auto i = 0; i < futures.size(); ++i) {
                if (futures[i].wait_for(std::chrono::seconds(0)) != std::future_status::ready) {
                    ready = false;
                    break;
                }
            }

            if (ready) {
                LOG(INFO) << "Scheduler : new cycle";
                futures.clear();
                std::transform(_tasks.begin(), _tasks.end(), std::back_inserter(futures), pFunction);
            }
        }
    }
}
