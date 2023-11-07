#include <vector>
#include <string>
#include "Veiculo.h"

namespace model {

    Veiculo::Veiculo(std::vector<std::string> &dados_veiculo){

        _os = dados_veiculo[0];
        _solicitacao = dados_veiculo[1];
        _funcionario = dados_veiculo[2];
        _placa_reboque = dados_veiculo[3];
        _motivo = dados_veiculo[4];
        _estado_veiculo = std::stoi(dados_veiculo[5]);
        _blitz = stob(dados_veiculo[6]);
        _local = dados_veiculo[7];
        _placa = dados_veiculo[8];
        _marca = dados_veiculo[9];
        _modelo = dados_veiculo[10];
        _ano = std::stoi(dados_veiculo[11]);
        _cidade = dados_veiculo[12];
        _chassi = dados_veiculo[13];
        _km = std::stoi(dados_veiculo[14]);
        _hodometro = std::stoi(dados_veiculo[15]);
        _ocorrencia = dados_veiculo[16];
        _policial = dados_veiculo[17];
        _data = dados_veiculo[18];
        _horario = dados_veiculo[19];
        _objetos = dados_veiculo[20];
        _observacoes = dados_veiculo[21];
        _rodas = std::stoi(dados_veiculo[22]);
        _retrovisores = std::stoi(dados_veiculo[23]);

    }

    const std::string &Veiculo::get_os() const {
        return _os;
    }

    void Veiculo:: set_os(const std::string &os){
        _os=os;
    }

    const std::string &Veiculo::get_solicitacao() const{
        return _solicitacao;
    }

    void Veiculo:: set_solicitacao(const std::string &solicitacao){
        _solicitacao=solicitacao;
    }

    const std::string &Veiculo::get_funcionario() const{
        return _funcionario;
    }

    void Veiculo::set_funcionario(const std::string &funcionario){
        _funcionario=funcionario;
    }

    const std::string &Veiculo::get_placa_reboque() const{
        return _placa_reboque;
    }

    void Veiculo::set_placa_reboque(const std::string &placa_reboque){
        _placa_reboque=placa_reboque;
    }

    const std::string &Veiculo::get_motivo() const{
        return _motivo;
    }

    void Veiculo::set_motivo(const std::string &motivo){
        _motivo=motivo;
    }

    const int &Veiculo::get_estado_veiculo() const{
        return _estado_veiculo;
    }

    void Veiculo::set_estado_veiculo(const int &estado_veiculo){
        _estado_veiculo=estado_veiculo;
    }

    const bool &Veiculo::get_blitz() const{
        return _blitz;
    }

    void Veiculo::set_blitz(const bool &blitz){
        _blitz=blitz;
    }

    const std::string &Veiculo::get_local() const{
        return _local;
    }

    void Veiculo::set_local(const std::string &local){
        _local=local;
    }

    const std::string &Veiculo::get_placa() const{
        return _placa;
    }

    void Veiculo::set_placa(const std::string &placa){
        _placa=placa;
    }

    const std::string &Veiculo::get_marca() const{
        return _marca;
    }

    void Veiculo::set_marca(const std::string &marca){
        _marca=marca;
    }

    const std::string &Veiculo::get_modelo() const{
        return _modelo;
    }

    void Veiculo::set_modelo(const std::string &modelo){
        _modelo=modelo;
    }

    const int &Veiculo:: get_ano() const{
        return _ano;
    }

    void Veiculo:: set_ano(const int &ano){
        _ano=ano;
    }

    const std::string &Veiculo::get_cidade() const{
        return _cidade;
    }

    void Veiculo::set_cidade(const std::string &cidade){
        _cidade=cidade;
    }

    const std::string &Veiculo:: get_chassi() const{
        return _chassi;
    }

    void Veiculo:: set_chassi(const std::string &chassi){
        _chassi=chassi;
    }

    const int &Veiculo::get_km() const{
        return _km;
    }

    void Veiculo::set_km(const int &km){
        _km=km;
    }

    const int &Veiculo::get_hodometro() const{
        return _hodometro;
    }

    void Veiculo::set_hodometro(const int &hodometro){
        _hodometro=hodometro;
    }

    const std::string &Veiculo::get_ocorrencia() const{
        return _ocorrencia;
    }

    void Veiculo::set_ocorrencia(const std::string &ocorrencia){
        _ocorrencia=ocorrencia;
    }

    const std::string &Veiculo::get_policial() const{
        return _policial;
    }

    void Veiculo::set_policial(const std::string &policial){
        _policial=policial;
    }

    const std::string &Veiculo::get_data() const{
        return _data;
    }

    void Veiculo::set_data(const std::string &data){
        _data=data;
    }

    const std::string &Veiculo::get_horario() const{
        return _horario;
    }

    void Veiculo::set_horario(const std::string &horario){
        _horario=horario;
    }

    const std::string &Veiculo::get_objetos() const{
        return _objetos;
    }

    void Veiculo::set_objetos(const std::string &objetos){
        _objetos=objetos;
    }

    const std::string &Veiculo::get_observacoes() const{
        return _observacoes;
    }

    void Veiculo::set_observacoes(const std::string &observacoes){
        _observacoes=observacoes;
    }

    const int &Veiculo:: get_rodas() const{
        return _rodas;
    }

    void Veiculo::set_rodas(const int &rodas){
        _rodas=rodas;
    }

    const int &Veiculo:: get_retrovisores() const{
        return _retrovisores;
    }

    void Veiculo:: set_retrovisores(const int &retrovisores){
        _retrovisores=retrovisores;
    }

    //função string to bool - usada para converter os dados do vector que devem ser interpretados como bool
    bool Veiculo::stob(const std::string &str){

        if(str == "true" || str == "1"){

            return true;

        }else if(str == "false" || str == "0"){

            return false;

        }

    }



} // model