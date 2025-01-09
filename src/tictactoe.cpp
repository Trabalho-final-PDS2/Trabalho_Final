#include "tictactoe.hpp"

namespace game {

    // Construtor de TicTacToe
    TicTacToe::TicTacToe() : board::Board(9, 'X', 'O'), currentPlayer(true) {
        // O construtor da classe TicTacToe apenas chama o construtor da classe base Board
        // com 9 espaços e jogadores 'X' e 'O'. 'currentPlayer' é 'true' inicialmente (jogador 1)
    }

    // Imprime o tabuleiro do jogo da velha
   void TicTacToe::PrintBoard() {
    int position = 0;  // Contador para as posições

    for (int i = 0; i < spaces; ++i) {
        // Imprime linha horizontal (se não for a primeira linha)
        if (i % 3 == 0 && i != 0) std::cout << "\n---+---+---\n";  

        // Se a posição estiver vazia, mostramos o número da posição
        if (board[i] == ' ') {
            std::cout << position;
        } else {
            // Caso contrário, mostramos o símbolo do jogador (X ou O)
            std::cout << board[i];
        }

        // Adiciona separador '|' entre as células, exceto na última coluna
        if (i % 3 != 2) {
            std::cout << " | ";
        }

        // Incrementa a posição numérica
        position++;
    }
    std::cout << "\n";
}


    // Movimento do jogador
    void TicTacToe::playerMove(int position, bool isPlayer1) {
        if (position >= 0 && position < spaces && board[position] == ' ') {
            board[position] = (isPlayer1 ? player1 : player2);  // Atribui 'X' ou 'O' ao espaço
        }
    }

    // Verifica se há vitória
    bool TicTacToe::CheckWin() {
        // Verifica linhas
        for (int i = 0; i < 3; ++i) {
            if (board[i * 3] != ' ' && board[i * 3] == board[i * 3 + 1] && board[i * 3] == board[i * 3 + 2]) {
                return true;
            }
        }

        // Verifica colunas
        for (int i = 0; i < 3; ++i) {
            if (board[i] != ' ' && board[i] == board[i + 3] && board[i] == board[i + 6]) {
                return true;
            }
        }

        // Verifica diagonais
        if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8]) {
            return true;
        }
        if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6]) {
            return true;
        }

        return false;
    }

    // Verifica empate
    bool TicTacToe::CheckTie() {
        for (int i = 0; i < spaces; ++i) {
            if (board[i] == ' ') {  // Se houver algum espaço vazio, o jogo não terminou
                return false;
            }
        }
        return !CheckWin();  // Se não há espaços vazios e ninguém venceu, é empate
    }

    // Alterna o jogador atual
    void TicTacToe::CheckGameStatus() {
        currentPlayer = !currentPlayer;  // Alterna entre 1 e 2
    }
}
