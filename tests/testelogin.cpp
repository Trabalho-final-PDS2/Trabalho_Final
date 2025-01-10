#include <iostream>
#include "cadastro.hpp"
#include "tictactoe.hpp"
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

void menu(){

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<std::endl;
    std::cout<< "Digite:" <<std::endl;
    std::cout<< "c -> Cadastrar usuário" <<std::endl;
    std::cout<< "e -> Editar usuário" <<std::endl;
    std::cout<< "d -> Deletar usuário" <<std::endl;
    std::cout<< "i -> Imprimir usuários" <<std::endl;
    std::cout<< "f -> Finalizar" <<std::endl;
}

int main(){
    cadastro meucadastro;
    std::string nome, apelido, novoapelido, linha, teste;
    char comando;
    std::cout<< "Deseja abrir o menu de cadastro?" << std::endl;
    getline(std::cin,teste);
    if (teste == "s"){
    menu();
    while(std::cin >> linha){
        std::istringstream input(linha);
        input.get(comando);
        switch (tolower(comando))
        {
        case 'c':{
            getchar();
            std::cout << "Digite o nome:" << std::endl;
            getline(std::cin, nome);
            if(nome.find_first_not_of(" ") == std::string::npos){
                std::cout << "Erro: nome nao digitado" << std::endl;
                break;
            }
            std::cout << "Digite o apelido (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            std::istringstream copia(linha);
            copia >> apelido;
            if(apelido.find_first_not_of(" ") == std::string::npos){
                std::cout << "Erro: apelido nao digitado" << std::endl;
                break;
            }
            meucadastro.CadastraJogador(nome,apelido);
            break;
        }

        case 'e':{
            getchar();
            std::cout << "Apelidos disponiveis para edicao" << std::endl;
            meucadastro.ExibeApelidos();
            std::cout << "Digite o apelido para edicao (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            std::istringstream copia(linha);
            copia >> apelido;
            if(apelido.find_first_not_of(" ") == std::string::npos){
                std::cout << "Erro: apelido nao digitado" << std::endl;
                break;
            }
            if(meucadastro.VerificaApelido(apelido) == -1){
                std::cout << "Erro apelido inexistente" << std::endl;
                break;
            }
            std::cout << "Digite o novo apelido (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            std::istringstream copia2(linha);
            copia2 >> novoapelido;
            if(novoapelido.find_first_not_of(" ") == std::string::npos){
                std::cout << "Erro: apelido nao digitado" << std::endl;
                break;
            }
            meucadastro.EditaJogador(apelido,novoapelido);
            break;
        }

        case 'd':{
            getchar();
            std::cout << "Apelidos existentes" << std::endl;
            meucadastro.ExibeApelidos();
            std::cout << "Digite o apelido para deletar (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            std::istringstream copia(linha);
            copia >> apelido;
            if(apelido.find_first_not_of(" ") == std::string::npos){
                std::cout << "Erro: apelido nao digitado" << std::endl;
                break;
            }
            meucadastro.DeletaJogador(apelido);
            break;
        }

        case 'i':{
            meucadastro.Imprime();
            break;
        }

        case 'f':{
            return 0;
        }

        default:{
            std::cout<< "Erro: comando não existente" <<std::endl;
            break;
        }
        }
        menu();
    }
    }else {
    game::TicTacToe games;

    int position;
    while (true) {
        games.PrintBoard();
        std::cout << "Jogador " << (games.currentPlayer ? 1 : 2) << ", enter a position (0-8): ";
        std::cin >> position;

        games.playerMove(position, games.currentPlayer);
        games.CheckGameStatus();

        // Se o jogo terminou, saia
        if (games.CheckWin() || games.CheckTie()) {
            break;
        }
    }
    }
    return 0;
}