#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <iostream>
#include <vector>
#include <string>
#include "board.hpp"

class reversi : public board::Board{
    public:
    reversi();
    bool currentPlayer;

    // Métodos sobrecarregados da classe base
    void PrintBoard() override;
    void playerMove(int position, bool isPlayer1) override;
    bool CheckWin() override;

    // Método para alternar o jogador
    void CheckGameStatus() override;
};
#endif