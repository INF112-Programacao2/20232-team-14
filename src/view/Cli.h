#ifndef INC_20232_TEAM_14_CLI_H
#define INC_20232_TEAM_14_CLI_H

#include <iostream>
#include <vector>
namespace view {

    class Cli {


    public:

        Cli();

        int mainMenu();

        std::string readUserInput();

        void displayOutput(const std::string& output);

        void errorMsg(const std::exception& e);

        int recebeTipo();
        void coletaChecklist(std::vector<std::string> &dados_veiculo);
        void coletaChecklistCarro(std::vector<std::string> &dados_carro);
        void coletaChecklistCaminhao(std::vector<std::string> &dados_caminhao);
        void coletaChecklistMoto(std::vector<std::string> &dados_moto);
    };

} // View

#endif //INC_20232_TEAM_14_CLI_H
