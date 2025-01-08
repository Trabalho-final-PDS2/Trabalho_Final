#include "jogador.hpp"
#include <iostream>
#include <string>

jogador::jogador(std::string nome, std::string apelido){
    for(int i=0; i < 3; i++){
        this->vitorias[i] = 0;
        this->derrotas[i] = 0;
    }
}

std::string jogador::GetNome(){
    return this->_nome;
}

void jogador::SetNome(std::string nome){
    this->_nome = nome;
}

void jogador::Imprime(){
    std::cout << this->_apelido << " - (" << this->_nome << ")" <<std::endl;
    std::cout << "Vitorias" << std::endl;
    std::cout << "Reversi:" << this->vitorias[0] << "Lig4:" << this->vitorias[1] << "Jogo da velha:" << this->vitorias[2];
    std::cout << std::endl;
    std::cout << "Derrotas" << std::endl;
    std::cout << "Reversi:" << this->derrotas[0] << "Lig4:" << this->derrotas[1] << "Jogo da velha:" << this->derrotas[2];
    std::cout << std::endl;
}