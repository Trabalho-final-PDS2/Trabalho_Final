#include <iostream>
#include "cadastro.hpp"
#include <string>

int main(){
    cadastro meucadastro;
    std::string nome, apelido, novoapelido;
    char comando;
    while(std::cin>>comando){
        switch (comando)
        {
        case 'c':{
            std::cin >> nome >> apelido;
            meucadastro.CadastraJogador(nome,apelido);
            break;
        }

        case 'e':{
            std::cin >> apelido >> novoapelido;
            meucadastro.EditaJogador(apelido,novoapelido);
            break;
        }

        case 'd':{
            std::cin >> apelido;
            meucadastro.DeletaJogador(apelido);
            break;
        }

        case 'i':{
            meucadastro.Imprime();
            break;
        }
        default:
            break;
        }
    }
}