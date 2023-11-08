
#include "Caminhao.h"
#include <vector>
#include <string>

namespace model {

    Caminhao::Caminhao(std::string os, std::string solicitacao, std::string funcionario, std::string placa_reboque, std::string motivo,
               int estado_veiculo, bool blitz, std::string local, std::string placa, std::string marca, std::string modelo,
               int ano, std::string cidade, std::string chassi, int km, int hodometro, std::string ocorrencia, std::string policial,
               std::string data, std::string horario,std::string objetos, std::string observacoes, int rodas, int retrovisores,
               std::vector<std::string> &_checklist):

            Veiculo(os,solicitacao,funcionario,placa_reboque,motivo,estado_veiculo,blitz,local,placa,marca,modelo,
                    ano,cidade,chassi,km,hodometro,ocorrencia,policial,data,horario,objetos,observacoes,rodas,retrovisores)

    {

        _id = _checklist[0];
        _carroceria = stoi(_checklist[1]);
        _eixoTraseiro = stob(_checklist[2]);
        _cintas = stob(_checklist[3]);
        _suspCabine = stoi(_checklist[4]);
        _estepe = stob(_checklist[5]);
        _extintor = stob(_checklist[6]);
        _macaco = stob(_checklist[7]);
        _chave_roda = stob(_checklist[8]);
        _triangulo = stob(_checklist[9]);
        _bateria = stob(_checklist[6]);
        _calotas = stob(_checklist[7]);
        _tapetes = stob(_checklist[8]);
        _radio = stob(_checklist[9]);

    }

    const std::string Caminhao::get_id() const {
        return _id;
    }

    void Caminhao::set_id(const std::string &id) {
        _id = id;
    }

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

    bool Caminhao::get_estepe() const {
        return _estepe;
    }

    void Caminhao::set_estepe(bool estepe) {
        _estepe = estepe;
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

    bool Caminhao::stob(const std::string& str){

        return Veiculo::stob(&str);

    }

}
