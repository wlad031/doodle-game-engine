#ifndef DOODLEGAMEENGINE_CONSOLE_WINDOW_H
#define DOODLEGAMEENGINE_CONSOLE_WINDOW_H

#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <ncurses.h>

namespace console {

    class ncursesbuf : public std::streambuf {
    public:
        ncursesbuf(WINDOW* window) : _window(window) {
        }

        virtual int overflow(int c) {
            wprintw(_window, "%c", c);
            wrefresh(_window);
        }

    private:
        WINDOW* _window;
    };

    class ncurses_stream : public std::ostream {
    public:
        ncursesbuf tbuf_;
        std::ostream& src_;
        std::streambuf* const srcbuf_;

        ncurses_stream(std::ostream& o, WINDOW* window) :
                src_(o), srcbuf_(o.rdbuf()), std::ostream(&tbuf_), tbuf_(ncursesbuf(window)) {
            o.rdbuf(rdbuf());
        }

        ~ncurses_stream() {
            src_.rdbuf(srcbuf_);
        }
    };

    class Window {
    public:

        enum class Option {
            SCROLL_OK
        };

        Window(int nlines, int ncols, int begin_y, int begin_x);
        Window(int nlines, int ncols, int begin_y, int begin_x, std::ostream& ostream);
        virtual ~Window();

        void setOption(Option option, bool on = true);

        void output(const std::string& line);
        void input(std::string& buffer);

        std::ostream* outStream() const;

    private:

        WINDOW        * _ptr;
        ncurses_stream* _outStream;

        void backspace();
        void left();
        void right();
    };
}

#endif //DOODLEGAMEENGINE_CONSOLE_WINDOW_H
