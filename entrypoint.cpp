#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

int main(int argc, const char** argv) {
    START_EASYLOGGINGPP(argc, argv);

    LOG(INFO) << "Hello, world!" << std::endl;
}