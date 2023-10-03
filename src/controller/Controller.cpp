#include "Controller.h"
#include "model/Carro.h"
#include "view/Cli.h"

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
                    c.setHoras(interface.readInt());
                    c.setPHora(interface.readInt());
                    break;
                case 3:
                    interface.displayInt(c.calculaPreco());
                    break;
                case 4:
                    //teria aqui um delete c
                    break;
            }

        }
    }
} // controller