#include <string>
#include <sstream>
#include "Veiculo.h"

namespace model {

    //Construtor Veiculo.h

    Veiculo::Veiculo(int os, const std::string &solicitacao, const std::string &funcionario,
                     const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
                     const std::string &local, const std::string &placa, const std::string &marca,
                     const std::string &modelo, int ano, const std::string &cidade, const std::string &chassi, int km,
                     int hodometro, const std::string &ocorrencia, const std::string &policial, const std::string &data_apreensao,
                     const std::string &horario, const std::string &objetos, const std::string &observacoes, int rodas,
                     int retrovisores, int tipo) : _os(os), _solicitacao(solicitacao), _funcionario(funcionario),
                     _placa_reboque(placaReboque), _motivo(motivo), _estado_veiculo(estadoVeiculo),
                     _blitz(blitz), _local(local), _placa(placa), _marca(marca),  _modelo(modelo), _ano(ano), _cidade(cidade),
                     _chassi(chassi), _km(km), _hodometro(hodometro), _ocorrencia(ocorrencia), _policial(policial), _data_apreensao(data_apreensao),
                     _horario(horario), _objetos(objetos), _observacoes(observacoes), _rodas(rodas), _retrovisores(retrovisores), _tipo(tipo) {

    }

    //Gets and Sets

    int Veiculo::get_os() const {
        return _os;
    }

    void Veiculo::set_os(int os) {
        _os = os;
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

    const std::string &Veiculo::get_marca() const {
        return _marca;
    }

    void Veiculo::set_marca(const std::string &marca) {
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

    const std::string &Veiculo::get_data_apreensao() const {
        return _data_apreensao;
    }

    void Veiculo::set_data_apreensao(const std::string &data_apreensao) {
        _data_apreensao=data_apreensao;
    }

    const std::string &Veiculo::get_data_liberacao() const {
        return _data_liberacao;
    }

    void Veiculo::set_data_liberacao(const std::string &data_liberacao) {
        _data_apreensao=data_liberacao;
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

    bool Veiculo::anoBissexto(int ano){

        bool valid = false;

        if(ano%4 == 0 && ano%100 != 0 || ano%400==0){

            valid = true;

        }

        return valid;

    }

    int Veiculo::calcDiasApreensao() {

        //Obtém dia, mes e ano das strings de data recebidas, guardando os valores nas variáveis abaixo
        int dia_Apreensao, mes_Apreensao, ano_Apreensao;
        int dia_Liberacao, mes_Liberacao, ano_Liberacao;
        char discard;
        std::stringstream ss_apreensao(_data_apreensao);
        ss_apreensao >> dia_Apreensao >> discard >> mes_Apreensao >> discard >> ano_Apreensao;
        std::stringstream ss_liberacao(_data_liberacao);
        ss_liberacao >> dia_Liberacao >> discard >> mes_Liberacao >> discard >> ano_Liberacao;

        int calendario_Entrada[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int calendario_Saida[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        /*A função trabalha encontrando a quantidade de dias do ano de liberação e do ano de apreensão
        Exemplo: se o carro foi apreendido dia 25/12/2022 e liberado dia 03/01/2023, a variável
        dias_liberacao = 3 e a variável dias_apreensao = 7, totalizando 10 dias */

        int dias_liberacao = 0;
        int dias_apreensao = 0;
        int cont_dias = 0;

        /*Verificando se os anos de entrada e 
        saída sao bissextos e adicionando 1 dia em fevereiro caso sejam*/

        if (anoBissexto(ano_Apreensao)) {

            //é somado um dia ao mes de fevereiro - referente ao ano de apreensão do veículo
            calendario_Entrada[1]++;

        }

        if (anoBissexto(ano_Liberacao)) {

            //é somado um dia ao mes de fevereiro - referente ao ano de liberação do veículo
            calendario_Saida[1]++;

        }

        //Verificando se a data de entrada e saída estão no mesmo ano

        if (ano_Apreensao == ano_Liberacao) {

            for (int i = 0; i < mes_Liberacao - 1; i++) {

                dias_liberacao += calendario_Saida[i];

                if (i < mes_Apreensao - 1) {

                    dias_apreensao += calendario_Entrada[i];

                }

            }

            dias_liberacao += dia_Liberacao;
            dias_apreensao += dia_Apreensao;

            cont_dias = dias_liberacao - dias_apreensao;

        } else {

            for (int i = 0; i < mes_Liberacao - 1; i++) {

                dias_liberacao += calendario_Saida[i];

            }

            dias_liberacao += dia_Liberacao;

            for (int i = 0; i < mes_Apreensao - 1; i++) {

                dias_apreensao += calendario_Entrada[i];

            }

            dias_apreensao += dia_Apreensao;

            if (anoBissexto(ano_Apreensao)) {

                dias_apreensao = 366 - dias_apreensao;

            } else {

                dias_apreensao = 365 - dias_apreensao;

            }

            for (int i = ano_Apreensao + 1; i < ano_Liberacao; i++) {

                if (anoBissexto(i)) {

                    cont_dias += 366;

                } else {

                    cont_dias += 365;

                }

            }

            cont_dias += dias_liberacao + dias_apreensao;

        }

        cont_dias++;

        return cont_dias;

    }


} // model