#ifndef DOODLEGAMEENGINE_COMMON_TAGGED_HPP
#define DOODLEGAMEENGINE_COMMON_TAGGED_HPP

#include "Tag.hpp"

////////////////////////////////////////////////////////////////////////////////
/////                   Abstract class for tagged objects                  /////
////////////////////////////////////////////////////////////////////////////////
class Tagged {
public:

    ///// -------------------------------------------------------------- getters
    const Tag& getTag() const { return _tag; }

    ///// -------------------------------------------------------------- setters
    void setTag(const Tag& tag) { _tag = tag; }

private:
    Tag _tag;
};

#endif //DOODLEGAMEENGINE_COMMON_TAGGED_HPP
