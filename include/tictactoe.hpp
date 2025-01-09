#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <iostream>
#include <vector>
#include <string>

#include "board.hpp"

namespace game {

    class TicTacToe : public board::Board {
    
        

    public:
        // Construtor
        TicTacToe();
        bool currentPlayer;  // Variável para controlar o jogador atual
        // Métodos sobrecarregados da classe base
        void PrintBoard() override;
        void playerMove(int position, bool isPlayer1) override;
        bool CheckWin() override;
        bool CheckTie() override;

        // Método para alternar o jogador
        void CheckGameStatus() override;
    };
}

#endif // TICTACTOE_HPP
