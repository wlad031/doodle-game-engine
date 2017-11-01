#ifndef DOODLEGAMEENGINE_COMMON_NAMED_HPP
#define DOODLEGAMEENGINE_COMMON_NAMED_HPP

#include "common/types/Aliases.hpp"

// TODO: rewrite comments

////////////////////////////////////////////////////////////////////////////////
/////             Classes implementing 'Named' functionality               /////
////////////////////////////////////////////////////////////////////////////////

///// ==================================================================== Named
class Named {
public:

    ///// --------------------------------------------------------------- getter
    const Name& getName() const {
        return _name;
    }

    ///// --------------------------------------------------------------- setter
    void setName(const Name& name) {
        _name = name;
    }

private:
    Name _name;
};

///// ============================================================ NameGenerator
class NameGenerator {
public:

    ///// --------------------------------------------------------- constructors

    NameGenerator() : NameGenerator(DEFAULT_PREFIX, DEFAULT_SUFFIX) {}

    NameGenerator(const std::string& prefix, const std::string& suffix) :
            _prefix(prefix),
            _suffix(suffix),
            _id(0) {}

    // TODO: implement
    ///// --------------------------------------------------------------- random
    const std::string& random(unsigned short length);

    // TODO: implement
    ///// ---------------------------------------------------------- incremental
    const std::string& incremental();

private:

    ///// ------------------------------------------------------- default values
    unsigned short DEFAULT_RANDOM_NAME_LENGTH = 12;
    std::string DEFAULT_PREFIX = "";
    std::string DEFAULT_SUFFIX = "";

    std::string _prefix;
    std::string _suffix;

    unsigned int _id;
};

#endif //DOODLEGAMEENGINE_COMMON_NAMED_HPP
