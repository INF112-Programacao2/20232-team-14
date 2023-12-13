#include <stdexcept>
#include <unordered_map>
#include "Controller.h"
#include "model/Carro.h"
#include "view/Cli.h"
#include "model/Moto.h"
#include "model/Caminhao.h"
#include "exceptions/abortFunctionException.h"
#include <iostream>
#include <sstream>
#include <chrono>
#include "exceptions/deLoreanException.h"
#include <iomanip>

namespace controller {

    Controller::Controller() = default;

    view::Cli interface;

    void Controller::startProgram() {
        _veiculos = nullptr;
        _id_patio = 1;


        while(true){
            switch(interface.mainMenu()) {
                //ilustra os casos que o usuario pode escolher
                case 0:
                    return;
                case 1:
                    iniciarApreensao();
                    break;
                case 2:
                    editarChecklist();
                    break;
                case 3:
                    try {
                        realizarOrcamento(stoi(interface.readOS()));
                    } catch (abortFunctionException &e) {
                        interface.errorMsg(e);
                        return;
                    }
                    break;
                case 4:
                    liberarVeiculo();
                    break;
                case 5:
                    consultarVeiculo();
                    break;
                case 6:
                    try {
                        searchByPlate(interface.readPlate());
                    } catch (abortFunctionException &e) {
                        interface.errorMsg(e);
                        return;
                    }
                    break;
                case 7:
                    printAll();
                    break;
                case 8:
                    deleteAll();
                    break;
            }
        }
    }

    bool Controller::stob(const std::string &str){ //função que recebe um parametro e retorna seu valor em bool (casos afirmativos retornam true e o contrario false)

        if(str == "true" || str == "1" || str == "S" || str == "s"){

            return true;

        }else{

            return false;

        }
    }

    void Controller::criarCarro(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::unordered_map<std::string, std::string> dados_carro;  //a funçao recebe os dados do usuario e cria um objeto da classe Carro a partir de seu construtor
        interface.coletaChecklistCarro(dados_carro);
        model::Veiculo *car = new model::Carro(stoi(dados_veiculo["OS"]), _id_patio,dados_veiculo["Solicitacao"], dados_veiculo["Funcionario"], dados_veiculo["PlacaReboque"], dados_veiculo["Motivo"],
                                               stoi(dados_veiculo["Estado"]), stob(dados_veiculo["Blitz"]), dados_veiculo["Local"], dados_veiculo["Placa"], dados_veiculo["Marca"],
                                               dados_veiculo["Modelo"], stoi(dados_veiculo["Ano"]), dados_veiculo["Cidade"], dados_veiculo["Chassi"], stoi(dados_veiculo["Distancia"]),
                                               stoi(dados_veiculo["KM"]), dados_veiculo["Ocorrencia"], dados_veiculo["Policial"], dados_veiculo["Data"], dados_veiculo["Horario"],
                                               dados_veiculo["Objetos"], dados_veiculo["Obs"], stoi(dados_veiculo["EstadoRodas"]), stoi(dados_veiculo["EstadoRetro"]), stoi(dados_veiculo["Tipo"]),
                                               stob(dados_carro["Extintor"]), stob(dados_carro["Estepe"]), stob(dados_carro["Macaco"]), stob(dados_carro["ChaveRoda"]),
                                               stob(dados_carro["Triangulo"]), stob(dados_carro["Bateria"]), stob(dados_carro["Calotas"]), stob(dados_carro["Tapetes"]), stob(dados_carro["Radio"]),
                                               stoi(dados_carro["EstadoPortas"]), stoi(dados_carro["EstadoCapo"]), stoi(dados_carro["EstadoPainel"]),stoi(dados_carro["EstadoTeto"]));
        _veiculos->push_back(car); //adiciona o novo carro ao vetor de veiculos
    }

    void Controller::criarCaminhao(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::unordered_map<std::string, std::string> dados_caminhao; //a funçao recebe os dados do usuario e cria um objeto da classe Caminhao a partir de seu construtor

        interface.coletaChecklistCaminhao(dados_caminhao);
        model::Veiculo *truck = new model::Caminhao(stoi(dados_veiculo["OS"]), _id_patio,dados_veiculo["Solicitacao"], dados_veiculo["Funcionario"], dados_veiculo["PlacaReboque"], dados_veiculo["Motivo"],
                                                    stoi(dados_veiculo["Estado"]), stob(dados_veiculo["Blitz"]), dados_veiculo["Local"], dados_veiculo["Placa"], dados_veiculo["Marca"],
                                                    dados_veiculo["Modelo"], stoi(dados_veiculo["Ano"]), dados_veiculo["Cidade"], dados_veiculo["Chassi"], stoi(dados_veiculo["Distancia"]),
                                                    stoi(dados_veiculo["KM"]), dados_veiculo["Ocorrencia"], dados_veiculo["Policial"], dados_veiculo["Data"], dados_veiculo["Horario"],
                                                    dados_veiculo["Objetos"], dados_veiculo["Obs"], stoi(dados_veiculo["EstadoRodas"]), stoi(dados_veiculo["EstadoRetro"]), stoi(dados_veiculo["Tipo"]),
                                                    stoi(dados_caminhao["EstadoCarroceria"]), stob(dados_caminhao["EixoTras"]), stob(dados_caminhao["Cintas"]),
                                                    stoi(dados_caminhao["SuspensaoC"]), stob(dados_caminhao["Extintor"]), stob(dados_caminhao["Estepe"]),
                                                    stob(dados_caminhao["Macaco"]), stob(dados_caminhao["ChaveRoda"]), stob(dados_caminhao["Triangulo"]),
                                                    stob(dados_caminhao["Bateria"]), stob(dados_caminhao["Calotas"]), stob(dados_caminhao["Tapetes"]), stob(dados_caminhao["Radio"]));
        _veiculos->push_back(truck); //adiciona o novo caminhao ao vetor de veiculos
    }

    void Controller::criarMoto(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::unordered_map<std::string, std::string> dados_moto; //a funçao recebe os dados do usuario e cria um objeto da classe Moto a partir de seu construtor

        interface.coletaChecklistMoto(dados_moto);
        model::Veiculo *motorcycle = new  model::Moto(stoi(dados_veiculo["OS"]), _id_patio,dados_veiculo["Solicitacao"], dados_veiculo["Funcionario"], dados_veiculo["PlacaReboque"], dados_veiculo["Motivo"],
                                                     stoi(dados_veiculo["Estado"]), stob(dados_veiculo["Blitz"]), dados_veiculo["Local"], dados_veiculo["Placa"], dados_veiculo["Marca"],
                                                     dados_veiculo["Modelo"], stoi(dados_veiculo["Ano"]), dados_veiculo["Cidade"], dados_veiculo["Chassi"], stoi(dados_veiculo["Distancia"]),
                                                     stoi(dados_veiculo["KM"]), dados_veiculo["Ocorrencia"], dados_veiculo["Policial"], dados_veiculo["Data"], dados_veiculo["Horario"],
                                                     dados_veiculo["Objetos"], dados_veiculo["Obs"], stoi(dados_veiculo["EstadoRodas"]), stoi(dados_veiculo["EstadoRetro"]), stoi(dados_veiculo["Tipo"]),
                                                     stob(dados_moto["Capacete"]), stob(dados_moto["Carenagem"]), stob(dados_moto["Bau"]), stob(dados_moto["Ferramentas"]), stoi(dados_moto["SuspensaoD"]),
                                                     stoi(dados_moto["SuspensaoT"]), stoi(dados_moto["Guidao"]), stoi(dados_moto["SistemaE"]), stoi(dados_moto["Escapamento"]));
        _veiculos->push_back(motorcycle); //adiciona a nova moto ao vetor de veiculos
    }

    void Controller::iniciarApreensao() {
        if(!_veiculos) { // basicamente, se _veiculos é nullptr, aloca o unordered map e o referencia. se já existe, não faz nada.
            _veiculos = new std::vector<model::Veiculo *>();
        }
        std::unordered_map<std::string, std::string> dados_veiculo; //responsavel por receber e encaminhar dados dos novos veiculos registrados

        try {
            interface.coletaChecklist(dados_veiculo);
        } catch (abortFunctionException &e) {
            interface.errorMsg(e);
            return;
        }

        while(true) {
            if (searchByOS(stoi(dados_veiculo["OS"]))) {

                try {
                    interface.osAlreadyExistsError(); //informa que a OS já foi cadastrada
                } catch (abortFunctionException &e) {
                    interface.errorMsg(e);
                    return;
                }

            }else{
                break;
            }
        }



        try {
            switch (stoi(dados_veiculo["Tipo"])) {
                case 1: //cada caso encaminha para uma funcao dependendo do tipo do veiculo (carro, moto ou caminhao)
                    criarCarro(dados_veiculo);
                    break;
                case 2:
                    criarMoto(dados_veiculo);
                    break;
                case 3:
                    criarCaminhao(dados_veiculo);
                    break;
            }
        }catch (abortFunctionException &e) {
            interface.errorMsg(e);
            return;
        }
    }

    void Controller::printVeiculo(model::Veiculo *v){
        if(!v){      //verifica se o ponteiro é nulo
            interface.veiculoNaoExiste();  //retorna que o veiculo nao existe
            return;
        }
        std::unordered_map<std::string, std::string> dados_veiculo;
        std::unordered_map<std::string, std::string> dados_especificos;
        v->veiculoToMap(dados_veiculo, dados_especificos);  //chama a funçao veiculoToMap
        interface.printChecklist(dados_veiculo);
        switch(v->get_tipo()){  //obtem o tipo do veiculo para saber qual funcao printChecklist chamar
            case 1:
                interface.printChecklistCarro(dados_especificos);
                break;
            case 2:
                interface.printChecklistMoto(dados_especificos);
                break;
            case 3:
                interface.printChecklistCaminhao(dados_especificos);
                break;
        }
    }

    void Controller::deleteAll(){
        if (_veiculos) {  //verifica se nao é nulo
            for (model::Veiculo *v: *_veiculos) {
                delete v;  //deleta o objeto v
            }
        } else {
            interface.vectorVazioError();
        }
    }

    void Controller::printAll() {
        if(_veiculos) { //verifica se nao é nulo
            for (model::Veiculo *v: *_veiculos) {
                printVeiculo(v); //imprime as informacoes de v
            }
        }else{
            interface.vectorVazioError();
        }
    }

    model::Veiculo* Controller::searchByOS(const int &OS){
        if (_veiculos) { //verifica se nao é nulo
            for (model::Veiculo *v: *_veiculos) {
                if (v->get_os() == OS) {  //verifica a OS
                    return v; //retorna o objeto referente àquela OS
                }
            }
        }else{
            interface.vectorVazioError();
        }
        return nullptr;
    }

    void Controller::searchByPlate(const std::string &plate){
        if (_veiculos) { //verifica se nao é nulo
            for (model::Veiculo *v: *_veiculos) {
                if (v->get_placa() == plate) { //verifica a placa
                    printVeiculo(v);  //imprime as informacoes do veiculo referente às informacoes recebidas
                }
            }
        } else {
            interface.vectorVazioError();
        }
    }

    void Controller::editarChecklist() {
        int OS;
        try {
            OS = stoi(interface.readOS());
        } catch (abortFunctionException &e) {
            interface.errorMsg(e);
            return;
        }
        model::Veiculo* v = searchByOS(OS);
        if(!v){  //verifica se nao é nulo
            interface.osNotFound();
            return;
        }
        std::unordered_map<std::string, std::string> dados_veiculo;  //armazena os dados do veiculo
        std::unordered_map<std::string, std::string> dados_especificos; //armazena os dados especificos de carro,moto ou caminhao
        v->veiculoToMap(dados_veiculo, dados_especificos);

        try {
            interface.coletaChecklist(dados_veiculo);
        } catch (abortFunctionException &e) {
            interface.errorMsg(e);
            return;
        }

        while(true) {
            if (searchByOS(stoi(dados_veiculo["OS"]))) {
                if(OS != stoi(dados_veiculo["OS"])) {
                    try {
                        interface.osAlreadyExistsError(); //informa que a OS já foi cadastrada
                    } catch (abortFunctionException &e) {
                        interface.errorMsg(e);
                        return;
                    }
                }else{
                    break;
                }
            }else{
                break;
            }
        }

        try{
            switch (stoi(dados_veiculo["Tipo"])) {
                case 1: //recebe o tipo e dependendo dele chama a funcao coletaChecklist para carro, moto ou caminhao
                    interface.coletaChecklistCarro(dados_especificos);
                    break;
                case 2:
                    interface.coletaChecklistMoto(dados_especificos);
                    break;
                case 3:
                    interface.coletaChecklistCaminhao(dados_especificos);
                    break;
            }
        } catch (abortFunctionException &e) {
            interface.errorMsg(e);
            return;
        }
        v->updateVeiculo(dados_veiculo, dados_especificos);
    }

    void Controller::realizarOrcamento(const int &OS) {
        model::Veiculo* v = searchByOS(OS); //procura um veiculo pela OS
        if(!v){ //verifica se é nulo
            interface.veiculoNaoExiste();
            return;
        }

        try {
            interface.printOrcamento(v->calcOrcamento(interface.getDataLiberacao())); //realiza o orcamento por meio da funcao calcOrcamento
        } catch (abortFunctionException &e) {
            interface.errorMsg(e);
            return;
        }
    }

    void Controller::liberarVeiculo() { // recebe OS da view, verifica se ja esta liberado, se nao estiver libera, se ja estiver mensagem de erro e aborta função
        model::Veiculo* v;
        try {
            v = searchByOS(stoi(interface.readOS()));
        } catch (abortFunctionException &e) {
            interface.errorMsg(e);
            return;
        }
        if(!v){
            interface.veiculoNaoExiste();
            return;
        }
        if(v->get_sit_veiculo()){
            v->set_sit_veiculo(false);
            try {
                v->set_data_liberacao(interface.getDataLiberacao());
            } catch (abortFunctionException &e) {
                interface.errorMsg(e);
                return;
            }

        }else{
            interface.veiculoJaLiberadoError();
            return;
        }
    }

    void Controller::consultarVeiculo() { //consulta um veiculo atraves da OS e imprime os dados
        model::Veiculo* v;

        try {
            v = searchByOS(stoi(interface.readOS()));
        } catch (abortFunctionException &e) {
            interface.errorMsg(e);
            return;
        }
        printVeiculo(v);
    }


    Controller::~Controller() { //verifica se o vector de veículos possui dados inseridos ou não, se sim varre o mesmo e realiza o delete de cada veículo inserido
        if (_veiculos) {
            for (model::Veiculo *v: *_veiculos) {
                delete (v);
            }
            delete _veiculos;
        }
    }

    bool Controller::verificaData(const std::string &data){
        auto now = std::chrono::system_clock::now();
        time_t current_time = std::chrono::system_clock::to_time_t(now);
        struct tm* current_tm = std::localtime(&current_time);

        std::tm input_tm = {};
        std::istringstream ss(data);
        ss >> std::get_time(&input_tm, "%d/%m/%Y");


        auto current_seconds = std::mktime(current_tm);
        auto input_seconds = std::mktime(&input_tm);

        if (input_seconds > current_seconds) {
           return false;
        } else {
            return true;
        }


}


} // controller