#include "Moto.h"
#include <string>
namespace model {

    //Construtor Moto.h

    Moto::Moto(int os, int id_patio, const std::string &solicitacao, const std::string &funcionario,
               const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
               const std::string &local, const std::string &placa, const std::string &marca, const std::string &modelo,
               int ano, const std::string &cidade, const std::string &chassi, int km, int hodometro,
               const std::string &ocorrencia, const std::string &policial, const std::string &data_apreensao,
               const std::string &horario, const std::string &objetos, const std::string &observacoes, int rodas,
               int retrovisores, int tipo, bool capacete, bool carenagem, bool bau, bool ferramentas,
               int suspDianteira, int suspTraseira, int guidao, int sistEletrico, int escapamento):

               Veiculo(os, id_patio, solicitacao, funcionario, placaReboque, motivo, estadoVeiculo, blitz, local, placa, marca, modelo,
                       ano, cidade, chassi, km, hodometro, ocorrencia, policial, data_apreensao, horario, objetos, observacoes, rodas, retrovisores, tipo), _capacete(capacete), _carenagem(carenagem), _bau(bau), _ferramentas(ferramentas), _suspDianteira(suspDianteira),
                       _suspTraseira(suspTraseira), _guidao(guidao), _sistEletrico(sistEletrico), _escapamento(escapamento){

        _diaria_moto = 30.22;
        _reboque_moto = 176.29;

    }


    //Gets and Sets

    bool Moto::get_capacete() const {
        return _capacete;
    }

    void Moto::set_capacete(bool capacete) {
        _capacete = capacete;
    }

    bool Moto::get_carenagem() const {
        return _carenagem;
    }

    void Moto::set_carenagem(bool carenagem) {
        _carenagem = carenagem;
    }

    bool Moto::get_bau() const {
        return _bau;
    }

    void Moto::set_bau(bool bau) {
        _bau = bau;
    }

    bool Moto:: get_ferramentas() const {
        return _ferramentas;
    }

    void Moto::set_ferramentas(bool ferramentas) {
        _ferramentas = ferramentas;
    }

    int Moto::get_suspDianteira() const {
        return _suspDianteira;
    }

    void Moto::set_suspDianteira(int suspDianteira) {
        _suspDianteira = suspDianteira;
    }

    int Moto::get_suspTraseira() const {
        return _suspTraseira;
    }

    void Moto::set_suspTraseira(int suspTraseira) {
        _suspTraseira = suspTraseira;
    }

    int Moto::get_guidao() const {
        return _guidao;
    }

    void Moto::set_guidao(int guidao) {
        _guidao = guidao;
    }

    int Moto::get_sistEletrico() const {
        return _sistEletrico;
    }

    void Moto::set_sistEletrico(int sistEletrico) {
        _sistEletrico = sistEletrico;
    }

    int Moto::get_escapamento() const {
        return _escapamento;
    }

    void Moto::set_escapamento(int escapamento) {
        _escapamento = escapamento;
    }

    double Moto::get_diaria_moto() const {
        return _diaria_moto;
    }

    void Moto::set_diaria_moto(double diaria_moto) {
        _diaria_moto = diaria_moto;
    }

    double Moto::get_reboque_moto() const {
        return _reboque_moto;
    }

    void Moto::set_reboque_moto(double reboque_moto) {
        _reboque_moto = reboque_moto;
    }
    //end of gets and sets

    //Cálculo de orçamento para motos, com base em dados do DETRAN respectivos à taxa de diária, reboque e KM do veículo
    double Moto::calcOrcamento(std::string data_liberacao_desejado){

        return (_diaria_moto * (calcDiasApreensao(data_liberacao_desejado)) + (_reboque_moto) + (2.5 * _km));

    }

    //Map de veículos do tipo Carro, associação de dados gerais com específicos do tipo
    void Moto::veiculoToMap(std::unordered_map<std::string, std::string> &dados_veiculo, std::unordered_map<std::string, std::string> &dados_especificos) {
        dados_veiculo["OS"] = std::to_string(_os);
        dados_veiculo["Patio"] = std::to_string(_id_patio);
        dados_veiculo["Solicitacao"] = _solicitacao;
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
        dados_veiculo["Tipo"] = "2";
        dados_especificos["Capacete"] = std::to_string(_capacete);
        dados_especificos["Carenagem"] = std::to_string(_carenagem);
        dados_especificos["Bau"] = std::to_string(_bau);
        dados_especificos["Ferramentas"] = std::to_string(_ferramentas);
        dados_especificos["SuspensaoD"] = std::to_string(_suspDianteira);
        dados_especificos["SuspensaoT"] = std::to_string(_suspTraseira);
        dados_especificos["Guidao"] = std::to_string(_guidao);
        dados_especificos["SistemaE"] = std::to_string(_sistEletrico);
        dados_especificos["Escapamento"] = std::to_string(_escapamento);


    }

    void Moto::updateVeiculo(std::unordered_map<std::string, std::string> &dados_veiculo, std::unordered_map<std::string, std::string> &dados_especificos) {

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
        _capacete = stob(dados_especificos["Capacete"]);
        _carenagem = stob(dados_especificos["Carenagem"]);
        _bau = stob(dados_especificos["Bau"]);
        _ferramentas = stob(dados_especificos["Ferramentas"]);
        _suspDianteira = std::stoi(dados_especificos["SuspensaoD"]);
        _suspTraseira = std::stoi(dados_especificos["SuspensaoT"]);
        _guidao = std::stoi(dados_especificos["Guidao"]);
        _sistEletrico = std::stoi(dados_especificos["SistemaE"]);
        _escapamento = std::stoi(dados_especificos["Escapamento"]);

    }


}
