#include "Loja.h"
#include "auxiliar.h"
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

// Construtor
Loja::Loja() {
    proximoIdProduto = 1;
    proximoIdCliente = 1;
    proximoNumeroFatura = 1;
}

void Loja::criarProduto(const string& nome, int quantidade, float precoCusto) {
    Produto novoProduto(proximoIdProduto, nome, quantidade, precoCusto);
    produtos.push_back(novoProduto);
    cout << "Produto criado com sucesso.\n";
    proximoIdProduto++;
}

void Loja::criarProduto() {
    string nome;
    int quantidade;
    float preco;

    cin.ignore();  // Limpa o buffer do cin antes de ler linhas
    cout << "Nome do produto: ";
    getline(cin, nome);

    quantidade = lernumero("Quantidade: ");
    preco = lerFloatPositivo("Preço de custo: ");

    criarProduto(nome, quantidade, preco);  // Chama a versão já implementada
}


void Loja::adicionarStock(int idProduto, int quantidade) {
    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i].getId() == idProduto) {
            produtos[i].adicionarStock(quantidade);
            cout << "Stock adicionado com sucesso!\n";
            return;
        }
    }
    cout << "Produto não encontrado.\n";
}

void Loja::eliminarProduto(int idProduto) {
    listarProdutos();
    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i].getId() == idProduto) {
            produtos.erase(produtos.begin() + i);
            cout << "Produto removido.\n";
            listarProdutos();
            return;
        }
    }
    cout << "Produto não encontrado.\n";
}

void Loja::eliminarProduto() {
    listarProdutos();
    int id = lernumero("Digite o ID do produto que deseja eliminar: ");
    eliminarProduto(id);
}


void Loja::listarProdutos() const {
    cout << "\n-------------------------- Produtos Disponíveis --------------------------\n";
    cout << left
        << setw(6) << "ID"
        << setw(30) << "Nome"
        << setw(10) << "Qtde"
        << setw(15) << "Preço de Custo"
        << setw(15) << "Preço de Venda"
        << "\n";
    cout << string(76, '-') << "\n";

    cout << fixed << setprecision(2);
    for (const auto& p : produtos) {
        cout << left
            << setw(6) << p.getId()
            << setw(30) << p.getNome()
            << setw(10) << p.getQuantidade()
            << setw(15) << p.getPrecoCusto()
            << setw(15) << p.getPrecoVenda()
            << "\n";
    }
}

void Loja::criarCliente(const string& nome, const string& telefone, const string& morada) {
    Cliente novoCliente(nome, telefone, morada);
    clientes.push_back(novoCliente);
    cout << "Cliente criado.\n";
    proximoIdCliente++;
}

void Loja::eliminarCliente(int idCliente) {
    for (size_t i = 0; i < clientes.size(); i++) {
        if (clientes[i].getIdCliente() == idCliente) {
            clientes.erase(clientes.begin() + i);
            cout << "Cliente removido.\n";
            return;
        }
    }
    cout << "Cliente não encontrado.\n";
}

void Loja::alterarNomeCliente(int idCliente, const string& novoNome) {
    for (size_t i = 0; i < clientes.size(); i++) {
        if (clientes[i].getIdCliente() == idCliente) {
            clientes[i].setNome(novoNome);
            cout << "Nome alterado.\n";
            return;
        }
    }
    cout << "Cliente não encontrado.\n";
}

void Loja::listarClientes() const {
    cout << "\n--- Lista de Clientes ---\n";
    for (const auto& c : clientes) {
        cout << "ID: " << c.getIdCliente()
            << " | Nome: " << c.getNome()
            << " | Telefone: " << c.getTelefone()
            << " | Morada: " << c.getMorada()
            << "\n";
    }
}

bool Loja::criarCarteiraClientes(const string& carteiraClientes) const {
    ofstream arquivo(carteiraClientes);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita: " << carteiraClientes << "\n";
        return false;
    }

    for (const auto& cliente : clientes) {
        arquivo << cliente.getNome() << ";"
            << cliente.getTelefone() << ";"
            << cliente.getMorada() << "\n";
    }

    arquivo.close();
    cout << "Carteira de clientes salva com sucesso no arquivo '" << carteiraClientes << "'.\n";
    return true;
}

bool Loja::carregarCarteiraClientes(const string& carteiraClientes) {
    ifstream arquivo(carteiraClientes);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo: " << carteiraClientes << "\n";
        return false;
    }

    clientes.clear();
    string linha;
    while (getline(arquivo, linha)) {
        istringstream iss(linha);
        string nome, telefone, morada;

        if (getline(iss, nome, ';') && getline(iss, telefone, ';') && getline(iss, morada)) {
            criarCliente(nome, telefone, morada);
        }
    }

    arquivo.close();
    cout << "Clientes carregados com sucesso do arquivo '" << carteiraClientes << "'.\n";
    return true;
}

void Loja::efetuarVenda(int idCliente) {
    Cliente* clienteEncontrado = nullptr;
    for (auto& c : clientes) {
        if (c.getIdCliente() == idCliente) {
            clienteEncontrado = &c;
            break;
        }
    }

    if (!clienteEncontrado) {
        cout << "Cliente não encontrado.\n";
        return;
    }

    Venda novaVenda(proximoNumeroFatura, idCliente);
    proximoNumeroFatura++;

    listarProdutos();

    char mais;
    do {
        int idProduto = lernumero("ID do produto: ");
        int quantidade = lernumero("Quantidade: ");

        Produto* produtoSelecionado = nullptr;
        for (auto& p : produtos) {
            if (p.getId() == idProduto) {
                produtoSelecionado = &p;
                break;
            }
        }

        if (!produtoSelecionado || produtoSelecionado->getQuantidade() < quantidade) {
            cout << "Produto inexistente ou stock insuficiente.\n";
            continue;
        }

        novaVenda.adicionarItem(produtoSelecionado->getNome(), quantidade, produtoSelecionado->getPrecoVenda());
        produtoSelecionado->removerStock(quantidade);

        cout << "Adicionar mais produtos? (s/n): ";
        cin >> mais;
    } while (mais == 's' || mais == 'S');

    float totalVenda = novaVenda.getValorTotal();
    cout << fixed << setprecision(2);
    cout << "\nTotal a pagar: " << totalVenda << "€\n";
    float valorEntregue = lerFloatPositivo("Valor entregue pelo cliente: ");

    novaVenda.finalizarVenda(valorEntregue);
    novaVenda.imprimirTalao();
    clienteEncontrado->adicionarCompra(totalVenda);

    if (vendas.size() < 100) {
        vendas.push_back(novaVenda);
    }
    else {
        vendas[proximoNumeroFatura % 100] = novaVenda;
    }
}
void Loja::listarHistoricoVendas() const {
    cout << "\n--- Histórico de Vendas ---\n";

    if (vendas.empty()) {
        cout << "Nenhuma venda registrada.\n";
        return;
    }

    for (const Venda& venda : vendas) {
        cout << "\nFatura Nº: " << venda.getNumeroFatura()
            << " | Cliente ID: " << venda.getIdCliente()
            << " | Total: R$ " << fixed << setprecision(2) << venda.getValorTotal() << "\n";

        const vector<ItemVenda>& itens = venda.getItens();
        for (const ItemVenda& item : itens) {
            cout << "  - Produto: " << item.nomeProduto
                << " | Quantidade: " << item.quantidade
                << " | Total c/IVA: R$ " << item.totalComIVA << "\n";
        }
    }
}
void Loja::relatorioStock() const {
    cout << "\n--- Relatório de Stock ---\n";
    for (const auto& p : produtos) {
        cout << "Produto: " << p.getNome()
            << " | Quantidade: " << p.getQuantidade() << "\n";
    }
}

void Loja::relatorioVendasPorProduto(const string& nomeProduto) const {
    cout << "\n--- Vendas do Produto: " << nomeProduto << " ---\n";

    for (const auto& venda : vendas) {
        for (const auto& item : venda.getItens()) {
            if (item.nomeProduto == nomeProduto) {
                cout << "Fatura Nº: " << venda.getNumeroFatura()
                    << " | Qtde: " << item.quantidade
                    << " | Total c/IVA: " << item.totalComIVA << "\n";
            }
        }
    }
}

void Loja::relatorioTotalVendas() const {
    cout << "\n--- Relatório Total de Vendas ---\n";

    float total = 0.0f;
    for (const auto& venda : vendas) {
        total += venda.getValorTotal();
    }

    cout << "Total vendido: " << fixed << setprecision(2) << total << "€\n";
}

void Loja::relatorioGraficoVendas() const {
    cout << "\n--- Relatório de Vendas com Gráfico ASCII ---\n";

    map<string, float> totalPorProduto;

    for (const auto& venda : vendas) {
        for (const auto& item : venda.getItens()) {
            totalPorProduto[item.nomeProduto] += item.totalComIVA;
        }
    }

    float maxValor = 0;
    for (const auto& p : totalPorProduto) {
        if (p.second > maxValor)
            maxValor = p.second;
    }

    for (const auto& p : totalPorProduto) {
        int barra = static_cast<int>((p.second / maxValor) * 30);
        cout << setw(20) << left << p.first << " | "
            << string(barra, '#') << " R$ " << fixed << setprecision(2) << p.second << "\n";
    }
}
