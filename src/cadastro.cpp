#include "cadastro.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

cadastro::cadastro(){ // o construtor de cadastro tenta pegar os cadastros salvos no arquivo txt e inicaliza-los
    _QuantidadeJogadores = 0;
    std::ifstream cadastro("cadastro.txt");
    if(cadastro.is_open()){
        std::string linha, lixo, nome, apelido, palavra;
        int vitorias[3], derrotas [3];
        while(std::getline(cadastro,linha)){
            std::istringstream fluxo(linha);
            fluxo >> lixo;
            nome = "";
            while(fluxo >> palavra){
                if(palavra == "Apelido:"){
                    break;
                }
                nome += palavra + " ";
            }
            fluxo >> lixo;
            fluxo >> apelido;
            for(int i = 0; i < 3; i++){
                fluxo >> vitorias[i];
            }
            for(int i = 0; i < 3; i++){
                fluxo >> derrotas[i];
            }
            jogador adiciona(nome,apelido,vitorias,derrotas);
            _QuantidadeJogadores++;
            _MeuCadastro.push_back(adiciona);
        }
        cadastro.close();
    }
    else{
        std::cerr << "Arquivo de cadastro nao encontrado" << std::endl;
    }
}

cadastro::~cadastro(){ //o destrutor de cadastro tenta salvar os novos cadastros em um arquivo txt temporario, deletar o antigo e renomear o temporario para cadastro
    std::string nome, apelido, estatisticas, linha;
    std::ofstream temporario("temporario.txt");
    if(temporario.is_open()){
        for(size_t i = 0; i < _MeuCadastro.size(); i++){
            linha="";
            nome = _MeuCadastro[i].GetNome();
            apelido = _MeuCadastro[i].GetApelido();
            estatisticas = _MeuCadastro[i].GetEstatisticas();
            linha = "Nome: " + nome + " Apelido: " + apelido + " " + estatisticas;
            temporario << linha << std::endl;
        }
        temporario.close();

        if(remove("cadastro.txt") != 0){
            std::cerr << "Erro ao deletar arquivo antigo de cadastro" << std::endl;
        }

        if(rename("temporario.txt", "cadastro.txt") != 0){
            std::cerr << "Erro ao renomear novo arquivo de cadastro" << std::endl;
        }
    }
    else{
        std::cerr << "Erro ao atualizar arquivo de cadastro" << std::endl;
    }   
}


bool cadastro::CadastraJogador(std::string nome, std::string apelido){
    for (size_t i = 0; i < _MeuCadastro.size(); i++){
        if(_MeuCadastro[i].GetApelido() == apelido){
            std::cout << "Erro: Apelido nao disponivel" << std::endl;
            return false;
        }
    }
    jogador adiciona(nome,apelido);
    _QuantidadeJogadores++;
    _MeuCadastro.push_back(adiciona);
    return true;
}


bool cadastro::DeletaJogador(std::string apelido){
    for (size_t i = 0; i < _MeuCadastro.size(); i++){
        if(_MeuCadastro[i].GetApelido() == apelido){
           _MeuCadastro.erase(_MeuCadastro.begin() + i);
            _QuantidadeJogadores--;
            std::cout << "Jogador" << apelido << "deletado com sucesso" << std::endl;
            return true;

        }
    }
    std::cout << "Erro: jogador " << apelido << "nao cadastrado" << std::endl;
    return false;
}


bool cadastro::EditaJogador(std::string apelido, std::string novoapelido){
    for (size_t i = 0; i < _MeuCadastro.size(); i++){
        if(_MeuCadastro[i].GetApelido() == apelido){
            _MeuCadastro[i].SetApelido(novoapelido);
            std::cout << "Jogador" << apelido << "editado com sucesso para " << novoapelido << std::endl;
            return true;
        }
    }
    std::cout << "Erro: jogador " << apelido << "nao cadastrado" << std::endl;
    return false;
}


void cadastro::Imprime() const {
    std::sort(_MeuCadastro.begin(), _MeuCadastro.end(), [](const jogador &j1, const jogador &j2){
        return j1.GetApelido() < j2.GetApelido();
    });

    for(size_t i = 0; i < _MeuCadastro.size(); i++){
        _MeuCadastro[i].Imprime();
    }
}
       

