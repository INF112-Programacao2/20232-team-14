#ifndef INC_20232_TEAM_14_CARRO_H
#define INC_20232_TEAM_14_CARRO_H

#include "Veiculo.h"

namespace model {

    class Carro  : Veiculo{
        int _pHora, _horas;

    public:
        Carro();

        Carro(int pHora, int horas);

        int calculaPreco();

        int getPHora() const;

        void setPHora(int pHora);

        int getHoras() const;

        void setHoras(int horas);
    };

} // model

#endif //INC_20232_TEAM_14_CARRO_H
