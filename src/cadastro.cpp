#include "cadastro.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

cadastro::cadastro(){ // o construtor de cadastro tenta pegar os cadastros salvos no arquivo txt e inicaliza-los
    std::ifstream cadastro("../data/cadastro.txt");
    if (!cadastro.is_open()) {
    std::cerr << "Erro: Não foi possível abrir '../data/cadastro.txt'" << std::endl;
    perror("Detalhes do erro");  // Exibe o erro do sistema
}
    /*Todos os cadastros estarão salvos no padrão 
    Nome: nome Apelido: apelido 0 0 0 0 0 0 
    sendo os ultimos 6 digitos os vetores vitórias e derrotas
    exemplo Nome: Thiago Henrique Apelido: Sarzedo 0 0 3 0 0 3*/

    if(cadastro.is_open()){
        std::string linha, lixo, nome, apelido, palavra;
        int vitorias[3], derrotas [3];
        while(std::getline(cadastro,linha)){ 
            std::istringstream fluxo(linha); //Lê uma linha inteira de cadastro e a transforma em um fluxo
            fluxo >> lixo; //joga a primeira palavra (Nome:) no lixo
            nome = "";

            //Recebe todas as palavras e vai salvando em nome, separadas por um espaço. Quando encontra a palavra "Apelido:", deleta o ultimo caractere de espaço sobrando em nome e da break
            while(fluxo >> palavra){
                if(palavra == "Apelido:"){ 
                    nome.pop_back(); 
                    break;
                }
                nome += palavra + " "; 
            }

            //Joga a ultima palavra em apelido, que tem apenas uma palavra
            fluxo >> apelido;


            //recebe os vetores de vitorias e derrotas
            for(int i = 0; i < 3; i++){
                fluxo >> vitorias[i];
            }
            for(int i = 0; i < 3; i++){
                fluxo >> derrotas[i];
            }

            //adiciona o jogador no cadastro
            jogador adiciona(nome,apelido,vitorias,derrotas);
            _MeuCadastro.push_back(adiciona);
        }
        cadastro.close();
    }
    else{
        std::cerr << "Arquivo de cadastro nao encontrado" << std::endl;
    }
}

cadastro::~cadastro(){ //o destrutor de cadastro tenta salvar o estado atual do cadastro em um arquivo txt temporario, deletar o antigo e renomear o temporario para cadastro

    std::string nome, apelido, estatisticas, linha;
    std::ofstream temporario("../data/temporario.txt"); //Cria um arquivo temporário

    //Para cada posição do meu cadastro, transforma as informações no padrão Nome: nome Apelido: apelido 0 0 0 0 0 0 e salva no arquivo, separados por quebra de linha
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

        //Deleta o arquivo antigo de cadastro
        if(remove("../data/cadastro.txt") != 0){
            std::cerr << "Erro ao deletar arquivo antigo de cadastro" << std::endl;
        }

        //Renomeia temporário para cadastro
        if(rename("../data/temporario.txt", "../data/cadastro.txt") != 0){
            std::cerr << "Erro ao renomear novo arquivo de cadastro" << std::endl;
        }
    }
    else{
        std::cerr << "Erro ao atualizar arquivo de cadastro" << std::endl;
    }   
}

//Retorna a posicao no vetor de jogadores ou -1 se o jogador nao existir
int cadastro::VerificaApelido(std::string apelido){
    std::string compara;
    std::transform(apelido.begin(), apelido.end(), apelido.begin(), ::tolower); //compara tudo em minusculo, o apelido não é case sensitive
    for (size_t i = 0; i < _MeuCadastro.size(); i++){
        compara = _MeuCadastro[i].GetApelido();
        std::transform(compara.begin(), compara.end(), compara.begin(), ::tolower);
        if(compara == apelido){
            return i;
        }
    }
    return -1;
}


//Verifica se ja existe um jogador com esse apelido cadastrado, se não, cadastra o jogador
void cadastro::CadastraJogador(std::string nome, std::string apelido){
    if(VerificaApelido(apelido) != -1){
        std::cout << "Erro: Apelido nao disponivel" << std::endl;
    }
    else{
        jogador adiciona(nome,apelido);
        _MeuCadastro.push_back(adiciona);
        std::cout << "Jogador " << apelido << " cadastrado com sucesso" << std::endl;
    }
}


//Verifica se existe jogador com esse apelido cadastrado, se sim, deleta o jogador
void cadastro::DeletaJogador(std::string apelido){
    int indice = VerificaApelido(apelido);
    if(indice != -1){
        _MeuCadastro.erase(_MeuCadastro.begin() + indice);
        std::cout << "Jogador " << apelido << " deletado com sucesso" << std::endl;
    }
    else{
        std::cout << "Erro: jogador " << apelido << " nao cadastrado" << std::endl;
    }
}


//Verifica se o novo apelido está disponivel, se sim, edita o apelido. 
void cadastro::EditaJogador(std::string apelido, std::string novoapelido){
    int indice = VerificaApelido(novoapelido);
    if(indice == -1){
        indice = VerificaApelido(apelido);
        _MeuCadastro[indice].SetApelido(novoapelido);
        std::cout << "Jogador " << apelido << " editado com sucesso para " << novoapelido << std::endl;
    }

    else{
        std::cout << "Erro: apelido " << novoapelido << " nao disponivel" << std::endl;
    }
}


//Ordena os jogadores por ordem alfabética dos apelidos e impime na tela
void cadastro::Imprime() {
    std::sort(_MeuCadastro.begin(), _MeuCadastro.end(), [](const jogador &j1, const jogador &j2){
        std::string apelido1 = j1.GetApelido();
        std::string apelido2 = j2.GetApelido();

        //importante transformar os apelidos para minusculas, todas as letras maiusculas tem precedencia, Z < a
        std::transform(apelido1.begin(), apelido1.end(), apelido1.begin(), ::tolower);
        std::transform(apelido2.begin(), apelido2.end(), apelido2.begin(), ::tolower);
        return apelido1 < apelido2;
    });

    for(size_t i = 0; i < _MeuCadastro.size(); i++){
        _MeuCadastro[i].Imprime();
    }
}


//Exibe todos os apelidos na tela
void cadastro::ExibeApelidos(){
    for(size_t i = 0; i < _MeuCadastro.size(); i++){
        std::cout<< _MeuCadastro[i].GetApelido() << std::endl;
    }
}


//Altera as estatisticas de 2 jogadores para vitoria e derrota em um jogo
void cadastro::SetVD(std::string playerV, std::string playerD, int game){
    _MeuCadastro[VerificaApelido(playerV)].SetEstatistica(game);
    game = game * -1;
    _MeuCadastro[VerificaApelido(playerD)].SetEstatistica(game);
}
  

