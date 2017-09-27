#include "StandaloneEngineRunner.h"

namespace standalone {

    void StandaloneEngineRunner::run() {

        auto go = model::GameObject();
        go.transform(model::component::Transform(V3{1.0, 2.0, 3.1}, V3{5, 1, 2}, V3{10}));

        auto s = serialize::JsonSerializer::serialize(go);
        LOG(INFO) << s;

        auto go1 = serialize::JsonSerializer::deserialize<model::GameObject>(s);
        LOG(INFO) << serialize::JsonSerializer::serialize(go1);

        auto manager = GlfwWindowManager::instance();
        manager.init();
        manager.window();
//        manager.loop();
    }
}
