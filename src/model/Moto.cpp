#include "Moto.h"
#include <string>

namespace model {

    //Construtor Moto.h

    Moto::Moto(const std::string &os, const std::string &solicitacao, const std::string &funcionario,
               const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
               const std::string &local, const std::string &placa, const std::string &marca, const std::string &modelo,
               int ano, const std::string &cidade, const std::string &chassi, int km, int hodometro,
               const std::string &ocorrencia, const std::string &policial, const std::string &data,
               const std::string &horario, const std::string &objetos, const std::string &observacoes, int rodas,
               int retrovisores, bool capacete, bool carenagem, bool bau, bool ferramentas,
               int suspDianteira, int suspTraseira, int guidao, int sistEletrico, int escapamento):

               Veiculo(os, solicitacao, funcionario, placaReboque, motivo, estadoVeiculo, blitz, local, placa, marca, modelo,
               ano, cidade, chassi, km, hodometro, ocorrencia, policial, data, horario, objetos, observacoes, rodas, retrovisores),
               _capacete(capacete), _carenagem(carenagem), _bau(bau), _ferramentas(ferramentas), _suspDianteira(suspDianteira),
               _suspTraseira(suspTraseira), _guidao(guidao), _sistEletrico(sistEletrico), _escapamento(escapamento){

               _diaria_moto = 30.22;
               _reboque_moto = 176.29;

    }

    //Gets and Sets

    const std::string &model::Moto::get_id() const {
        return _id;
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

    double Moto::get_diariaMoto() const {
        return _diaria_moto;
    }

    void Moto::set_diariaMoto(double diariaMoto) {
        _diaria_moto = diariaMoto;
    }

    double Moto::get_reboqueMoto() const {
        return _reboque_moto;
    }

    void Moto::set_reboqueMoto(double reboqueMoto) {
        _reboque_moto = reboqueMoto;
    }
    //end of gets and sets

}
