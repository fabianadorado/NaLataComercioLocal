#pragma once
#include <vector>
#include <string>
#include "produto.h"
#include "cliente.h"
#include "venda.h"
using namespace std;

class Loja {
private:
    vector<Produto> produtos;
    vector<Cliente> clientes;
    vector<Venda> vendas;

    int proximoIdProduto;
    int proximoIdCliente;
    int proximoNumeroFatura;
    static const int qtd_Clientes = 1000;
    int totalClientes = 0;

public:
    Loja();

    // Produtos
    void criarProduto();
    void eliminarProduto();
    void criarProduto(const string& nome, int quantidade, float precoCusto);
    void adicionarStock(int idProduto, int quantidade);
    void eliminarProduto(int idProduto);
    void listarProdutos() const;

    // Clientes
    void criarCliente(const string& nome, const string& telefone, const string& morada);
    void eliminarCliente(int idCliente);
    void alterarNomeCliente(int idCliente, const string& novoNome);
    void listarClientes() const;

    // Carteira de clientes
    bool criarCarteiraClientes(const string& carteiraClientes = "clientes.txt") const;
    bool carregarCarteiraClientes(const string& carteiraClientes = "clientes.txt");

    // Vendas
    void efetuarVenda(int idCliente);

    // Relatórios
    void relatorioStock() const;
    void relatorioVendasPorProduto(const string& nomeProduto) const;
    void relatorioTotalVendas() const;
    void relatorioGraficoVendas() const;

    // Histórico de Vendas
    void listarHistoricoVendas() const;
};
