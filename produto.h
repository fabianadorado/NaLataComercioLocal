#pragma once
#include <string>
#include <iostream>

using namespace std;


class Produto {
private:
    static int proximoId;
    int id;
    string nome;
    int quantidade;
    double precoCusto;

public:
    Produto();
    Produto(int id, string nome, int quantidade, double precoCusto);

    int getId() const;
    string getNome() const;
    int getQuantidade() const;
    double getPrecoCusto() const;
    double getPrecoVenda() const;           // Pre�o com margem
    double getPrecoVendaComIVA() const;     // Pre�o com margem + IVA

    void adicionarStock(int qtd);
    void removerStock(int qtd);
};
