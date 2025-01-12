#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include "cadastro.hpp"
#include "modulo_cadastro.hpp"
#include "modulo_jogos.hpp"
#include "validacao_entrada.hpp"


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

        //evita que comando receba char por exemplo
        if (validacao_entrada()) {
            continue; // Volta para o início do loop
        }


        //Opção jogar
        if (comando == 1)
        {
            if(meucadastro.login(jogador1, jogador2, meucadastro)){
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
