#include "abortFunctionException.h"


abortFunctionException::abortFunctionException(const std::string &arg) : std::runtime_error(arg) {}

const char *abortFunctionException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return "Funcionalidade abortada.";
}
