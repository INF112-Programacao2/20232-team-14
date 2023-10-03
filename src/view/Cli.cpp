#include <iostream>
#include "Cli.h"

namespace view {

    Cli::Cli() = default;

    int Cli::mainMenu() {
        int input;
        std::cout << "1. Criar Novo Carro (nao ta funcionando)" << std::endl;
        std::cout << "2. Alterar Carro" << std::endl;
        std::cout << "3. Calcula Preco do Carro" << std::endl;
        std::cout << "4. OBLITERA CARRO. (nao ta funcionando)" << std::endl;
        std::cout << "0. Encerra Programa" << std::endl;
        std::cin >> input;
        return input;
    }

    int Cli::readInt(){
        int input;
        std::cin >> input;
        return input;
    }

    void Cli::displayInt(int i) {
        std::cout << i << std::endl;
    }
} // view

