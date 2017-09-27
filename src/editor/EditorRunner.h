#ifndef DOODLEGAMEENGINE_EDITORRUNNER_H
#define DOODLEGAMEENGINE_EDITORRUNNER_H

#include <easylogging++.h>

#include "common/Runnable.hpp"

namespace editor {
    class EditorRunner : public Runnable {
    public:
        void run() override;
    };
}

#endif //DOODLEGAMEENGINE_EDITORRUNNER_H
