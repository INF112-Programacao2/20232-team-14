#include "Caminhao.h"
#include <vector>
#include <string>

namespace model {

    //Construtor Caminhao.h

    Caminhao::Caminhao(int os, int id_patio, const std::string &solicitacao, const std::string &funcionario,
                       const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
                       const std::string &local, const std::string &placa, const std::string &marca,
                       const std::string &modelo, int ano, const std::string &cidade, const std::string &chassi, int km,
                       int hodometro, const std::string &ocorrencia, const std::string &policial,
                       const std::string &data_apreensao, const std::string &horario, const std::string &objetos,
                       const std::string &observacoes, int rodas, int retrovisores, int tipo, int carroceria, bool eixoTraseiro,
                       bool cintas, int suspCabine, bool extintor, bool estepe, bool macaco, bool chaveRoda, bool triangulo,
                       bool bateria, bool calotas, bool tapetes, bool radio) :

                       Veiculo(os, id_patio, solicitacao, funcionario, placaReboque, motivo, estadoVeiculo, blitz,
                               local, placa, marca, modelo, ano, cidade, chassi, km, hodometro,
                               ocorrencia, policial, data_apreensao, horario, objetos, observacoes, rodas, retrovisores, tipo)
                               , _carroceria(carroceria), _eixoTraseiro(eixoTraseiro), _cintas(cintas),
                               _suspCabine(suspCabine), _extintor(extintor), _estepe(estepe), _macaco(macaco),
                               _chave_roda(chaveRoda), _triangulo(triangulo), _bateria(bateria), _calotas(calotas),
                               _tapetes(tapetes), _radio(radio){

        _diaria_caminhao = 60.44;
        _reboque_caminhao = 367.69;

    }

    //Gets and Sets

    int Caminhao::get_carroceria() const {
        return _carroceria;
    }

    void Caminhao::set_carroceria(int carroceria) {
        _carroceria = carroceria;
    }

    bool Caminhao::get_eixoTraseiro() const {
        return _eixoTraseiro;
    }

    void Caminhao::set_eixoTraseiro(bool eixoTraseiro) {
        _eixoTraseiro = eixoTraseiro;
    }

    bool Caminhao::get_cintas() const {
        return _cintas;
    }

    void Caminhao::set_cintas(bool cintas) {
        _cintas = cintas;
    }

    int Caminhao::get_suspCabine() const {
        return _suspCabine;
    }

    void Caminhao::set_suspCabine(int suspCabine) {
        _suspCabine = suspCabine;
    }

    bool Caminhao::get_extintor() const {
        return _extintor;
    }

    void Caminhao::set_extintor(bool extintor) {
        _extintor = extintor;
    }

    bool Caminhao::get_estepe() const {
        return _estepe;
    }

    void Caminhao::set_estepe(bool estepe) {
        _estepe = estepe;
    }

    bool Caminhao::get_macaco() const {
        return _macaco;
    }

    void Caminhao::set_macaco(bool macaco) {
        _macaco = macaco;
    }

    bool Caminhao::get_chaveRoda() const {
        return _chave_roda;
    }

    void Caminhao::set_chaveRoda(bool chaveRoda) {
        _chave_roda = chaveRoda;
    }

    bool Caminhao::get_triangulo() const {
        return _triangulo;
    }

    void Caminhao::set_triangulo(bool triangulo) {
        _triangulo = triangulo;
    }

    bool Caminhao::get_bateria() const {
        return _bateria;
    }

    void Caminhao::set_bateria(bool bateria) {
        _bateria = bateria;
    }

    bool Caminhao::get_calotas() const {
        return _calotas;
    }

    void Caminhao::set_calotas(bool calotas) {
        _calotas = calotas;
    }

    bool Caminhao::get_tapetes() const {
        return _tapetes;
    }

    void Caminhao::set_tapetes(bool tapetes) {
        _tapetes = tapetes;
    }

    bool Caminhao::get_radio() const {
        return _radio;
    }

    void Caminhao::set_radio(bool radio) {
        _radio = radio;
    }

    double Caminhao::get_diaria_caminhao() const {
        return _diaria_caminhao;
    }

    void Caminhao::set_diaria_caminhao(double diaria_caminhao) {
        _diaria_caminhao = diaria_caminhao;
    }

    double Caminhao::get_reboque_caminhao() const {
        return _reboque_caminhao;
    }

    void Caminhao::set_reboque_caminhao(double reboque_caminhao) {
        _reboque_caminhao = reboque_caminhao;
    }
    //end of gets and sets

    void Caminhao::updateVeiculo(std::unordered_map<std::string, std::string> &dados_veiculo, std::unordered_map<std::string, std::string> &dados_especificos) {
        _os = std::stoi(dados_veiculo["OS"]);
        _id_patio = std::stoi(dados_veiculo["Patio"]);
        _solicitacao = dados_veiculo["Solicitacao"];
        _funcionario = dados_veiculo["Funcionario"];
        _placa_reboque = dados_veiculo["PlacaReboque"];
        _motivo = dados_veiculo["Motivo"];
        _estado_veiculo = std::stoi(dados_veiculo["Estado"]);
        _blitz = stob(dados_veiculo["Blitz"]);
        _local = dados_veiculo["Local"];
        _placa = dados_veiculo["Placa"];
        _marca = dados_veiculo["Marca"];
        _modelo = dados_veiculo["Modelo"];
        _ano = std::stoi(dados_veiculo["Ano"]);
        _cidade = dados_veiculo["Cidade"];
        _chassi = dados_veiculo["Chassi"];
        _km = std::stoi(dados_veiculo["Distancia"]);
        _hodometro = std::stoi(dados_veiculo["KM"]);
        _ocorrencia = dados_veiculo["Ocorrencia"];
        _policial = dados_veiculo["Policial"];
        _data_apreensao = dados_veiculo["Data"];
        _horario = dados_veiculo["Horario"];
        _objetos = dados_veiculo["Objetos"];
        _observacoes = dados_veiculo["Obs"];
        _rodas = std::stoi(dados_veiculo["EstadoRodas"]);
        _retrovisores = std::stoi(dados_veiculo["EstadoRetro"]);
        _carroceria = std::stoi(dados_especificos["EstadoCarroceria"]);
        _eixoTraseiro = stob(dados_especificos["EixoTras"]);
        _cintas = stob(dados_especificos["Cintas"]);
        _suspCabine = std::stoi(dados_especificos["SuspensaoC"]);
        _extintor = stob(dados_especificos["Extintor"]);
        _estepe = stob(dados_especificos["Estepe"]);
        _macaco = stob(dados_especificos["Macaco"]);
        _chave_roda = stob(dados_especificos["ChaveRoda"]);
        _triangulo = stob(dados_especificos["Triangulo"]);
        _bateria = stob(dados_especificos["Bateria"]);
        _calotas = stob(dados_especificos["Calotas"]);
        _tapetes = stob(dados_especificos["Tapetes"]);
        _radio = stob(dados_especificos["Radio"]);

    }



    //Cálculo de orçamento para caminhões, com base em dados do DETRAN respectivos à taxa de diária, reboque e KM do veículo
    double Caminhao::calcOrcamento(std::string data_liberacao_desejado){

        return (_diaria_caminhao * (calcDiasApreensao(data_liberacao_desejado)) + (_reboque_caminhao) + (2.5 * _km));

    }

    //Map de veículos do tipo Carro, associação de dados gerais com específicos do tipo
    void Caminhao::veiculoToMap(std::unordered_map<std::string, std::string> &dados_veiculo, std::unordered_map<std::string, std::string> &dados_especificos) {
        dados_veiculo["OS"] = std::to_string(_os);
        dados_veiculo["Patio"] = std::to_string(_id_patio);
        dados_veiculo["Solicitacao"] = _solicitacao;
        dados_veiculo["Situacao"] = std::to_string(_sit_veiculo);
        dados_veiculo["Data"] = _data_apreensao;
        dados_veiculo["DataLib"] = _data_liberacao;
        dados_veiculo["Funcionario"] = _funcionario;
        dados_veiculo["PlacaReboque"] = _placa_reboque;
        dados_veiculo["Motivo"] = _motivo;
        dados_veiculo["Estado"] = std::to_string(_estado_veiculo);
        dados_veiculo["Blitz"] = std::to_string(_blitz);
        dados_veiculo["Local"] = _local;
        dados_veiculo["Placa"] = _placa;
        dados_veiculo["Marca"] = _marca;
        dados_veiculo["Modelo"] = _modelo;
        dados_veiculo["Ano"] = std::to_string(_ano);
        dados_veiculo["Cidade"] = _cidade;
        dados_veiculo["Chassi"] = _chassi;
        dados_veiculo["Distancia"] = std::to_string(_km);
        dados_veiculo["KM"] = std::to_string(_hodometro);
        dados_veiculo["Ocorrencia"] = _ocorrencia;
        dados_veiculo["Policial"] = _policial;
        dados_veiculo["Data"] = _data_apreensao;
        dados_veiculo["Horario"] = _horario;
        dados_veiculo["Objetos"] = _objetos;
        dados_veiculo["Obs"] = _observacoes;
        dados_veiculo["EstadoRodas"] = std::to_string(_rodas);
        dados_veiculo["EstadoRetro"] = std::to_string(_retrovisores);
        dados_veiculo["Tipo"] = "3";
        dados_especificos["EstadoCarroceria"] = std::to_string(_carroceria);
        dados_especificos["EixoTras"] = std::to_string(_eixoTraseiro);
        dados_especificos["Cintas"] = std::to_string(_cintas);
        dados_especificos["SuspensaoC"] = std::to_string(_suspCabine);
        dados_especificos["Extintor"] = std::to_string(_extintor);
        dados_especificos["Estepe"] = std::to_string(_estepe);
        dados_especificos["Macaco"] = std::to_string(_macaco);
        dados_especificos["ChaveRoda"] = std::to_string(_chave_roda);
        dados_especificos["Triangulo"] = std::to_string(_triangulo);
        dados_especificos["Bateria"] = std::to_string(_bateria);
        dados_especificos["Calotas"] = std::to_string(_calotas);
        dados_especificos["Tapetes"] = std::to_string(_tapetes);
        dados_especificos["Radio"] = std::to_string(_radio);
    }
}
