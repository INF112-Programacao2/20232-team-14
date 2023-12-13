#include "deLoreanException.h"

deLoreanException::deLoreanException(const std::string &arg) : runtime_error(arg) {

}

const char *deLoreanException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return "A data informada não pode ser posterior à data atual!";
}