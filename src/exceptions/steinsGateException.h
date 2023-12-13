//
// Nome em referencia a um anime sobre viagem no tempo :D
// Exceção serve para lidar com o caso de uma data de liberação ser anterior à data de apreensão

#ifndef INC_20232_TEAM_14_STEINSGATEEXCEPTION_H
#define INC_20232_TEAM_14_STEINSGATEEXCEPTION_H


#include <stdexcept>

class steinsGateException : public std::runtime_error{
public:
    explicit steinsGateException(const std::string &arg);
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};


#endif //INC_20232_TEAM_14_STEINSGATEEXCEPTION_H
