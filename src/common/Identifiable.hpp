#ifndef DOODLEGAMEENGINE_COMMON_IDENTIFIABLE_HPP
#define DOODLEGAMEENGINE_COMMON_IDENTIFIABLE_HPP

#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

////////////////////////////////////////////////////////////////////////////////
/////               Abstract class for objects that have ID                /////
////////////////////////////////////////////////////////////////////////////////

///// ============================================================ Identifiable
class Identifiable {
public:

    ///// --------------------------------------------------------- constructors
    Identifiable() : _uuid(boost::uuids::random_generator()()) {}

    ///// -------------------------------------------------------------- getters
    const std::string& getId() const { return to_string(_uuid); }

private:
    boost::uuids::uuid _uuid;
};

#endif //DOODLEGAMEENGINE_COMMON_IDENTIFIABLE_HPP
