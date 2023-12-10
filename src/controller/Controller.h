#ifndef INC_20232_TEAM_14_CONTROLLER_H
#define INC_20232_TEAM_14_CONTROLLER_H

#include <vector>
#include <unordered_map>
#include "model/Veiculo.h"

namespace controller {

    class Controller {
    private:
        std::vector<model::Veiculo *> *_veiculos;
        int _id_patio;

    public:
        Controller();

        virtual ~Controller();

        void startProgram();
        void iniciarApreensao();
        void editarChecklist(const int &OS);
        void realizarOrcamento(const int &OS);
        void liberarVeiculo();
        void consultarVeiculo();
        bool stob(const std::string &str);
        void criarCarro(std::unordered_map<std::string, std::string> &dados_veiculo);
        void criarCaminhao(std::unordered_map<std::string, std::string> &dados_veiculo);
        void criarMoto(std::unordered_map<std::string, std::string> &dados_veiculo);

        void deleteAll();

        void printAll();

        model::Veiculo* searchByOS(const int &OS);

        model::Veiculo* searchByPlate(const std::string &plate);

        void printVeiculo(model::Veiculo *v);

    };

}

#endif //INC_20232_TEAM_14_CONTROLLER_H
