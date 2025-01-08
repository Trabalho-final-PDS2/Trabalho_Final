#ifndef JOGADOR_H
#define JOGADOR_H
#include<iostream>
#include<string>

class jogador{
    private:
    std::string _nome, _apelido;
    int vitorias[3],derrotas[3];

    public:
    jogador(std::string nome, std::string apelido);
    jogador(std::string nome, std::string apelido, int vitorias[], int derrotas[]);
    std::string GetNome() const;
    std::string GetApelido() const;
    std::string GetEstatisticas() const;
    void SetNome(std::string nome);
    void SetApelido(std::string novoapelido);
    void Imprime() const;
};
#endif