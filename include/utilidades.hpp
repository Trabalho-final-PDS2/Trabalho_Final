#ifndef UTILIDADES_HPP
#define UTILIDADES_HPP

bool validacao_entrada();
void limpa_tela();
bool validacao_fluxo_linha(std::istringstream &fluxo, std::ofstream &erros, std::string &linha);
void sleep(double i);
std::string vazio(std::string palavra);
std::string valida_apelido(std::string linha);
#endif