#ifndef INC_20232_TEAM_14_CONTROLLER_H
#define INC_20232_TEAM_14_CONTROLLER_H

#include <vector>

namespace controller {

    class Controller {

    public:

        Controller();

        void startProgram();
        void iniciarApreensao();
        void editarChecklist();
        void realizarOrcamento();
        void liberarVeiculo();
        void consultarVeiculo();
        bool stob(const std::string &str);
        void criarCarro(std::vector<std::string> &dados_veiculo);
        void criarCaminhao(std::vector<std::string> &sdados_veiculo);
        void criarMoto(std::vector<std::string> &dados_veiculo);
    };

}

#endif //INC_20232_TEAM_14_CONTROLLER_H
