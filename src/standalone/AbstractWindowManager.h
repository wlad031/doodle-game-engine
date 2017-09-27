#ifndef DOODLEGAMEENGINE_ABSTRACTWINDOWMANAGER_H
#define DOODLEGAMEENGINE_ABSTRACTWINDOWMANAGER_H

#include <easylogging++.h>

namespace standalone {

    class AbstractWindowManager {
    public:
        virtual void init() = 0;
        virtual void window() = 0;
        virtual void loop() = 0;

        virtual void keyboardCallback(std::function<void(int, int, int, int)> function) = 0;
        virtual void cursorPositionCallback(std::function<void(double, double)> function) = 0;
        virtual void reshapeCallback(std::function<void(int, int)> function) = 0;
    };
}

#endif //DOODLEGAMEENGINE_ABSTRACTWINDOWMANAGER_H
