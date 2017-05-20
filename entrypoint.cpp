#include <easylogging++.h>

#include "runner/EngineRunner.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, const char** argv) {
    START_EASYLOGGINGPP(argc, argv);

    auto engineRunner = std::make_unique<EngineRunner>();
    engineRunner->run();
}