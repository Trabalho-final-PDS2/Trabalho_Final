#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include "cadastro.hpp"
#include "modulo_cadastro.hpp"
#include "modulo_jogos.hpp"


//Recebe dois apelidos e verifica se eles estão cadastrados
bool login(std::string &jogador1, std::string &jogador2, cadastro &meucadastro){
    std::string login1, login2;

    std::cout << "\n====================================\n";
    std::cout << "Digite o apelido do Jogador 1: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, login1);

    int indice1 = meucadastro.VerificaApelido(login1);

    if (indice1 == -1){
        std::cout << "ERRO: Apelido: '" << login1 << "' não encontrado. Tente Novamente!!\n";
        return false;
    }

    else{
        std::cout << "\nDigite o apelido do Jogador 2: ";
        getline(std::cin, login2);

        int indice2 = meucadastro.VerificaApelido(login2);

        if (indice2 == -1){
            std::cout << "ERRO: Apelido: '" << login2 << "' não encontrado. Tente Novamente!!\n";
            return false;
        }
    }

    //Se os dois apelidos existem, atribui aos jogadores e retorna true
    jogador1 = login1;
    jogador2 = login2;
    return true;
}





int main()
{   
    cadastro meucadastro;
    std::string jogador1, jogador2;
    int comando = 0;

    while (comando != 3)
    {
        std::cout << "\n====================================\n";
        std::cout << "Bem vindo ao Tabuleiro de Jogos\n";
        std::cout << "====================================\n";
        std::cout << "1 - Jogar\n";
        std::cout << "2 - Menu de Cadastros\n";
        std::cout << "3 - Sair\n";
        std::cout << "====================================\n";
        std::cout << "Digite a opção desejada: ";
        std::cin >> comando;

        //validação da entrada (evita que comando receba char por exemplo)
        if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro do cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta entrada inválida
                std::cout << "Entrada invalida, por favor insira apenas numeros!" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                continue; // Volta para o início do loop
        }


        //Opção jogar
        if (comando == 1)
        {
            if(login(jogador1, jogador2, meucadastro)){
                comando = modulo_jogos(jogador1, jogador2, meucadastro);
            }
        }


        //Opção cadastro
        else if (comando == 2)
        {
            comando = modulo_cadastro(meucadastro); 
        }


        //Opção sair
        else if (comando == 3)
        {
            std::cout << "Obrigado por Jogar, até mais!!!\n";
            return 0;
        }


        else if (comando != 1)
        {
            std::cout << "ERRO: Opção Inválida!!\n";
        }
    }
    return 0;
}
