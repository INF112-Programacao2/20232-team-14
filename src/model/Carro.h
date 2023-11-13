#ifndef INC_20232_TEAM_14_CARRO_H
#define INC_20232_TEAM_14_CARRO_H

#include "Veiculo.h"
#include <string>

namespace model {

    class Carro  : public Veiculo {

    private:

        std::string _id;
        bool _extintor;         //(1)Sim/(2)Não
        bool _estepe;           //(1)Sim/(2)Não
        bool _macaco;           //(1)Sim/(2)Não
        bool _chave_roda;       //(1)Sim/(2)Não
        bool _triangulo;        //(1)Sim/(2)Não
        bool _bateria;          //(1)Sim/(2)Não
        bool _calotas;          //(1)Sim/(2)Não
        bool _tapetes;          //(1)Sim/(2)Não
        bool _radio;            //(1)Sim/(2)Não
        int _portas;            //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        int _capo;              //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        int _painel;            //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        int _teto;              //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado

    public:

        //Construtor Carro.h

        Carro(const std::string &os, const std::string &solicitacao, const std::string &funcionario,
              const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
              const std::string &local, const std::string &placa, const std::string &marca, const std::string &modelo,
              int ano, const std::string &cidade, const std::string &chassi, int km, int hodometro,
              const std::string &ocorrencia, const std::string &policial, const std::string &data,
              const std::string &horario, const std::string &objetos, const std::string &observacoes, int rodas,
              int retrovisores, bool extintor, bool estepe, bool macaco, bool chaveRoda,
              bool triangulo, bool bateria, bool calotas, bool tapetes, bool radio, int portas, int capo, int painel,
              int teto);

        //autogenerated getters and setters
        const std::string &get_id() const;
        bool get_extintor() const;
        void set_extintor(bool _extintor);
        bool get_estepe() const;
        void set_estepe(bool _estepe);
        bool get_macaco() const;
        void set_macaco(bool _macaco);
        bool get_chave_roda() const;
        void set_chave_roda(bool _chave_roda);
        bool get_triangulo() const;
        void set_triangulo(bool _triangulo);
        bool get_bateria() const;
        void set_bateria(bool _bateria);
        bool get_calotas() const;
        void set_calotas(bool _calotas) ;
        bool get_tapetes() const ;
        void set_tapetes(bool _tapetes);
        bool get_radio() const;
        void set_radio(bool _radio);
        int get_portas() const;
        void set_portas(int _portas);
        int get_capo() const;
        void set_capo(int _capo);
        int get_painel() const;
        void set_painel(int _painel);
        int get_teto() const;
        void set_teto(int _teto);
        //end of autogenerated getters and setters

    };

} // model

#endif //INC_20232_TEAM_14_CARRO_H