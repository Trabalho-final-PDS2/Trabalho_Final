#include "cadastro.hpp"
#include <iostream>
#include <fstream>
#include <string>

namespace cadastro{
    void cadastro::CadastraJogador(std::string nome, std::string apelido){
        std::fstream cadastro("cadastro.txt");
        if(cadastro.is_open()){
            std::string linha;
            while(std::getline(cadastro, linha)){
                if() //parei aqui, vou verificar se o jogador ja existe antes de cadastrar
            }
        }
    }
}
