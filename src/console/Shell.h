#ifndef DOODLEGAMEENGINE_CONSOLE_SHELL_H
#define DOODLEGAMEENGINE_CONSOLE_SHELL_H

#include <string>
#include <functional>
#include <map>
#include <thread>
#include <string>
#include <easylogging++.h>

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

#include "NCurses.h"
#include "Window.h"

namespace console {
    class Shell {
    public:

        static const unsigned short COMMANDS_OUTPUT_HEIGHT = 5;

        Shell();
        virtual ~Shell();

        Shell& command(
                const std::string& name,
                const std::function<void(std::vector<std::string> input, std::ostream& out)>& action
        );

    private:

        NCurses _curses;
        Window  _inputCommandsWindow;
        Window  _outputCommandsWindow;
        Window  _outputLogsWindow;

        std::thread _inputCommandsThread;

        std::map<std::string, std::function<void(std::vector<std::string> input, std::ostream& out)>> _commands;

    };
}

#endif //DOODLEGAMEENGINE_CONSOLE_SHELL_H
