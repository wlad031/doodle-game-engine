#ifndef DOODLEGAMEENGINE_COMMON_EXCEPTIONS_EXCEPTION_HPP
#define DOODLEGAMEENGINE_COMMON_EXCEPTIONS_EXCEPTION_HPP

#include <exception>
#include <memory>
#include <string>
#include <utility>

////////////////////////////////////////////////////////////////////////////////
/////                       Common Exception definition                    /////
////////////////////////////////////////////////////////////////////////////////

///// ================================================================ Exception
class Exception : public std::exception {
public:

    ///// --------------------------------------------------------- constructors
    Exception() : Exception("") {}
    explicit Exception(std::string message) :
            _message(std::move(message)) {}

    ///// ----------------------------------------------------------------- what
    const char* what() const throw() override { return _message.c_str(); }

protected:
    std::string _message;
};

#endif //DOODLEGAMEENGINE_COMMON_EXCEPTIONS_EXCEPTION_HPP
