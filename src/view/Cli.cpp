#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include "Cli.h"
#include <regex>

namespace view {

    Cli::Cli() = default;

    int Cli::mainMenu() {

        int input;

        std::cout << "\n1. Inserir Apreensão." << std::endl;
        std::cout << "2. Editar checklist." << std::endl;
        std::cout << "3. Realizar orçamento. (WIP)" << std::endl;
        std::cout << "4. Liberar veículo." << std::endl;
        std::cout << "5. Consultar veículo por OS." << std::endl;
        std::cout << "6. Consultar veículo por Placa." << std::endl;
        std::cout << "7. Mostrar todos os veículos." << std::endl;
        std::cout << "8. Deletar todos os veículos." << std::endl;
        std::cout << "0. Encerra Programa." << std::endl;
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
        leituraCampo("Ano de fabricação do veiculo: ", dados_veiculo["Ano"], "^(19[012][0-9]|20[0-9]{2})$", "Ano invalido.");
        leituraCampo("Cidade em que ocorreu a apreensao: ", dados_veiculo["Cidade"]);
        leituraCampo("Chassi do veiculo apreendido: ", dados_veiculo["Chassi"]);
        leituraCampo("Distancia em quilometro do patio no momento de apreensao: ", dados_veiculo["Distancia"], "^[0-9]+$", "Distancia invalida. Este campo deve conter apenas numeros.");
        leituraCampo("Quilometragem do veiculo no momento de apreensao: ", dados_veiculo["KM"], "^[0-9]+$", "Quilometragem invalida. Este campo deve conter apenas numeros.");
        leituraCampo("Ocorrencia registrada: ", dados_veiculo["Ocorrencia"]);
        leituraCampo("Policial responsavel pela apreensao: ", dados_veiculo["Policial"]);
        leituraCampo("Data de apreensao do veiculo:\nConsidere o formato dd/mm/aaaa", dados_veiculo["Data"]); // TODO: REFAZER ESSE REGEX
        leituraCampo("Horario de apreensao:", dados_veiculo["Horario"], "^([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$", "Horario invalido.");
        leituraCampo("Objetos que estavam no carro no momento de apreensao: ", dados_veiculo["Objetos"]);
        leituraCampo("Observacao (se nao houver, pressione 'N'): ", dados_veiculo["Obs"]);
        leituraCampo("Estado das rodas do veiculo no momento de apreensao:\n0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado", dados_veiculo["EstadoRodas"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Estado dos retrovisores do veiculo no momento de apreensao:\n0-inexistente\n1-amassado\n2-riscado\n3-quebrado\n4-bom estado", dados_veiculo["EstadoRetro"], "^[01234]$", "Estado invalido selecionado. deve conter um numero entre um e quatro");
        leituraCampo("Tipo do veículo:\n1-Carro\n2-Moto\n3-Caminhao", dados_veiculo["Tipo"], "^[123]$", "Tipo invalido selecionado. Resposta deve conter um numero entre 1 e 3.");

    }

    void Cli::coletaChecklistCarro(std::unordered_map<std::string, std::string> &dados_carro) {
        leituraCampo("Extintor(S/N):", dados_carro["Extintor"]);
        leituraCampo("Estepe(S/N): ", dados_carro["Estepe"]);
        leituraCampo("Macaco (S/N): ", dados_carro["Macaco"]);
        leituraCampo("Chave roda (S/N): ", dados_carro["ChaveRoda"]);
        leituraCampo("Triangulo (S/N): ", dados_carro["Triangulo"]);
        leituraCampo("Bateria (S/N): ", dados_carro["Bateria"]);
        leituraCampo("Calotas (S/N): ", dados_carro["Calotas"]);
        leituraCampo("Tapetes (S/N): ", dados_carro["Tapetes"]);
        leituraCampo("Radio (S/N): ", dados_carro["Radio"]);
        leituraCampo("Portas:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoPortas"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Capo:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoCapo"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Painel:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoPainel"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
        leituraCampo("Teto:\n(0)Inexistente/(1)Amassado/(2)Riscado/(3)Quebrado/(4)Bom estado", dados_carro["EstadoTeto"], "^[01234]$", "Estado invalido selecionado. Resposta deve conter um numero entre um e quatro");
    }

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

    std::string Cli::readOS(){
        std::string os;
        leituraCampo("Informe a ordem de servico: ", os,"^[0-9]+$","Ordem de servico invalida.");
        return os;
    }

    std::string Cli::osAlreadyExistsError(){
        std::string os;
        leituraCampo("A OS previamente informada ja esta em uso! Informe outra: ", os,"^[0-9]+$","Ordem de servico invalida.");
        return os;
    }

    void Cli::osNotFound(){
        std::cout << "A OS não foi encontrada." << std::endl;
    }

    std::string Cli::readPlate(){
        std::string plate;
        leituraCampo("Informe a placa do veiculo: ", plate,"^[A-Z]{3}-?[0-9][0-9A-Z][0-9][0-9]$","Placa invalida.");
        return plate;
    }

    void Cli::printChecklist(std::unordered_map<std::string, std::string> &dados_veiculo) {
        std::cout << "Ordem de servico: " << dados_veiculo["OS"] << std::endl;
        std::cout << "Solicitacao: " << dados_veiculo["Solicitacao"] << std::endl;
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

    void Cli::veiculoJaLiberadoError(){
        std::cout << "Veiculo ja liberado!" << std::endl;
    }

    void Cli::vectorVazioError(){
        std::cout << "Não há veiculos carregados na memória!" << std::endl;
    }

    void Cli::veiculoNaoExiste(){
        std::cout << "Erro! A OS não está cadastrada no sistema!" << std::endl;
    }

    void Cli::errorMsg(const std::exception& e) {

        std::cerr << "ERRO: "<< e.what() << std::endl; //what() transforma a excecao em uma string legivel

    }

    //Pensei que a data de liberação não é a mesma que a pretensão do usuário liberar
    //As vezes queme sta usando o programa quer apenas calcular orcamento, sem pretensao de liberar o carro de fato
    //nesse caso, o atributo _data_liberacao da classe Veiculo, nao deveria ser mudado, sem que, de fato, o carro seja liberado
    //Essa funcao vai receber a pretensao da data de liberação, e será usada pela funcao CalcDiasApreensao da classe Veiculo

    std::string Cli::getDataLiberacao() {

        std::string data_lib;

        //Não sei configurar para datas específicas, exemplo: Se fosse em um ano bissexto, a data 29/02/(anoBissexto) seria válida, mas se n fosse nao seria
        //Acho que não vai precisar de ser taaaao específico mas vai que ne, por enquanto ta configurado para datas convencionais
        leituraCampo("Insira o dia de liberação: ", data_lib, "^[0-3][0-9]/(0[1-9]|1[0-2])/(20[0-9]{2})$","Data invalida.");

        return data_lib;

    }

    std::string Cli::getIdVehicle() {

        std::string escolha;
        std::string id;
        std::cout << "Insira como a pesquisa será feita [(1) Placa | (2) OS] : " << std::endl;   //TODO: fazer regex pro usuario nao fazer burrada
        //escolha = readUserInput();
        // READ USER INPUT NAO EXISTE NUNCA EXISTIU
        if(stoi(escolha) == 1){

            id = readPlate();

        }else{

            id = readOS();

        }

        return id;

    }

    void Cli::printOrcamento(double valor) {

        std::cout << "Preço para liberação do veículo: " << valor << "R$" << std::endl;

    }

    //mais tarde, para abrir caminho para a implementacao de uma GUI, deveremos implementar chamadas especificas as maneiras diferentes de exibir dados na tela
    //de certa forma, "especificas ao metodo" com o qual elas estao relacionadas
    //displayOutput nao vai ser necessariamente descontinuada, mas teremos outras opcoes para permitir maior intercambiabilidade da view

} // view

