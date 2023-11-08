#include "Carro.h"
#include <vector>
#include <string>

namespace model {

    Carro::Carro(std::string os, std::string solicitacao, std::string funcionario, std::string placa_reboque,
                 std::string motivo, int estado_veiculo, bool blitz, std::string local, std::string placa,
                 std::string marca, std::string modelo, int ano, std::string cidade, std::string chassi, int km,
                 int hodometro, std::string ocorrencia, std::string policial, std::string data, std::string horario,
                 std::string objetos, std::string observacoes, int rodas, int retrovisores, std::vector <std::string> &_checklist):

    Veiculo(os,solicitacao,funcionario,placa_reboque,motivo,estado_veiculo,blitz,local,placa,marca,modelo,
            ano,cidade,chassi,km,hodometro,ocorrencia,policial,data,horario,objetos,observacoes,rodas,retrovisores)

    {

        _id = _checklist[0];
        _extintor = stob(_checklist[1]);
        _estepe = stob (_checklist[2]);
        _macaco = stob(_checklist[3]);
        _chave_roda = stob (_checklist[4]);
        _triangulo = stob(_checklist[5]);
        _bateria = stob(_checklist[6]);
        _calotas = stob(_checklist[7]);
        _tapetes = stob(_checklist[8]);
        _radio = stob(_checklist[9]);
        _portas = std::stoi(_checklist[10]);
        _capo = std::stoi(_checklist[11]);
        _painel = std::stoi(_checklist[12]);
        _teto = std::stoi( _checklist[13]);

    }

    const std::string &Carro::get_id() const {
        return _id;
    }

    void Carro::set_id(const std::string &id) {
        _id = id;
    }

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

    bool Carro::stob(const std::string& str){

        return Veiculo::stob(&str);

    }

};

//end of autogenerated getters and setters

// model