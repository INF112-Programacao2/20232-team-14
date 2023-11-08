#include <stdexcept>
#include "Controller.h"
#include "model/Carro.h"
#include "view/Cli.h"
#include "model/Model.h"
#include "model/Moto.h"
#include "model/Caminhao.h"

namespace controller {

    Controller::Controller() = default;

    view::Cli interface;

    void Controller::startProgram() {
        std::vector<model::Veiculo *> _veiculos;

        bool loop = true;
        bool erro = false; //responsavel por solicitar novamente entradas consideradas invalidas


        while(loop){

            switch(interface.mainMenu()) {

                case 0:
                    loop = false;
                    break;
                case 1:
                    //teria aqui uma instanciação de c

                    //_dados_veiculo.clear(); //esvaziando o vetor apos seus dados serem transferidos para o objeto veiculo
                    break;
                case 2:
                    /* interface.displayOutput("*Digite 0 a qualquer momento caso queira desistir da operacao*\n");
                    do {
                    try { //try catch pois stoi retorna excecao de invalid_argument
                        interface.displayOutput("Horario de registro do veiculo: ");
                        c.setHoras(stoi(interface.readUserInput()));
                        if (c.getHoras()==0) {
                            break;
                        }
                        interface.displayOutput("Horario de liberacao do veiculo: ");
                        c.setPHora(stoi(interface.readUserInput()));
                        if (c.getPHora()==0) {
                            break;
                        }
                        erro = false;
                    } catch (std::exception& e) { //catch chama a interface para exibir a mensagem de erro, no formato exception
                        interface.errorMsg(e);
                        erro = true;
                    }
                    } while (erro); */
                    break;
                case 3:
                    break;
                case 4:
                    //teria aqui um delete c
                    break;
                case 5:
                    //abre database
                    model::Model::connectDB();
                    model::Model::initDB();
                    model::Model::closeDB();
                    break;
            }
        }
    }

    bool Controller::stob(const std::string &str){

        if(str == "true" || str == "1"){

            return true;

        }else if(str == "false" || str == "0"){

            return false;

        }

    }

    void Controller::criarCarro(std::vector<std::string> &dados_veiculo) {
        std::vector<std::string> dados_carro;
        interface.coletaChecklistCarro(dados_carro);
        model::Veiculo *car = new model::Carro(dados_veiculo[0], dados_veiculo[1], dados_veiculo[2], dados_veiculo[3], dados_veiculo[4],
                                               stoi(dados_veiculo[5]), stob(dados_veiculo[6]), dados_veiculo[7], dados_veiculo[8], dados_veiculo[9],
                                               dados_veiculo[10], dados_veiculo[11], dados_veiculo[12], dados_veiculo[13], dados_veiculo[14],
                                               dados_veiculo[15], dados_veiculo[16], dados_veiculo[17], dados_veiculo[18], dados_veiculo[19],
                                               dados_veiculo[20], dados_veiculo[21], dados_veiculo[22], dados_veiculo[23],
                                               dados_carro[0], dados_carro[1], dados_carro[2], dados_carro[3],
                                               dados_carro[4], dados_carro[5], dados_carro[6], dados_carro[7],
                                               dados_carro[8], dados_carro[9], dados_carro[10], dados_carro[11],
                                               dados_carro[12]);
    }

    void Controller::criarCaminhao(std::vector<std::string> &dados_veiculo) {
        std::vector<std::string> dados_caminhao;
        interface.coletaChecklistCaminhao(dados_caminhao);
        model::Veiculo *truck = new model::Caminhao(dados_veiculo[0], dados_veiculo[1], dados_veiculo[2], dados_veiculo[3], dados_veiculo[4],
                                                    dados_veiculo[5], dados_veiculo[6], dados_veiculo[7], dados_veiculo[8], dados_veiculo[9],
                                                    dados_veiculo[10], dados_veiculo[11], dados_veiculo[12], dados_veiculo[13], dados_veiculo[14],
                                                    dados_veiculo[15], dados_veiculo[16], dados_veiculo[17], dados_veiculo[18], dados_veiculo[19],
                                                    dados_veiculo[20], dados_veiculo[21], dados_veiculo[22], dados_veiculo[23], dados_caminhao[0],
                                                    dados_caminhao[1], dados_caminhao[2], dados_caminhao[3], dados_caminhao[4], dados_caminhao[5],
                                                    dados_caminhao[6], dados_caminhao[7], dados_caminhao[8], dados_caminhao[9], dados_caminhao[10],
                                                    dados_caminhao[11], dados_caminhao[12]);
    }

    void Controller::criarMoto(std::vector<std::string> &dados_veiculo) {
        std::vector<std::string> dados_moto;
        interface.coletaChecklistMoto(dados_moto);
        model::Veiculo *motorcycle = new model::Moto(dados_veiculo[0], dados_veiculo[1], dados_veiculo[2], dados_veiculo[3], dados_veiculo[4],
                                                     dados_veiculo[5], dados_veiculo[6], dados_veiculo[7], dados_veiculo[8], dados_veiculo[9],
                                                     dados_veiculo[10], dados_veiculo[11], dados_veiculo[12], dados_veiculo[13], dados_veiculo[14],
                                                     dados_veiculo[15], dados_veiculo[16], dados_veiculo[17], dados_veiculo[18], dados_veiculo[19],
                                                     dados_veiculo[20], dados_veiculo[21], dados_veiculo[22], dados_veiculo[23], dados_moto[0], dados_moto[1],
                                                     dados_moto[2], dados_moto[3], dados_moto[4], dados_moto[5], dados_moto[6], dados_moto[7], dados_moto[8]);
    }

    void Controller::iniciarApreensao() {
        int tipo;
        std::vector<std::string> dados_veiculo; //responsavel por receber e encaminhar dados dos novos veiculos registrados
        interface.coletaChecklist(dados_veiculo);
        tipo = interface.recebeTipo();
        switch (tipo) {
            case 1:
                criarMoto(dados_veiculo);
                break;
            case 2:
                criarCarro(dados_veiculo);
                break;
            case 3:
                criarCaminhao(dados_veiculo);
                break;
        }
    }

    void Controller::editarChecklist() {

    }

    void Controller::realizarOrcamento() {

    }

    void Controller::liberarVeiculo() {

    }
// startProgram()



} // controller