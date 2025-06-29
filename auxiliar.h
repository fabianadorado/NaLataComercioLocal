#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int lernumero(const string& mensagem);
double lerdoublePositivo(const string& mensagem);
string toLower(const string& str);

#define END_COLOR  "\033[0m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define BOLD    "\033[1m"
#define YELLOW  "\033[33m"

void limparBuffer();
void desenharLinhaHorizontal(const string& inicio, const string& fim, int largura);
void desenharLinhaHorizontalVenda(const string& inicio, const string& fim, int largura);
string repetir(const string& s, int n);
int mostrarMenu(const string& titulo, const vector<string>& opcoes);
bool arquivoExiste(const string& nomeArquivo);
void criarDiretorioSeNaoExistir(const string& nomeDiretorio);
