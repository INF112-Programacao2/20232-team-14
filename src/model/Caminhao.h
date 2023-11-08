
#ifndef INC_20232_TEAM_14_CAMINHAO_H
#define INC_20232_TEAM_14_CAMINHAO_H

#include "Veiculo.h"
#include <string>
#include <vector>

namespace model {

    class Caminhao  : public Veiculo {

    private:

        std::string _id;
        int _carroceria;
        bool _eixoTraseiro;
        bool _cintas;
        int _suspCabine;
        bool _extintor;
        bool _estepe;
        bool _macaco;
        bool _chave_roda;
        bool _triangulo;
        bool _bateria;
        bool _calotas;
        bool _tapetes;
        bool _radio;

    public:

        //constructor Caminhão
        Caminhao(std::string os, std::string solicitacao, std::string funcionario, std::string placa_reboque, std::string motivo, int estado_veiculo, bool blitz, std::string local, std::string placa, std::string marca, std::string modelo, int ano, std::string cidade, std::string chassi, int km, int hodometro, std::string ocorrencia, std::string policial, std::string data, std::string horario,std::string objetos, std::string observacoes, int rodas, int retrovisores, std::vector<std::string> &_checklist);

        //autogenerated getters and setters
        const std::string &get_id() const;
        void set_id(const std::string &id);
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
        //end of autogenerated getters and setters

        //String to bool
        virtual bool stob(const std::string& str);

    };

}

#endif //INC_20232_TEAM_14_CAMINHAO_H
