#include <stdexcept>
#include <unordered_map>
#include "Controller.h"
#include "model/Carro.h"
#include "view/Cli.h"
#include "model/SqliteHook.h"
#include "model/Moto.h"
#include "model/Caminhao.h"

namespace controller {

    Controller::Controller() = default;

    view::Cli interface;

    void Controller::startProgram() {
        bool loop = true;
        bool erro = false; //responsavel por solicitar novamente entradas consideradas invalidas
        _veiculos = nullptr;


        while(loop){

            switch(interface.mainMenu()) {

                case 0:
                    loop = false;
                    break;
                case 1:
                    //teria aqui uma instanciação de c
                    iniciarApreensao();
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
                    std::string sql;
                    sql = "CREATE TABLE IF NOT EXISTS patios("  \
                        "ID             INT PRIMARY KEY NOT NULL," \
                        "NAME           TEXT    NOT NULL," \
                        "CAPACITY       INT     NOT NULL," \
                        "ADDRESS        CHAR(50)," \
                        "PROPRIETARY    CHAR(50)," \
                        "CONTACT        CHAR(12)," \
                        "DAILY_FEE      REAL);"; \
                        /*"CREATE TABLE IF NOT EXISTS veiculos("  \
                        "ID             INT PRIMARY KEY NOT NULL," \
                        "ID_PATIO             INT NOT NULL," \ // FOREIGN KEY
                        "PLATE          TEXT    NOT NULL," \
                        "DOORS          INT     NOT NULL," \
                        "MAKE           CHAR(50)," \
                        "MODEL          CHAR(50)," \
                        "YEAR           INT," \
                        "VIN            REAL);";  // numero do chassi
                        */
                    model::SqliteHook::connectDB();
                    model::SqliteHook::initDB(sql);
                    model::SqliteHook::closeDB();
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

    void Controller::criarCarro(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::unordered_map<std::string, std::string> dados_carro;
        interface.coletaChecklistCarro(dados_carro);
        int os = stoi(dados_veiculo["OS"]);
        model::Veiculo *car = new model::Carro(os, dados_veiculo["Solicitacao"], dados_veiculo["Funcionario"], dados_veiculo["PlacaReboque"], dados_veiculo["Motivo"],
                                               stoi(dados_veiculo["Estado"]), stob(dados_veiculo["Blitz"]), dados_veiculo["Local"], dados_veiculo["Placa"], dados_veiculo["Marca"],
                                               dados_veiculo["Modelo"], stoi(dados_veiculo["Ano"]), dados_veiculo["Cidade"], dados_veiculo["Chassi"], stoi(dados_veiculo["Distancia"]),
                                               stoi(dados_veiculo["KM"]), dados_veiculo["Ocorrencia"], dados_veiculo["Policial"], dados_veiculo["Data"], dados_veiculo["Horario"],
                                               dados_veiculo["Objetos"], dados_veiculo["Obs"], stoi(dados_veiculo["EstadoRodas"]), stoi(dados_veiculo["EstadoRetro"]),
                                               stob(dados_carro["Extintor"]), stob(dados_carro["Estepe"]), stob(dados_carro["Macaco"]), stob(dados_carro["ChaveRoda"]),
                                               stob(dados_carro["Triangulo"]), stob(dados_carro["Bateria"]), stob(dados_carro["Calotas"]), stob(dados_carro["Tapetes"]), stob(dados_carro["Radio"]),
                                               stoi(dados_carro["EstadoPortas"]), stoi(dados_carro["EstadoCapo"]), stoi(dados_carro["EstadoPainel"]),stoi(dados_carro["EstadoTeto"]));
        //aaaaaaa
    }

    void Controller::criarCaminhao(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::unordered_map<std::string, std::string> dados_caminhao;
        interface.coletaChecklistCaminhao(dados_caminhao);
        model::Veiculo *truck = new model::Caminhao(stoi(dados_veiculo["OS"]), dados_veiculo["Solicitacao"], dados_veiculo["Funcionario"], dados_veiculo["PlacaReboque"], dados_veiculo["Motivo"],
                                                    stoi(dados_veiculo["Estado"]), stob(dados_veiculo["Blitz"]), dados_veiculo["Local"], dados_veiculo["Placa"], dados_veiculo["Marca"],
                                                    dados_veiculo["Modelo"], stoi(dados_veiculo["Ano"]), dados_veiculo["Cidade"], dados_veiculo["Chassi"], stoi(dados_veiculo["Distancia"]),
                                                    stoi(dados_veiculo["KM"]), dados_veiculo["Ocorrencia"], dados_veiculo["Policial"], dados_veiculo["Data"], dados_veiculo["Horario"],
                                                    dados_veiculo["Objetos"], dados_veiculo["Obs"], stoi(dados_veiculo["EstadoRodas"]), stoi(dados_veiculo["EstadoRetro"]),
                                                    stoi(dados_caminhao["EstadoCarroceria"]), stob(dados_caminhao["EixoTras"]), stob(dados_caminhao["Cintas"]),
                                                    stoi(dados_caminhao["SuspensaoC"]), stob(dados_caminhao["Extintor"]), stob(dados_caminhao["Estepe"]),
                                                    stob(dados_caminhao["Macaco"]), stob(dados_caminhao["ChaveRoda"]), stob(dados_caminhao["Triangulo"]),
                                                    stob(dados_caminhao["Bateria"]), stob(dados_caminhao["Calotas"]), stob(dados_caminhao["Tapetes"]), stob(dados_caminhao["Radio"]));
        //*_veiculos[]
    }

    void Controller::criarMoto(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::unordered_map<std::string, std::string> dados_moto;
        interface.coletaChecklistMoto(dados_moto);
        int os = stoi(dados_veiculo["OS"]);
        model::Veiculo *motorcycle = new model::Moto(os, dados_veiculo["Solicitacao"], dados_veiculo["Funcionario"], dados_veiculo["PlacaReboque"], dados_veiculo["Motivo"],
                                                     stoi(dados_veiculo["Estado"]), stob(dados_veiculo["Blitz"]), dados_veiculo["Local"], dados_veiculo["Placa"], dados_veiculo["Marca"],
                                                     dados_veiculo["Modelo"], stoi(dados_veiculo["Ano"]), dados_veiculo["Cidade"], dados_veiculo["Chassi"], stoi(dados_veiculo["Distancia"]),
                                                     stoi(dados_veiculo["KM"]), dados_veiculo["Ocorrencia"], dados_veiculo["Policial"], dados_veiculo["Data"], dados_veiculo["Horario"],
                                                     dados_veiculo["Objetos"], dados_veiculo["Obs"], stoi(dados_veiculo["EstadoRodas"]), stoi(dados_veiculo["EstadoRetro"]),
                                                     stob(dados_moto["Capacete"]), stob(dados_moto["Carenagem"]), stob(dados_moto["Bau"]), stob(dados_moto["Ferramentas"]), stoi(dados_moto["SuspensaoD"]),
                                                     stoi(dados_moto["SuspensaoT"]), stoi(dados_moto["Guidao"]), stoi(dados_moto["SistemaE"]), stoi(dados_moto["Escapamento"]));
        //*_veiculos[os] =
        std::cout << "eh vidinha" << std::endl;
    }

    void Controller::iniciarApreensao() {
        if(_veiculos){ // basicamente, se _veiculos é nullptr, aloca o unordered map e o referencia. se já existe, não faz nada.

        }else{
            _veiculos = new std::unordered_map<int, model::Veiculo *>();
        }
        int tipo;
        std::unordered_map<std::string, std::string> dados_veiculo; //responsavel por receber e encaminhar dados dos novos veiculos registrados
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

    void Controller::persistChecklists(){ //para cada veiculo em _veiculos, chama a funcao de persistencia respectiva (salva as alterações)
        //for (model::Veiculo *v : _veiculos)
    }

    void Controller::editarChecklist() { //busca no bd um veículo pela OS, que retorna um unordered map com os dados - posteriormente, as informações são mostradas e é oferecida a oportunidade de alterá-las

    }

    void Controller::realizarOrcamento() {

    }

    void Controller::liberarVeiculo() { // suponho que venha a ser uma variante da edição

    }

    void Controller::consultarVeiculo() {

    }


} // controller