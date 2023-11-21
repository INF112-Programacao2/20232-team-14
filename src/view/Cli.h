#ifndef INC_20232_TEAM_14_CLI_H
#define INC_20232_TEAM_14_CLI_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <regex>

namespace view {

    class Cli {


    public:

        Cli();

        int mainMenu();

        std::string readUserInput();

        void displayOutput(const std::string& output);

        void errorMsg(const std::exception& e);

        void coletaChecklist(std::unordered_map<std::string, std::string> &dados_veiculo);
        void coletaChecklistCarro(std::unordered_map<std::string, std::string> &dados_carro);
        void coletaChecklistCaminhao(std::unordered_map<std::string, std::string> &dados_caminhao);
        void coletaChecklistMoto(std::unordered_map<std::string, std::string> &dados_moto);

        void leituraCampo(const std::string &label, std::string &field);
        void leituraCampo(const std::string &label, std::string &field, const std::string &check, const std::string &errorMsg);
    };

} // View

#endif //INC_20232_TEAM_14_CLI_H
