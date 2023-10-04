#include "Carro.h"

namespace model {
    Carro::Carro() {
        pHora = 3;
        horas = 23;
    }

    Carro::Carro(int pHora, int horas) {
        this->pHora = pHora;
        this->horas = horas;
    }

    int Carro::calculaPreco() {
        return this->horas*this->pHora;
    }

    int Carro::getPHora() const {
        return pHora;
    }

    void Carro::setPHora(int pHora) {
        Carro::pHora = pHora;
    }

    int Carro::getHoras() const {
        return horas;
    }

    void Carro::setHoras(int horas) {
        Carro::horas = horas;
    }
} // model