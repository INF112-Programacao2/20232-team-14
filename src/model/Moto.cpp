#include "Moto.h"
#include <vector>
#include <string>

namespace model {

    Moto::Moto(std::string os, std::string solicitacao, std::string funcionario, std::string placa_reboque, std::string motivo,
               int estado_veiculo, bool blitz, std::string local, std::string placa, std::string marca, std::string modelo,
               int ano, std::string cidade, std::string chassi, int km, int hodometro, std::string ocorrencia, std::string policial,
               std::string data, std::string horario,std::string objetos, std::string observacoes, int rodas, int retrovisores,
               std::vector<std::string> &_checklist):

    Veiculo(os,solicitacao,funcionario,placa_reboque,motivo,estado_veiculo,blitz,local,placa,marca,modelo,
            ano,cidade,chassi,km,hodometro,ocorrencia,policial,data,horario,objetos,observacoes,rodas,retrovisores)

    {

        _id = _checklist[0];
        _capacete = stob(_checklist[1]);
        _carenagem = stob(_checklist[2]);
        _bau = stob(_checklist[3]);
        _ferramentas = stob(_checklist[4]);
        _suspDianteira = stoi(_checklist[5]);
        _suspTraseira = stoi(_checklist[6]);
        _guidao = stoi(_checklist[7]);
        _sistEletrico = stoi(_checklist[8]);
        _escapamento = stoi(_checklist[9]);

    }

    const std::string &model::Moto::get_id() const {
        return _id;
    }

    void Moto::set_id(const std::string &id) {
        _id = id;
    }

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

    bool Moto::stob(const std::string& str){

        return Veiculo::stob(str);

    }

}
