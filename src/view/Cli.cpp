#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include "Cli.h"
#include <regex>

namespace view {

    Cli::Cli() = default;

    int Cli::mainMenu() {

        int input;

        std::cout << "\n1. Inserir Apreensão (nao ta funcionando)" << std::endl;
        std::cout << "2. Editar checklist (nao ta funcionando) " << std::endl;
        std::cout << "3. Realizar orçamento (nao ta funcionando)" << std::endl;
        std::cout << "4. Liberar veículo. (nao ta funcionando)" << std::endl;
        std::cout << "5. Consultar veículo. (nao ta funcionando)" << std::endl;
        std::cout << "6. Test Database" << std::endl;
        std::cout << "0. Encerra Programa" << std::endl;
        std::cin >> input;
        std::cin.ignore(); // preciso fazer uma implementacao mais limpa, mas ignore() limpa o inputstream apos um read

        return input;

    }

    void Cli::leituraCampo(const std::string &label, std::string &field){
        std::cout << label << std::endl;

        std::cin.sync();
        std::getline(std::cin, field);
    }
    void Cli::leituraCampo(const std::string &label, std::string &field, const std::string &regex, const std::string &errorMsg) {
        bool flag = true;
        std::string input;
        std::regex rules(regex);
        std::cout << label << std::endl;

        while (flag){
            std::cin.sync();
            std::getline(std::cin, field);
            if(std::regex_match(field, rules)) {
                flag = false;
            }else{
                std::cout << errorMsg << std::endl;
                std::cout << label << std::endl;
            }
        }

    }




    void Cli::coletaChecklist(std::unordered_map<std::string, std::string> &dados_veiculo){
        leituraCampo("Ordem de servico: ", dados_veiculo["OS"]);
        leituraCampo("Solicitacao: ", dados_veiculo["Solicitacao"]);
        leituraCampo("Funcionario responsavel por registrar o veiculo: ", dados_veiculo["Funcionario"]);
        leituraCampo("Placa do veiculo que realizou o reboque: ", dados_veiculo["PlacaReboque"]);
        leituraCampo("Motivo da apreensao: ", dados_veiculo["Motivo"]);
        leituraCampo("Estado do veiculo no momento de apreensao:\n1 - Ruim\n2 - Regular\n3 - Bom", dados_veiculo["Estado"]);
        leituraCampo("Informe se houve blitz (S/N):\n**Responda com 1 em caso afirmativo ou com 0 em caso negativo**", dados_veiculo["Blitz"]);
        leituraCampo("Local de apreensao: ", dados_veiculo["Local"]);
        leituraCampo("Placa do veiculo apreendido: ", dados_veiculo["Placa"]);
        leituraCampo("Marca do veiculo apreendido: ", dados_veiculo["Marca"]);
        leituraCampo("Modelo do veiculo apreendido: ", dados_veiculo["Modelo"]);
        leituraCampo("Ano de apreensao do veiculo: ", dados_veiculo["Ano"]);
        leituraCampo("Cidade em que ocorreu a apreensao: ", dados_veiculo["Cidade"]);
        leituraCampo("Chassi do veiculo apreendido: ", dados_veiculo["Chassi"]);
        leituraCampo("Distancia do patio no momento de apreensao: ", dados_veiculo["Distancia"]);
        leituraCampo("Quilometragem do veiculo no momento de apreensao: ", dados_veiculo["KM"]);
        leituraCampo("Ocorrencia registrada: ", dados_veiculo["Ocorrencia"]);
        leituraCampo("Policial responsavel pela apreensao: ", dados_veiculo["Policial"]);
        leituraCampo("Data de apreensao do veiculo: ", dados_veiculo["Data"]);
        leituraCampo("Horario de apreensao: ", dados_veiculo["Horario"]);
        leituraCampo("Objetos que estavam no carro no momento de apreensao: ", dados_veiculo["Objetos"]);
        leituraCampo("Se desejar, acrescente alguma observacao, caso contrario digite 0 para continuar: ", dados_veiculo["Obs"]);
        leituraCampo("Estado das rodas do veiculo no momento de apreensao:\n0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado", dados_veiculo["EstadoRodas"]);
        leituraCampo("Estado dos retrovisores do veiculo no momento de apreensao:\n0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado", dados_veiculo["EstadoRetro"]);
    }

    void Cli::coletaChecklistCarro(std::unordered_map<std::string, std::string> &dados_carro) {
        leituraCampo("Extintor(S/N):\n", dados_carro["Extintor"]);
        leituraCampo("Estepe(S/N): ", dados_carro["Estepe"]);
        leituraCampo("Macaco (S/N): ", dados_carro["Macaco"]);
        leituraCampo("Chave roda (S/N) : ", dados_carro["ChaveRoda"]);
        leituraCampo("Triangulo (S/N): ", dados_carro["Triangulo"]);
        leituraCampo("Bateria (S/N): ", dados_carro["Bateria"]);
        leituraCampo("Calotas (S/N): ", dados_carro["Calotas"]);
        leituraCampo("Tapetes (S/N): ", dados_carro["Tapetes"]);
        leituraCampo("Radio (S/N): ", dados_carro["Radio"]);
        leituraCampo("Portas:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoPortas"]);
        leituraCampo("Capo:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoCapo"]);
        leituraCampo("Painel:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoPainel"]);
        leituraCampo("Teto:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoTeto"]);
    }

    void Cli::coletaChecklistCaminhao(std::unordered_map<std::string, std::string> &dados_caminhao) {
        leituraCampo("Carroceria:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_caminhao["EstadoCarroceria"]);
        leituraCampo("Eixo traseiro(S/N): ", dados_caminhao["EixoTras"]);
        leituraCampo("Cintas(S/N): ", dados_caminhao["Cintas"]);
        leituraCampo("Suspensao da cabine(S/N): ", dados_caminhao["SuspensaoC"]);
        leituraCampo("Extintor(S/N): ", dados_caminhao["Extintor"]);
        leituraCampo("Estepe(S/N): ", dados_caminhao["Estepe"]);
        leituraCampo("Macaco(S/N): ", dados_caminhao["Macaco"]);
        leituraCampo("Chave roda(S/N): ", dados_caminhao["ChaveRoda"]);
        leituraCampo("Triangulo(S/N): ", dados_caminhao["Triangulo"]);
        leituraCampo("Bateria(S/N): ", dados_caminhao["Bateria"]);
        leituraCampo("Calotas(S/N): ", dados_caminhao["Calotas"]);
        leituraCampo("Tapetes(S/N): ", dados_caminhao["Tapetes"]);
        leituraCampo("Radio(S/N): ", dados_caminhao["Radio"]);
    }

    void Cli::coletaChecklistMoto(std::unordered_map<std::string, std::string> &dados_moto) {
        leituraCampo("Capacete(S/N): ", dados_moto["Capacete"]);
        leituraCampo("Carenagem(S/N): ", dados_moto["Carenagem"]);
        leituraCampo("Bau(S/N): ", dados_moto["Bau"]);
        leituraCampo("Ferramentas(S/N): ", dados_moto["Ferramentas"]);
        leituraCampo("Suspensao dianteira:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["SuspensaoD"]);
        leituraCampo("Suspensao traseira:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["SuspensaoT"]);
        leituraCampo("Guidao:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["Guidao"]);
        leituraCampo("Sistema eletrico:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["SistemaE"]);
        leituraCampo("Escapamento:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["Escapamento"]);
    }


    std::string Cli::readUserInput(){

        std::string input;
        std::cin.sync(); //necessario usar .sync() por enquanto para limpar o inputstream pro getline (refer to line 16)
        std::getline(std::cin, input);

        return input;

    }

    void Cli::displayOutput(const std::string& output){ //passagem por referencia pois economia de memoria, referencia const pois nao queremos nunca que seja mutavel

        std::cout << output; //toda string que representa fim de linha deve vir acompanhada de \n ao final

    }

    void Cli::errorMsg(const std::exception& e) {

        std::cerr << "ERRO: "<< e.what() << std::endl; //what() transforma a excecao em uma string legivel

    }

    int Cli::recebeTipo() {
        int input;
        std::cout << "\n1. Moto" << std::endl;
        std::cout << "2. Carro" << std::endl;
        std::cout << "3. Caminhao" << std::endl;
        std::cin >> input;
        std::cin.ignore(); // preciso fazer uma implementacao mais limpa, mas ignore() limpa o inputstream apos um read
    }



    //mais tarde, para abrir caminho para a implementacao de uma GUI, deveremos implementar chamadas especificas as maneiras diferentes de exibir dados na tela
    //de certa forma, "especificas ao metodo" com o qual elas estao relacionadas
    //displayOutput nao vai ser necessariamente descontinuada, mas teremos outras opcoes para permitir maior intercambiabilidade da view

} // view

