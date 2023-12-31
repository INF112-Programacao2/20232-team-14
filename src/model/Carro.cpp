#include "Carro.h"
#include <string>

namespace model {

    //Construtor Carro.h

    Carro::Carro(int os, int id_patio, const std::string &solicitacao, const std::string &funcionario,
                 const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
                 const std::string &local, const std::string &placa, const std::string &marca,
                 const std::string &modelo, int ano, const std::string &cidade, const std::string &chassi, int km,
                 int hodometro, const std::string &ocorrencia, const std::string &policial, const std::string &data_apreensao,
                 const std::string &horario, const std::string &objetos, const std::string &observacoes, int rodas,
                 int retrovisores, int tipo, bool extintor, bool estepe, bool macaco, bool chaveRoda, bool triangulo,
                 bool bateria, bool calotas, bool tapetes, bool radio, int portas, int capo, int painel, int teto) :

                Veiculo(os, id_patio, solicitacao, funcionario, placaReboque, motivo, estadoVeiculo, blitz, local,
                        placa, marca, modelo, ano, cidade, chassi, km, hodometro, ocorrencia, policial,
                        data_apreensao, horario, objetos, observacoes, rodas, retrovisores, tipo), _extintor(extintor),
                        _estepe(estepe), _macaco(macaco), _chave_roda(chaveRoda), _triangulo(triangulo), _bateria(bateria),
                        _calotas(calotas), _tapetes(tapetes), _radio(radio), _portas(portas), _capo(capo), _painel(painel), _teto(teto){

                _diaria_carro = 50.37;
                _reboque_carro = 277.03;

    }

    //Gets and Sets

    bool Carro::get_extintor() const {
        return _extintor;
    }

    void Carro::set_extintor(bool extintor) {
        _extintor = extintor;
    }

    bool Carro:: get_estepe() const {
        return _estepe;
    }

    void Carro:: set_estepe(bool estepe) {
        _estepe = estepe;
    }

    bool Carro::get_macaco() const {
        return _macaco;
    }

    void Carro::set_macaco(bool macaco) {
        _macaco = macaco;
    }

    bool Carro:: get_chave_roda() const {
        return _chave_roda;
    }

    void Carro::set_chave_roda(bool chave_roda) {
        _chave_roda = chave_roda;
    }

    bool Carro::get_triangulo() const {
        return _triangulo;
    }

    void Carro:: set_triangulo(bool triangulo) {
        _triangulo = triangulo;
    }

    bool Carro:: get_bateria() const {
        return _bateria;
    }

    void Carro::set_bateria(bool bateria) {
        _bateria = bateria;
    }

    bool Carro::get_calotas() const {
        return _calotas;
    }

    void Carro:: set_calotas(bool calotas) {
        _calotas = calotas;
    }

    bool Carro::get_tapetes() const {
        return _tapetes;
    }

    void Carro::set_tapetes(bool tapetes) {
        _tapetes = tapetes;
    }

    bool Carro::get_radio() const {
        return _radio;
    }

    void Carro::set_radio(bool radio) {
        _radio = radio;
    }

    int Carro::get_portas() const {
        return _portas;
    }

    void Carro::set_portas(int portas) {
        _portas = portas;
    }

    int Carro::get_capo() const {
        return _capo;
    }

    void Carro:: set_capo(int capo) {
        _capo = capo;
    }

    int Carro:: get_painel() const {
        return _painel;
    }

    void Carro:: set_painel(int painel) {
        _painel = painel;
    }

    int Carro::get_teto() const {
        return _teto;
    }

    void Carro:: set_teto(int teto) {
        _teto = teto;
    }

    double Carro::get_diaria_carro() const {
        return _diaria_carro;
    }

    void Carro::set_diaria_carro(double diaria_carro) {
        _diaria_carro = diaria_carro;
    }

    double Carro::get_reboque_carro() const {
        return _reboque_carro;
    }

    void Carro::set_reboque_carro(double reboque_carro){
        _reboque_carro = reboque_carro;
    }
    //end of gets and sets

    //Cálculo de orçamento para carros, com base em dados do DETRAN respectivos à taxa de diária, reboque e KM do veículo
    double Carro::calcOrcamento(std::string data_liberacao){

        return (_diaria_carro * (calcDiasApreensao(data_liberacao)) + (_reboque_carro) + (2.5 * _km));

    }

    //Map de veículos do tipo Carro, associação de dados gerais com específicos do tipo
    void Carro::veiculoToMap(std::unordered_map<std::string, std::string> &dados_veiculo,
                             std::unordered_map<std::string, std::string> &dados_especificos) {

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
        dados_veiculo["Horario"] = _horario;
        dados_veiculo["Objetos"] = _objetos;
        dados_veiculo["Obs"] = _observacoes;
        dados_veiculo["EstadoRodas"] = std::to_string(_rodas);
        dados_veiculo["EstadoRetro"] = std::to_string(_retrovisores);
        dados_veiculo["Tipo"] = "1";
        dados_especificos["Extintor"] = std::to_string(_extintor);
        dados_especificos["Estepe"] = std::to_string(_estepe);
        dados_especificos["Macaco"] = std::to_string(_macaco);
        dados_especificos["ChaveRoda"] = std::to_string(_chave_roda);
        dados_especificos["Triangulo"] = std::to_string(_triangulo);
        dados_especificos["Bateria"] = std::to_string(_bateria);
        dados_especificos["Calotas"] = std::to_string(_calotas);
        dados_especificos["Tapetes"] = std::to_string(_tapetes);
        dados_especificos["Radio"] = std::to_string(_radio);
        dados_especificos["EstadoPortas"] = std::to_string(_portas);
        dados_especificos["EstadoCapo"] = std::to_string(_capo);
        dados_especificos["EstadoPainel"] = std::to_string(_painel);
        dados_especificos["EstadoTeto"] = std::to_string(_teto);
    }

    void Carro::updateVeiculo(std::unordered_map<std::string, std::string> &dados_veiculo, std::unordered_map<std::string, std::string> &dados_especificos) {

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
        _extintor = stob(dados_especificos["Extintor"]);
        _estepe = stob(dados_especificos["Estepe"]);
        _macaco = stob(dados_especificos["Macaco"]);
        _chave_roda = stob(dados_especificos["ChaveRoda"]);
        _triangulo = stob(dados_especificos["Triangulo"]);
        _bateria = stob(dados_especificos["Bateria"]);
        _calotas = stob(dados_especificos["Calotas"]);
        _tapetes = stob(dados_especificos["Tapetes"]);
        _radio = stob(dados_especificos["Radio"]);
        _portas = std::stoi(dados_especificos["EstadoPortas"]);
        _capo = std::stoi(dados_especificos["EstadoCapo"]);
        _painel = std::stoi(dados_especificos["EstadoPainel"]);
        _teto = std::stoi(dados_especificos["EstadoTeto"]);

    }

}

// model