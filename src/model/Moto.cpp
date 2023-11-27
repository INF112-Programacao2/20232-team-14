#include "Moto.h"
#include <string>
#include "SqliteHook.h"
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

    double Moto::calcOrcamento(std::string data_liberacao_desejado){

        return (_diaria_moto * (calcDiasApreensao(data_liberacao_desejado)) + (_reboque_moto) + (2.5 * _km));

    }

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

    void Moto::persistVeiculo() {
        std::string sql = "INSERT INTO motos VALUES("
                        + std::to_string(_os) + ", "
                        + std::to_string(_id_patio) + ", "
                        + std::to_string(_sit_veiculo) + ", "
                        + "\'" + _solicitacao + "\', "
                        + "\'" + _funcionario + "\', "
                        + "\'" + _placa_reboque + "\', "
                        + "\'" + _motivo + "\', "
                        + std::to_string(_estado_veiculo) + ", "
                        + std::to_string(_blitz) + ", "
                        + "\'" + _local + "\', "
                        + "\'" + _placa + "\', "
                        + "\'" + _marca + "\', "
                        + "\'" + _modelo + "\', "
                        + std::to_string(_ano) + ", "
                        + "\'" + _cidade + "\', "
                        + "\'" + _chassi + "\', "
                        + std::to_string(_km) + ", "
                        + std::to_string(_hodometro) + ", "
                        + "\'" + _ocorrencia + "\', "
                        + "\'" + _policial + "\', "
                        + "\'" + _data_apreensao + "\', "
                        + "NULL" + ", "
                        + "\'" + _horario + "\', "
                        + "\'" + _objetos + "\', "
                        + "\'" + _observacoes + "\', "
                        + std::to_string(_rodas) + ", "
                        + std::to_string(_retrovisores) + ", "
                        + "2" + ", "
                        + std::to_string(_capacete) + ", "
                        + std::to_string(_carenagem) + ", "
                        + std::to_string(_bau) + ", "
                        + std::to_string(_ferramentas) + ", "
                        + std::to_string(_suspDianteira) + ", "
                        + std::to_string(_suspTraseira) + ", "
                        + std::to_string(_guidao) + ", "
                        + std::to_string(_sistEletrico) + ", "
                        + std::to_string(_escapamento) + ", "
                        + std::to_string(_diaria_moto) + ", "
                        + std::to_string(_reboque_moto) + ")"
        ;



        model::SqliteHook::executeQuery(sql);
    }


    void Moto::deleteRecord() {

    }

    void Moto::recordToVeiculo() {
        std::string sql =  "SELECT PLACA FROM carros WHERE ID = "
                           + std::to_string(_os)
                           + " UNION SELECT PLACA FROM motos WHERE ID = "
                           + std::to_string(_os)
                           + " UNION SELECT PLACA FROM caminhoes WHERE ID = "
                           + std::to_string(_os);

        SqliteHook::executeQuery(sql);
        std::vector<std::vector<std::string>*>* result = SqliteHook::fetchResult();

        if(result->empty()){
            sql = "SELECT * FROM carros WHERE ID = " + std::to_string(_os);
            model::SqliteHook::executeQuery(sql);
            result = model::SqliteHook::fetchResult();
            if(result){
                _os = stoi((*(*result)[0])[0]);
                _id_patio = stoi((*(*result)[0])[1]);
                _sit_veiculo = (*(*result)[0])[2] == "true"; // oq for booleano pd fazer assim
                _solicitacao = (*(*result)[0])[3];
                _funcionario = (*(*result)[0])[4];
                _placa_reboque = (*(*result)[0])[5];
                _motivo = (*(*result)[0])[6];
                _estado_veiculo = stoi((*(*result)[0])[7]);
                _blitz = (*(*result)[0])[8] == "true";
                _local = (*(*result)[0])[9];
                _placa = (*(*result)[0])[10];
                _marca = (*(*result)[0])[11];
                _modelo = (*(*result)[0])[12];
                _ano = stoi((*(*result)[0])[13]);
                _cidade = (*(*result)[0])[14];
                _chassi = (*(*result)[0])[15];
                _km = stoi((*(*result)[0])[16]);
                _hodometro = stoi((*(*result)[0])[17]);
                _ocorrencia = (*(*result)[0])[18];
                _policial = (*(*result)[0])[19];
                _data_apreensao = (*(*result)[0])[20];
                _data_liberacao = (*(*result)[0])[21];
                _horario = (*(*result)[0])[22];
                _objetos = (*(*result)[0])[23];
                _observacoes = (*(*result)[0])[24];
                _rodas = stoi((*(*result)[0])[25]);
                _retrovisores = stoi((*(*result)[0])[26]);
                _tipo = stoi((*(*result)[0])[27]);
                _capacete = stoi((*(*result)[0])[28]);
                _carenagem = stoi((*(*result)[0])[29]);
                _bau = stoi((*(*result)[0])[30]);
                _ferramentas = stoi((*(*result)[0])[31]);
                _suspDianteira = stoi((*(*result)[0])[32]);
                _suspTraseira = stoi((*(*result)[0])[33]);
                _guidao = stoi((*(*result)[0])[34]);
                _sistEletrico = stoi((*(*result)[0])[35]);
                _escapamento = stoi((*(*result)[0])[36]);
                _diaria_moto = stoi((*(*result)[0])[37]);
                _reboque_moto = stoi((*(*result)[0])[38]);
            }
        }
    }


}
