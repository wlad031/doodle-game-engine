#include <easylogging++.h>

#include "standalone/StandaloneEngineRunner.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, const char** argv) {
    START_EASYLOGGINGPP(argc, argv);

    auto engineRunner = std::make_unique<standalone::StandaloneEngineRunner>();
    engineRunner->run();
}