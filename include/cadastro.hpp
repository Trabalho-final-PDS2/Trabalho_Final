#ifndef CADASTRO_H
#define CADASTRO_H
#include "jogador.hpp"
#include <iostream>
#include<string>

namespace cadastro{
    void CadastraJogador(std::string nome, std::string apelido);
    void DeletaJogador(std::string apelido);
    void EditaJogador(std::string apelido);
    void Imprime();
}


#endif
