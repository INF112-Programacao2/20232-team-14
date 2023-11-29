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
        _id_patio = 1;
        std::string OS;


        while(loop){

            switch(interface.mainMenu()) {

                case 0:
                    return;
                case 1:
                    iniciarApreensao();
                    break;
                case 2:
                    interface.leituraCampo("Ordem de serviço do veiculo para busca: ",OS);
                    editarChecklist(std::stoi(OS));
                    break;
                case 3:
                    realizarOrcamento(searchByPlate(interface.readPlate()));
                    //persistChecklists();
                    break;
                case 4:
                    liberarVeiculo();
                    break;
                case 5:
                    //teste, limpar implementacao dps
                    printVeiculo(searchByOS(interface.readOS()));
                    break;
                case 6:
                    model::SqliteHook::connectDB();
                    model::SqliteHook::initDB();
                    model::Moto *m = new model::Moto(123);
                    m->recordToVeiculo();
                    printVeiculo(m);
                    model::SqliteHook::closeDB();
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
        std::unordered_map<std::string, std::string> dados_veiculo;
        std::unordered_map<std::string, std::string> dados_especificos;
        v->veiculoToMap(dados_veiculo, dados_especificos);
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
    void Controller::persistChecklists(){ //para cada veiculo em _veiculos, chama a funcao de persistencia respectiva (salva as alterações)
        for (model::Veiculo *v : *_veiculos){
            v->persistVeiculo();
            delete v;
        }
    }

    model::Veiculo* Controller::searchByOS(const int &OS){
        for(model::Veiculo *v : *_veiculos){
            if(v->get_os() == OS){
                return v;
            }
        }
    }

    model::Veiculo* Controller::searchByPlate(const std::string &plate){
        for(model::Veiculo *v : *_veiculos){
            if(v->get_placa() == plate){
                return v;
            }
        }
    }

     //busca no vetor um veículo pela OS, posteriormente, as informações são mostradas e é oferecida a oportunidade de alterá-las
//        //pede a interface para ler uma OS
//        //recebe esse inteiro
    void Controller::editarChecklist(const int &OS) {
            std::unordered_map<std::string, std::string> dados_veiculo;
            std::unordered_map<std::string, std::string> dados_especificos;

            model::Veiculo* v = searchByOS(OS);
            v->veiculoToMap(dados_veiculo, dados_especificos);

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

        }

    void Controller::realizarOrcamento(model::Veiculo *pVeiculo) {

        interface.displayOutput(std::to_string(pVeiculo->calcOrcamento(interface.supostaDataLiberacao()))); //TODO: formatar o valor de saída para RR.CC (real e centavos)
        interface.displayOutput(" R$");

    }

    void Controller::liberarVeiculo() { // receber OS da view, verificar se ja esta liberado, se nao estiver libera, se ja estiver mensagem de erro e aborta função

    }

    void Controller::consultarVeiculo() {

    }

    Controller::~Controller() {
        for(model::Veiculo *v : *_veiculos){ // preciso disso funcional pra nao dar um leak de memoria bizonho
            delete(v);
        }
        delete _veiculos;
    }


} // controller