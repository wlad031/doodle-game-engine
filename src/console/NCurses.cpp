#include "NCurses.h"

namespace console {
    NCurses::NCurses() {
        initscr();

        noecho();
        curs_set(0);
        getmaxyx(stdscr, _yMax, _xMax);
    }

    NCurses::~NCurses() {
        if (!isendwin()) {
            endwin();
        }
    }

    int NCurses::getXMax() const { return _xMax; }
    int NCurses::getYMax() const { return _yMax; }

    void NCurses::setXMax(int xMax) { _xMax = xMax; }
    void NCurses::setYMax(int yMax) { _yMax = yMax; }
}
