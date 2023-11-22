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

        std::cout << "\n1. Inserir Apreensão (test insert)" << std::endl;
        std::cout << "2. Editar checklist (nao ta funcionando) " << std::endl;
        std::cout << "3. Realizar orçamento (test print/persist)" << std::endl;
        std::cout << "4. Liberar veículo. (nao ta funcionando)" << std::endl;
        std::cout << "5. Consultar veículo. (nao ta funcionando)" << std::endl;
        std::cout << "6. Test Database" << std::endl;
        std::cout << "0. Encerra Programa" << std::endl;
        std::cin >> input;
        std::cin.ignore();
        return input;

    }

    void Cli::leituraCampo(const std::string &label, std::string &field){
        std::cout << label << std::endl;
        std::string input;
        if(!field.empty()){
            std::cout << "Valor atual: " << field << "\nPressione enter para manter o valor atual." << std::endl;
        }
        std::cin.sync();
        std::getline(std::cin, input);
        if(input.empty()){
            if(field.empty()){
                std::cout << "Campo não pode ser vazio!" << std::endl;
                std::cout << label << std::endl;
            }else{
                return;
            }
        }else{
            field = input;
            return;
        }
    }
    void Cli::leituraCampo(const std::string &label, std::string &field, const std::string &regex, const std::string &errorMsg) {
        std::string input;
        std::regex rules(regex);
        if(!field.empty()){
            std::cout << "Valor atual: " << field << "\nPressione enter para manter o valor atual." << std::endl;
        }
        std::cout << label << std::endl;
        while (true){
            std::cin.sync();
            std::getline(std::cin, input);
            if(std::regex_match(input, rules)) {
                field = input;
                return;
            }else if(field.empty()){
                std::cout << errorMsg << std::endl;
                std::cout << label << std::endl;
            }else{
                return;
            }
        }
    }


    void Cli::coletaChecklist(std::unordered_map<std::string, std::string> &dados_veiculo){
        leituraCampo("Ordem de servico: ", dados_veiculo["OS"],"^[0-9]+$","Ordem de servico invalida.");
        leituraCampo("Solicitacao: ", dados_veiculo["Solicitacao"]);
        leituraCampo("Funcionario responsavel por registrar o veiculo: ", dados_veiculo["Funcionario"]);
        leituraCampo("Placa do veiculo que realizou o reboque: ", dados_veiculo["PlacaReboque"], "^[A-Z]{3}-?[0-9][0-9A-Z][0-9][0-9]$", "Placa invalida.");
        leituraCampo("Motivo da apreensao: ", dados_veiculo["Motivo"]);
        leituraCampo("Estado do veiculo no momento de apreensao:\n1 - Ruim\n2 - Regular\n3 - Bom", dados_veiculo["Estado"],"^[123]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e tres.");
        leituraCampo("Informe se houve blitz (S/N): ", dados_veiculo["Blitz"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Local de apreensao: ", dados_veiculo["Local"]);
        leituraCampo("Placa do veiculo apreendido: ", dados_veiculo["Placa"],"^[A-Z]{3}-?[0-9][0-9A-Z][0-9][0-9]$","Placa invalida.");
        leituraCampo("Marca do veiculo apreendido: ", dados_veiculo["Marca"]);
        leituraCampo("Modelo do veiculo apreendido: ", dados_veiculo["Modelo"]);
        leituraCampo("Ano de apreensao do veiculo: ", dados_veiculo["Ano"], "^(19[012][0-9]|20[0-9]{2})$", "Ano invalido");
        leituraCampo("Cidade em que ocorreu a apreensao: ", dados_veiculo["Cidade"]);
        leituraCampo("Chassi do veiculo apreendido: ", dados_veiculo["Chassi"]);
        leituraCampo("Distancia em quilometro do patio no momento de apreensao: ", dados_veiculo["Distancia"], "^[0-9]+$", "Distancia invalida");
        leituraCampo("Quilometragem do veiculo no momento de apreensao: ", dados_veiculo["KM"], "^[0-9]+$", "Quilometragem invalida");
        leituraCampo("Ocorrencia registrada: ", dados_veiculo["Ocorrencia"]);
        leituraCampo("Policial responsavel pela apreensao: ", dados_veiculo["Policial"]);
        leituraCampo("Data de apreensao do veiculo:\nConsidere o formato dd/mm/aaaa", dados_veiculo["Data"]); // TODO: REFAZER ESSE REGEX
        leituraCampo("Horario de apreensao: ", dados_veiculo["Horario"], "^([0-9]|0[0-9]|1[0-9]|2[0-3]):?[0-5][0-9]$", "Horario invalido.");
        leituraCampo("Objetos que estavam no carro no momento de apreensao: ", dados_veiculo["Objetos"]);
        leituraCampo("Se desejar, acrescente alguma observacao", dados_veiculo["Obs"]);
        leituraCampo("Estado das rodas do veiculo no momento de apreensao:\n0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado", dados_veiculo["EstadoRodas"], "^[1234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Estado dos retrovisores do veiculo no momento de apreensao:\n0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado", dados_veiculo["EstadoRetro"], "^[1234]$", "Estado invalido selecionado. deve conter um numero entre um e quatro");
        leituraCampo("Tipo do veículo:\n1-Carro\n2-Moto\n3-Caminhao", dados_veiculo["Tipo"], "^[123]$", "Tipo invalido selecionado. Resposta deve conter um numero entre 1 e 3.");

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
        leituraCampo("Portas:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoPortas"], "^[1234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Capo:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoCapo"], "^[1234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Painel:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoPainel"], "^[1234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Teto:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoTeto"], "^[1234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
    }

    void Cli::coletaChecklistCaminhao(std::unordered_map<std::string, std::string> &dados_caminhao) {
        leituraCampo("Carroceria:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_caminhao["EstadoCarroceria"], "^[1234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Eixo traseiro(S/N): ", dados_caminhao["EixoTras"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Cintas(S/N): ", dados_caminhao["Cintas"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Suspensao da cabine(S/N): ", dados_caminhao["SuspensaoC"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Extintor(S/N): ", dados_caminhao["Extintor"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Estepe(S/N): ", dados_caminhao["Estepe"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Macaco(S/N): ", dados_caminhao["Macaco"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Chave roda(S/N): ", dados_caminhao["ChaveRoda"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Triangulo(S/N): ", dados_caminhao["Triangulo"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Bateria(S/N): ", dados_caminhao["Bateria"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Calotas(S/N): ", dados_caminhao["Calotas"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Tapetes(S/N): ", dados_caminhao["Tapetes"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Radio(S/N): ", dados_caminhao["Radio"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
    }

    void Cli::coletaChecklistMoto(std::unordered_map<std::string, std::string> &dados_moto) {
        leituraCampo("Capacete(S/N): ", dados_moto["Capacete"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Carenagem(S/N): ", dados_moto["Carenagem"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Bau(S/N): ", dados_moto["Bau"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Ferramentas(S/N): ", dados_moto["Ferramentas"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Suspensao dianteira:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["SuspensaoD"], "^[1234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Suspensao traseira:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["SuspensaoT"], "^[1234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Guidao:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["Guidao"], "^[1234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Sistema eletrico:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["SistemaE"], "^[1234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Escapamento:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["Escapamento"], "^[1234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
    }

    int Cli::readOS(){
        std::string os;
        leituraCampo("Ordem de servico: ", os,"^[0-9]+$","Ordem de servico invalida.");
        return stoi(os);
    }
    std::string Cli::readPlate(){
        std::string plate;
        leituraCampo("Placa do veiculo: ", plate,"^[A-Z]{3}-?[0-9][0-9A-Z][0-9][0-9]$","Placa invalida.");
        return plate;
    }

    void Cli::printChecklist(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::cout << "Ordem de servico: " << dados_veiculo["OS"] << std::endl;
        std::cout << "Solicitacao: " << dados_veiculo["Solicitacao"] << std::endl;
        std::cout << "Funcionario responsavel por registrar o veiculo: " << dados_veiculo["Funcionario"] << std::endl;
        std::cout << "Placa do veiculo que realizou o reboque: " << dados_veiculo["PlacaReboque"] << std::endl;
        std::cout << "Motivo da apreensao: " << dados_veiculo["Motivo"] << std::endl;
        std::cout << "Estado do veiculo no momento de apreensao: " << dados_veiculo["Estado"] << std::endl;
        std::cout << "Ocorrencia de Blitz: " << dados_veiculo["Blitz"] << std::endl;
        std::cout << "Local de apreensao: " << dados_veiculo["Local"] << std::endl;
        std::cout << "Placa do veiculo apreendido: " << dados_veiculo["Placa"] << std::endl;
        std::cout << "Marca do veiculo apreendido: " << dados_veiculo["Marca"] << std::endl;
        std::cout << "Modelo do veiculo apreendido: " << dados_veiculo["Modelo"] << std::endl;
        std::cout << "Ano de apreensao do veiculo: " << dados_veiculo["Ano"] << std::endl;
        std::cout << "Cidade em que ocorreu a apreensao: " << dados_veiculo["Cidade"] << std::endl;
        std::cout << "Chassi do veiculo apreendido: " << dados_veiculo["Chassi"] << std::endl;
        std::cout << "Distancia em quilometro do patio no momento de apreensao: " << dados_veiculo["Distancia"] << std::endl;
        std::cout << "Quilometragem do veiculo no momento de apreensao: " << dados_veiculo["KM"] << std::endl;
        std::cout << "Ocorrencia registrada: " << dados_veiculo["Ocorrencia"] << std::endl;
        std::cout << "Policial responsavel pela apreensao: " << dados_veiculo["Policial"] << std::endl;
        std::cout << "Data de apreensao do veiculo: " << dados_veiculo["Data"] << std::endl;
        std::cout << "Horario de apreensao: " << dados_veiculo["Horario"] << std::endl;
        std::cout << "Objetos que estavam no carro no momento de apreensao: " << dados_veiculo["Objetos"] << std::endl;
        std::cout << "Se desejar, acrescente alguma observacao, caso contrario digite 0 para continuar: " << dados_veiculo["Obs"] << std::endl;
        std::cout << "Estado das rodas do veiculo no momento de apreensao: " << dados_veiculo["EstadoRodas"] << std::endl;
        std::cout << "Estado dos retrovisores do veiculo no momento de apreensao: " << dados_veiculo["EstadoRetro"] << std::endl;
        std::cout << "Tipo do veículo: " << dados_veiculo["Tipo"] << std::endl;
    }

    void Cli::printChecklistCarro(std::unordered_map<std::string, std::string> &dados_carro) {
        std::cout << "Extintor: " << dados_carro["Extintor"] << std::endl;
        std::cout << "Estepe: " << dados_carro["Estepe"] << std::endl;
        std::cout << "Macaco: " << dados_carro["Macaco"] << std::endl;
        std::cout << "Chave roda: " << dados_carro["ChaveRoda"] << std::endl;
        std::cout << "Triangulo: " << dados_carro["Triangulo"] << std::endl;
        std::cout << "Bateria: " << dados_carro["Bateria"] << std::endl;
        std::cout <<"Calotas " << dados_carro["Calotas"] << std::endl;
        std::cout <<"Tapetes: " << dados_carro["Tapetes"] << std::endl;
        std::cout << "Radio: " << dados_carro["Radio"] << std::endl;
        std::cout << "Portas: " << dados_carro["EstadoPortas"] << std::endl;
        std::cout << "Capo: " << dados_carro["EstadoCapo"] << std::endl;
        std::cout << "Painel: " << dados_carro["EstadoPainel"] << std::endl;
        std::cout << "Teto: " << dados_carro["EstadoTeto"] << std::endl;
    }

    void Cli::printChecklistCaminhao(std::unordered_map<std::string, std::string> &dados_caminhao) {
        std::cout << "Carroceria: " << dados_caminhao["EstadoCarroceria"] << std::endl;
        std::cout << "Eixo traseiro: " << dados_caminhao["EixoTras"] << std::endl;
        std::cout << "Cintas: " << dados_caminhao["Cintas"] << std::endl;
        std::cout << "Suspensao da cabine: " << dados_caminhao["SuspensaoC"] << std::endl;
        std::cout << "Extintor: " << dados_caminhao["Extintor"] << std::endl;
        std::cout << "Estepe: " << dados_caminhao["Estepe"] << std::endl;
        std::cout << "Macaco: " << dados_caminhao["Macaco"] << std::endl;
        std::cout << "Chave roda: " << dados_caminhao["ChaveRoda"] << std::endl;
        std::cout << "Triangulo: " << dados_caminhao["Triangulo"] << std:: endl;
        std::cout << "Bateria: " << dados_caminhao["Bateria"] << std:: endl;
        std::cout << "Calotas: " << dados_caminhao["Calotas"] << std:: endl;
        std::cout << "Tapetes: " << dados_caminhao["Tapetes"] << std:: endl;
        std::cout << "Radio: " << dados_caminhao["Radio"] << std:: endl;
    }

    void Cli::printChecklistMoto(std::unordered_map<std::string, std::string> &dados_moto) {
        std::cout << "Capacete: " << dados_moto["Capacete"] << std::endl;
        std::cout << "Carenagem: " << dados_moto["Carenagem"] << std::endl;
        std::cout << "Bau: " << dados_moto["Bau"] << std::endl;
        std::cout << "Ferramentas: " << dados_moto["Ferramentas"] << std::endl;
        std::cout << "Suspensao dianteira: " << dados_moto["SuspensaoD"] << std::endl;
        std::cout << "Suspensao traseira: " << dados_moto["SuspensaoT"] << std::endl;
        std::cout << "Guidao: " << dados_moto["Guidao"] << std::endl;
        std::cout << "Sistema eletrico: " << dados_moto["SistemaE"] << std::endl;
        std::cout << "Escapamento: " << dados_moto["Escapamento"] << std::endl;
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

    //mais tarde, para abrir caminho para a implementacao de uma GUI, deveremos implementar chamadas especificas as maneiras diferentes de exibir dados na tela
    //de certa forma, "especificas ao metodo" com o qual elas estao relacionadas
    //displayOutput nao vai ser necessariamente descontinuada, mas teremos outras opcoes para permitir maior intercambiabilidade da view

} // view

