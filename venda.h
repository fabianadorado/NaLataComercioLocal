#pragma once
#include <string>
#include <vector>
#include <iomanip>
#include <sstream> 
#include <random>
#include <chrono>
#include "Cliente.h"

using namespace std;

struct ItemVenda {
    int numeroLinha;
    string nomeProduto;
    int quantidade;
    double precoSemIVA;
    double iva;
    double totalComIVA;

    ItemVenda(int linha, const string& nomeProduto, int quantidade, double precoUnit);
};

class Venda {
private:
    static mt19937 gerador;  // Gerador Mersenne Twister
    static uniform_int_distribution<int> distribuidor;  // Distribuição

    int idCliente;
    string numeroFatura;
    vector<ItemVenda> itens;
    double valorEntregue;
    double troco;
    bool gratis = false;

public:
    Venda();
    explicit Venda(int idCliente);  // explicit previne conversões implícitas

    void adicionarItem(const string& nomeProduto, int quantidade, double precoUnit);
    void finalizarVenda(double valorEntregue);
    void imprimirTalao() const;

    string getNumeroFatura() const
    {
        return numeroFatura;
    }

    int getIdCliente() const
    {
        return idCliente;
    }

    double getValorTotal() const;
    double getTroco() const 
    {
        return troco;
    }

    bool isGratis() const 
    { 
        return gratis; 
    }

    const vector<ItemVenda>& getItens() const
    {
        return itens;
    }

};