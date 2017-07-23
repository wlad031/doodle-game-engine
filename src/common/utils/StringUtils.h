#ifndef DOODLEGAMEENGINE_STRINGUTILS_H
#define DOODLEGAMEENGINE_STRINGUTILS_H

#include <string>
#include <vector>

#include <boost/algorithm/string/join.hpp>

namespace utils {
    namespace string {

        const std::string& mult(
                const std::string& s, unsigned int k,
                const std::string& sep = ","
        );
        const std::string& join(
                const std::vector<std::string>& v,
                const std::string& delimeter = ","
        );
    };
}

#endif //DOODLEGAMEENGINE_STRINGUTILS_H
