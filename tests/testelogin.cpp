#include <iostream>
#include "cadastro.hpp"
#include <string>
#include <sstream>

int main(){
    cadastro meucadastro;
    std::string nome, apelido, novoapelido, linha;
    char comando;
    while(std::cin>>comando){
        switch (comando)
        {
        case 'c':{
            getchar();
            std::cout << "Digite o nome:" << std::endl;
            getline(std::cin, nome);
            std::cout << "Digite o apelido (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            std::istringstream copia(linha);
            copia >> apelido;
            meucadastro.CadastraJogador(nome,apelido);
            break;
        }

        case 'e':{
            getchar();
            std::cout << "Digite o apelido para edicao (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            std::istringstream copia(linha);
            copia >> apelido;
            std::cout << "Digite o novo apelido (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            std::istringstream copia2(linha);
            copia2 >> novoapelido;
            meucadastro.EditaJogador(apelido,novoapelido);
            break;
        }

        case 'd':{
            getchar();
            std::cout << "Digite o apelido para deletar (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            std::istringstream copia(linha);
            copia >> apelido;
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