#ifndef DOODLEGAMEENGINE_EDITOR_EDITORRUNNER_H
#define DOODLEGAMEENGINE_EDITOR_EDITORRUNNER_H

#include "common/Logger.hpp"
#include "common/Runnable.hpp"

namespace editor {
    class EditorRunner : public Runnable {
    public:
        virtual void run() override;
    };
}

#endif //DOODLEGAMEENGINE_EDITOR_EDITORRUNNER_H
