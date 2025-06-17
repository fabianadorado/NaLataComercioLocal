#pragma once
#include <string>
#include <vector>
using namespace std;

struct ItemVenda {
    int numeroLinha;
    string nomeProduto;
    int quantidade;
    float precoSemIVA;
    float iva;
    float totalComIVA;

    ItemVenda(int linha, const string& nomeProduto, int quantidade, float precoUnit);
};

class Venda {
private:
    int numeroFatura;
    int idCliente;
    vector<ItemVenda> itens;
    float valorEntregue;
    float troco;
    bool gratis = false;

public:
    Venda();
    Venda(int numeroFatura, int idCliente);

    void adicionarItem(const string& nomeProduto, int quantidade, float precoUnit);
    void finalizarVenda(float valorEntregue);
    void imprimirTalao();

    int getNumeroFatura() const;
    int getIdCliente() const;
    float getValorTotal() const;
    float getTroco() const;

    const vector<ItemVenda>& getItens() const
    {
        return itens;
    }

};