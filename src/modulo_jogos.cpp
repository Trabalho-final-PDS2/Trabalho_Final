#include <string>
#include <thread>
#include <chrono>
#include "tictactoe.hpp"
#include "reversi.hpp"
#include "modulo_cadastro.hpp"
#include "validacao_entrada.hpp"

int modulo_jogos(std::string jogador1, std::string jogador2, cadastro &meucadastro){
    std::cout << "\n====================================\n";
    std::cout << "Jogadores encontrados!!!\n";
    std::cout << "Jogador 1: " << jogador1 << "\nJogador 2: " << jogador2 << "\n";
    std::cout << "====================================\n";

    int comando;
    while (comando != 5)
    {
        std::cout << "\n====================================\n";
        std::cout << "Escolha Qual Jogo Deseja: \n";
        std::cout << "1 - Jogo da Velha\n";
        std::cout << "2 - Lig4\n";
        std::cout << "3 - Reversi\n";
        std::cout << "4 - Voltar para o menu inicial\n";
        std::cout << "5 - Sair\n";
        std::cout << "Digite a opção desejada: ";
        std::cin >> comando;
        
        //evita que comando receba char por exemplo
        if (validacao_entrada()) {
            continue; // Volta para o início do loop
        }

        //Jogar jogo da velha
        if (comando == 1)
        {
            game::TicTacToe games;
            int position;
            while (true)
            {
                std::cout << std::endl;
                games.PrintBoard();
                std::cout << std::endl;
                std::cout << "Jogador " << (games.currentPlayer ? jogador1 : jogador2) << ", entre com a posição (0-8): ";
                std::cin >> position;

                //evita que position receba char por exemplo
                if (validacao_entrada()) {
                    continue; // Volta para o início do loop
                }

                // Verifica se a posição é válida
                if (position < 0 || position >= 9)
                {
                    std::cout << std::endl;
                    std::cout << "Posição inválida! Tente novamente.\n";
                    continue;
                }

                // Realiza o movimento
                games.playerMove(position, games.currentPlayer);

                // Verifica o status do jogo
                if (games.CheckWin())
                {   
                    std::cout << std::endl;
                    games.PrintBoard();                                    std::cout << std::endl;
                    std::cout << "Jogador " << (games.currentPlayer ? jogador1 : jogador2) << " venceu!\n";
                    break;
                }
                else if (games.CheckTie())
                {
                    std::cout << std::endl;
                    games.PrintBoard();
                    std::cout << std::endl;
                    std::cout << "Empate!\n";
                    break;
                }
            }
        }

        else if (comando == 2){
            // Lógica para Lig4 (em construção)    
        }

        //Jogar Reversi
        else if (comando == 3){
            reversi Reversi;
            Reversi.JogarReversi(jogador1, jogador2, meucadastro, Reversi);
        }

        //Retorna 1 ao menu anterior, que mantém a execução do programa
        else if (comando == 4){
            return 1;
        }


        //Retorna 3 ao menu anterior, que finaliza o programa
        else if (comando == 5){
        return 3;
        }


        else{
            std::cout << "ERRO: Opção Inválida!!\n";
        }
    }
    return 1;
}
    