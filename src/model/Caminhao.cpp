
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

    const std::string &model::Caminhao::get_id() const {
        return _id;
    }

    void model::Caminhao::set_id(const std::string &id) {
        _id = id;
    }

    int model::Caminhao::get_carroceria() const {
        return _carroceria;
    }

    void model::Caminhao::set_carroceria(int carroceria) {
        _carroceria = carroceria;
    }

    bool model::Caminhao::is_eixoTraseiro() const {
        return _eixoTraseiro;
    }

    void model::Caminhao::set_eixoTraseiro(bool eixoTraseiro) {
        _eixoTraseiro = eixoTraseiro;
    }

    bool model::Caminhao::is_cintas() const {
        return _cintas;
    }

    void model::Caminhao::set_cintas(bool cintas) {
        _cintas = cintas;
    }

    int model::Caminhao::get_suspCabine() const {
        return _suspCabine;
    }

    void model::Caminhao::set_suspCabine(int suspCabine) {
        _suspCabine = suspCabine;
    }

    bool model::Caminhao::is_estepe() const {
        return _estepe;
    }

    void model::Caminhao::set_estepe(bool estepe) {
        _estepe = estepe;
    }

    bool model::Caminhao::is_extintor() const {
        return _extintor;
    }

    void model::Caminhao::set_extintor(bool extintor) {
        _extintor = extintor;
    }

    bool model::Caminhao::is_estepe() const {
        return _estepe;
    }

    void model::Caminhao::set_estepe(bool estepe) {
        _estepe = estepe;
    }

    bool model::Caminhao::is_macaco() const {
        return _macaco;
    }

    void model::Caminhao::set_macaco(bool macaco) {
        _macaco = macaco;
    }

    bool model::Caminhao::is_chaveRoda() const {
        return _chave_roda;
    }

    void model::Caminhao::set_chaveRoda(bool chaveRoda) {
        _chave_roda = chaveRoda;
    }

    bool model::Caminhao::is_triangulo() const {
        return _triangulo;
    }

    void model::Caminhao::set_triangulo(bool triangulo) {
        _triangulo = triangulo;
    }

    bool model::Caminhao::is_bateria() const {
        return _bateria;
    }

    void model::Caminhao::set_bateria(bool bateria) {
        _bateria = bateria;
    }

    bool model::Caminhao::is_calotas() const {
        return _calotas;
    }

    void model::Caminhao::set_calotas(bool calotas) {
        _calotas = calotas;
    }

    bool model::Caminhao::is_tapetes() const {
        return _tapetes;
    }

    void model::Caminhao::set_tapetes(bool tapetes) {
        _tapetes = tapetes;
    }

    bool model::Caminhao::is_radio() const {
        return _radio;
    }

    void model::Caminhao::set_radio(bool radio) {
        _radio = radio;
    }

}
