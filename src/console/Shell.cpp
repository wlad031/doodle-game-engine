#include "Shell.h"

namespace console {
    Shell::Shell() :
            _curses(NCurses()),
            _inputCommandsWindow(Window(0, 0, _curses.getYMax() - 1, 0)),
            _outputCommandsWindow(Window(COMMANDS_OUTPUT_HEIGHT, 0,
                                         _curses.getYMax() - 1 - COMMANDS_OUTPUT_HEIGHT, 0)),
            _outputLogsWindow(Window(_curses.getYMax() - COMMANDS_OUTPUT_HEIGHT - 1, 0, 0, 0)) {

        _outputCommandsWindow.setOption(Window::Option::SCROLL_OK);
        _outputLogsWindow.setOption(Window::Option::SCROLL_OK);

        _inputCommandsThread = std::move(
                std::thread(
                        [&]() {
                            std::string buffer;
                            while (true) {
                                _inputCommandsWindow.input(buffer);
                                auto command = buffer.substr(0, buffer.find(" "));

                                std::vector<std::string> details;
                                boost::split(details, buffer, boost::is_any_of(" "));

                                if (_commands[command]) {
                                        _commands[command](details, *_outputCommandsWindow.outStream());
                                } else {
                                    _outputCommandsWindow.output("undefined command : " + buffer);
                                }

                                buffer.clear();
                            }
                        }
                ));
    }

    Shell::~Shell() {
        _inputCommandsThread.join();
    }

    Shell& Shell::command(
            const std::string& name,
            const std::function<void(std::vector<std::string> input, std::ostream& out)>& action
    ) {
        _commands.insert({ name, action });
        return *this;
    }
}
