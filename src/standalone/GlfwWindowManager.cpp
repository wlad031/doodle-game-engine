#include "GlfwWindowManager.h"

namespace standalone {
    GlfwWindowManager& GlfwWindowManager::instance() {
        static GlfwWindowManager _instance;
        return _instance;
    }

    GlfwWindowManager::GlfwWindowManager() :
            _monitorId(), _videoMode(), _windowId() {
    }

    void GlfwWindowManager::init() {
        int glfwInitCode = glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwGetVersion(&glfwVersion.major, &glfwVersion.minor, &glfwVersion.rev);
        LOG(INFO) << boost::format("GLFW %1%.%2%.%3% initialized")
                     % glfwVersion.major % glfwVersion.minor % glfwVersion.rev;
    }

    void GlfwWindowManager::window() {
        _monitorId = glfwGetPrimaryMonitor();
        _videoMode = _monitorId ? (GLFWvidmode*) glfwGetVideoMode(_monitorId) : nullptr;
        _windowId  = glfwCreateWindow(300, 300, "title", nullptr, nullptr);

        glfwMakeContextCurrent(_windowId);
    }

    void GlfwWindowManager::loop() {
        while (glfwWindowShouldClose(_windowId) == 0) {
            glfwSwapBuffers(_windowId);
            glfwPollEvents();
        }
    }

    void GlfwWindowManager::keyboardCallback(std::function<void(int, int, int, int)> function) {
//        glfwSetKeyCallback(
//                _windowId, [&function](GLFWwindow* w, int key, int scanCode, int action, int mods) {
//                    function(key, scanCode, action, mods);
//                }
//        );
    }

    void GlfwWindowManager::cursorPositionCallback(std::function<void(double, double)> function) {
//        glfwSetInputMode(_windowId, GLFW_CURSOR, GLFW_CURSOR_HIDDEN); // TODO: will be changed
//        glfwSetCursorPosCallback(
//                _windowId, [&function](GLFWwindow* w, double xPosition, double yPosition) {
//                    function(xPosition, yPosition);
//                }
//        );
    }

    void GlfwWindowManager::reshapeCallback(std::function<void(int, int)> function) {
//        glfwSetWindowSizeCallback(
//                _windowId, [&function](GLFWwindow* w, int width, int height) {
//                    function(width, height);
//                }
//        );
    }
}
