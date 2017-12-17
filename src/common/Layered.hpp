#ifndef DOODLEGAMEENGINE_COMMON_LAYERED_HPP
#define DOODLEGAMEENGINE_COMMON_LAYERED_HPP

#include "Layer.hpp"

////////////////////////////////////////////////////////////////////////////////
/////                Abstract class for objects that have layer            /////
////////////////////////////////////////////////////////////////////////////////
class Layered {
public:

    ///// -------------------------------------------------------------- getters
    const Layer& getLayer() const { return _layer; }

    ///// -------------------------------------------------------------- setters
    void setLayer(const Layer& layer) { _layer = layer; }

private:
    Layer _layer;
};

#endif //DOODLEGAMEENGINE_COMMON_LAYERED_HPP
