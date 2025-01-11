#include "reversi.hpp"

reversi::reversi() : board::Board(64, 'X', 'O'), currentPlayer(true){
   
}
int reversi::BoardToVector(int position){
    int jogadax,jogaday;
    jogadax = position / 10;
    jogaday = position % 10;
    jogadax--;
    jogaday--;
    position = 8 * jogadax + jogaday;
    return position;
}

int reversi::VectorToBoard(int position){
    int linha = position / 8;
    int coluna = position % 8;
    position = (linha + 1) * 10 + (coluna + 1);

    return position;
}

bool reversi::IsValidDireita(int position) {
    position = BoardToVector(position); // Transforma a posição para índice do vetor
    if (position < 0 || position >= 64) return false; // Verifica se está no tabuleiro

    char opponent = currentPlayer ? player2 : player1; // Jogador oponente
    char self = currentPlayer ? player1 : player2;    // Jogador atual
    bool valid = false;

    // Verifica a direção à direita
    if (position % 8 < 7 && board[position + 1] == opponent) {
        int tempPos = position + 1;
        while (tempPos % 8 < 7) { // Continua verificando na mesma linha
            tempPos++;
            if (board[tempPos] == self) { // Encontrou peça do jogador atual
                valid = true; // Jogada válida
                break;
            } else if (board[tempPos] != opponent) { // Parar se não encontrar oponente
                break;
            }
        }
    }
    return valid;
}

bool reversi::IsValidEsquerda(int position){
    position = BoardToVector(position); // Transforma a posição para índice do vetor
    if (position < 0 || position >= 64) return false; // Verifica se está no tabuleiro

    char opponent = currentPlayer ? player2 : player1; // Jogador oponente
    char self = currentPlayer ? player1 : player2;    // Jogador atual
    bool valid = false;
    
    // Verifica a direção à esquerda
    if (position % 8 > 0 && board[position - 1] == opponent) {
        int tempPos = position - 1;
        while (tempPos % 8 > 0) { // Continua verificando na mesma linha
            tempPos--;
            if (board[tempPos] == self) { // Encontrou peça do jogador atual
                valid = true; // Jogada válida
                break;
            } else if (board[tempPos] != opponent) { // Parar se não encontrar oponente
                break;
            }
        }
    }

    return valid;
}

bool reversi::IsValidCima(int position) {
    position = BoardToVector(position); // Transforma a posição para índice do vetor
    if (position < 0 || position >= 64) return false; // Verifica se está no tabuleiro

    char opponent = currentPlayer ? player2 : player1; // Jogador oponente
    char self = currentPlayer ? player1 : player2;    // Jogador atual
    bool valid = false;

    // Verifica a direção para cima
    if (position / 8 > 0 && board[position - 8] == opponent) {
        int tempPos = position - 8;
        while (tempPos / 8 > 0) { // Continua verificando na mesma coluna
            tempPos -= 8;
            if (board[tempPos] == self) { // Encontrou peça do jogador atual
                valid = true; // Jogada válida
                break;
            } else if (board[tempPos] != opponent) { // Parar se não encontrar oponente
                break;
            }
        }
    }

    return valid;
}

bool reversi::IsValidBaixo(int position) {
    position = BoardToVector(position); // Transforma a posição para índice do vetor
    if (position < 0 || position >= 64) return false; // Verifica se está no tabuleiro

    char opponent = currentPlayer ? player2 : player1; // Jogador oponente
    char self = currentPlayer ? player1 : player2;    // Jogador atual
    bool valid = false;

    // Verifica a direção para baixo
    if (position / 8 < 7 && board[position + 8] == opponent) {
        int tempPos = position + 8;
        while (tempPos / 8 < 7) { // Continua verificando na mesma coluna
            tempPos += 8;
            if (board[tempPos] == self) { // Encontrou peça do jogador atual
                valid = true; // Jogada válida
                break;
            } else if (board[tempPos] != opponent) { // Parar se não encontrar oponente
                break;
            }
        }
    }

    return valid;
}

bool reversi::IsValidNordeste(int position) {
    position = BoardToVector(position); // Transforma a posição para índice do vetor
    if (position < 0 || position >= 64) return false; // Verifica se está no tabuleiro

    char opponent = currentPlayer ? player2 : player1; // Jogador oponente
    char self = currentPlayer ? player1 : player2;    // Jogador atual
    bool valid = false;

    // Verifica a direção nordeste (cima à direita)
    if (position / 8 > 0 && position % 8 < 7 && board[position - 7] == opponent) {
        int tempPos = position - 7;
        while (tempPos / 8 > 0 && tempPos % 8 < 7) { // Continua verificando na diagonal
            tempPos -= 7;
            if (board[tempPos] == self) { // Encontrou peça do jogador atual
                valid = true; // Jogada válida
                break;
            } else if (board[tempPos] != opponent) { // Parar se não encontrar oponente
                break;
            }
        }
    }

    return valid;
}

bool reversi::IsValidSudeste(int position) {
    position = BoardToVector(position); // Transforma a posição para índice do vetor
    if (position < 0 || position >= 64) return false; // Verifica se está no tabuleiro

    char opponent = currentPlayer ? player2 : player1; // Jogador oponente
    char self = currentPlayer ? player1 : player2;    // Jogador atual
    bool valid = false;

    // Verifica a direção sudeste (baixo à direita)
    if (position / 8 < 7 && position % 8 < 7 && board[position + 9] == opponent) {
        int tempPos = position + 9;
        while (tempPos / 8 < 7 && tempPos % 8 < 7) { // Continua verificando na diagonal
            tempPos += 9;
            if (board[tempPos] == self) { // Encontrou peça do jogador atual
                valid = true; // Jogada válida
                break;
            } else if (board[tempPos] != opponent) { // Parar se não encontrar oponente
                break;
            }
        }
    }

    return valid;
}

bool reversi::IsValidSudoeste(int position) {
    position = BoardToVector(position); // Transforma a posição para índice do vetor
    if (position < 0 || position >= 64) return false; // Verifica se está no tabuleiro

    char opponent = currentPlayer ? player2 : player1; // Jogador oponente
    char self = currentPlayer ? player1 : player2;    // Jogador atual
    bool valid = false;

    // Verifica a direção sudoeste (baixo à esquerda)
    if (position / 8 < 7 && position % 8 > 0 && board[position + 7] == opponent) {
        int tempPos = position + 7;
        while (tempPos / 8 < 7 && tempPos % 8 > 0) { // Continua verificando na diagonal
            tempPos += 7;
            if (board[tempPos] == self) { // Encontrou peça do jogador atual
                valid = true; // Jogada válida
                break;
            } else if (board[tempPos] != opponent) { // Parar se não encontrar oponente
                break;
            }
        }
    }

    return valid;
}

bool reversi::IsValidNoroeste(int position) {
    position = BoardToVector(position); // Transforma a posição para índice do vetor
    if (position < 0 || position >= 64) return false; // Verifica se está no tabuleiro

    char opponent = currentPlayer ? player2 : player1; // Jogador oponente
    char self = currentPlayer ? player1 : player2;    // Jogador atual
    bool valid = false;

    // Verifica a direção noroeste (cima à esquerda)
    if (position / 8 > 0 && position % 8 > 0 && board[position - 9] == opponent) {
        int tempPos = position - 9;
        while (tempPos / 8 > 0 && tempPos % 8 > 0) { // Continua verificando na diagonal
            tempPos -= 9;
            if (board[tempPos] == self) { // Encontrou peça do jogador atual
                valid = true; // Jogada válida
                break;
            } else if (board[tempPos] != opponent) { // Parar se não encontrar oponente
                break;
            }
        }
    }

    return valid;
}

bool reversi::isValidAll(int position){
    if (position < 0 || position >= 64) return false; // Verifica se está no tabuleiro
    position = VectorToBoard(position);
    if(IsValidEsquerda(position) ||  IsValidDireita(position) ||
    IsValidCima(position) || IsValidBaixo(position) ||
    IsValidNordeste(position) || IsValidSudeste(position) ||
    IsValidSudoeste(position) || IsValidNoroeste(position)){
        return true;
    }
    else{
        return false;
    }
}


void reversi::PrintBoard(){
    int indice = 0;
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            if (board[indice] == player1 || board[indice] == player2){
                std::cout << board[indice] << " ";
            }
            else if(isValidAll(indice)){
                std::cout << "\033[31m" << i << "\033[0m" << "\033[31m" << j << "\033[0m";
            }
            else{
                std::cout << i << j;
            }
            if(j != 8){
                std::cout << " | ";
            }
            indice++;
        }
        std::cout << std::endl;
    }
}

void reversi::playerMove(int position, bool isPlayer1) {
    position = BoardToVector(position); // Converte para índice do vetor
    if (position < 0 || position >= 64) return; // Verifica se está dentro do tabuleiro

    char self = isPlayer1 ? player1 : player2; // Jogador atual
    char opponent = isPlayer1 ? player2 : player1; // Adversário

    // Captura para a direita
    if (IsValidDireita(VectorToBoard(position))) {
        int tempPos = position + 1;
        while (board[tempPos] == opponent) {
            board[tempPos] = self;
            tempPos++;
        }
    }

    // Captura para a esquerda
    if (IsValidEsquerda(VectorToBoard(position))) {
        int tempPos = position - 1;
        while (board[tempPos] == opponent) {
            board[tempPos] = self;
            tempPos--;
        }
    }

    // Captura para cima
    if (IsValidCima(VectorToBoard(position))) {
        int tempPos = position - 8;
        while (board[tempPos] == opponent) {
            board[tempPos] = self;
            tempPos -= 8;
        }
    }

    // Captura para baixo
    if (IsValidBaixo(VectorToBoard(position))) {
        int tempPos = position + 8;
        while (board[tempPos] == opponent) {
            board[tempPos] = self;
            tempPos += 8;
        }
    }

    // Captura para nordeste
    if (IsValidNordeste(VectorToBoard(position))) {
        int tempPos = position - 7;
        while (board[tempPos] == opponent) {
            board[tempPos] = self;
            tempPos -= 7;
        }
    }

    // Captura para sudeste
    if (IsValidSudeste(VectorToBoard(position))) {
        int tempPos = position + 9;
        while (board[tempPos] == opponent) {
            board[tempPos] = self;
            tempPos += 9;
        }
    }

    // Captura para sudoeste
    if (IsValidSudoeste(VectorToBoard(position))) {
        int tempPos = position + 7;
        while (board[tempPos] == opponent) {
            board[tempPos] = self;
            tempPos += 7;
        }
    }

    // Captura para noroeste
    if (IsValidNoroeste(VectorToBoard(position))) {
        int tempPos = position - 9;
        while (board[tempPos] == opponent) {
            board[tempPos] = self;
            tempPos -= 9;
        }
    }

    // Marca a posição atual como do jogador atual
    board[position] = self;
}



void reversi::Inicio(){
    board[BoardToVector(44)] = player1;
    board[BoardToVector(55)] = player1;
    board[BoardToVector(45)] = player2;
    board[BoardToVector(54)] = player2;
}

bool reversi::CanIPlay(){
    bool ans = false;
    for(int i = 0; i < 63; i++){
        if(isValidAll(i) && board[i] == ' '){
            ans = true;
            break;
        }
    }
    return ans;
}

bool reversi::CheckTie(){
    bool test1, test2;

    test1 = CanIPlay();
    CheckGameStatus();
    test2 = CanIPlay();
    if(test1 || test2){
        CheckGameStatus();
        return false;
    }
    else{
        return true;
    }
}

int reversi::Score(int player){
    int score = 0;
    if(player == 1){
            for(int i = 0; i < 63; i++){
            if(board[i] == 'X'){
                score++;
            }
        }
        return score;
    }
    if(player == 2){
            for(int i = 0; i < 63; i++){
            if(board[i] == 'O'){
                score++;
            }
        }
        return score;
    }
    return 0;
}

bool reversi::CheckWin(){
    int X = 0, O = 0;
    for(int i = 0; i < 63; i++){
        if(board[i] == 'X'){
            X++;
        }

        else if(board[i] == 'O'){
            O++;
        }
    }
    return X > O;
}

void reversi::CheckGameStatus(){
    currentPlayer = !currentPlayer;
}
