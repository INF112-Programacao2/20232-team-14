#ifndef INC_20232_TEAM_14_MOTO_H
#define INC_20232_TEAM_14_MOTO_H

#include "Veiculo.h"
#include <vector>
#include <string>

namespace model {

    class Moto : public Veiculo {

    private:

        std::string _id;
        bool _capacete;
        bool _carenagem;
        bool _bau;
        bool _ferramentas;
        int _suspDianteira;
        int _suspTraseira;
        int _guidao;
        int _sistEletrico;
        int _escapamento;

    public:

        Moto(std::string os, std::string solicitacao, std::string funcionario, std::string placa_reboque, std::string motivo, int estado_veiculo, bool blitz, std::string local, std::string placa, std::string marca, std::string modelo, int ano, std::string cidade, std::string chassi, int km, int hodometro, std::string ocorrencia, std::string policial, std::string data, std::string horario,std::string objetos, std::string observacoes, int rodas, int retrovisores, std::vector<std::string> &_checklist);

        const std::string &getId() const;

        void setId(const std::string &id);

        bool isCapacete() const;

        void setCapacete(bool capacete);

        bool isCarenagem() const;

        void setCarenagem(bool carenagem);

        bool isBau() const;

        void setBau(bool bau);

        bool isFerramentas() const;

        void setFerramentas(bool ferramentas);

        int getSuspDianteira() const;

        void setSuspDianteira(int suspDianteira);

        int getSuspTraseira() const;

        void setSuspTraseira(int suspTraseira);

        int getGuidao() const;

        void setGuidao(int guidao);

        int getSistEletrico() const;

        void setSistEletrico(int sistEletrico);

        int getEscapamento() const;

        void setEscapamento(int escapamento);

        virtual bool stob(const std::string& str);

    };


}

#endif //INC_20232_TEAM_14_MOTO_H
