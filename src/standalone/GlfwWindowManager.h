#ifndef DOODLEGAMEENGINE_GLFWWINDOWMANAGER_H
#define DOODLEGAMEENGINE_GLFWWINDOWMANAGER_H

#include <GLFW/glfw3.h>

#include <boost/format.hpp>

#include "AbstractWindowManager.h"

namespace standalone {
    class GlfwWindowManager : public AbstractWindowManager {
    public:
        static GlfwWindowManager& instance();

        struct GlfwVersion {
            int major, minor, rev;
        } glfwVersion;

        void init() override;
        void window() override;
        void loop() override;

        void keyboardCallback(std::function<void(int, int, int, int)> function) override;
        void cursorPositionCallback(std::function<void(double, double)> function) override;
        void reshapeCallback(std::function<void(int, int)> function) override;

    private:
        GlfwWindowManager();

        GLFWmonitor* _monitorId;
        GLFWvidmode* _videoMode;
        GLFWwindow * _windowId;
    };
}

#endif //DOODLEGAMEENGINE_GLFWWINDOWMANAGER_H
