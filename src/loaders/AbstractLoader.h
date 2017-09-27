#ifndef DOODLEGAMEENGINE_ABSTRACTLOADER_H
#define DOODLEGAMEENGINE_ABSTRACTLOADER_H

namespace loader {

    template<typename T>
    class AbstractLoader {
        virtual T& load() = 0;
    };
}

#endif //DOODLEGAMEENGINE_ABSTRACTLOADER_H
