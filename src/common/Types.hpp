#ifndef DOODLEGAMEENGINE_TYPES_H
#define DOODLEGAMEENGINE_TYPES_H

#include <string>
#include <functional>

#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <glm/glm.hpp>

#include <json_dto/pub.hpp>

// Namespace aliases
namespace json = json_dto;

// Type aliases
typedef std::string Name;

// Boost namespaces
namespace boost {
    namespace fs { using namespace boost::filesystem; }
}

#endif //DOODLEGAMEENGINE_TYPES_H
