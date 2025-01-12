#include <iostream>
#include <thread>

bool validacao_entrada(){
     if (std::cin.fail()) {
        std::cin.clear(); // Limpa o estado de erro do cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta entrada inválida
        std::cout << "Entrada invalida, por favor insira apenas numeros!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return true;
    }
    return false;
}