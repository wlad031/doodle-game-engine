#ifndef DOODLEGAMEENGINE_STANDALONE_GLFWWINDOWMANAGER_H
#define DOODLEGAMEENGINE_STANDALONE_GLFWWINDOWMANAGER_H

#include <GLFW/glfw3.h>

#include <boost/format.hpp>

#include "common/Logger.hpp"
#include "common/exceptions/Exception.hpp"

namespace standalone {

class GlfwWindowManager {
public:
    static GlfwWindowManager& instance() {
        static GlfwWindowManager _instance;
        return _instance;
    }

    ~GlfwWindowManager();

    void init();
    void window();
    void loop(
            std::function<void()> initialFunction,
            std::function<void()> loopFunction
    );

    void setKeyboardCallback(
            std::function<void(int, int, int, int)> function
    );
    void setCursorPositionCallback(
            std::function<void(double, double)> function
    );
    void setReshapeCallback(
            std::function<void(int, int)> function
    );

private:
    GlfwWindowManager();

    GLFWmonitor* _monitorId;
    GLFWvidmode* _videoMode;
    GLFWwindow * _windowId;

    struct GlfwVersion {
        int major, minor, rev;
    } _version;
};

///// ============================================================ GlfwException
class GlfwException : public Exception {
public:

    ///// --------------------------------------------------------- constructors
    explicit GlfwException(int code) : _code(code) {}

    ///// ----------------------------------------------------------------- what
    const char* what() const throw() override {
        std::string s = "GLFW error; code =  " + _code;
        return s.c_str();
    }

private:
    int _code;
};

} // namespace standalone

#endif //DOODLEGAMEENGINE_STANDALONE_GLFWWINDOWMANAGER_H
