#include <iostream>
#include <vector>
#include "Cli.h"

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

    void Cli::coletaChecklist(std::unordered_map<std::string, std::string> &dados_veiculo){
        std::cout << "Ordem de servico: ";
        std::cin >> dados_veiculo["OS"];
        std::cout << "Solicitacao: ";
        std::cin >> dados_veiculo["Solicitacao"];
        std::cout << "Funcionario responsavel por registrar o veiculo: ";
        std::cin >> dados_veiculo["Funcionario"];
        std::cout << "Placa do veiculo que realizou o reboque: ";
        std::cin >> dados_veiculo["PlacaReboque"];
        std::cout << "Motivo da apreensao: ";
        std::cin >> dados_veiculo["Motivo"];
        std::cout << "Estado do veiculo no momento de apreensao:\n";
        std::cout << "1 - Ruim\n2 - Regular\n3 - Bom\n";
        std::cin >> dados_veiculo["Estado"];
        std::cout << "Informe se houve blitz (S/N):\n";
        std::cout << "**Responda com 1 em caso afirmativo ou com 0 em caso negativo**\n";
        std::cin >> dados_veiculo["Blitz"];
        std::cout << "Local de apreensao: ";
        std::cin >> dados_veiculo["Local"];
        std::cout << "Placa do veiculo apreendido: ";
        std::cin >> dados_veiculo["Placa"];
        std::cout << "Marca do veiculo apreendido: ";
        std::cin >> dados_veiculo["Marca"];
        std::cout << "Modelo do veiculo apreendido: ";
        std::cin >> dados_veiculo["Modelo"];
        std::cout << "Ano de apreensao do veiculo: ";
        std::cin >> dados_veiculo["Ano"];
        std::cout << "Cidade em que ocorreu a apreensao: ";
        std::cin >> dados_veiculo["Cidade"];
        std::cout << "Chassi do veiculo apreendido: ";
        std::cin >> dados_veiculo["Chassi"];
        std::cout << "Distancia do patio no momento de apreensao: ";
        std::cin >> dados_veiculo["Distancia"];
        std::cout << "Quilometragem do veiculo no momento de apreensao: ";
        std::cin >> dados_veiculo["KM"];
        std::cout << "Ocorrencia registrada: ";
        std::cin >> dados_veiculo["Ocorrencia"];
        std::cout << "Policial responsavel pela apreensao: ";
        std::cin >> dados_veiculo["Policial"];
        std::cout << "Data de apreensao do veiculo: ";
        std::cin >> dados_veiculo["Data"];
        std::cout << "Horario de apreensao: ";
        std::cin >> dados_veiculo["Horario"];
        std::cout << "Objetos que estavam no carro no momento de apreensao: ";
        std::cin >> dados_veiculo["Objetos"];
        std::cout << "Se desejar, acrescente alguma observacao, caso contrario digite 0 para continuar: ";
        std::cin >> dados_veiculo["Obs"];
        std::cout << "Estado das rodas do veiculo no momento de apreensao:\n";
        std::cout << "0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado\n";
        std::cin >> dados_veiculo["EstadoRodas"];
        std::cout << "Estado dos retrovisores do veiculo no momento de apreensao:\n";
        std::cout << "0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado\n";
        std::cin >> dados_veiculo["EstadoRetro"];
    }

    void Cli::coletaChecklistCarro(std::unordered_map<std::string, std::string> &dados_carro) {
        std::cout << "Extintor(S/N):\n";
        std::cin >> dados_carro["Extintor"];
        std::cout << "Estepe(S/N): ";
        std::cin >> dados_carro["Estepe"];
        std::cout << "Macaco (S/N): ";
        std::cin >> dados_carro["Macaco"];
        std::cout << "Chave roda (S/N) : ";
        std::cin >> dados_carro["ChaveRoda"];
        std::cout << "Triangulo (S/N): ";
        std::cin >> dados_carro["Triangulo"];
        std::cout << "Bateria (S/N): ";
        std::cin >> dados_carro["Bateria"];
        std::cout << "Calotas (S/N): ";
        std::cin >> dados_carro["Calotas"];
        std::cout << "Tapetes (S/N): ";
        std::cin >> dados_carro["Tapetes"];
        std::cout << "Radio (S/N): ";
        std::cin >> dados_carro["Radio"];
        std::cout << "Portas: ";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado";
        std::cin >> dados_carro["EstadoPortas"];
        std::cout << "Capo: ";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado";
        std::cin >> dados_carro["EstadoCapo"];
        std::cout << "Painel: ";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado";
        std::cin >> dados_carro["EstadoPainel"];
        std::cout << "Teto: ";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado";
        std::cin >> dados_carro["EstadoTeto"];
    }

    void Cli::coletaChecklistCaminhao(std::unordered_map<std::string, std::string> &dados_caminhao) {
        std::cout << "Carroceria:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_caminhao["EstadoCarroceria"];
        std::cout << "Eixo traseiro(S/N): ";
        std::cin >> dados_caminhao["EixoTras"];
        std::cout << "Cintas(S/N): ";
        std::cin >> dados_caminhao["Cintas"];
        std::cout << "Suspensao da cabine(S/N): ";
        std::cin >> dados_caminhao["SuspensaoC"];
        std::cout << "Extintor(S/N): ";
        std::cin >> dados_caminhao["Extintor"];
        std::cout << "Estepe(S/N): ";
        std::cin >> dados_caminhao["Estepe"];
        std::cout << "Macaco(S/N): ";
        std::cin >> dados_caminhao["Macaco"];
        std::cout << "Chave roda(S/N): ";
        std::cin >> dados_caminhao["ChaveRoda"];
        std::cout << "Triangulo(S/N): ";
        std::cin >> dados_caminhao["Triangulo"];
        std::cout << "Bateria(S/N): ";
        std::cin >> dados_caminhao["Bateria"];
        std::cout << "Calotas(S/N): ";
        std::cin >> dados_caminhao["Calotas"];
        std::cout << "Tapetes(S/N): ";
        std::cin >> dados_caminhao["Tapetes"];
        std::cout << "Radio(S/N): ";
        std::cin >> dados_caminhao["Radio"];
    }

    void Cli::coletaChecklistMoto(std::unordered_map<std::string, std::string> &dados_moto) {
        std::cout << "Capacete(S/N): ";
        std::cin >> dados_moto["Capacete"];
        std::cout << "Carenagem(S/N): ";
        std::cin >> dados_moto["Carenagem"];
        std::cout << "Bau(S/N): ";
        std::cin >> dados_moto["Bau"];
        std::cout << "Ferramentas(S/N): ";
        std::cin >> dados_moto["Ferramentas"];
        std::cout << "Suspensao dianteira:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_moto["SuspensaoD"];
        std::cout << "Suspensao traseira:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_moto["SuspensaoT"];
        std::cout << "Guidao:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_moto["Guidao"];
        std::cout << "Sistema eletrico:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_moto["SistemaE"];
        std::cout << "Escapamento:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_moto["Escapamento"];
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

