#include <iostream>
#include "cadastro.hpp"
#include "tictactoe.hpp"
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

void menu()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << " " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Bem vindo ao Menu de Cadastro" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "c -> Cadastrar usuário" << std::endl;
    std::cout << "e -> Editar usuário" << std::endl;
    std::cout << "d -> Deletar usuário" << std::endl;
    std::cout << "i -> Imprimir usuários" << std::endl;
    std::cout << "f -> Finalizar" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "Digite a opção desejada: ";
}

int main()
{
    cadastro meucadastro;
    std::string nome, apelido, novoapelido, linha, teste, jogador1, jogador2;
    int contador = 0, contador2 = 0;
    char comando;

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

                    while (contador != 4)
                    {
                        std::cout << "====================================" << std::endl;
                        std::cout << " " << std::endl;
                        std::cout << "Escolha Qual Jogo Deseja : " << std::endl;
                        std::cout << "1 - Jogo da Velha" << std::endl;
                        std::cout << "2 - Lig4" << std::endl;
                        std::cout << "3 - Reversi" << std::endl;
                        std::cout << "4 - Sair" << std::endl;
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
                        if (contador2 == 2)
                        { // Logica Lig4
                        }
                        if (contador2 == 3)
                        { // Logica Reversi
                        }
                        if (contador2 == 4)
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
            menu();
            while (std::cin >> linha)
            {
                std::istringstream input(linha);
                input.get(comando);
                switch (tolower(comando))
                {
                case 'c':
                {
                    getchar();
                    std::cout << "Digite o nome:" << std::endl;
                    getline(std::cin, nome);
                    if (nome.find_first_not_of(" ") == std::string::npos)
                    {
                        std::cout << "Erro: nome nao digitado" << std::endl;
                        break;
                    }
                    std::cout << "Digite o apelido (apenas uma palavra permitida)" << std::endl;
                    getline(std::cin, linha);
                    std::istringstream copia(linha);
                    copia >> apelido;
                    if (apelido.find_first_not_of(" ") == std::string::npos)
                    {
                        std::cout << "Erro: apelido nao digitado" << std::endl;
                        break;
                    }
                    meucadastro.CadastraJogador(nome, apelido);
                    break;
                }

                case 'e':
                {
                    getchar();
                    std::cout << "Apelidos disponiveis para edicao" << std::endl;
                    meucadastro.ExibeApelidos();
                    std::cout << "Digite o apelido para edicao (apenas uma palavra permitida)" << std::endl;
                    getline(std::cin, linha);
                    std::istringstream copia(linha);
                    copia >> apelido;
                    if (apelido.find_first_not_of(" ") == std::string::npos)
                    {
                        std::cout << "Erro: apelido nao digitado" << std::endl;
                        break;
                    }
                    if (meucadastro.VerificaApelido(apelido) == -1)
                    {
                        std::cout << "Erro apelido inexistente" << std::endl;
                        break;
                    }
                    std::cout << "Digite o novo apelido (apenas uma palavra permitida)" << std::endl;
                    getline(std::cin, linha);
                    std::istringstream copia2(linha);
                    copia2 >> novoapelido;
                    if (novoapelido.find_first_not_of(" ") == std::string::npos)
                    {
                        std::cout << "Erro: apelido nao digitado" << std::endl;
                        break;
                    }
                    meucadastro.EditaJogador(apelido, novoapelido);
                    break;
                }

                case 'd':
                {
                    getchar();
                    std::cout << "Apelidos existentes" << std::endl;
                    meucadastro.ExibeApelidos();
                    std::cout << "Digite o apelido para deletar (apenas uma palavra permitida)" << std::endl;
                    getline(std::cin, linha);
                    std::istringstream copia(linha);
                    copia >> apelido;
                    if (apelido.find_first_not_of(" ") == std::string::npos)
                    {
                        std::cout << "Erro: apelido nao digitado" << std::endl;
                        break;
                    }
                    meucadastro.DeletaJogador(apelido);
                    break;
                }

                case 'i':
                {
                    meucadastro.Imprime();
                    break;
                }

                case 'f':
                {
                    return 0;
                }

                default:
                {
                    std::cout << "Erro: comando não existente" << std::endl;
                    break;
                }
                }
                menu();
            }

        } // fim da opção 2
        if (contador == 3)
        {
            std::cout << "Obrigado por Jogar, até mais!!! " << std::endl;
            return 0;
        }
        else
        {
            std::cout << "ERRO: Opção Inválida!!" << std::endl;
        }
    } // fim do while

    return 0;
}