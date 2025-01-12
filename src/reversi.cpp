#include "reversi.hpp"
#include <thread>
#include <chrono>

reversi::reversi() : board::Board(64, 'X', 'O'), currentPlayer(true){//Constrói um tabuleiro 8x8 e seta X e O para os players
   
}
int reversi::BoardToVector(int position){ //Transforma um numero no padrao board (11 a 88) para o padrao vector (0 a 63)
    int jogadax,jogaday;
    jogadax = position / 10;
    jogaday = position % 10;
    jogadax--;
    jogaday--;
    position = 8 * jogadax + jogaday;
    return position;
}

int reversi::VectorToBoard(int position){ //Transforma um numero no padrao vector (0 a 63) para o padrao board (11 a 88)
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
    if(IsValidEsquerda(position) ||  IsValidDireita(position) || //Verifica se a jogada é valida em qualquer direçao
    IsValidCima(position) || IsValidBaixo(position) ||
    IsValidNordeste(position) || IsValidSudeste(position) ||
    IsValidSudoeste(position) || IsValidNoroeste(position)){
        return true;
    }
    else{
        return false;
    }
}


void reversi::PrintBoard(std::string jogador1, std::string jogador2){
    int indice = 0;
    for(int i = 1; i <= 8; i++){ 
        for(int j = 1; j <= 8; j++){
            if (board[indice] == player1 || board[indice] == player2){
                std::cout << (board[indice] == player1 ? "\033[31m" : "\033[34m") << board[indice] << "\033[0m" << " "; //printa o simbolo do player na cor do playr
            }
            else if(isValidAll(indice)){
                std::cout << i << j; //se não está ocupada mas é uma casa valida, printa o numero da casa em formato board na cor vermelha
            }
            else{
                std::cout <<"  "; //se nao está ocupada e não é valida nao printa nada
            }
            if(j != 8){
                std::cout << " | "; //separadores do tabuleiro
            }
            indice++;
        }
        std::cout << std::endl;
    }
    Score(jogador1, jogador2);
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
            board[tempPos] = self; //Vai preenchendo as casas com o simbolo do player
            tempPos++;
        }
    }

    // Captura para a esquerda
    if (IsValidEsquerda(VectorToBoard(position))) {
        int tempPos = position - 1;
        while (board[tempPos] == opponent) { 
            board[tempPos] = self; //Vai preenchendo as casas com o simbolo do player
            tempPos--;
        }
    }

    // Captura para cima
    if (IsValidCima(VectorToBoard(position))) {
        int tempPos = position - 8;
        while (board[tempPos] == opponent) {
            board[tempPos] = self; //Vai preenchendo as casas com o simbolo do player
            tempPos -= 8;
        }
    }

    // Captura para baixo
    if (IsValidBaixo(VectorToBoard(position))) {
        int tempPos = position + 8;
        while (board[tempPos] == opponent) {
            board[tempPos] = self; //Vai preenchendo as casas com o simbolo do player
            tempPos += 8;
        }
    }

    // Captura para nordeste
    if (IsValidNordeste(VectorToBoard(position))) {
        int tempPos = position - 7;
        while (board[tempPos] == opponent) {
            board[tempPos] = self; //Vai preenchendo as casas com o simbolo do player
            tempPos -= 7;
        }
    }

    // Captura para sudeste
    if (IsValidSudeste(VectorToBoard(position))) {
        int tempPos = position + 9;
        while (board[tempPos] == opponent) {
            board[tempPos] = self; //Vai preenchendo as casas com o simbolo do player
            tempPos += 9;
        }
    }

    // Captura para sudoeste
    if (IsValidSudoeste(VectorToBoard(position))) {
        int tempPos = position + 7;
        while (board[tempPos] == opponent) {
            board[tempPos] = self; //Vai preenchendo as casas com o simbolo do player
            tempPos += 7;
        }
    }

    // Captura para noroeste
    if (IsValidNoroeste(VectorToBoard(position))) {
        int tempPos = position - 9;
        while (board[tempPos] == opponent) {
            board[tempPos] = self; //Vai preenchendo as casas com o simbolo do player
            tempPos -= 9;
        }
    }

    // Marca a posição atual como do jogador atual
    board[position] = self;
}



void reversi::Inicio(){
    board[BoardToVector(44)] = player1; //Preenche as casas iniciais no padrão do Reversi
    board[BoardToVector(55)] = player1;
    board[BoardToVector(45)] = player2;
    board[BoardToVector(54)] = player2;
}

bool reversi::CanIPlay(){ //Verifica se existe alguma jogada válida para o player
    bool ans = false;
    for(int i = 0; i < 63; i++){
        if(isValidAll(i) && board[i] == ' '){
            ans = true;
            break;
        }
    }
    return ans;
}

bool reversi::CheckTie(){ //Verifica se o jogo terminou (nenhum dos jogadores tem jogada válida)
    bool test1, test2;

    test1 = CanIPlay();
    CheckGameStatus();
    test2 = CanIPlay();
    if(test1 || test2){
        CheckGameStatus();
        return false;
    }
    else{
        CheckGameStatus();
        return true;
    }
}

void reversi::Score(std::string jogador1, std::string jogador2){ //Conta o score e exibe na tela
    int score1 = 0, score2 = 0;;
    for(int i = 0; i < 63; i++){
        if(board[i] == 'X'){
            score1++;
        }
    }

    for(int i = 0; i < 63; i++){
        if(board[i] == 'O'){
            score2++;
        }
    }
    std::cout << jogador1 << " " << score1 << " - " << jogador2 << " " << score2 << std::endl;
}

int reversi::CheckWin(std::string jogador1, std::string jogador2){ //Conta quem tem mais símbolos no tabuleiro para a vitória
    int X = 0, O = 0;
    for(int i = 0; i < 63; i++){
        if(board[i] == 'X'){
            X++;
        }

        else if(board[i] == 'O'){
            O++;
        }
    }
    PrintBoard(jogador1, jogador2);

    if(X != O){
        std::cout << "PARABENS!!! " << (X > O ? jogador1 : jogador2) << " voce venceu" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return X > O;
    }
    else{
        std::cout << "O jogo empatou!" << std::endl;
        return -1;
    }
}

void reversi::CheckGameStatus(){ //Troca o player, passa a vez
    currentPlayer = !currentPlayer;
}

//Implementação de um jogo de Reversi
void reversi::JogarReversi(std::string jogador1, std::string jogador2, cadastro &meucadastro, reversi &Reversi){
    int position;
    Reversi.Inicio();
    while(position != -1){

        //Se o jogador tem jogadas válidas ele vai jogar
        if(Reversi.CanIPlay()){
            Reversi.PrintBoard(jogador1, jogador2);
            std::cout << (Reversi.currentPlayer ? jogador1 : jogador2) << ", escolha entre as casas válidas (-1 finaliza o jogo): " << std::endl;

            std::cin >> position;

            //validação da entrada (evita que position receba char por exemplo)
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o estado de erro do cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta entrada inválida
                std::cout << "Entrada invalida, por favor insira apenas numeros!" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                continue; // Volta para o início do loop
            }

            //Se a jogada é válida, faz a jogada e passa a vez
            if(Reversi.isValidAll(Reversi.BoardToVector(position))){
                Reversi.playerMove(position, Reversi.currentPlayer);
                Reversi.CheckGameStatus();
            }
            //Se a jogada não é valida exibe mensagem de erro e o mesmo jogador tenta jogar novamente
            else if (position != -1){
                std::cout << "Jogada invalida, siga os numeros vermelhos" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
        }

        //Se o jogador nao tem jogadas válidas, passa a vez
        else{
            Reversi.CheckGameStatus();
        }

        //Checa se o jogo acabou após cada rodada
        if(Reversi.CheckTie()){
            break;
        }
    }


    //Confere quem venceu e exibe na tela, além de atualizar as estatísticas
    if(position != -1){
        int resultado = Reversi.CheckWin(jogador1, jogador2);
        if(resultado == 1){ 
            meucadastro.SetVD(jogador1,jogador2,3);
        }
        else if (resultado == 0){
            meucadastro.SetVD(jogador2,jogador1,3);
        }
        else if (resultado == -1){
            std::cout << "nenhuma, vitoria registrada" << std::endl;
        }
    }
}