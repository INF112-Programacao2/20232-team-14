#ifndef INC_20232_TEAM_14_CLI_H
#define INC_20232_TEAM_14_CLI_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <regex>

namespace view {

    class Cli {


    public:

        //construtor da Cli
        Cli();

        int mainMenu();

        //funcao que exibe as funcionalidades
        void errorMsg(const std::exception& e);

        //leitura e impressao de dados
        void coletaChecklist(std::unordered_map<std::string, std::string> &dados_veiculo);
        void coletaChecklistCarro(std::unordered_map<std::string, std::string> &dados_carro);
        void coletaChecklistCaminhao(std::unordered_map<std::string, std::string> &dados_caminhao);
        void coletaChecklistMoto(std::unordered_map<std::string, std::string> &dados_moto);
        void printChecklist(std::unordered_map<std::string, std::string> &dados_veiculo);
        void printChecklistCarro(std::unordered_map<std::string, std::string> &dados_carro);
        void printChecklistCaminhao(std::unordered_map<std::string, std::string> &dados_caminhao);
        void printChecklistMoto(std::unordered_map<std::string, std::string> &dados_moto);
        //sobrecarga de funcoes de leitura e impressao de dados
        void leituraCampo(const std::string &label, std::string &field);
        void leituraCampo(const std::string &label, std::string &field, const std::string &check, const std::string &errorMsg);

        //retorna id do veiculo
        std::string getIdVehicle();

        //imprime valor do orcamento
        void printOrcamento(double valor);

        //leitura de OS e placa
        std::string readOS();
        std::string readPlate();

        //informa que a OS fornecida ja foi previamente cadastrada
        std::string osAlreadyExistsError();

        //informa que a OS fornecida nao foi encontrada pela busca
        void osNotFound();

        //informa que um veiculo ja foi liberado
        void veiculoJaLiberadoError();

        //informa que nao ha nenhum veiculo cadastrado
        void vectorVazioError();

        //informa a data de liberacao de um veiculo
        std::string getDataLiberacao();

        //informa que a OS fornecida nao foi cadastrada
        void veiculoNaoExiste();
    };

} // View

#endif //INC_20232_TEAM_14_CLI_H
