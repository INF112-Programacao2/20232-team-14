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

    const std::string &model::Moto::getId() const {
        return _id;
    }

    void model::Moto::setId(const std::string &id) {
        _id = id;
    }

    bool model::Moto::isCapacete() const {
        return _capacete;
    }

    void model::Moto::setCapacete(bool capacete) {
        _capacete = capacete;
    }

    bool model::Moto::isCarenagem() const {
        return _carenagem;
    }

    void model::Moto::setCarenagem(bool carenagem) {
        _carenagem = carenagem;
    }

    bool model::Moto::isBau() const {
        return _bau;
    }

    void model::Moto::setBau(bool bau) {
        _bau = bau;
    }

    bool model::Moto::isFerramentas() const {
        return _ferramentas;
    }

    void model::Moto::setFerramentas(bool ferramentas) {
        _ferramentas = ferramentas;
    }

    int model::Moto::getSuspDianteira() const {
        return _suspDianteira;
    }

    void model::Moto::setSuspDianteira(int suspDianteira) {
        _suspDianteira = suspDianteira;
    }

    int model::Moto::getSuspTraseira() const {
        return _suspTraseira;
    }

    void model::Moto::setSuspTraseira(int suspTraseira) {
        _suspTraseira = suspTraseira;
    }

    int model::Moto::getGuidao() const {
        return _guidao;
    }

    void model::Moto::setGuidao(int guidao) {
        _guidao = guidao;
    }

    int model::Moto::getSistEletrico() const {
        return _sistEletrico;
    }

    void model::Moto::setSistEletrico(int sistEletrico) {
        _sistEletrico = sistEletrico;
    }

    int model::Moto::getEscapamento() const {
        return _escapamento;
    }

    void model::Moto::setEscapamento(int escapamento) {
        _escapamento = escapamento;
    }

}
