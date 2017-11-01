#ifndef DOODLEGAMEENGINE_CONSOLE_NCURSES_H
#define DOODLEGAMEENGINE_CONSOLE_NCURSES_H

#include <ncurses.h>

#include "Window.h"

namespace console {
    class NCurses {
    public:
        NCurses();
        virtual ~NCurses();

        int getXMax() const;
        int getYMax() const;

        void setXMax(int xMax);
        void setYMax(int yMax);

    private:
        int _xMax;
        int _yMax;
    };
}

#endif //DOODLEGAMEENGINE_CONSOLE_NCURSES_H
