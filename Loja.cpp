#include "Loja.h"
#include "auxiliar.h"
#include <windows.h> // necessario para usar sleep
#include <iostream>
#include <iomanip>
#include <cctype> // Para o ToLower
#include <limits> // Para FLT_MAX
#include <map>
using namespace std;

// Construtor padrão
Loja::Loja() {
    proximoIdProduto = 1;
    proximoIdCliente = 1;
    proximoNumeroFatura = 1;
}


//void Loja::criarProduto() {
//    int nAdicionar = lernumero("Quantos produtos deseja adicionar? ");
//    cin.ignore();  // Limpa o buffer para leitura de nomes
//
//    for (int i = 0; i < nAdicionar; i++) {
//        string nome;
//        cout << "\nNome do produto: ";
//        getline(cin, nome);
//
//        string nomeInserido = toLower(nome); // para comparar de forma insensível a maiúsculas
//        bool existe = false;
//
//        for (Produto& p : produtos) {
//            if (toLower(p.getNome()) == nomeInserido) {
//                int quantidade = lernumero("Produto já existe. Quantidade a adicionar: ");
//                p.adicionarStock(quantidade);
//                cout << "Quantidade atualizada.\n";
//                Sleep(1500);
//                existe = true;
//                break;
//            }
//        }
//
//        if (!existe) {
//            int quantidade = lernumero("Quantidade: ");
//            float preco = lerFloatPositivo("Preço de custo: ");
//            criarProduto(nome, quantidade, preco);
//        }
//    }
//
//    system("CLS");
//    cout << "\n\033[32mProdutos atualizados com sucesso!\033[0m\n";
//    listarProdutos();
//}

void Loja::criarProduto(const string& nome, int quantidade, float precoCusto) {
    Produto novoProduto(proximoIdProduto, nome, quantidade, precoCusto);
    produtos.push_back(novoProduto);
    cout << "Produto criado com sucesso.\n";
    proximoIdProduto++;
}


// Adicionar estoque a um produto
void Loja::adicionarStock(int idProduto, int quantidade) {
    for (int i = 0; i < produtos.size(); i++) {
        if (produtos[i].getId() == idProduto) {
            produtos[i].adicionarStock(quantidade);
            cout << "Stock adicionado com sucesso!\n";
            return;
        }
    }
    cout << "Produto não encontrado.\n";
}

// Eliminar produto
//void Loja::eliminarProduto() {
//    int nProdEliminar;
//    cout << "Quantos produtos deseja eliminar? ";
//
//    while (!(cin >> nProdEliminar) || nProdEliminar <= 0) {
//        cout << "\n\033[31mAtenção, digite apenas números maiores que 0.\033[0m\n";
//        cout << "Quantos produtos deseja eliminar? ";
//        cin.clear();
//        cin.ignore(1000, '\n');
//    }
//
//    if (nProdEliminar > produtos.size()) {
//        cout << "\033[31mNão existem " << nProdEliminar << " produtos na loja.\033[0m\n";
//        return;
//    }
//
//    for (int n = 0; n < nProdEliminar; n++) {
//        listarProdutos(); 
//
//        int id;
//        cout << "\nDigite o ID do produto a eliminar: ";
//        cin >> id;
//
//        bool encontrado = false;
//        for (size_t i = 0; i < produtos.size(); i++) {
//            if (produtos[i].getId() == id) {
//                produtos.erase(produtos.begin() + i);
//                cout << "\033[31mProduto eliminado.\033[0m\n";
//                encontrado = true;
//                break;
//            }
//        }
//
//        if (!encontrado) {
//            cout << "\033[31mProduto não encontrado.\033[0m\n";
//        }
//
//        // Atualiza a tela e espera um pouco
//        system("CLS");
//        Sleep(1500);
//    }
//
//    // Mostra os produtos restantes
//    cout << "Atualização de estoque:\n";
//    listarProdutos();
//}

void Loja::eliminarProduto(int idProduto) {
    listarProdutos();
    for (int i = 0; i < produtos.size(); i++) {
        if (produtos[i].getId() == idProduto) {
            produtos.erase(produtos.begin() + i);
            cout << "Produto removido.\n";
            listarProdutos();
            return;
        }
    }
    cout << "Produto não encontrado.\n";
}


void Loja::listarProdutos() const {
    cout << "\n-------------------------- Produtos Disponíveis--------------------------\n";
    cout << left
        << setw(6) << "ID"
        << setw(30) << "Nome"
        << setw(10) << "Qtde"
        << setw(15) << "Preço Custo"
        << setw(15) << "Preço Venda"
        << "\n";
    cout << string(76, '-') << "\n";  // Linha separadora proporcional ao total

    cout << fixed << setprecision(2); // Aplica a todos os preços

    for (const Produto& p : produtos) {
        cout << left
            << setw(6) << p.getId()
            << setw(30) << p.getNome()
            << setw(10) << p.getQuantidade()
            << setw(15) << p.getPrecoCusto()
            << setw(15) << p.getPrecoVenda()
            << "\n";
    }
}


// Criar um novo cliente
void Loja::criarCliente(const string& nome, const string& telefone, const string& morada) {
    Cliente novoCliente(nome, telefone, morada);
    clientes.push_back(novoCliente);
    cout << "Cliente criado.\n";
    proximoIdCliente++;
}

// Eliminar cliente
void Loja::eliminarCliente(int idCliente) {
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].getIdCliente() == idCliente) {
            clientes.erase(clientes.begin() + i);
            cout << "Cliente removido.\n";
            return;
        }
    }
    cout << "Cliente não encontrado.\n";
}

// Alterar nome do cliente
void Loja::alterarNomeCliente(int idCliente, const string& novoNome) {
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].getIdCliente() == idCliente) {
            clientes[i].setNome(novoNome);
            cout << "Nome alterado.\n";
            return;
        }
    }
    cout << "Cliente não encontrado.\n";
}

// Listar todos os clientes
void Loja::listarClientes() const {
    cout << "\n--- Lista de Clientes ---\n";
    for (int i = 0; i < clientes.size(); i++) {
        const Cliente& c = clientes[i];
        cout << "ID: " << c.getIdCliente()
            << " | Nome: " << c.getNome()
            << " | Telefone: " << c.getTelefone()
            << " | Morada: " << c.getMorada()
            << "\n";
    }
}

// Efetuar uma venda
void Loja::efetuarVenda(int idCliente) {
    Cliente* clienteEncontrado = nullptr;

    // Procurar cliente
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].getIdCliente() == idCliente) {
            clienteEncontrado = &clientes[i];
            break;
        }
    }

    if (clienteEncontrado == nullptr) {
        cout << "Cliente não encontrado.\n";
        return;
    }

    Venda novaVenda(proximoNumeroFatura, idCliente);
    proximoNumeroFatura++;

    listarProdutos();

    char mais;
    do {
        int idProduto;
        int quantidade;

        cout << "ID do produto: ";
        cin >> idProduto;
        cout << "Quantidade: ";
        cin >> quantidade;

        Produto* produtoSelecionado = nullptr;

        // Procurar produto
        for (int i = 0; i < produtos.size(); i++) {
            if (produtos[i].getId() == idProduto) {
                produtoSelecionado = &produtos[i];
                break;
            }
        }

        if (produtoSelecionado == nullptr || produtoSelecionado->getQuantidade() < quantidade) {
            cout << "Produto inexistente ou stock insuficiente.\n";
            continue;
        }

        float precoVenda = produtoSelecionado->getPrecoVenda();
        novaVenda.adicionarItem(produtoSelecionado->getNome(), quantidade, precoVenda);
        produtoSelecionado->removerStock(quantidade);

        cout << "Adicionar mais produtos? (s/n): ";
        cin >> mais;
    } while (mais == 's' || mais == 'S');

    float valorEntregue;
    cout << "Valor entregue pelo cliente: ";
    cin >> valorEntregue;

    novaVenda.finalizarVenda(valorEntregue);
    novaVenda.imprimirTalao();

    clienteEncontrado->adicionarCompra(novaVenda.getValorTotal());

    // Guardar venda
    if (vendas.size() < 100) {
        vendas.push_back(novaVenda);
    }
    else {
        vendas[proximoNumeroFatura % 100] = novaVenda;
    }
}

// Relatório de estoque
void Loja::relatorioStock() const {
    cout << "\n--- Relatório de Stock ---\n";
    int total = 0;

    for (int i = 0; i < produtos.size(); i++) {
        const Produto& p = produtos[i];
        total += p.getQuantidade();
        cout << "Produto: " << p.getNome()
            << " | Qtde: " << p.getQuantidade()
            << "\n";
    }

    cout << "Stock total: " << total << "\n";
}

// Relatório de vendas por produto
void Loja::relatorioVendasPorProduto(const string& nomeProduto) const {
    cout << "\n--- Vendas do Produto: " << nomeProduto << " ---\n";

    for (int i = 0; i < vendas.size(); i++) {
        const Venda& venda = vendas[i];
        const vector<ItemVenda>& itens = venda.getItens();

        for (int j = 0; j < itens.size(); j++) {
            const ItemVenda& item = itens[j];

            if (item.nomeProduto == nomeProduto) {
                cout << "Fatura Nº: " << venda.getNumeroFatura()
                    << " | Qtde: " << item.quantidade
                    << " | Total c/IVA: " << item.totalComIVA
                    << "\n";
            }
        }
    }
}

// Relatório total de vendas
void Loja::relatorioTotalVendas() const {
    cout << "\n--- Relatório Total de Vendas ---\n";

    float total = 0;
    float maiorTotal = 0;
    float menorTotal = FLT_MAX;

    string maisVendido;
    string menosVendido;

    map<string, float> totaisPorProduto;
    map<int, float> totalPorCliente;

    for (int i = 0; i < vendas.size(); i++) {
        const Venda& venda = vendas[i];
        total += venda.getValorTotal();
        totalPorCliente[venda.getIdCliente()] += venda.getValorTotal();

        const vector<ItemVenda>& itens = venda.getItens();

        for (int j = 0; j < itens.size(); j++) {
            const ItemVenda& item = itens[j];
            totaisPorProduto[item.nomeProduto] += item.totalComIVA;
        }
    }

    for (const auto& par : totaisPorProduto) {
        if (par.second > maiorTotal) {
            maiorTotal = par.second;
            maisVendido = par.first;
        }
        if (par.second < menorTotal) {
            menorTotal = par.second;
            menosVendido = par.first;
        }
    }

    int clienteTop = 0;
    float valorTop = 0;

    for (const auto& par : totalPorCliente) {
        if (par.second > valorTop) {
            valorTop = par.second;
            clienteTop = par.first;
        }
    }

    cout << "Total vendido: " << total << "\n";
    cout << "Produto mais vendido: " << maisVendido << " (" << maiorTotal << ")\n";
    cout << "Produto menos vendido: " << menosVendido << " (" << menorTotal << ")\n";
    cout << "Cliente que mais comprou (ID): " << clienteTop << " com total: " << valorTop << "\n";
}

void Loja::relatorioGraficoVendas() const {
    cout << "\n--- Relatório de Vendas com Gráfico ASCII ---\n";

    // Mapeia produto ? total vendido
    map<string, float> totalPorProduto;

    for (const Venda& venda : vendas) {
        for (const ItemVenda& item : venda.getItens()) {
            totalPorProduto[item.nomeProduto] += item.totalComIVA;
        }
    }

    // Descobre maior valor para normalizar a barra
    float maxValor = 0;
    for (const auto& p : totalPorProduto) {
        if (p.second > maxValor)
            maxValor = p.second;
    }

    // Exibe o gráfico
    for (const auto& p : totalPorProduto) {
        string nome = p.first;
        float valor = p.second;

        int barraTam = static_cast<int>((valor / maxValor) * 30); // normaliza para 30 caracteres
        cout << setw(20) << left << nome << " | "
            << string(barraTam, '?') << "  R$ " << fixed << setprecision(2) << valor << endl;
    }
}