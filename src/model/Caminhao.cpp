#include "Caminhao.h"
#include <vector>
#include <string>

namespace model {

    //Construtor Caminhao.h

    Caminhao::Caminhao(const std::string &os, const std::string &solicitacao, const std::string &funcionario,
                       const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
                       const std::string &local, const std::string &placa, const std::string &marca,
                       const std::string &modelo, int ano, const std::string &cidade, const std::string &chassi, int km,
                       int hodometro, const std::string &ocorrencia, const std::string &policial,
                       const std::string &data, const std::string &horario, const std::string &objetos,
                       const std::string &observacoes, int rodas, int retrovisores, int carroceria, bool eixoTraseiro,
                       bool cintas, int suspCabine, bool extintor, bool estepe, bool macaco, bool chaveRoda, bool triangulo,
                       bool bateria, bool calotas, bool tapetes, bool radio) :

                       Veiculo(os, solicitacao, funcionario, placaReboque, motivo, estadoVeiculo, blitz,
                               local, placa, marca, modelo, ano, cidade, chassi, km, hodometro,
                               ocorrencia, policial, data, horario, objetos, observacoes, rodas, retrovisores)
                               , _carroceria(carroceria), _eixoTraseiro(eixoTraseiro), _cintas(cintas),
                               _suspCabine(suspCabine), _extintor(extintor), _estepe(estepe), _macaco(macaco),
                               _chave_roda(chaveRoda), _triangulo(triangulo), _bateria(bateria), _calotas(calotas),
                               _tapetes(tapetes), _radio(radio){

    }

    //Gets and Sets

    const std::string &Caminhao::get_id() const {
        return _id;
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

    double Caminhao::get_taxaDiaria() const {
        return _taxaDiaria;
    }

    void Caminhao::set_taxaDiaria(double taxaDiaria){
        _taxaDiaria = taxaDiaria;
    }

    double Caminhao::get_taxaReboque() const{
        return _taxaReboque;
    }

    void Caminhao::set_taxaReboque(double taxaReboque){
        _taxaReboque = taxaReboque;
    }

    //end of gets and sets

    bool Caminhao::stob(const std::string& str){

        return Veiculo::stob(str);

    }

}
