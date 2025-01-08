#ifndef JOGADOR_H
#define JOGADOR_H
#include<iostream>
#include<string>

class jogador{
    private:
    std::string _nome, _apelido;
    int vitorias[3],derrotas[3];

    public:
    jogador(std::string nome, std::string apelido) : _nome(nome), _apelido(apelido) {};
    std::string GetNome();
    void SetNome(std::string nome);
    void Imprime();
};
#endif