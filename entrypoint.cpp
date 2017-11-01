#include <glbinding/gl/gl.h>

#define GLFW_INCLUDE_NONE
#include <easylogging++.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "common/patterns/Observer.hpp"
#include "models/GameObject.h"
#include "common/Runnable.hpp"
#include "standalone/GlfwWindowManager.h"
#include "common/serialize/JsonSerializer.hpp"
#include "common/Scheduler.h"
#include "console/Shell.h"
#include "systems/rendering/engine/impl/opengl/Shader.h"
#include <systems/rendering/RenderSystem.h>
#include <systems/physic/PhysicSystem.h>
#include <systems/physic/scene/PhysicScene.h>
#include "systems/rendering/engine/impl/opengl/GraphicObject.h"
#include "systems/rendering/scene/RenderingScene.h"
#include "systems/rendering/utils/MeshLoader.h"

INITIALIZE_EASYLOGGINGPP

class A : public patterns::Observer {
public:
    virtual void update() override {
        LOG(INFO) << "A: I was updated!";
    }
};

class B : public patterns::Observable {
public:
    B(int a) : a(a) {}

    void kek() {
        LOG(INFO) << a << " B: kek!";
        notify();
    }

    int a = 0;
};

namespace systems::rendering::engine::opengl {

    class GraphicObject;
}

// TODO: 1. refactor #ifdef compile variables (PROJECT_PATHTOCLASS_EXT) done
// TODO: 2. refactor code style (common dir except ThreadPool, Scheduler classes is good)
// TODO: 3. refactor reference storing (common dir except Observer, ThreadPool, Scheduler classes is good)
// TODO: 4. ThreadPool, Scheduler, Logger

class TestRunner : public Runnable {
public:
    virtual void run() override {
        srand(time(NULL));

        auto manager = standalone::GlfwWindowManager::instance();
        manager.init();
        manager.window();

//        console::Shell shell;
//
//        shell
//                .command(
//                        "reload",
//                        [&vs, &fs](std::vector<std::string> input, std::ostream& out) {
//                            out << "COMMAND reload\n";
//                            if (input[1] == "v") {
//                                vs.reload();
//                                out << "v reloaded\n";
//                            } else if (input[1] == "f") {
//                                fs.reload();
//                                out << "f reloaded\n";
//                            }
//                        }
//                )
//                .command("exit", [](std::vector<std::string> input, std::ostream& out) { out << "COMMAND exit"; })
//                .command(
//                        "hello",
//                        [](std::vector<std::string> input, std::ostream& out) {
//                            out << "COMMAND HELLO -> " << input[0] << "\n";
//                        }
//                );

//        auto go = models::GameObject();
//        go.setTransform(
//                models::components::Transform(
//                        math::vec::v3{1.0, 2.0, 3.1},
//                        math::vec::v3{5, 1, 2},
//                        math::vec::v3{10}
//                ));
//
//        auto s = serialize::JsonSerializer::serialize(go);
//        LOG(INFO) << s;
//
//        auto go1 = serialize::JsonSerializer::deserialize<models::GameObject>(s);
//        LOG(INFO) << serialize::JsonSerializer::serialize(go1);

        auto thread1 = std::thread(
                        [&]() {
                            for (int i = 0;; ++i) {
                                LOG(INFO) << "log " << i;
                                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                            }
                        }
                );

        auto gameObject = std::make_shared<models::GameObject>();
        auto meshFilter = std::make_shared<models::components::mesh::MeshFilter>();
        auto transform = std::make_shared<models::components::Transform>();
        meshFilter->setFile(std::make_shared<files::File>("/home/wlad031/Downloads/Blonde Elexis - nude/BlondeElexis-nude.obj"));
        gameObject->setMeshFilter(meshFilter);
        gameObject->setTransform(transform);

        auto renderingObject = systems::rendering::scene::RenderingScene::instance().createObject(gameObject);
        auto physicObject = systems::physic::scene::PhysicScene::instance().createObject(gameObject);

        auto renderSystem = systems::rendering::RenderSystem::instance();
        auto physicSystem = systems::physic::PhysicSystem::instance();

        auto thread2 = std::thread([&]() { while (true) renderSystem.getTask()(); });
        auto thread3 = std::thread([&]() { while (true) physicSystem.getTask()(); });

        thread1.join();
        thread2.join();
        thread3.join();

//
//        B b1 = B(1);
//        B b2 = B(2);
//        A a  = A();
//
//        b1.addWatcher(a);
//        b2.addWatcher(a);
//
//        b1.kek();
//        b2.kek();
//
//        schedule::Scheduler scheduler;
//        concurrency::ThreadPool _threadPool;
//        std::vector<std::function<void()>> tasks;
//        for (int i = 0; i < 40; ++i) {
//            tasks.push_back([i]() {
//                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//                LOG(INFO) << "I am task #" << i;
//            });
//        }
//
//        for (auto&& task : tasks) {
//            _threadPool.submit(task);
//        }
//
//        scheduler._tasks = tasks;
//        scheduler.runTasks();
    }
};

int main(int argc, const char** argv) {
    START_EASYLOGGINGPP(argc, argv);

    el::Configurations conf("/home/wlad031/Documents/doodle-game-engine/logging.conf");
    el::Loggers::reconfigureLogger("default", conf);
//    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    el::Loggers::reconfigureAllLoggers(conf);

    auto engineRunner = std::make_unique<TestRunner>();

    try {
        engineRunner->run();
    } catch (Exception& e) {
        LOG(ERROR) << e.what();
        return 1;
    }
}