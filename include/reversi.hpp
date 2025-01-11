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


    bool IsValidDireita(int position);
    bool IsValidEsquerda(int position);
    bool IsValidCima(int position);
    bool IsValidBaixo(int position);
    bool IsValidNordeste(int position);
    bool IsValidSudeste(int position);
    bool IsValidSudoeste(int position);
    bool IsValidNoroeste(int position);
    bool isValidAll(int position);
    bool CanIPlay ();
    int VectorToBoard(int position);
    int BoardToVector(int position);
    void Inicio();
    // Métodos sobrecarregados da classe base
    void PrintBoard() override;
    void playerMove(int position, bool isPlayer1) override;
    bool CheckWin() override;
    bool CheckTie() override;

    // Método para alternar o jogador
    void CheckGameStatus() override;
};
#endif