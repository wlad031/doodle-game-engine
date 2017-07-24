#include "EngineRunner.h"

void EngineRunner::run() {

    using namespace math;

    auto transform =
            model::component::Transform(V3{1.0, 2.0, 3.0}, V3{5, 1, 2}, V3{10});

    auto s = serialize::JsonSerializer::serialize(transform, true);
    LOG(INFO) << s;

    auto a1 = serialize::JsonSerializer::deserialize<model::component::Transform>(s);

    LOG(INFO) << "Hello, world!";
}