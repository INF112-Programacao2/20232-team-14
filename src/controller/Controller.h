#ifndef INC_20232_TEAM_14_CONTROLLER_H
#define INC_20232_TEAM_14_CONTROLLER_H

#include <vector>
#include <unordered_map>
#include "model/Veiculo.h"

namespace controller {

    class Controller {

    private:

        std::vector<model::Veiculo *> *_veiculos; //Cria um vector para armazenar os dados de cada veiculo
        int _id_patio;

    public:

        Controller();

        virtual ~Controller();

        void startProgram(); //inicia o programa
        void iniciarApreensao(); //inicia a apreensao pegando os dados iniciais, como o tipo do veiculo
        void editarChecklist();  //permite editar o checklist de cada veiculo
        void realizarOrcamento(const int &OS); //realiza o orcamento para retirada do veiculo
        void liberarVeiculo(); //libera o veiculo
        void consultarVeiculo(); //consulta os dados de um veiculo
        bool stob(const std::string &str); //retorna um valor em bool
        void criarCarro(std::unordered_map<std::string, std::string> &dados_veiculo);
        void criarCaminhao(std::unordered_map<std::string, std::string> &dados_veiculo);
        void criarMoto(std::unordered_map<std::string, std::string> &dados_veiculo);

        void deleteAll(); //deleta os dados de veiculo

        void printAll(); //imprime os dados de veiculo

        model::Veiculo* searchByOS(const int &OS); //procura um veiculo pela OS

        void searchByPlate(const std::string &plate); //procura um veiculo pela placa

        void printVeiculo(model::Veiculo *v); //imprime os dados de um veiculo

        bool verificaData(const std::string &data); //verifica se a data é válida
    };

}

#endif //INC_20232_TEAM_14_CONTROLLER_H
