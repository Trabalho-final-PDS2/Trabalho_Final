// lig4.cpp
#include "lig4.hpp"
#include "utilidades.hpp"
#include <iostream>
#include <string>

namespace game{
    Lig4::Lig4() : board::Board(ROWS * COLS, 'X', 'O'), currentPlayer(true), gameOver(false) {
        for(int i = 0; i < ROWS * COLS; i++){
            board[i] = '_'; 
        }
    }

    void Lig4::PrintBoard() {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                std::cout << "|" << board[i * COLS + j] << "|";
            }
            std::cout << std::endl;
        }
    }

    int Lig4::findNextEmptyPosition(int col) {
        for (int row = ROWS - 1; row >= 0; row--) {
            if (board[row * COLS + col] == '_') {
                return row;
            }
        }
        this->colunaCheia[col] = true;
        return -1; // Coluna cheia
    }

    void Lig4::playerMove(int position, bool currentPlayer) {
        if (position < 1 || position > COLS) {
            std::cout << "Erro: coluna inválida\n";
            return;
        }

        int col = position - 1;
        int row = findNextEmptyPosition(col);

        if (row == -1) {
            std::cout << "Erro: coluna cheia\n";
            return;
        }

        board[row * COLS + col] = (this->currentPlayer ? player1 : player2);
        this->CheckGameStatus();
    }

    bool Lig4::CheckWin() {
        char playerSymbol = currentPlayer ? player1 : player2;

        // Horizontal
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j <= COLS - 4; j++) {
                if (board[i * COLS + j] == playerSymbol &&
                    board[i * COLS + j + 1] == playerSymbol &&
                    board[i * COLS + j + 2] == playerSymbol &&
                    board[i * COLS + j + 3] == playerSymbol) {
                    return true;
                }
            }
        }

        // Vertical
        for (int i = 0; i <= ROWS - 4; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i * COLS + j] == playerSymbol &&
                    board[(i + 1) * COLS + j] == playerSymbol &&
                    board[(i + 2) * COLS + j] == playerSymbol &&
                    board[(i + 3) * COLS + j] == playerSymbol) {
                    return true;
                }
            }
        }

        // Diagonal (descendente)
        for (int i = 0; i <= ROWS - 4; i++) {
            for (int j = 0; j <= COLS - 4; j++) {
                if (board[i * COLS + j] == playerSymbol &&
                    board[(i + 1) * COLS + j + 1] == playerSymbol &&
                    board[(i + 2) * COLS + j + 2] == playerSymbol &&
                    board[(i + 3) * COLS + j + 3] == playerSymbol) {
                    return true;
                }
            }
        }

        // Diagonal (ascendente)
        for (int i = 3; i < ROWS; i++) {
            for (int j = 0; j <= COLS - 4; j++) {
                if (board[i * COLS + j] == playerSymbol &&
                    board[(i - 1) * COLS + j + 1] == playerSymbol &&
                    board[(i - 2) * COLS + j + 2] == playerSymbol &&
                    board[(i - 3) * COLS + j + 3] == playerSymbol) {
                    return true;
                }
            }
        }

        return false;
    }

    bool Lig4::CheckTie() {
        for(int i = 0; i < COLS; i++){
            if(!this->colunaCheia[i]){
                return false;
            }
        }

        return true;
    }

    void Lig4::CheckGameStatus() {
        if (CheckWin()) {
            std::cout << "Jogador " << (this->currentPlayer ? 1 : 2) << " venceu!\n";
            gameOver = true;
        }
        else if (CheckTie()) {
            std::cout << "Empate!\n";
            gameOver = true;
        }
        else {
            this->currentPlayer = !this->currentPlayer;
        }
    }

    void Lig4::runGame(std::string& jogador1, std::string& jogador2, cadastro& meuCadastro){
        int jogada;

        while (true) {
            this->PrintBoard();
            
            std::cout << "Jogador " << (this->currentPlayer ? jogador1 : jogador2) << ", faça sua jogada (1-7): ";
            std::cin >> jogada;
            
            this->playerMove(jogada, this->currentPlayer);
    
            if (this->gameOver) {
                this->currentPlayer? 
                    meuCadastro.SetVD(jogador1, jogador2, 2) :
                    meuCadastro.SetVD(jogador2, jogador1, 2);
                this->PrintBoard();
                break;
            }
            
        }
    }
}