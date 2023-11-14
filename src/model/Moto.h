#ifndef INC_20232_TEAM_14_MOTO_H
#define INC_20232_TEAM_14_MOTO_H

#include "Veiculo.h"
#include <string>

namespace model {

    class Moto : public Veiculo {

    private:

        std::string _id;
        bool _capacete;                 //(1)Sim/(2)Não
        bool _carenagem;                //(1)Sim/(2)Não
        bool _bau;                      //(1)Sim/(2)Não
        bool _ferramentas;              //(1)Sim/(2)Não
        int _suspDianteira;             //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        int _suspTraseira;              //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        int _guidao;                    //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        int _sistEletrico;              //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        int _escapamento;               //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        double _diaria_moto;            //preço pago por cada dia que uma moto permanece no patio
        double _reboque_moto;           //preço base cobrado pelo reboque de motos

    public:

        //Construtor Moto.h

        Moto(int os, const std::string &solicitacao, const std::string &funcionario,
             const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
             const std::string &local, const std::string &placa, const std::string &marca, const std::string &modelo,
             int ano, const std::string &cidade, const std::string &chassi, int km, int hodometro,
             const std::string &ocorrencia, const std::string &policial, const std::string &data_apreensao,
             const std::string &horario, const std::string &objetos, const std::string &observacoes, int rodas,
             int retrovisores, bool capacete, bool carenagem, bool bau, bool ferramentas,
             int suspDianteira, int suspTraseira, int guidao, int sistEletrico, int escapamento);

        //autogenerated getters and setters
        const std::string &get_id() const;
        bool get_capacete() const;
        void set_capacete(bool capacete);
        bool get_carenagem() const;
        void set_carenagem(bool carenagem);
        bool get_bau() const;
        void set_bau(bool bau);
        bool get_ferramentas() const;
        void set_ferramentas(bool ferramentas);
        int get_suspDianteira() const;
        void set_suspDianteira(int suspDianteira);
        int get_suspTraseira() const;
        void set_suspTraseira(int suspTraseira);
        int get_guidao() const;
        void set_guidao(int guidao);
        int get_sistEletrico() const;
        void set_sistEletrico(int sistEletrico);
        int get_escapamento() const;
        void set_escapamento(int escapamento);
        double get_diaria_moto() const;
        void set_diaria_moto(double diaria_moto);
        double get_reboque_moto() const;
        void set_reboque_moto(double reboque_moto);
        //end of autogenerated getters and setters

        virtual double calcOrcamento() override;

    };

}

#endif //INC_20232_TEAM_14_MOTO_H
