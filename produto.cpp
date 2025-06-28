#include "Produto.h"
#include <iostream>

using namespace std;

// Inicializa��o do ID est�tico
int Produto::proximoId = 1;

// Construtor padr�o
Produto::Produto() {
    id = proximoId++;
    nome = "";
    quantidade = 0;
    precoCusto = 0.0;
}

// Construtor com par�metros
Produto::Produto(int id, string nome, int quantidade, double precoCusto) {
    this->id = id;
    this->nome = nome;
    this->quantidade = quantidade;
    this->precoCusto = precoCusto;
    if (id >= proximoId) {
        proximoId = id + 1;
    }
}

// Getters
int Produto::getId() const {
    return id;
}

string Produto::getNome() const {
    return nome;
}

int Produto::getQuantidade() const {
    return quantidade;
}

double Produto::getPrecoCusto() const {
    return precoCusto;
}

// Pre�o de venda com margem (exemplo: 30% de lucro)
double Produto::getPrecoVenda() const {
    return precoCusto * 1.3;
}

// Pre�o de venda com IVA (23% aplicado sobre o pre�o de venda)
double Produto::getPrecoVendaComIVA() const {
    double precoVenda = getPrecoVenda();
    return precoVenda * 1.23;
}

// Estoque
void Produto::adicionarStock(int qtd) {
    quantidade += qtd;
}

void Produto::removerStock(int qtd) {
    if (quantidade >= qtd) {
        quantidade -= qtd;
    }
}