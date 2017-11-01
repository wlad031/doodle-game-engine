#ifndef DOODLEGAMEENGINE_STANDALONE_GLFWWINDOWMANAGER_H
#define DOODLEGAMEENGINE_STANDALONE_GLFWWINDOWMANAGER_H

#include <GLFW/glfw3.h>

#include <boost/format.hpp>

#include "common/Logger.hpp"

namespace standalone {
    class GlfwWindowManager {
    public:
        static GlfwWindowManager& instance();

        struct GlfwVersion {
            int major, minor, rev;
        } glfwVersion;

        void init();
        void window();
        void loop();

        void keyboardCallback(std::function<void(int, int, int, int)> function);
        void cursorPositionCallback(std::function<void(double, double)> function);
        void reshapeCallback(std::function<void(int, int)> function);

    private:
        GlfwWindowManager();

        GLFWmonitor* _monitorId;
        GLFWvidmode* _videoMode;
        GLFWwindow * _windowId;
    };
}

#endif //DOODLEGAMEENGINE_STANDALONE_GLFWWINDOWMANAGER_H
