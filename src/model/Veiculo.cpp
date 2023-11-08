#include <string>
#include "Veiculo.h"

namespace model {

    //Construtor Veiculo.h

    Veiculo::Veiculo(const std::string &os, const std::string &solicitacao, const std::string &funcionario,
                     const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
                     const std::string &local, const std::string &placa, const std::string &marca,
                     const std::string &modelo, int ano, const std::string &cidade, const std::string &chassi, int km,
                     int hodometro, const std::string &ocorrencia, const std::string &policial, const std::string &data,
                     const std::string &horario, const std::string &objetos, const std::string &observacoes, int rodas,
                     int retrovisores) : _os(os), _solicitacao(solicitacao), _funcionario(funcionario),
                     _placa_reboque(placaReboque), _motivo(motivo), _estado_veiculo(estadoVeiculo),
                     _blitz(blitz), _local(local), _placa(placa), _marca(marca), _modelo(modelo),
                     _ano(ano), _cidade(cidade), _chassi(chassi), _km(km), _hodometro(hodometro),
                     _ocorrencia(ocorrencia), _policial(policial), _data(data), _horario(horario),
                     _objetos(objetos), _observacoes(observacoes), _rodas(rodas),
                     _retrovisores(retrovisores) {

    }

    //Gets and Sets

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

    //end of gets and Sets

    //função verifica se um ano é bissexto ou não (usada para estabelecer o cálculo do orçamento baseado nas diárias)

    /*bool Veiculo::anoBissexto(int ano){

        bool valid = false;

        if(ano%4 == 0 && ano%100 != 0 || ano%400==0){

            valid = true;

        }

        return valid;

    }*/

} // model