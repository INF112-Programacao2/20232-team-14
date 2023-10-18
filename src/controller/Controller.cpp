#include <stdexcept>
#include "Controller.h"
#include "model/Carro.h"
#include "view/Cli.h"
#include "model/Model.h"

namespace controller {

    Controller::Controller() = default;


    void Controller::startProgram() {
        bool loop = true;
        model::Carro c;
        view::Cli interface;
        while(loop){

            switch(interface.mainMenu()) {
                case 0:
                    loop = false;
                    break;
                case 1:
                    //teria aqui uma instanciação de c
                    break;
                case 2:
                    try { //try catch pois stoi retorna excecao de invalid_argument
                        c.setHoras(stoi(interface.readUserInput()));
                        c.setPHora(stoi(interface.readUserInput()));
                    } catch (std::exception& e) { //catch chama a interface para exibir a mensagem de erro, no formato exception
                        interface.errorMsg(e);
                    }
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