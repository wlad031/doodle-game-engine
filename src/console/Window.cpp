#include "Window.h"

namespace console {
    Window::Window(int nlines, int ncols, int begin_y, int begin_x, std::ostream& ostream) {
        _ptr       = newwin(nlines, ncols, begin_y, begin_x);
        _outStream = new ncurses_stream(ostream, _ptr);
    }

    Window::Window(int nlines, int ncols, int begin_y, int begin_x) :
            Window(nlines, ncols, begin_y, begin_x, std::cout) {
    }

    Window::~Window() {
        delwin(_ptr);
    }

    void Window::setOption(Window::Option option, bool on) {
        switch (option) {
            case Option::SCROLL_OK:
                scrollok(_ptr, on);
                break;
        }
    }

    void Window::output(const std::string& line) {
        *_outStream << line << "\n";
    }

    void Window::input(std::string& buffer) {
        char ch;
        waddch(_ptr, '>');
        waddch(_ptr, ' ');

        while (true) {
            ch = wgetch(_ptr);

            if (ch == '\n') {
                if (!buffer.empty()) {
                    for (auto i = 0; i < buffer.size(); ++i) backspace();
                    waddch(_ptr, '\n');
                    waddch(_ptr, '\r');
                    break;
                }
            } else if (ch == 127) {
                if (!buffer.empty()) {
                    buffer.pop_back();
                    backspace();
                }
            } else {
                waddch(_ptr, ch);
                buffer.push_back(ch);
            }
        }
    }

    void Window::backspace() {
        waddch(_ptr, '\b');
        waddch(_ptr, ' ');
        int y, x;
        getyx (_ptr, y, x);
        wmove(_ptr, y, x - 1);
    }

    std::ostream* Window::outStream() const {
        return _outStream;
    }
}
