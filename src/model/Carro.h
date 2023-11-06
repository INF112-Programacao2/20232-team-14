#ifndef INC_20232_TEAM_14_CARRO_H
#define INC_20232_TEAM_14_CARRO_H

#include "Veiculo.h"

namespace model {

    class Carro  : public Veiculo{
    private:
        double _pHora;
        std::string _id;
        bool _extintor;
        bool _estepe;
        bool _macaco;
        bool _chave_roda;
        bool _triangulo;
        bool _bateria;
        bool _calotas;
        bool _tapetes;
        bool _radio;
        int _portas; //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        int _capo;
        int _painel;
        int _teto;

    public:
        Carro(std::string os, std::string solicitacao, std::string funcionario, std::string placa_reboque, std::string motivo, int estado_veiculo, bool blitz, std::string local, std::string placa, std::string marca, std::string modelo, int ano, std::string cidade, std::string chassi, int km, int hodometro, std::string ocorrencia, std::string policial, std::string data, std::string horario,std::string objetos, std::string obervacoes, int rodas, int retrovisores, double _pHora, std::string _id, bool _extintor, bool _estepe, bool _macaco, bool _chave_roda, bool _triangulo, bool _bateria, bool _calotas, bool _tapetes, bool _radio, int _portas, int _capo, int _painel, int _teto );

        int calculaPreco();
        int get_pHora() const;
        void set_pHora(int _pHora);
        std::string get_id() const;
        void set_id(std::string _id);
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
        bool get_bateria() const;
        void set_bateria(bool _bateria);
        virtual void preenche_checklist(std::string &_checklist);

    };

} // model

#endif //INC_20232_TEAM_14_CARRO_H