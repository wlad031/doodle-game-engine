#include "EngineRunner.h"

void EngineRunner::run() {

    auto go = model::GameObject();
    auto transform =
            model::component::Transform(V3{1.0, 2.0, 3.0}, V3{5, 1, 2}, V3{10});
    go.getComponents().transforms.push_back(transform);

    auto s = serialize::JsonSerializer::serialize(go, true);
    LOG(INFO) << s;

    auto a1 = serialize::JsonSerializer::deserialize<model::component::Transform>(s);

    LOG(INFO) << "Hello, world!";
}