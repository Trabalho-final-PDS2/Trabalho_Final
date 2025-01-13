#include <iostream>
#include "cadastro.hpp"
#include "utilidades.hpp"
#include <string>
#include <sstream>


void menu(){
    limpa_tela();
    std::cout<< "Digite:" <<std::endl;
    std::cout<< "c -> Cadastrar usuário" <<std::endl;
    std::cout<< "e -> Editar usuário" <<std::endl;
    std::cout<< "d -> Deletar usuário" <<std::endl;
    std::cout<< "i -> Imprimir usuários" <<std::endl;
    std::cout<< "m -> Voltar para o menu inicial" <<std::endl;
    std::cout<< "f -> Finalizar" <<std::endl;
}


int modulo_cadastro(cadastro &meucadastro){
    std::string nome, apelido, novoapelido, linha;
    char comando;
    menu();
    while(std::cin >> linha){
        std::istringstream input(linha);
        input.get(comando);
        limpa_tela();
        switch (tolower(comando))
        {
        
        //Cadastro de jogador
        case 'c':{
            getchar();
            std::cout << "Digite o nome:" << std::endl;
            getline(std::cin, nome);
            nome = vazio(nome); //Evita nomes vazios
            if(nome == "ERROR"){
                break;
            }
            std::cout << "Digite o apelido (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            apelido = valida_apelido(linha);//Evita apelidos com mais de uma palavra e apelidos vazios
            if(apelido == "ERROR"){
                break;
            }
            meucadastro.CadastraJogador(nome,apelido);
            break;
        }


        //Edição de jogador
        case 'e':{
            getchar();
            std::cout << "Apelidos disponiveis para edicao" << std::endl;
            meucadastro.ExibeApelidos();
            std::cout << "Digite o apelido para edicao (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            apelido = valida_apelido(linha);//Evita apelidos com mais de uma palavra e apelidos vazio
            if(apelido == "ERROR"){
                break;
            }
            if(meucadastro.VerificaApelido(apelido) == -1){ //Verifica se o apelido está cadastrado
                std::cout << "Erro apelido inexistente" << std::endl;
                break;
            }
            std::cout << "Digite o novo apelido (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            novoapelido = valida_apelido(linha);
            if(apelido == "ERROR"){
                break;
            }
            meucadastro.EditaJogador(apelido,novoapelido);
            break;
        }


        //Deletor de jogadores
        case 'd':{
            getchar();
            std::cout << "Apelidos existentes" << std::endl;
            meucadastro.ExibeApelidos();
            std::cout << "Digite o apelido para deletar (apenas uma palavra permitida)" << std::endl;
            getline(std::cin, linha);
            apelido = valida_apelido(linha);//Evita apelidos com mais de uma palavra e apelidos vazio
            if(apelido == "ERROR"){
                break;
            }
            meucadastro.DeletaJogador(apelido);
            break;
        }

        case 'i':{
            limpa_tela();
            meucadastro.Imprime();
            sleep(5);
            break;
        }


        //Retorna 1 para o menu anterior, que mantém o programa funcionando
        case 'm':{
            return 1;
        }


        //Retorna 3 pra o menu anterior, que finaliza o programa
        case 'f':{
            return 3;
        }

        default:{
            std::cout<< "Erro: comando não existente" <<std::endl;
            sleep(2);
            break;
        }
        }
        menu();
    }
    return 3;
}