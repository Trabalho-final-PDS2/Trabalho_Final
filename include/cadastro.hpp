#ifndef CADASTRO_H
#define CADASTRO_H
#include "jogador.hpp"
#include <iostream>
#include <string>
#include <vector>

class cadastro{
    private:
    int _QuantidadeJogadores;
    std::vector<jogador> _MeuCadastro;

    public:
    cadastro();
    ~cadastro();
    bool CadastraJogador(std::string nome, std::string apelido);
    bool DeletaJogador(std::string apelido);
    bool EditaJogador(std::string apelido, std::string novoapelido);
    void Imprime() const;
};
    

#endif
