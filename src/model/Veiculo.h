#ifndef INC_20232_TEAM_14_VEICULO_H
#define INC_20232_TEAM_14_VEICULO_H
#include <string>
#include "SqliteHook.h"

namespace model {

    class Veiculo{

    protected:

        int _os;                                //Ordem de serviço
        int _id_patio;                          //ID Patio
        bool _sit_veiculo;                      //Situacao do veiculo: true - apreendido, false - liberado
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
        std::string _data_liberacao;            //Data de Liberação (enviada somente depois, não consta no construtor)
        std::string _horario;                   //Horário de Apreensão
        std::string _objetos;                   //Objetos que estavam dentro do veículo
        std::string _observacoes;               //Observações a mais, se for necessário
        int _rodas;                             //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        int _retrovisores;                      //(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado
        int _tipo;                              //(1)Carro/(2)Moto/(3)Caminhao

    public:

        //Construtor Veiculo.h

        Veiculo(int os, int id_patio, const std::string &solicitacao, const std::string &funcionario,
                const std::string &placaReboque, const std::string &motivo, int estadoVeiculo, bool blitz,
                const std::string &local, const std::string &placa, const std::string &marca, const std::string &modelo,
                int ano, const std::string &cidade, const std::string &chassi, int km, int hodometro,
                const std::string &ocorrencia, const std::string &policial, const std::string &data_apreensao,
                const std::string &horario, const std::string &objetos, const std::string &observacoes, int rodas,
                int retrovisores, int tipo);

        Veiculo(int os);
        Veiculo(std::string placa);

        //autogenerated getters and setters
        int get_os() const;
        void set_os(int os);
        int get_patio_id() const;
        void set_patio_id(int patio_id);
        bool get_sit_veiculo() const;
        void set_sit_veiculo(int sit_veiculo);
        const std::string &get_solicitacao() const;
        void set_solicitacao(const std::string &solicitacao);
        const std::string &get_funcionario() const;
        void set_funcionario(const std::string &funcionario);
        const std::string &get_placa_reboque() const;
        void set_placa_reboque(const std::string &placa_reboque);
        const std::string &get_motivo() const;
        void set_motivo(const std::string &motivo);
        const int &get_estado_veiculo() const;
        void set_estado_veiculo(const int &estado_veiculo);
        const bool &get_blitz() const;
        void set_blitz(const bool &blitz);
        const std::string &get_local() const;
        void set_local(const std::string &local);
        const std::string &get_placa() const;
        void set_placa(const std::string &placa);
        const std::string &get_marca() const;
        void set_marca(const std::string &marca);
        const std::string &get_modelo() const;
        void set_modelo(const std::string &modelo);
        const int &get_ano() const;
        void set_ano(const int &ano);
        const std::string &get_cidade() const;
        void set_cidade(const std::string &cidade);
        const std::string &get_chassi() const;
        void set_chassi(const std::string &chassi);
        const int &get_km() const;
        void set_km(const int &km);
        const int &get_hodometro() const;
        void set_hodometro(const int &hodometro);
        const std::string &get_ocorrencia() const;
        void set_ocorrencia(const std::string &ocorrencia);
        const std::string &get_policial() const;
        void set_policial(const std::string &policial);
        const std::string &get_data_apreensao() const;
        void set_data_apreensao(const std::string &data_apreensao);
        const std::string &get_data_liberacao() const;
        void set_data_liberacao(const std::string &data_liberacao);
        const std::string &get_horario() const;
        void set_horario(const std::string &horario);
        const std::string &get_objetos() const;
        void set_objetos(const std::string &objetos);
        const std::string &get_observacoes() const;
        void set_observacoes(const std::string &observacoes);
        const int &get_rodas() const;
        void set_rodas(const int &rodas);
        const int &get_retrovisores() const;
        void set_retrovisores(const int &retrovisores);
        int get_tipo() const;
        void set_tipo(int tipo);
        //end of autogenerated getters and setters

        //Verificador de Ano Bissexto
        bool anoBissexto(int ano);

        //Calcula os dias entre a data de apreensão e liberação de veículo para realizar o orçamento
        int calcDiasApreensao(std::string data_liberacao_desejado);

        //Realiza o orçamento de um veículo baseado no seu tipo e na quantidade de dias que permaneceu no patio
        //Será sobrescrita pois há variáveis dependentes de cada subclasse
        virtual double calcOrcamento(std::string dia_liberacao_desejado) = 0;

        virtual void veiculoToMap(std::unordered_map<std::string, std::string> &dados_veiculo, std::unordered_map<std::string, std::string> &dados_especificos) = 0;

        virtual void persistVeiculo() = 0; // insert
        virtual void deleteRecord() = 0; // delete
        virtual void recordToVeiculo() = 0; // select
        bool hasRecord();
        void fetchByPlate(); // insert
        virtual ~Veiculo();
    };

} // model

#endif //INC_20232_TEAM_14_VEICULO_H