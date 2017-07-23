#include "EngineRunner.h"

void EngineRunner::run() {

    using namespace math;
    
    auto transform =
            model::component::Transform({1.0, 2.0, 3.0}, {1, 2, 3}, {10});

    auto s = serialize::JsonSerializer::serialize(transform);
    LOG(INFO) << s;

    auto a1 = serialize::JsonSerializer::deserialize<model::component::Transform>(s);

    LOG(INFO) << "Hello, world!";
}