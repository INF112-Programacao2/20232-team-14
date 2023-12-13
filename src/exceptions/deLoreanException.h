//
// Nome em referencia ao filme de volta pro futuro
// Exceção serve para lidar com uma data posterior ao dia atual

#ifndef INC_20232_TEAM_14_DELOREANEXCEPTION_H
#define INC_20232_TEAM_14_DELOREANEXCEPTION_H


#include <stdexcept>

class deLoreanException : public std::runtime_error{
public:
    explicit deLoreanException(const std::string &arg);
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};


#endif //INC_20232_TEAM_14_DELOREANEXCEPTION_H
