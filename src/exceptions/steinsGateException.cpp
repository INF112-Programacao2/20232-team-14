#include "steinsGateException.h"

steinsGateException::steinsGateException(const std::string &arg) : runtime_error(arg) {

}

const char *steinsGateException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return "A data de liberação informada não pode ser anterior à data de apreensão!";
}
