#include "GlfwWindowManager.h"

namespace standalone {

GlfwWindowManager::GlfwWindowManager() :
        _monitorId(), _videoMode(), _windowId() {
}

GlfwWindowManager::~GlfwWindowManager() {
    glfwTerminate();
}

void GlfwWindowManager::init() {
    int glfwInitCode = glfwInit();

    glfwSetErrorCallback([](int code, const char* msg) {
        LOG(ERROR) << "GLFW error: code = " << code << "; " << msg;
    });

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (glfwInitCode != 1) throw GlfwException(glfwInitCode);

    glfwGetVersion(&_version.major, &_version.minor, &_version.rev);
    LOG(INFO) << boost::format("GLFW version: %1%.%2%.%3%")
                 % _version.major % _version.minor % _version.rev;
}

void GlfwWindowManager::window() {
    _monitorId = glfwGetPrimaryMonitor();
    _videoMode = _monitorId != nullptr
                 ? (GLFWvidmode*)(glfwGetVideoMode(_monitorId))
                 : nullptr;
    _windowId  = glfwCreateWindow(300, 300, "title", nullptr, nullptr);
    glfwMakeContextCurrent(_windowId);
}

void GlfwWindowManager::loop(
        std::function<void()> initialFunction,
        std::function<void()> loopFunction
) {
    initialFunction();

    while (glfwWindowShouldClose(_windowId) == 0) {
        glfwPollEvents();
        loopFunction();
        glfwSwapBuffers(_windowId);
    }
}

void GlfwWindowManager::setKeyboardCallback(
        std::function<void(int, int, int, int)> function
) {
    // TODO: implement
//        glfwSetKeyCallback(
//                _windowId, [&function](GLFWwindow* w, int key, int scanCode, int action, int mods) {
//                    function(key, scanCode, action, mods);
//                }
//        );
}

void GlfwWindowManager::setCursorPositionCallback(
        std::function<void(
                double,
                double
        )> function
) {
    // TODO: implement
//        glfwSetInputMode(_windowId, GLFW_CURSOR, GLFW_CURSOR_HIDDEN); // TODO: will be changed
//        glfwSetCursorPosCallback(
//                _windowId, [&function](GLFWwindow* w, double xPosition, double yPosition) {
//                    function(xPosition, yPosition);
//                }
//        );
}

void GlfwWindowManager::setReshapeCallback(
        std::function<void(int, int)> function
) {
    // TODO: implement
//        glfwSetWindowSizeCallback(
//                _windowId, [&function](GLFWwindow* w, int width, int height) {
//                    function(width, height);
//                }
//        );
}

} // namespace standalone
