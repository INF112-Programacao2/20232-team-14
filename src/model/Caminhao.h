#ifndef INC_20232_TEAM_14_CAMINHAO_H
#define INC_20232_TEAM_14_CAMINHAO_H

#include "Veiculo.h"
#include <string>
#include <vector>

namespace model {

    class Caminhao  : public Veiculo {

    private:

        std::string _id;
        int _carroceria;                //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        bool _eixoTraseiro;             //(1)Sim/(2)Não
        bool _cintas;                   //(1)Sim/(2)Não
        int _suspCabine;                //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        bool _extintor;                 //(1)Sim/(2)Não
        bool _estepe;                   //(1)Sim/(2)Não
        bool _macaco;                   //(1)Sim/(2)Não
        bool _chave_roda;               //(1)Sim/(2)Não
        bool _triangulo;                //(1)Sim/(2)Não
        bool _bateria;                  //(1)Sim/(2)Não
        bool _calotas;                  //(1)Sim/(2)Não
        bool _tapetes;                  //(1)Sim/(2)Não
        bool _radio;                    //(1)Sim/(2)Não
        double _diaria_caminhao;        //preço pago por cada dia que um caminhao permanece no patio
        double _reboque_caminhao;       //preço base cobrado pelo reboque de caminhoes

    public:

        //Construtor Caminhao.h

        Caminhao(int os, const std::string &solicitacao, const std::string &funcionario,
                 const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
                 const std::string &local, const std::string &placa, const std::string &marca,
                 const std::string &modelo, int ano, const std::string &cidade, const std::string &chassi, int km,
                 int hodometro, const std::string &ocorrencia, const std::string &policial, const std::string &data_apreensao,
                 const std::string &horario, const std::string &objetos, const std::string &observacoes, int rodas,
                 int retrovisores, int tipo, int carroceria, bool eixoTraseiro, bool cintas, int suspCabine, bool extintor,
                 bool estepe, bool macaco, bool chaveRoda, bool triangulo, bool bateria, bool calotas, bool tapetes, bool radio);

        //autogenerated getters and setters
        const std::string &get_id() const;
        int get_carroceria() const;
        void set_carroceria(int carroceria);
        bool get_eixoTraseiro() const;
        void set_eixoTraseiro(bool eixoTraseiro);
        bool get_cintas() const;
        void set_cintas(bool cintas);
        int get_suspCabine() const;
        void set_suspCabine(int suspCabine);
        bool get_extintor() const;
        void set_extintor(bool extintor);
        bool get_estepe() const;
        void set_estepe(bool estepe);
        bool get_macaco() const;
        void set_macaco(bool macaco);
        bool get_chaveRoda() const;
        void set_chaveRoda(bool chaveRoda);
        bool get_triangulo() const;
        void set_triangulo(bool triangulo);
        bool get_bateria() const;
        void set_bateria(bool bateria);
        bool get_calotas() const;
        void set_calotas(bool calotas);
        bool get_tapetes() const;
        void set_tapetes(bool tapetes);
        bool get_radio() const;
        void set_radio(bool radio);
        double get_diaria_caminhao() const;
        void set_diaria_caminhao(double diaria_caminhao);
        double get_reboque_caminhao() const;
        void set_reboque_caminhao(double reboquecaminhao);
        //end of autogenerated getters and setters
        virtual double calcOrcamento() override;
    };

}

#endif //INC_20232_TEAM_14_CAMINHAO_H
