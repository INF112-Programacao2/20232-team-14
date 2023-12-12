#ifndef INC_20232_TEAM_14_ABORTFUNCTIONEXCEPTION_H
#define INC_20232_TEAM_14_ABORTFUNCTIONEXCEPTION_H


#include <string>
#include <stdexcept>

class abortFunctionException : public std::runtime_error{
public:
    explicit abortFunctionException(const std::string &arg);
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};


#endif //INC_20232_TEAM_14_ABORTFUNCTIONEXCEPTION_H
