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

    void Cli::coletaChecklist(std::vector<std::string> &dados_veiculo){
        std::cout << "Ordem de servico: ";
        std::cin >> dados_veiculo[0];
        std::cout << "Solicitacao: ";
        std::cin >> dados_veiculo[1];
        std::cout << "Funcionario responsavel por registrar o veiculo: ";
        std::cin >> dados_veiculo[2];
        std::cout << "Placa do veiculo que realizou o reboque: ";
        std::cin >> dados_veiculo[3];
        std::cout << "Motivo da apreensao: ";
        std::cin >> dados_veiculo[4];
        std::cout << "Estado do veiculo no momento de apreensao:\n";
        std::cout << "1 - Ruim\n2 - Regular\n3 - Bom\n";
        std::cin >> dados_veiculo[5];
        std::cout << "Informe se houve blitz (S/N):\n";
        std::cout << "**Responda com 1 em caso afirmativo ou com 0 em caso negativo**\n";
        std::cin >> dados_veiculo[6];
        std::cout << "Local de apreensao: ";
        std::cin >> dados_veiculo[7];
        std::cout << "Placa do veiculo apreendido: ";
        std::cin >> dados_veiculo[8];
        std::cout << "Marca do veiculo apreendido: ";
        std::cin >> dados_veiculo[9];
        std::cout << "Modelo do veiculo apreendido: ";
        std::cin >> dados_veiculo[10];
        std::cout << "Ano de apreensao do veiculo: ";
        std::cin >> dados_veiculo[11];
        std::cout << "Cidade em que ocorreu a apreensao: ";
        std::cin >> dados_veiculo[12];
        std::cout << "Chassi do veiculo apreendido: ";
        std::cin >> dados_veiculo[13];
        std::cout << "Distancia do patio no momento de apreensao: ";
        std::cin >> dados_veiculo[14];
        std::cout << "Quilometragem do veiculo no momento de apreensao: ";
        std::cin >> dados_veiculo[15];
        std::cout << "Ocorrencia registrada: ";
        std::cin >> dados_veiculo[16];
        std::cout << "Policial responsavel pela apreensao: ";
        std::cin >> dados_veiculo[17];
        std::cout << "Data de apreensao do veiculo: ";
        std::cin >> dados_veiculo[18];
        std::cout << "Horario de apreensao: ";
        std::cin >> dados_veiculo[19];
        std::cout << "Objetos que estavam no carro no momento de apreensao: ";
        std::cin >> dados_veiculo[20];
        std::cout << "Se desejar, acrescente alguma observacao, caso contrario digite 0 para continuar: ";
        std::cin >> dados_veiculo[21];
        std::cout << "Estado das rodas do veiculo no momento de apreensao:\n";
        std::cout << "0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado\n";
        std::cin >> dados_veiculo[22];
        std::cout << "Estado dos retrovisores do veiculo no momento de apreensao:\n";
        std::cout << "0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado\n";
        std::cin >> dados_veiculo[23];
    }

    void Cli::coletaChecklistCarro(std::vector<std::string> &dados_carro) {
        std::cout << "Extintor(S/N):\n";
        std::cin >> dados_carro[0];
        std::cout << "Estepe(S/N): ";
        std::cin >> dados_carro[1];
        std::cout << "Macaco (S/N): ";
        std::cin >> dados_carro[2];
        std::cout << "Chave roda (S/N) : ";
        std::cin >> dados_carro[3];
        std::cout << "Triangulo (S/N): ";
        std::cin >> dados_carro[4];
        std::cout << "Bateria (S/N): ";
        std::cin >> dados_carro[5];
        std::cout << "Calotas (S/N): ";
        std::cin >> dados_carro[6];
        std::cout << "Tapetes (S/N): ";
        std::cin >> dados_carro[7];
        std::cout << "Radio (S/N): ";
        std::cin >> dados_carro[8];
        std::cout << "Portas: ";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado";
        std::cin >> dados_carro[9];
        std::cout << "Capo: ";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado";
        std::cin >> dados_carro[10];
        std::cout << "Painel: ";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado";
        std::cin >> dados_carro[11];
        std::cout << "Teto: ";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado";
        std::cin >> dados_carro[12];
    }

    void Cli::coletaChecklistCaminhao(std::vector<std::string> &dados_caminhao) {
        std::cout << "Carroceria:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_caminhao[0];
        std::cout << "Eixo traseiro(S/N): ";
        std::cin >> dados_caminhao[1];
        std::cout << "Cintas(S/N): ";
        std::cin >> dados_caminhao[2];
        std::cout << "Suspensao da cabine(S/N): ";
        std::cin >> dados_caminhao[3];
        std::cout << "Extintor(S/N): ";
        std::cin >> dados_caminhao[4];
        std::cout << "Estepe(S/N): ";
        std::cin >> dados_caminhao[5];
        std::cout << "Macaco(S/N): ";
        std::cin >> dados_caminhao[6];
        std::cout << "Chave roda(S/N): ";
        std::cin >> dados_caminhao[7];
        std::cout << "Triangulo(S/N): ";
        std::cin >> dados_caminhao[8];
        std::cout << "Bateria(S/N): ";
        std::cin >> dados_caminhao[9];
        std::cout << "Calotas(S/N): ";
        std::cin >> dados_caminhao[10];
        std::cout << "Tapetes(S/N): ";
        std::cin >> dados_caminhao[11];
        std::cout << "Radio(S/N): ";
        std::cin >> dados_caminhao[12];
    }

    void Cli::coletaChecklistMoto(std::vector<std::string> &dados_moto) {
        std::cout << "Taxa de reboque: ";
        std::cin >> dados_moto[0];
        std::cout << "Taxa diaria: ";
        std::cin >> dados_moto[1];
        std::cout << "Capacete(S/N): ";
        std::cin >> dados_moto[2];
        std::cout << "Carenagem(S/N): ";
        std::cin >> dados_moto[3];
        std::cout << "Bau(S/N): ";
        std::cin >> dados_moto[4];
        std::cout << "Ferramentas(S/N): ";
        std::cin >> dados_moto[5];
        std::cout << "Suspensao dianteira:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_moto[6];
        std::cout << "Suspensao traseira:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_moto[7];
        std::cout << "Guidao:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_moto[8];
        std::cout << "Sistema eletrico:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_moto[9];
        std::cout << "Escapamento:\n";
        std::cout << "(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado\n";
        std::cin >> dados_moto[10];
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

