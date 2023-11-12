#ifndef INC_20232_TEAM_14_CONTROLLER_H
#define INC_20232_TEAM_14_CONTROLLER_H

#include <vector>
#include "model/Veiculo.h"

namespace controller {

    class Controller {
    private:
        std::vector<model::Veiculo *> _veiculos;
    public:


        Controller();
        void startProgram();
        void iniciarApreensao();
        void editarChecklist();
        void realizarOrcamento();
        void liberarVeiculo();
        void consultarVeiculo();
        bool stob(const std::string &str);
        void criarCarro(std::unordered_map<std::string, std::string> &dados_veiculo);
        void criarCaminhao(std::unordered_map<std::string, std::string> &sdados_veiculo);
        void criarMoto(std::unordered_map<std::string, std::string> &dados_veiculo);

        void persistChecklists();
    };

}

#endif //INC_20232_TEAM_14_CONTROLLER_H
