#include <iostream>
#include "cadastro.hpp"
#include "tictactoe.hpp"
#include "reversi.hpp"
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
        std::cout << " " << std::endl;
        std::cout << "====================================" << std::endl;
        std::cout << "Bem vindo ao Tabuleiro de Jogos" << std::endl;
        std::cout << "====================================" << std::endl;
        std::cout << "1 - Jogar" << std::endl;
        std::cout << "2 - Menu de Cadastros" << std::endl;
        std::cout << "3 - Sair" << std::endl;
        std::cout << "====================================" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "Digite a opção desejada: ";
        std::cin >> contador;

        if (contador == 1)
        {
            std::cout << " " << std::endl;
            std::cout << "====================================" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "Digite o apelido do Jogador 1: ";

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            getline(std::cin, jogador1);
            int indice1 = meucadastro.VerificaApelido(jogador1);

            if (indice1 == -1)
            {
                std::cout << "ERRO: Apelido: '" << jogador1 << "' não encontrado. Tente Novamente!!" << std::endl;
            }
            else
            {
                std::cout << " " << std::endl;
                std::cout << "Digite o apelido do Jogador 2: ";
                getline(std::cin, jogador2);

                int indice2 = meucadastro.VerificaApelido(jogador2);
                if (indice2 == -1)
                {
                    std::cout << "ERRO: Apelido: '" << jogador2 << "' não encontrado. Tente Novamente!!" << std::endl;
                }
                else
                {
                    std::cout << "====================================" << std::endl;
                    std::cout << " " << std::endl;
                    std::cout << "Jogadores encontrados!!!" << std::endl;
                    std::cout << "Jogador 1: " << jogador1 << std::endl << "Jogador 2: " << jogador2 << std::endl;
                    std::cout << " " << std::endl;

                    while (contador != 5)
                    {
                        std::cout << "====================================" << std::endl;
                        std::cout << " " << std::endl;
                        std::cout << "Escolha Qual Jogo Deseja : " << std::endl;
                        std::cout << "1 - Jogo da Velha" << std::endl;
                        std::cout << "2 - Lig4" << std::endl;
                        std::cout << "3 - Reversi" << std::endl;
                        std::cout << "4 - Voltar para o menu inicial" << std::endl;
                        std::cout << "5 - Sair" << std::endl;
                        std::cout << "Digite a opção desejada: ";
                        std::cin >> contador2;

                        if (contador2 == 1)
                        { // Logica Jogo da Velha
                            game::TicTacToe games;

                            int position;
                            while (true)
                            {
                                games.PrintBoard();
                                std::cout << "Jogador " << (games.currentPlayer ? 1 : 2) << ", enter a position (0-8): ";
                                std::cin >> position;

                                games.playerMove(position, games.currentPlayer);
                                games.CheckGameStatus();

                                // Se o jogo terminou, saia
                                if (games.CheckWin() || games.CheckTie())
                                {
                                    break;
                                }
                            }
                        }
                        else if (contador2 == 2)
                        {     
                        }
                        else if (contador2 == 3)
                        {
                            reversi Reversi;
                            int position;
                            Reversi.Inicio();
                            while(true){
                                if(Reversi.CanIPlay()){
                                    Reversi.PrintBoard();
                                    std::cout << "Jogador " << (Reversi.currentPlayer ? 1 : 2) << ", esolha entre as casas vermelhas (11-88): " << std::endl;
                                    std::cout << "Jogador 1: " << Reversi.Score(1) << " - Jogador 2: " << Reversi.Score(2) << std::endl;
                                    std::cin >> position;
                                    if(Reversi.isValidAll(Reversi.BoardToVector(position))){
                                        Reversi.playerMove(position, Reversi.currentPlayer);
                                        Reversi.CheckGameStatus();
                                    }
                                    else{
                                        std::cout << "Jogada invalida, siga os numeros vermelhos" << std::endl;
                                        std::this_thread::sleep_for(std::chrono::seconds(2));
                                    }
                                }
                                else{
                                    Reversi.CheckGameStatus();
                                }
                                if(Reversi.CheckTie()){
                                    break;
                                }
                            }
                            if(Reversi.CheckWin()){
                                std::cout << "PARABENS!!! " << meucadastro.Apelido(indice1) << " voce venceu" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                meucadastro.SetVD(indice1,3);
                                meucadastro.SetVD(indice2,-3);
                            }
                            else{
                                std::cout << "PARABENS!!! " << meucadastro.Apelido(indice2) << " voce venceu" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                meucadastro.SetVD(indice1,-3);
                                meucadastro.SetVD(indice2,3);
                            }
                        }
                        else if (contador2 == 4)
                        { 
                            contador = 1;
                            break;
                        }
                        else if (contador2 == 5)
                        { // Sair
                            return 0;
                        }
                        else
                        {
                            std::cout << "ERRO: Opção Inválida!!" << std::endl;
                        }
                    }
                } // fim da checagem de jogador, so entra nessa etapa jogadores validos e ja checados no sistema de cadastro

            } // começo da checagem de jogador, se nao for encontrado, volta para o inicio

        } // fim da opção 1

        if (contador == 2)
        {
           contador = modulo_cadastro(meucadastro);
        } // fim da opção 2
        if (contador == 3)
        {
            std::cout << "Obrigado por Jogar, até mais!!! " << std::endl;
            return 0;
        }
        else if (contador != 1)
        {
            std::cout << "ERRO: Opção Inválida!!" << std::endl;
        }
    } // fim do while

    return 0;
}