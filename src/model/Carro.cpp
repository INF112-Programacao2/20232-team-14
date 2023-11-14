#include "Carro.h"
#include <string>

namespace model {

    //Construtor Carro.h

    Carro::Carro(int os, const std::string &solicitacao, const std::string &funcionario,
                 const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
                 const std::string &local, const std::string &placa, const std::string &marca,
                 const std::string &modelo, int ano, const std::string &cidade, const std::string &chassi, int km,
                 int hodometro, const std::string &ocorrencia, const std::string &policial, const std::string &data,
                 const std::string &horario, const std::string &objetos, const std::string &observacoes, int rodas,
                 int retrovisores, bool extintor, bool estepe, bool macaco, bool chaveRoda, bool triangulo,
                 bool bateria, bool calotas, bool tapetes, bool radio, int portas, int capo, int painel, int teto) :

                Veiculo(os, solicitacao, funcionario, placaReboque, motivo, estadoVeiculo, blitz, local,
                        placa, marca, modelo, ano, cidade, chassi, km, hodometro, ocorrencia, policial,
                        data, horario, objetos, observacoes, rodas, retrovisores), _extintor(extintor),
                        _estepe(estepe), _macaco(macaco), _chave_roda(chaveRoda), _triangulo(triangulo), _bateria(bateria),
                        _calotas(calotas), _tapetes(tapetes), _radio(radio), _portas(portas), _capo(capo), _painel(painel), _teto(teto){

    }

    //Gets and Sets

    const std::string &Carro::get_id() const {
        return _id;
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
    double Carro::calcOrcamento(){

        return (_diaria_carro * (calcDiasApreensao()) + (_reboque_carro) + (2.5 * _km));

    }
};

// model