#ifndef INC_20232_TEAM_14_VEICULO_H
#define INC_20232_TEAM_14_VEICULO_H
#include <string>
#include "Model.h"

namespace model {

    class Veiculo : Model{
        std::string Placa, Tipo;

    public:
        const std::string &getPlaca() const;

        void setPlaca(const std::string &placa);

        const std::string &getTipo() const;

        void setTipo(const std::string &tipo);
    };

} // model

#endif //INC_20232_TEAM_14_VEICULO_H
