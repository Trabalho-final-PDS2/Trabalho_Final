#include "jogador.hpp"
#include <iostream>
#include <string>

jogador::jogador(std::string nome, std::string apelido) : _nome(nome), _apelido(apelido){
    for(int i=0; i < 3; i++){
        this->vitorias[i] = 0;
        this->derrotas[i] = 0;
    }
}

jogador::jogador(std::string nome, std::string apelido, int vitorias[], int derrotas[]) : _nome(nome), _apelido(apelido){
    for(int i=0; i < 3; i++){
        this->vitorias[i] = vitorias[i];
        this->derrotas[i] = derrotas[i];
    }
}

std::string jogador::GetNome() const{
    return this->_nome;
}

std::string jogador::GetApelido() const {
    return this->_apelido;
}

std::string jogador::GetEstatisticas() const { //as estatisticas sao passadas em string pois são usadas para salvar no arquivo txt
    std::string estatisticas="";

    for(int i = 0; i < 3; i++){
        estatisticas += std::to_string(vitorias[i]) + " ";
    }
    for(int i = 0; i < 3; i++){
        estatisticas += std::to_string(derrotas[i]) + " ";
    }

    return estatisticas;
}

void jogador::SetNome(std::string nome){
    this->_nome = nome;
}

void jogador::SetApelido(std::string novoapelido){
    this->_apelido = novoapelido;
}

void jogador::Imprime() const {
    std::cout << this->_apelido << " - (" << this->_nome << ")" <<std::endl;
    std::cout << "Vitorias" << std::endl;
    std::cout << "Reversi: " << this->vitorias[0] << "Lig4: " << this->vitorias[1] << "Jogo da velha: " << this->vitorias[2];
    std::cout << std::endl;
    std::cout << "Derrotas" << std::endl;
    std::cout << "Reversi: " << this->derrotas[0] << "Lig4: " << this->derrotas[1] << "Jogo da velha: " << this->derrotas[2];
    std::cout << std::endl;
}