#ifndef DOODLEGAMEENGINE_COMMON_FILES_FILE_H
#define DOODLEGAMEENGINE_COMMON_FILES_FILE_H

#include <boost/filesystem/path.hpp>
#include <utility>

#include "common/exceptions/Exception.hpp"

////////////////////////////////////////////////////////////////////////////////
/////             Filesystem types and operations definitions              /////
////////////////////////////////////////////////////////////////////////////////

namespace files {

///// ===================================================================== File
class File {
public:

    ///// --------------------------------------------------------- constructors
    explicit File(const std::string& filePath) : _path(filePath) {}

    ///// -------------------------------------------------------------- getPath
    const std::string& getPath() const { return _path.string(); }

    ///// ----------------------------------------------------------------- read
    std::string read();

    ///// ----------------------------------------------------------- predicates
    bool isExists() const;
    bool isDirectory() const;
    bool isPlainFile() const;

private:
    boost::filesystem::path _path;
};

///// ===================================================== FileLoadingException
class FileLoadingException : public Exception {
public:

    ///// --------------------------------------------------------- constructors
    explicit FileLoadingException(std::shared_ptr<files::File> file) :
            _file(std::move(file)) {}

    ///// ----------------------------------------------------------------- what
    const char* what() const throw() override {
        std::string s = "File " + _file->getPath() + " cannot be loaded";
        return s.c_str();
    }

private:
    std::shared_ptr<files::File> _file;
};

}  // namespace files

#endif //DOODLEGAMEENGINE_COMMON_FILES_FILE_H
