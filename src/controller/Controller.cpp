#include <stdexcept>
#include <unordered_map>
#include "Controller.h"
#include "model/Carro.h"
#include "view/Cli.h"
#include "model/Moto.h"
#include "model/Caminhao.h"

namespace controller {

    Controller::Controller() = default;

    view::Cli interface;

    void Controller::startProgram() {
        _veiculos = nullptr;
        _id_patio = 1;


        while(true){
            switch(interface.mainMenu()) {

                case 0:
                    return;
                case 1:
                    iniciarApreensao();
                    break;
                case 2:
                    editarChecklist();
                    break;
                case 3:
                    realizarOrcamento(stoi(interface.readOS()));
                    break;
                case 4:
                    liberarVeiculo();
                    break;
                case 5:
                    consultarVeiculo();
                    break;
                case 6:
                    searchByPlate(interface.readPlate());
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

    bool Controller::stob(const std::string &str){

        if(str == "true" || str == "1" || str == "S" || str == "s"){

            return true;

        }else{

            return false;

        }
    }

    void Controller::criarCarro(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::unordered_map<std::string, std::string> dados_carro;
        interface.coletaChecklistCarro(dados_carro);
        model::Veiculo *car = new model::Carro(stoi(dados_veiculo["OS"]), _id_patio,dados_veiculo["Solicitacao"], dados_veiculo["Funcionario"], dados_veiculo["PlacaReboque"], dados_veiculo["Motivo"],
                                               stoi(dados_veiculo["Estado"]), stob(dados_veiculo["Blitz"]), dados_veiculo["Local"], dados_veiculo["Placa"], dados_veiculo["Marca"],
                                               dados_veiculo["Modelo"], stoi(dados_veiculo["Ano"]), dados_veiculo["Cidade"], dados_veiculo["Chassi"], stoi(dados_veiculo["Distancia"]),
                                               stoi(dados_veiculo["KM"]), dados_veiculo["Ocorrencia"], dados_veiculo["Policial"], dados_veiculo["Data"], dados_veiculo["Horario"],
                                               dados_veiculo["Objetos"], dados_veiculo["Obs"], stoi(dados_veiculo["EstadoRodas"]), stoi(dados_veiculo["EstadoRetro"]), stoi(dados_veiculo["Tipo"]),
                                               stob(dados_carro["Extintor"]), stob(dados_carro["Estepe"]), stob(dados_carro["Macaco"]), stob(dados_carro["ChaveRoda"]),
                                               stob(dados_carro["Triangulo"]), stob(dados_carro["Bateria"]), stob(dados_carro["Calotas"]), stob(dados_carro["Tapetes"]), stob(dados_carro["Radio"]),
                                               stoi(dados_carro["EstadoPortas"]), stoi(dados_carro["EstadoCapo"]), stoi(dados_carro["EstadoPainel"]),stoi(dados_carro["EstadoTeto"]));
        _veiculos->push_back(car);
    }

    void Controller::criarCaminhao(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::unordered_map<std::string, std::string> dados_caminhao;
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
        _veiculos->push_back(truck);
    }

    void Controller::criarMoto(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::unordered_map<std::string, std::string> dados_moto;
        interface.coletaChecklistMoto(dados_moto);
        model::Veiculo *motorcycle = new  model::Moto(stoi(dados_veiculo["OS"]), _id_patio,dados_veiculo["Solicitacao"], dados_veiculo["Funcionario"], dados_veiculo["PlacaReboque"], dados_veiculo["Motivo"],
                                                     stoi(dados_veiculo["Estado"]), stob(dados_veiculo["Blitz"]), dados_veiculo["Local"], dados_veiculo["Placa"], dados_veiculo["Marca"],
                                                     dados_veiculo["Modelo"], stoi(dados_veiculo["Ano"]), dados_veiculo["Cidade"], dados_veiculo["Chassi"], stoi(dados_veiculo["Distancia"]),
                                                     stoi(dados_veiculo["KM"]), dados_veiculo["Ocorrencia"], dados_veiculo["Policial"], dados_veiculo["Data"], dados_veiculo["Horario"],
                                                     dados_veiculo["Objetos"], dados_veiculo["Obs"], stoi(dados_veiculo["EstadoRodas"]), stoi(dados_veiculo["EstadoRetro"]), stoi(dados_veiculo["Tipo"]),
                                                     stob(dados_moto["Capacete"]), stob(dados_moto["Carenagem"]), stob(dados_moto["Bau"]), stob(dados_moto["Ferramentas"]), stoi(dados_moto["SuspensaoD"]),
                                                     stoi(dados_moto["SuspensaoT"]), stoi(dados_moto["Guidao"]), stoi(dados_moto["SistemaE"]), stoi(dados_moto["Escapamento"]));
        _veiculos->push_back(motorcycle);
    }

    void Controller::iniciarApreensao() {
        if(!_veiculos) { // basicamente, se _veiculos é nullptr, aloca o unordered map e o referencia. se já existe, não faz nada.
            _veiculos = new std::vector<model::Veiculo *>();
        }
        std::unordered_map<std::string, std::string> dados_veiculo; //responsavel por receber e encaminhar dados dos novos veiculos registrados
        interface.coletaChecklist(dados_veiculo);
        while(true) {
            if (searchByOS(stoi(dados_veiculo["OS"]))) {
                interface.osAlreadyExistsError();
            }else{
                break;
            }
        }
        switch (stoi(dados_veiculo["Tipo"])) {
            case 1:
                criarCarro(dados_veiculo);
                break;
            case 2:
                criarMoto(dados_veiculo);
                break;
            case 3:
                criarCaminhao(dados_veiculo);
                break;
        }
    }

    void Controller::printVeiculo(model::Veiculo *v){
        if(!v){
            interface.veiculoNaoExiste();
            return;
        }
        std::unordered_map<std::string, std::string> dados_veiculo;
        std::unordered_map<std::string, std::string> dados_especificos;
        v->veiculoToMap(dados_veiculo, dados_especificos);  //perguntar caio porque essa funcao é chamada, nao consigo ver a necessidade ainda
        interface.printChecklist(dados_veiculo);
        switch(v->get_tipo()){
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

    void Controller::deleteAll(){ //para cada veiculo em _veiculos, chama a funcao de persistencia respectiva (salva as alterações)
        if (_veiculos) {
            for (model::Veiculo *v: *_veiculos) {
                delete v;
            }
        } else {
            interface.vectorVazioError();
        }
    }

    void Controller::printAll() {
        if(_veiculos) {
            for (model::Veiculo *v: *_veiculos) {
                printVeiculo(v);
            }
        }else{
            interface.vectorVazioError();
        }
    }

    model::Veiculo* Controller::searchByOS(const int &OS){
        if (_veiculos) {
            for (model::Veiculo *v: *_veiculos) {
                if (v->get_os() == OS) {
                    return v;
                }
                return nullptr;
            }
        }else{
            interface.vectorVazioError();
            return nullptr;
        }
    }

    void Controller::searchByPlate(const std::string &plate){
        if (_veiculos) {
            for (model::Veiculo *v: *_veiculos) {
                if (v->get_placa() == plate) {
                    printVeiculo(v);
                }
            }
        } else {
            interface.vectorVazioError();
        }
    }

    void Controller::editarChecklist() {
        int OS = stoi(interface.readOS());
        model::Veiculo* v = searchByOS(OS);
        if(!v){
            interface.osNotFound();
            return;
        }
        std::unordered_map<std::string, std::string> dados_veiculo;
        std::unordered_map<std::string, std::string> dados_especificos;
        v->veiculoToMap(dados_veiculo, dados_especificos);
        interface.coletaChecklist(dados_veiculo);

        switch (stoi(dados_veiculo["Tipo"])) {
            case 1:
                interface.coletaChecklistCarro(dados_veiculo);
                break;
            case 2:
                interface.coletaChecklistMoto(dados_veiculo);
                break;
            case 3:
                interface.coletaChecklistCaminhao(dados_veiculo);
                break;
        }
        v->updateVeiculo(dados_veiculo, dados_especificos);
    }

    void Controller::realizarOrcamento(const int &OS) {
        model::Veiculo* v = searchByOS(OS);
        if(!v){
            interface.veiculoNaoExiste();
            return;
        }
        interface.printOrcamento(v->calcOrcamento(interface.getDataLiberacao()));
    }

    void Controller::liberarVeiculo() { // receber OS da view, verificar se ja esta liberado, se nao estiver libera, se ja estiver mensagem de erro e aborta função
        model::Veiculo* v = searchByOS(stoi(interface.readOS()));
        if(!v){
            interface.veiculoNaoExiste();
            return;
        }
        if(v->get_sit_veiculo()){
            v->set_sit_veiculo(false);
            v->set_data_liberacao(interface.getDataLiberacao());
        }else{
            interface.veiculoJaLiberadoError();
            return;
        }
    }

    void Controller::consultarVeiculo() {
        model::Veiculo* v = searchByOS(stoi(interface.readOS()));
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



} // controller