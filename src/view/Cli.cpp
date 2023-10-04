#include <iostream>
#include "Cli.h"

namespace view {

    Cli::Cli() = default;

    int Cli::mainMenu() {
        int input;
        std::cout << "\n1. Criar Novo Carro (nao ta funcionando)" << std::endl;
        std::cout << "2. Alterar Carro" << std::endl;
        std::cout << "3. Calcula Preco do Carro" << std::endl;
        std::cout << "4. OBLITERA CARRO. (nao ta funcionando)" << std::endl;
        std::cout << "0. Encerra Programa" << std::endl;
        std::cin >> input;
        std::cin.ignore(); // preciso fazer uma implementacao mais limpa, mas ignore() limpa o inputstream apos um read
        return input;
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

