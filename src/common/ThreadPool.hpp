#ifndef DOODLEGAMEENGINE_COMMON_THREADPOOL_HPP
#define DOODLEGAMEENGINE_COMMON_THREADPOOL_HPP

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

#include "common/CompileTimeVariables.h"
#include "common/Logger.hpp"

// TODO: IT DOESN'T WORK WELL
// TODO: implement discard polices
namespace concurrency {
    class ThreadPool {
    public:
        static const unsigned int DEFAULT_N_THREADS = 4;

        enum class Policy {
            STUB
        };

        ThreadPool() : ThreadPool(DEFAULT_N_THREADS, 0, Policy::STUB) {}

        ThreadPool(unsigned int nThreads) : ThreadPool(nThreads, 0, Policy::STUB) {}

        ThreadPool(unsigned int nThreads, unsigned int queueSize) : ThreadPool(nThreads, queueSize, Policy::STUB) {}

        ThreadPool(unsigned int nThreads, Policy policy) : ThreadPool(nThreads, 0, policy) {}

        ThreadPool(unsigned int nThreads, unsigned int queueSize, Policy policy) :
                _stop(false), _policy(policy) {
//                LOGGER(logging::getLogger("ThreadPool")) {

            for (size_t i = 0; i < nThreads; ++i) {
                _workers.emplace_back(
                        [this, &i] {
                            while (true) {
//                                LOGGER.debug("Thread %d is working...", std::this_thread::get_id());

                                std::unique_lock<std::mutex> lock(_queue_mutex);
                                _condition.wait(
                                        lock,
                                        [this] {
                                            return _stop || !_tasks.empty();
                                        }
                                );

                                if (_stop && _tasks.empty()) {
                                    return;
                                }

                                auto task = std::move(_tasks.front());

//                                LOGGER.debug("Task was acquired by thread %d", std::this_thread::get_id());

                                _tasks.pop();

                                task();
                            }
                        }
                );
            }
        }

        ~ThreadPool() {
            std::unique_lock<std::mutex> lock(_queue_mutex);
            _stop = true;

            _condition.notify_all();

            for (std::thread& worker: _workers) {
                worker.join();
            }
        }

        template<class F, class... Args>
        auto submit(F&& f, Args&& ... args) -> std::future<typename std::result_of<F(Args...)>::type> {
            using return_type = typename std::result_of<F(Args...)>::type;

            auto task = std::make_shared<std::packaged_task<return_type()> >(
                    std::bind(std::forward<F>(f), std::forward<Args>(args)...)
            );

            std::future<return_type> res = task->get_future();

            std::unique_lock<std::mutex> lock(_queue_mutex);

            if (_stop) {
                // TODO: implement another behavior
                throw std::runtime_error("submit on stopped ThreadPool");
            }

            _tasks.emplace([task]() { (*task)(); });
//            LOGGER.debug("Task was submitted. Current size of task queue = ", _tasks.size());

            _condition.notify_all();

            return res;
        };

    private:
//        logging::Logger LOGGER;

        std::vector<std::thread>          _workers;
        std::queue<std::function<void()>> _tasks;
        Policy                            _policy;

        std::mutex              _queue_mutex;
        std::condition_variable _condition;
        bool                    _stop;
    };
}

#endif //DOODLEGAMEENGINE_COMMON_THREADPOOL_HPP
