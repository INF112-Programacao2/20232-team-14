

#include "Veiculo.h"

namespace model {


    const std::string &Veiculo::getPlaca() const {
        return Placa;
    }

    void Veiculo::setPlaca(const std::string &placa) {
        Placa = placa;
    }

    const std::string &Veiculo::getTipo() const {
        return Tipo;
    }

    void Veiculo::setTipo(const std::string &tipo) {
        Tipo = tipo;
    }
} // model
