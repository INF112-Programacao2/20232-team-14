#include <stdexcept>
#include "Controller.h"
#include "model/Carro.h"
#include "view/Cli.h"
#include "model/Model.h"

namespace controller {

    Controller::Controller() = default;


    void Controller::startProgram() {
        std::vector<std::string> _dados_veiculo //responsavel por receber e encaminhar dados dos novos veiculos registrados
        bool loop = true;
        bool erro = false; //responsavel por solicitar novamente entradas consideradas invalidas
        model::Carro c;
        view::Cli interface;

        while(loop){

            switch(interface.mainMenu()) {

                case 0:
                    loop = false;
                    break;
                case 1:
                    //teria aqui uma instanciação de c
                    interface.displayOutput("Informe a ordem de servico: ");
                    _dados_veiculo[0] = interface.readUserInput();
                    interface.displayOutput("Informe a solicitacao: ");
                    _dados_veiculo[1] = interface.readUserInput();
                    interface.displayOutput("Informe o funcionario responsavel por registrar este veiculo: ");
                    _dados_veiculo[2] = interface.readUserInput();
                    interface.displayOutput("Informe a placa do veiculo que realizou o reboque: ");
                    _dados_veiculo[3] = interface.readUserInput();
                    interface.displayOutput("Informe o motivo da apreensao: ");
                    _dados_veiculo[4] = interface.readUserInput();
                    interface.displayOutput("Informe o estado do veiculo no momento de apreensao, considerando:\n");
                    interface.displayOutput("1 - Ruim\n2 - Regular\n3 - Bom\n");
                    _dados_veiculo[5] = interface.readUserInput();
                    interface.displayOutput("Informe se houve blitz, considerando:\n");
                    interface.displayOutput("**Responda com 1 em caso afirmativo e com 0 em caso negativo**\n");
                    _dados_veiculo[6] = interface.readUserInput();
                    interface.displayOutput("Informe o local de apreensao: ");
                    _dados_veiculo[7] = interface.readUserInput();
                    interface.displayOutput("Informe a placa do veiculo apreendido: ");
                    _dados_veiculo[8] = interface.readUserInput();
                    interface.displayOutput("Informe a marca do veiculo apreendido: ");
                    _dados_veiculo[9] = interface.readUserInput();
                    interface.displayOutput("Informe o modelo do veiculo apreendido: ");
                    _dados_veiculo[10] = interface.readUserInput();
                    interface.displayOutput("Informe o ano de apreensao do veiculo: ");
                    _dados_veiculo[11] = interface.readUserInput();
                    interface.displayOutput("Informe a cidade em que ocorreu a apreensao: ");
                    _dados_veiculo[12] = interface.readUserInput();
                    interface.displayOutput("Informe o chassi do veiculo apreendido: ");
                    _dados_veiculo[13] = interface.readUserInput();
                    interface.displayOutput("Informe a que distancia do patio o veiculo foi apreendido: ");
                    _dados_veiculo[14] = interface.readUserInput();
                    interface.displayOutput("Informe a quilometragem do veiculo no momento de apreensao: ");
                    _dados_veiculo[15] = interface.readUserInput();
                    interface.displayOutput("Informe a ocorrencia registrada: ");
                    _dados_veiculo[16] = interface.readUserInput();
                    interface.displayOutput("Informe o policial responsavel pela apreensao: ");
                    _dados_veiculo[17] = interface.readUserInput();
                    interface.displayOutput("Informe a data de apreensao do veiculo: ");
                    _dados_veiculo[18] = interface.readUserInput();
                    interface.displayOutput("Informe o horario de apreensao: ");
                    _dados_veiculo[19] = interface.readUserInput();
                    interface.displayOutput("Liste os objetos que estavam no carro no momento de apreensao: ");
                    _dados_veiculo[20] = interface.readUserInput();
                    interface.displayOutput("Se desejar, acrescente alguma observacao, caso contrario digite 0 para continuar: ");
                    _dados_veiculo[21] = interface.readUserInput();
                    interface.displayOutput("Informe o estado das rodas do veiculo no momento de apreensao, considerando:\n");
                    interface.displayOutput("0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado\n");
                    _dados_veiculo[22] = interface.readUserInput();
                    interface.displayOutput("Informe o estado dos retrovisoes do veiculo no momento de apreensao, considerando:\n");
                    interface.displayOutput("0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado\n");
                    _dados_veiculo[23] = interface.readUserInput();

                    model::Veiculo v(_dados_veiculo); //chamando funcao que vai armazenar os dados do veiculo
                    _dados_veiculo.clear(); //esvaziando o vetor apos seus dados serem transferidos para o objeto veiculo
                    break;

                case 2:
                    interface.displayOutput("*Digite 0 a qualquer momento caso queira desistir da operacao*\n");
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
                    } while (erro);
                    break;
                case 3:
                    {//bloco pro compilador nao encher o saco (explico depois mas basicamente nao pode declarar variavel dentro do switch sem usar bloco)
                        std::string output = std::to_string(c.calculaPreco()).append("\n"); //esse append por algum motivo ta adiantando de nada :(
                        interface.displayOutput(std::to_string(c.calculaPreco()));
                    }
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
    }// startProgram()

} // controller