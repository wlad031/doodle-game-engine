#include <glbinding/gl/gl.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "CannotResolve"
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
#include "systems/rendering/engine/impl/opengl/OpenGlShader.h"
#include <systems/rendering/RenderSystem.h>
#include <systems/physic/PhysicSystem.h>
#include <systems/physic/scene/PhysicScene.h>
#include <glbinding/Binding.h>
#include "systems/rendering/engine/impl/opengl/OpenGlObject.h"
#include "systems/rendering/scene/RenderingScene.h"
#include "systems/rendering/utils/MeshLoader.h"

#include "cmake.h"

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

    class OpenGlObject;
}

// TODO: 1. refactor #ifdef compile variables (PROJECT_PATHTOCLASS_EXT) done
// TODO: 2. refactor code style (common dir except ThreadPool, Scheduler classes is good)
// TODO: 3. refactor reference storing (common dir except Observer, ThreadPool, Scheduler classes is good)
// TODO: 4. ThreadPool, Scheduler, Logger

class TestRunner : public Runnable {
public:
    virtual void run() override {
        srand(time(NULL));

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
//            auto s = serialize::JsonSerializer::serialize(gameObject, true);
//            LOG(INFO) << s;
//
//            auto go1 = serialize::JsonSerializer::deserialize<std::shared_ptr<models::GameObject>>(s);
//            LOG(INFO) << serialize::JsonSerializer::serialize(go1, true);

//        auto renderingScene = systems::rendering::scene::RenderingScene::instance();
//        auto physicScene = systems::physic::scene::PhysicScene::instance();

        {
            auto gameObject = std::make_shared<models::GameObject>();
            auto transform = std::make_shared<models::components::Transform>();
            auto camera = std::make_shared<models::components::rendering::Camera>();

            transform->setPosition(math::vec::v3(0.0, 0.0, 5.0));
            camera->setActive(true);
            camera->setClippingPlane(models::components::rendering::Camera::ClippingPlane());
            camera->setFieldOfView(100.0);

            gameObject->setTransform(transform);
            gameObject->setCamera(camera);

            systems::rendering::scene::RenderingScene::instance().add(gameObject);
        }

        {
            auto gameObject = std::make_shared<models::GameObject>();
            auto transform = std::make_shared<models::components::Transform>();
            auto light = std::make_shared<models::components::rendering::Light>();

            transform->setPosition(math::vec::v3(0.0, 0.0, 5.0));
            light->setType(models::components::rendering::Light::Type::DIRECTIONAL);
            light->setColor(Color());

            gameObject->setTransform(transform);
            gameObject->setLight(light);

            systems::rendering::scene::RenderingScene::instance().add(gameObject);
        }

        {
            auto gameObject = std::make_shared<models::GameObject>();
            auto meshFilter = std::make_shared<models::components::mesh::MeshFilter>();
            auto transform = std::make_shared<models::components::Transform>();
            auto rigidBody = std::make_shared<models::components::physic::RigidBody>();
            auto sphereCollider = std::make_shared<models::components::physic::SphereCollider>();

            meshFilter->setFile(
                    std::make_shared<files::File>(
                            "/home/wlad031/Documents/projects/game-engine/cube/cube.obj"
                    ));
            rigidBody->setMass(100);
            sphereCollider->setRadius(1);
            transform->setPosition(math::vec::v3(0.0, 3.0, 0.0));

            gameObject->setMeshFilter(meshFilter);
            gameObject->setTransform(transform);
            gameObject->setRigidBody(rigidBody);
            gameObject->setSphereColliders({sphereCollider});

            systems::rendering::scene::RenderingScene::instance().add(gameObject);
            systems::physic::scene::PhysicScene::instance().add(gameObject);
        }

        {
            auto gameObject = std::make_shared<models::GameObject>();
            auto transform  = std::make_shared<models::components::Transform>();
            auto boxCollider = std::make_shared<models::components::physic::BoxCollider>();
            auto rigidBody  = std::make_shared<models::components::physic::RigidBody>();

            rigidBody->setMass(0.01);
            boxCollider->setSize(math::vec::v3(5.0));

            gameObject->setTransform(transform);
            gameObject->setBoxColliders({boxCollider});
            gameObject->setRigidBody(rigidBody);
        }

        bool exited = false;
        auto thread2 = std::thread([&]() {
            auto manager = standalone::GlfwWindowManager::instance();
            manager.init();
            manager.window();
            glbinding::Binding::useCurrentContext();
            manager.loop(
                    [&]() {},
                    systems::rendering::RenderSystem::instance().getTask()
            );
            exited = true;
        });

        auto thread3 = std::thread([&]() {
            auto task = systems::physic::PhysicSystem::instance().getTask();
            while (!exited) task();
        });

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

    el::Configurations conf(std::string(PROJECT_DIRECTORY) + "logging.conf");
    el::Loggers::getLogger("Physic");
    el::Loggers::getLogger("OpenGL");
//    el::Loggers::reconfigureLogger("default", conf);
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    el::Loggers::reconfigureAllLoggers(conf);

    auto engineRunner = std::make_unique<TestRunner>();

    try {
        engineRunner->run();
    } catch (Exception& e) {
        LOG(ERROR) << e.what();
        return 1;
    }
}
#pragma clang diagnostic pop