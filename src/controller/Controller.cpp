#include <stdexcept>
#include "Controller.h"
#include "model/Carro.h"
#include "view/Cli.h"
#include <sqlite3.h>
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
                    initDatabase();
                    break;
            }
        }
    }// startProgram()
    void Controller::initDatabase(){ // essa função NÃO PERTENCE AQUI, está aqui temporariamente pra testes (e tenho que pensar em onde ela deveria ficar de fato)
        //peguei essa implementação de um site, pretendo dissecar posteriormente e analisar pra aprender, mas por agora, podemos comemorar a implementação do BD!
        sqlite3 *db;
        char *errMsg = 0;
        int rc;

        rc = sqlite3_open("../test.db", &db);

        if(rc){
            fprintf(stderr, "Nao pode abrir banco de dados: %s\n", sqlite3_errmsg(db));
        }else{
            fprintf(stderr, "Banco de dados aberto");
        }
        sqlite3_close(db);
    }

} // controller