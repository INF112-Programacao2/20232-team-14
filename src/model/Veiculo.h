#ifndef INC_20232_TEAM_14_VEICULO_H
#define INC_20232_TEAM_14_VEICULO_H
#include <string>
#include "SqliteHook.h"

namespace model {

    class Veiculo : SqliteHook{

    protected:

        int _os;                                //Ordem de serviço
        std::string _solicitacao;               //Quem solicitou a apreensão (PM, PRV, etc...)
        std::string _funcionario;               //Funcionário que realizou a apreensão
        std::string _placa_reboque;             //Placa do veículo do pátio (caminhão ou carro) que realizou a apreensão
        std::string _motivo;                    //(Inf. Trânsito/Crime de Trânsito/Falta de Licenciamento/Etc... -> são vários, o usuário que vai escrever)
        int _estado_veiculo;                    //(1)Ruim/(2)Regular/(3)Bom
        bool _blitz;                            //(1)Sim/(2)Não
        std::string _local;                     //Local de apreensão do veículo
        std::string _placa;                     //Placa do veículo
        std::string _marca;                     //Marca do veículo
        std::string _modelo;                    //Modelo do veículo
        int _ano;                               //Ano de fabricação do veículo
        std::string _cidade;                    //Cidade que consta na placa do veículo
        std::string _chassi;                    //Chassi do veículo
        int _km;                                //Distancia do patio ao local de apreensão do veiculo
        int _hodometro;                         //Quantidade de km que o carro ja percorreu
        std::string _ocorrencia;                //Número da ocorrência da apreensão
        std::string _policial;                  //Policial responsável pela apreensão
        std::string _data_apreensao;            //Data de Apreensão (mandada pro construtor)
        std::string _data_liberacao;            //Data de Apreensão (eniada somente depois, não consta no construtor)
        std::string _horario;                   //Horário de Apreensão
        std::string _objetos;                   //Objetos que estavam dentro do veículo
        std::string _observacoes;               //Observações a mais, se for necessário
        int _rodas;                             //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        int _retrovisores;                      //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado

    public:

        //Construtor Veiculo.h

        Veiculo(int os, const std::string &solicitacao, const std::string &funcionario,
                const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
                const std::string &local, const std::string &placa, const std::string &marca, const std::string &modelo,
                int ano, const std::string &cidade, const std::string &chassi, int km, int hodometro,
                const std::string &ocorrencia, const std::string &policial, const std::string &data_apreensao,
                const std::string &horario, const std::string &objetos, const std::string &observacoes, int rodas,
                int retrovisores);

        //autogenerated getters and setters
        virtual int get_os() const;
        virtual void set_os(int os);
        virtual const std::string &get_solicitacao() const;
        virtual void set_solicitacao(const std::string &solicitacao);
        virtual const std::string &get_funcionario() const;
        virtual void set_funcionario(const std::string &funcionario);
        virtual const std::string &get_placa_reboque() const;
        virtual void set_placa_reboque(const std::string &placa_reboque);
        virtual const std::string &get_motivo() const;
        virtual void set_motivo(const std::string &motivo);
        virtual const int &get_estado_veiculo() const;
        virtual void set_estado_veiculo(const int &estado_veiculo);
        virtual const bool &get_blitz() const;
        virtual void set_blitz(const bool &blitz);
        virtual const std::string &get_local() const;
        virtual void set_local(const std::string &local);
        virtual const std::string &get_placa() const;
        virtual void set_placa(const std::string &placa);
        virtual const std::string &get_marca() const;
        virtual void set_marca(const std::string &marca);
        virtual const std::string &get_modelo() const;
        virtual void set_modelo(const std::string &modelo);
        virtual const int &get_ano() const;
        virtual void set_ano(const int &ano);
        virtual const std::string &get_cidade() const;
        virtual void set_cidade(const std::string &cidade);
        virtual const std::string &get_chassi() const;
        virtual void set_chassi(const std::string &chassi);
        virtual const int &get_km() const;
        virtual void set_km(const int &km);
        virtual const int &get_hodometro() const;
        virtual void set_hodometro(const int &hodometro);
        virtual const std::string &get_ocorrencia() const;
        virtual void set_ocorrencia(const std::string &ocorrencia);
        virtual const std::string &get_policial() const;
        virtual void set_policial(const std::string &policial);
        virtual const std::string &get_data_apreensao() const;
        virtual void set_data_apreensao(const std::string &data_apreensao);
        virtual const std::string &get_data_liberacao() const;
        virtual void set_data_liberacao(const std::string &data_liberacao);
        virtual const std::string &get_horario() const;
        virtual void set_horario(const std::string &horario);
        virtual const std::string &get_objetos() const;
        virtual void set_objetos(const std::string &objetos);
        virtual const std::string &get_observacoes() const;
        virtual void set_observacoes(const std::string &observacoes);
        virtual const int &get_rodas() const;
        virtual void set_rodas(const int &rodas);
        virtual const int &get_retrovisores() const;
        virtual void set_retrovisores(const int &retrovisores);
        //end of autogenerated getters and setters

        //Verificador de Ano Bissexto
        virtual bool anoBissexto(int ano);

        //Calcula os dias entre a data de apreensão e liberação de veículo para realizar o orçamento
        virtual int calcDiasApreensao();

        //Realiza o orçamento de um veículo baseado no seu tipo e na quantidade de dias que permaneceu no patio
        //Será sobrescrita pois há variáveis dependentes de cada subclasse
        virtual double calcOrcamento() = 0;

    };

} // model

#endif //INC_20232_TEAM_14_VEICULO_H