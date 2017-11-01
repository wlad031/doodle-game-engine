#include "File.h"

#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>

namespace files {

using namespace boost::filesystem;

///// --------------------------------------------------------------- predicates
bool File::isExists()    const { return exists(_path);                }
bool File::isDirectory() const { return is_directory(_path);          }
bool File::isPlainFile() const { return isExists() && !isDirectory(); }

///// --------------------------------------------------------------------- read
std::string File::read() {
    // TODO: may be not optimal implementation
    std::ifstream stream(_path.string());
    std::string line;
    std::string res;

    while (std::getline(stream, line)) {
        res += line + "\n";
    }

    stream.close();

    return res;
}

}  // namespace files