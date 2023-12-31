#include <iostream>
#include <vector>
#include <unordered_map>
#include "Cli.h"
#include <regex>
#include "exceptions/abortFunctionException.h"

namespace view {

    //implementacao do construtor
    Cli::Cli() = default;

    //exibicao das operacoes possiveis para o usuario
    int Cli::mainMenu() {

        int input;

        std::cout << "\n1. Inserir Apreensão." << std::endl;
        std::cout << "2. Editar checklist." << std::endl;
        std::cout << "3. Realizar orçamento." << std::endl;
        std::cout << "4. Liberar veículo." << std::endl;
        std::cout << "5. Consultar veículo por OS." << std::endl;
        std::cout << "6. Consultar veículo por Placa." << std::endl;
        std::cout << "7. Mostrar todos os veículos." << std::endl;
        std::cout << "8. Deletar todos os veículos." << std::endl;
        std::cout << "0. Encerra Programa." << std::endl;
        std::cout << "-- Digite 'CANCELA' para interromper qualquer entrada de dados --" << std::endl;
        std::cin >> input;
        std::cin.ignore();
        return input;

    }

    //funcao de leitura de dados
    //imprime a variavel do primeiro parametro e armazena a leitura no segundo
    void Cli::leituraCampo(const std::string &label, std::string &field){
        std::cout << label << std::endl;
        std::string input;
        if(!field.empty()){
            std::cout << "Valor atual: " << field << "\nPressione enter para manter o valor atual." << std::endl;
        }
        while (true){
            std::cin.sync();
            std::getline(std::cin, input);
            if (input == "CANCELA") {
                throw abortFunctionException("Função abortada");
            }
            if (input.empty()) {
                if (field.empty()) {
                    std::cout << "Campo não pode ser vazio!" << std::endl;
                    std::cout << label << std::endl;
                } else {
                    return;
                }
            } else {
                field = input;
                return;
            }
        }
    }

    //sobrecarga de metodo em relacao a funcao anterior
    //com um parametro de regex e outro de mensagem de erro
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
            if(input == "CANCELA"){
                throw abortFunctionException("Função abortada");
            }
            if(input.empty()){
                if(field.empty()){
                    std::cout << errorMsg << std::endl;
                    std::cout << label << std::endl;
                }else{
                    return;
                }
            }else if(std::regex_match(input, rules)){
                field = input;
                return;
            }else{
                std::cout << errorMsg << std::endl;
                std::cout << label << std::endl;
            }
        }
    }

    //coleta dados comuns entre todos os veiculos
    void Cli::coletaChecklist(std::unordered_map<std::string, std::string> &dados_veiculo){
        leituraCampo("Ordem de servico: ", dados_veiculo["OS"],"^[0-9]+$","Ordem de servico invalida. Este campo deve conter apenas numeros.");
        leituraCampo("Solicitacao: ", dados_veiculo["Solicitacao"]);
        leituraCampo("Funcionario responsavel por registrar o veiculo: ", dados_veiculo["Funcionario"]);
        leituraCampo("Placa do veiculo que realizou o reboque: ", dados_veiculo["PlacaReboque"], "^[A-Za-z]{3}-?[0-9][0-9A-Za-z][0-9][0-9]$", "Placa invalida.");
        leituraCampo("Motivo da apreensao: ", dados_veiculo["Motivo"]);
        leituraCampo("Estado do veiculo no momento de apreensao:\n1 - Ruim\n2 - Regular\n3 - Bom", dados_veiculo["Estado"],"^[123]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e tres.");
        leituraCampo("Informe se houve blitz (S/N): ", dados_veiculo["Blitz"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Local de apreensao: ", dados_veiculo["Local"]);
        leituraCampo("Placa do veiculo apreendido: ", dados_veiculo["Placa"],"^[A-Z]{3}-?[0-9][0-9A-Z][0-9][0-9]$","Placa invalida.");
        leituraCampo("Marca do veiculo apreendido: ", dados_veiculo["Marca"]);
        leituraCampo("Modelo do veiculo apreendido: ", dados_veiculo["Modelo"]);
        leituraCampo("Ano de fabricação do veiculo: ", dados_veiculo["Ano"], "^(19[0-9]{2}|20[0-9]{2})$", "Ano invalido.");
        leituraCampo("Cidade em que ocorreu a apreensao: ", dados_veiculo["Cidade"]);
        leituraCampo("Chassi do veiculo apreendido: ", dados_veiculo["Chassi"]);
        leituraCampo("Distancia em quilometro do patio no momento de apreensao: ", dados_veiculo["Distancia"], "^[0-9]+$", "Distancia invalida. Este campo deve conter apenas numeros.");
        leituraCampo("Quilometragem do veiculo no momento de apreensao: ", dados_veiculo["KM"], "^[0-9]+$", "Quilometragem invalida. Este campo deve conter apenas numeros.");
        leituraCampo("Ocorrencia registrada: ", dados_veiculo["Ocorrencia"]);
        leituraCampo("Policial responsavel pela apreensao: ", dados_veiculo["Policial"]);
        leituraCampo("Data de apreensao do veiculo:\nConsidere o formato dd/mm/aaaa", dados_veiculo["Data"], "^(0?[1-9]|[12][0-9]|3[01])[\\/](0?[1-9]|1[012])[\\/](19[0-9]{2}|20[0-9]{2})$", "Formato de data invalida.");
        leituraCampo("Horario de apreensao:", dados_veiculo["Horario"], "^([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$", "Horario invalido.");
        leituraCampo("Objetos que estavam no carro no momento de apreensao: ", dados_veiculo["Objetos"]);
        leituraCampo("Observacao (se nao houver, pressione 'N'): ", dados_veiculo["Obs"]);
        leituraCampo("Estado das rodas do veiculo no momento de apreensao:\n0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado", dados_veiculo["EstadoRodas"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Estado dos retrovisores do veiculo no momento de apreensao:\n0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado", dados_veiculo["EstadoRetro"], "^[01234]$", "Estado invalido selecionado. deve conter um numero entre um e quatro");
        if(dados_veiculo["Tipo"].empty())
            leituraCampo("Tipo do veículo:\n1-Carro\n2-Moto\n3-Caminhao", dados_veiculo["Tipo"], "^[123]$", "Tipo invalido selecionado. Resposta deve conter um numero entre 1 e 3.");
    }

    //coleta dados especificos de carro
    void Cli::coletaChecklistCarro(std::unordered_map<std::string, std::string> &dados_carro) {
        leituraCampo("Extintor(S/N):", dados_carro["Extintor"], "^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Estepe(S/N): ", dados_carro["Estepe"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Macaco (S/N): ", dados_carro["Macaco"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Chave roda (S/N): ", dados_carro["ChaveRoda"], "^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Triangulo (S/N): ", dados_carro["Triangulo"], "^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Bateria (S/N): ", dados_carro["Bateria"], "^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Calotas (S/N): ", dados_carro["Calotas"], "^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Tapetes (S/N): ", dados_carro["Tapetes"], "^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Radio (S/N): ", dados_carro["Radio"], "^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Portas:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoPortas"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Capo:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoCapo"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Painel:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoPainel"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Teto:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoTeto"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
    }

    //coleta dados especificos de caminhhao
    void Cli::coletaChecklistCaminhao(std::unordered_map<std::string, std::string> &dados_caminhao) {
        leituraCampo("Carroceria:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_caminhao["EstadoCarroceria"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Eixo traseiro(S/N): ", dados_caminhao["EixoTras"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Cintas(S/N): ", dados_caminhao["Cintas"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Suspensao da cabine:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_caminhao["SuspensaoC"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
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

    //coleta dados especificos de moto
    void Cli::coletaChecklistMoto(std::unordered_map<std::string, std::string> &dados_moto) {
        leituraCampo("Capacete(S/N): ", dados_moto["Capacete"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Carenagem(S/N): ", dados_moto["Carenagem"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Bau(S/N): ", dados_moto["Bau"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Ferramentas(S/N): ", dados_moto["Ferramentas"],"^[SNsn]$","Resposta deve conter 'S' ou 'N'.");
        leituraCampo("Suspensao dianteira:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["SuspensaoD"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Suspensao traseira:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["SuspensaoT"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Guidao:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["Guidao"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Sistema eletrico:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["SistemaE"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Escapamento:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_moto["Escapamento"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
    }

    //le OS
    std::string Cli::readOS(){
        std::string os;
        leituraCampo("Informe a ordem de servico: ", os,"^[0-9]+$","Ordem de servico invalida.");
        return os;
    }

    //informa que a OS ja foi cadastrada previamente
    std::string Cli::osAlreadyExistsError(){
        std::string os;
        leituraCampo("A OS previamente informada ja esta em uso! Informe outra: ", os,"^[0-9]+$","Ordem de servico invalida.");
        return os;
    }

    //informa que a busca nao encontrou a OS
    void Cli::osNotFound(){
        std::cout << "A OS não foi encontrada." << std::endl;
    }

    //le placa
    std::string Cli::readPlate(){
        std::string plate;
        leituraCampo("Informe a placa do veiculo: ", plate,"^[A-Z]{3}-?[0-9][0-9A-Z][0-9][0-9]$","Placa invalida.");
        return plate;
    }

    //imprime dados do checklist comum entre todos os veiculos
    void Cli::printChecklist(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::cout << "Ordem de servico: " << dados_veiculo["OS"] << std::endl;
        std::cout << "Solicitacao: " << dados_veiculo["Solicitacao"] << std::endl;

        std::cout << "Situação do veículo: " << std::endl;
        if (std::stoi(dados_veiculo["Situacao"])==1)
            std::cout << "Apreendido\n";
        else if (std::stoi(dados_veiculo["Situacao"])==0)
            std::cout << "Liberado\n";

        std::cout << "Funcionario responsavel por registrar o veiculo: " << dados_veiculo["Funcionario"] << std::endl;
        std::cout << "Placa do veiculo que realizou o reboque: " << dados_veiculo["PlacaReboque"] << std::endl;
        std::cout << "Motivo da apreensao: " << dados_veiculo["Motivo"] << std::endl;

        std::cout << "Estado do veiculo no momento de apreensao: ";
        if (std::stoi(dados_veiculo["Estado"])==1)
            std::cout << "Ruim\n";
        else if (std::stoi(dados_veiculo["Estado"])==2)
            std::cout << "Regular\n";
        else
            std::cout << "Bom\n";

        std::cout << "Ocorrencia de blitz: ";
        if(std::stoi(dados_veiculo["Blitz"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }

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
        if (!dados_veiculo["DataLib"].empty()) {
            std::cout << "Data de liberacao do veiculo: " << dados_veiculo["DataLib"] << std::endl;
        }
        std::cout << "Horario de apreensao: " << dados_veiculo["Horario"] << std::endl;
        std::cout << "Objetos que estavam no carro no momento de apreensao: " << dados_veiculo["Objetos"] << std::endl;

        if (dados_veiculo["Obs"]!="N" && dados_veiculo["Obs"]!="n" ) {
            std::cout << "Observacao: " << dados_veiculo["Obs"] << std::endl;
        }

        std::cout << "Estado das rodas do veiculo no momento de apreensao: ";
        if (std::stoi(dados_veiculo["EstadoRodas"])==0)
            std::cout << "Inexistente\n";
        else if (std::stoi(dados_veiculo["EstadoRodas"])==1)
            std::cout << "Amassado\n";
        else if (std::stoi(dados_veiculo["EstadoRodas"])==2)
            std::cout << "Riscado\n";
        else if (std::stoi(dados_veiculo["EstadoRodas"])==3)
            std::cout << "Quebrado\n";
        else
            std::cout << "Bom estado\n";

        std::cout << "Estado dos retrovisores do veiculo no momento de apreensao: ";
        if (std::stoi(dados_veiculo["EstadoRetro"])==0)
            std::cout << "Inexistente\n";
        else if (std::stoi(dados_veiculo["EstadoRetro"])==1)
            std::cout << "Amassado\n";
        else if (std::stoi(dados_veiculo["EstadoRetro"])==2)
            std::cout << "Riscado\n";
        else if (std::stoi(dados_veiculo["EstadoRetro"])==3)
            std::cout << "Quebrado\n";
        else
            std::cout << "Bom estado\n";
    }

    //imprime dados especificos de carro
    void Cli::printChecklistCarro(std::unordered_map<std::string, std::string> &dados_carro) {

        std::cout << "Extintor: ";
        if(std::stoi(dados_carro["Extintor"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }

        std::cout << "Estepe: ";
        if(std::stoi(dados_carro["Estepe"]) ==1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Macaco: ";
        if(std::stoi(dados_carro["Macaco"]) ==1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Chave roda: ";
        if(std::stoi(dados_carro["ChaveRoda"]) ==1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Triângulo: ";
        if(std::stoi(dados_carro["Triangulo"]) ==1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Bateria: ";
        if(std::stoi(dados_carro["Bateria"]) ==1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Calotas: ";
        if(std::stoi(dados_carro["Calotas"]) ==1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Tapetes: ";
        if(std::stoi(dados_carro["Tapetes"]) ==1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Rádio: ";
        if(std::stoi(dados_carro["Radio"]) ==1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Portas: ";
        if(std::stoi(dados_carro["EstadoPortas"]) ==0) {
            std::cout << "Inexistente" << std::endl;
        } else if (std::stoi(dados_carro["EstadoPortas"]) ==1) {
            std::cout << "Amassado" << std::endl;
        }else if (std::stoi(dados_carro["EstadoPortas"]) == 2) {
            std::cout << "Riscado" << std::endl;
        }else if (std::stoi(dados_carro["EstadoPortas"]) ==3) {
            std::cout << "Quebrado" << std::endl;
        }else{
            std::cout << "Bom estado" << std::endl;
        }

        std::cout << "Capô: ";
        if(std::stoi(dados_carro["EstadoCapo"]) == 0) {
            std::cout << "Inexistente" << std::endl;
        } else if (std::stoi(dados_carro["EstadoCapo"]) == 1) {
            std::cout << "Amassado" << std::endl;
        } else if (std::stoi(dados_carro["EstadoCapo"]) == 2) {
            std::cout << "Riscado" << std::endl;
        } else if (std::stoi(dados_carro["EstadoCapo"]) == 3) {
            std::cout << "Quebrado" << std::endl;
        } else {
            std::cout << "Bom estado" << std::endl;
        }

        std::cout << "Painel: ";
        if(std::stoi(dados_carro["EstadoPainel"]) == 0) {
            std::cout << "Inexistente" << std::endl;
        } else if (std::stoi(dados_carro["EstadoPainel"]) == 1) {
            std::cout << "Amassado" << std::endl;
        } else if (std::stoi(dados_carro["EstadoPainel"]) == 2) {
            std::cout << "Riscado" << std::endl;
        } else if (std::stoi(dados_carro["EstadoPainel"]) == 3) {
            std::cout << "Quebrado" << std::endl;
        } else {
            std::cout << "Bom estado" << std::endl;
        }

        std::cout << "Teto: ";
        if(std::stoi(dados_carro["EstadoTeto"]) == 0) {
            std::cout << "Inexistente" << std::endl;
        } else if (std::stoi(dados_carro["EstadoTeto"]) == 1) {
            std::cout << "Amassado" << std::endl;
        } else if (std::stoi(dados_carro["EstadoTeto"]) == 2) {
            std::cout << "Riscado" << std::endl;
        } else if (std::stoi(dados_carro["EstadoTeto"]) == 3) {
            std::cout << "Quebrado" << std::endl;
        } else {
            std::cout << "Bom estado" << std::endl;
        }

    }

    //imprime dados especificos de caminhao
    void Cli::printChecklistCaminhao(std::unordered_map<std::string, std::string> &dados_caminhao) {
        std::cout << "Carroceria: ";
        if(std::stoi(dados_caminhao["EstadoCarroceria"]) == 0 ) {
            std::cout << "Inexistente" << std::endl;
        }
        else if (std::stoi(dados_caminhao["EstadoCarroceria"]) == 1) {
            std::cout << "Amassado" << std::endl;
        }
        else if (std::stoi(dados_caminhao["EstadoCarroceria"]) == 2) {
            std::cout << "Riscado" << std::endl;
        }
        else if (std::stoi(dados_caminhao["EstadoCarroceria"]) == 3) {
            std::cout << "Quebrado" << std::endl;
        }
        else if (std::stoi(dados_caminhao["EstadoCarroceria"]) == 4) {
            std::cout << "Carroceria: " << "Bom estado" << std::endl;
        }
        std::cout << "Eixo traseiro: ";
        if(std::stoi(dados_caminhao["EixoTras"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }
        std::cout << "Cinta: ";
        if(std::stoi(dados_caminhao["Cintas"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }
        std::cout << "Suspensao da Cabine: ";
        if(std::stoi(dados_caminhao["SuspensaoC"]) ==0) {
            std::cout << "Inexistente" << std::endl;
        } else if (std::stoi(dados_caminhao["SuspensaoC"]) ==1) {
            std::cout << "Amassado" << std::endl;
        }else if (std::stoi(dados_caminhao["SuspensaoC"]) == 2) {
            std::cout << "Riscado" << std::endl;
        }else if (std::stoi(dados_caminhao["SuspensaoC"]) ==3) {
            std::cout << "Quebrado" << std::endl;
        }else{
            std::cout << "Bom estado" << std::endl;
        }
        std::cout << "Extintor: ";
        if(std::stoi(dados_caminhao["Extintor"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }
        std::cout << "Estepe: ";
        if(std::stoi(dados_caminhao["Estepe"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }
        std::cout << "Macaco: ";
        if(std::stoi(dados_caminhao["Macaco"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }
        std::cout << "Chave roda: ";
        if(std::stoi(dados_caminhao["ChaveRoda"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }
        std::cout << "Triangulo: ";
        if(std::stoi(dados_caminhao["Triangulo"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }
        std::cout << "Bateria: ";
        if(std::stoi(dados_caminhao["Bateria"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }
        std::cout << "Calotas: ";
        if(std::stoi(dados_caminhao["Calotas"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }
        std::cout << "Tapetes: ";
        if(std::stoi(dados_caminhao["Tapetes"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }
        std::cout << "Radio: ";
        if(std::stoi(dados_caminhao["Radio"])==1){
            std::cout << "Sim" << std::endl;
        }else{
            std::cout << "Não" << std::endl;
        }
    }

    //imprime dados especificos de moto
    void Cli::printChecklistMoto(std::unordered_map<std::string, std::string> &dados_moto) {

        std::cout << "Capacete: ";
        if(std::stoi(dados_moto["Capacete"]) == 1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Carenagem: ";
        if(std::stoi(dados_moto["Carenagem"]) == 1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Bau: ";
        if(std::stoi(dados_moto["Bau"]) == 1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Ferramentas: ";
        if(std::stoi(dados_moto["Ferramentas"]) == 1) {
            std::cout << "Sim" << std::endl;
        } else {
            std::cout << "Não" << std::endl;
        }

        std::cout << "Suspensão Dianteira: ";
        if(std::stoi(dados_moto["SuspensaoD"]) == 0) {
            std::cout << "Inexistente" << std::endl;
        } else if (std::stoi(dados_moto["SuspensaoD"]) == 1) {
            std::cout << "Amassado" << std::endl;
        } else if (std::stoi(dados_moto["SuspensaoD"]) == 2) {
            std::cout << "Riscado" << std::endl;
        } else if (std::stoi(dados_moto["SuspensaoD"]) == 3) {
            std::cout << "Quebrado" << std::endl;
        } else {
            std::cout << "Bom estado" << std::endl;
        }

        std::cout << "Suspensão traseira: ";
        if (std::stoi(dados_moto["SuspensaoT"]) == 0) {
            std::cout << "Inexistente" << std::endl;
        } else if (std::stoi(dados_moto["SuspensaoT"]) == 1) {
            std::cout << "Amassada" << std::endl;
        } else if (std::stoi(dados_moto["SuspensaoT"]) == 2) {
            std::cout << "Riscada" << std::endl;
        } else if (std::stoi(dados_moto["SuspensaoT"])== 3) {
            std::cout << "Quebrada" << std::endl;
        } else {
            std::cout << "Bom estado" << std::endl;
        }

        std::cout << "Guidao: ";
        if (std::stoi(dados_moto["Guidao"]) == 0) {
            std::cout << "Inexistente" << std::endl;
        } else if (std::stoi(dados_moto["Guidao"]) == 1) {
            std::cout << "Amassado" << std::endl;
        } else if (std::stoi(dados_moto["Guidao"])== 2) {
            std::cout << "Riscado" << std::endl;
        } else if (std::stoi(dados_moto["Guidao"])== 3) {
            std::cout << "Quebrado" << std::endl;
        } else {
            std::cout << "Bom estado" << std::endl;
        }

        std::cout << "Sistema eletrico: ";
        if (std::stoi(dados_moto["SistemaE"]) == 0) {
            std::cout << "Inexistente" << std::endl;
        } else if (std::stoi(dados_moto["SistemaE"]) == 1) {
            std::cout << "Amassado" << std::endl;
        } else if (std::stoi(dados_moto["SistemaE"]) == 2) {
            std::cout << "Riscado" << std::endl;
        }else if (std::stoi(dados_moto["SistemaE"]) == 3) {
            std::cout << "Quebrado" << std::endl;
        }else {
            std::cout << "Bom estado" << std::endl;
        }

        std::cout << "Escapamento: ";
        if (std::stoi(dados_moto["Escapamento"]) == 0) {
            std::cout << "Inexistente" << std::endl;
        } else if (std::stoi(dados_moto["Escapamento"]) == 1) {
            std::cout << "Amassado" << std::endl;
        } else if (std::stoi(dados_moto["Escapamento"]) == 2) {
            std::cout << "Riscado" << std::endl;
        }else if (std::stoi(dados_moto["Escapamento"]) == 3) {
            std::cout << "Quebrado" << std::endl;
        }else {
            std::cout << "Bom estado" << std::endl;
        }

    }

    //informa que um veiculo ja foi liberado
    void Cli::veiculoJaLiberadoError(){
        std::cout << "Veiculo ja liberado!" << std::endl;
    }

    //informa que nao ha veiculos cadastrados no sistema
    void Cli::vectorVazioError(){
        std::cout << "Não há veiculos carregados na memória!" << std::endl;
    }

    //informa que a OS fornecida nao foi cadastrada para nenhum veiculo
    void Cli::veiculoNaoExiste(){
        std::cout << "Erro! A OS não está cadastrada no sistema!" << std::endl;
    }

    //imprime mensagem de erro
    void Cli::errorMsg(const std::exception& e) {

        std::cerr << e.what() << std::endl; //what() transforma a excecao em uma string legivel

    }

    //retorna a data de liberacao de um veiculo
    std::string Cli::getDataLiberacao() {

        std::string data_lib;

        //realiza leitura da data de liberacao e verifica se e valida
        leituraCampo("Insira o dia de liberação: ", data_lib, "^(0?[1-9]|[12][0-9]|3[01])[\\/](0?[1-9]|1[012])[\\/]\\d{4}$","Formato de data invalido.");

        return data_lib;

    }

    std::string Cli::getData(){
        std::string data;
        leituraCampo("Insira a data de apreensão: ", data, "^(0?[1-9]|[12][0-9]|3[01])[\\/](0?[1-9]|1[012])[\\/]\\d{4}$", "Formato de data invalido.");
        return data;
    }

    void Cli::dataInvalidaErro(){
        std::cout << "A data informada não pode ser posterior à data atual!" << std::endl;
    }

    void Cli::deLoreanError(){
        std::cout << "A data de liberação não pode ser anterior à data atual!" << std::endl;
    }

    //imprime o valor de orcamento
    void Cli::printOrcamento(double valor) {

        std::cout << "Preço para liberação do veículo: " << valor << "R$" << std::endl;

    }

} // view

