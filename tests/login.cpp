#include <iostream>
#include "cadastro.hpp"
#include "tictactoe.hpp"
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include "modulo_cadastro.hpp"

int main()
{
    cadastro meucadastro;
    std::string jogador1, jogador2;
    int contador = 0, contador2 = 0;

    while (contador != 3)
    {
        std::cout << "\n====================================\n";
        std::cout << "Bem vindo ao Tabuleiro de Jogos\n";
        std::cout << "====================================\n";
        std::cout << "1 - Jogar\n";
        std::cout << "2 - Menu de Cadastros\n";
        std::cout << "3 - Sair\n";
        std::cout << "====================================\n";
        std::cout << "Digite a opção desejada: ";
        std::cin >> contador;

        if (contador == 1)
        {
            std::cout << "\n====================================\n";
            std::cout << "Digite o apelido do Jogador 1: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(std::cin, jogador1);
            int indice1 = meucadastro.VerificaApelido(jogador1);

            if (indice1 == -1)
            {
                std::cout << "ERRO: Apelido: '" << jogador1 << "' não encontrado. Tente Novamente!!\n";
            }
            else
            {
                std::cout << "\nDigite o apelido do Jogador 2: ";
                getline(std::cin, jogador2);
                int indice2 = meucadastro.VerificaApelido(jogador2);

                if (indice2 == -1)
                {
                    std::cout << "ERRO: Apelido: '" << jogador2 << "' não encontrado. Tente Novamente!!\n";
                }
                else
                {
                    std::cout << "\n====================================\n";
                    std::cout << "Jogadores encontrados!!!\n";
                    std::cout << "Jogador 1: " << jogador1 << "\nJogador 2: " << jogador2 << "\n";
                    std::cout << "====================================\n";

                    while (contador2 != 5)
                    {
                        std::cout << "\n====================================\n";
                        std::cout << "Escolha Qual Jogo Deseja: \n";
                        std::cout << "1 - Jogo da Velha\n";
                        std::cout << "2 - Lig4\n";
                        std::cout << "3 - Reversi\n";
                        std::cout << "4 - Voltar para o menu inicial\n";
                        std::cout << "5 - Sair\n";
                        std::cout << "Digite a opção desejada: ";
                        std::cin >> contador2;

                        if (contador2 == 1)
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
                                    games.PrintBoard();
                                    std::cout << std::endl;
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
                        else if (contador2 == 2)
                        {
                            // Lógica para Lig4 (em construção)
                        }
                        else if (contador2 == 3)
                        {
                            // Lógica para Reversi (em construção)
                        }
                        else if (contador2 == 4)
                        {
                            contador = 1;
                            break;
                        }
                        else if (contador2 == 5)
                        {
                            return 0;
                        }
                        else
                        {
                            std::cout << "ERRO: Opção Inválida!!\n";
                        }
                    }
                }
            }
        }

        if (contador == 2)
        {
            contador = modulo_cadastro(meucadastro); // Chama o cadastro de jogadores
        }
        else if (contador == 3)
        {
            std::cout << "Obrigado por Jogar, até mais!!!\n";
            return 0;
        }
        else
        {
            std::cout << "ERRO: Opção Inválida!!\n";
        }
    }
    return 0;
}
