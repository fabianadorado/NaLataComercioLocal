// naLatinha.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iomanip>   // para usar manipuladores de entrada e saida para controlar a formatação dos dados
#include <string>    // para usar strings
#include <ctime>     // para adicionar horas e datas (talao)
#include <sstream>   // para poder usar setprecision em strings || deixa-me usar manipulador de strings
#include <iostream>
#include <limits>
#include <windows.h>
#include <locale>
#include "Loja.h"
#include "auxiliar.h"

#define RESET "\033[0m"  // Define a cor de texto para padrão
#define RED "\033[31m"   // Define a cor de texto para vermelho
#define GREEN "\033[32m" // Define a cor de texto para verde

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    Loja loja;
    int opcao;

    loja.criarProduto("Monsters Punch", 10, 1.99f);
    loja.criarProduto("Monsters Ultra", 10, 2.50f);
    loja.criarProduto("Monsters Mango", 10, 1.75f);
    loja.criarProduto("Monsters Rehab", 10, 1.80f);
    loja.criarProduto("Monsters Rosa", 10, 2.50f);
    loja.criarProduto("Monsters Blue", 10, 1.80f);
    loja.criarProduto("Monsters Red", 10, 1.99f);
    loja.criarProduto("Monsters Gold", 10, 1.75f);
    loja.criarProduto("Monsters Black", 10, 1.80f);
    loja.criarProduto("Monsters White", 10, 1.99f);
    loja.criarCliente("João Silva", "910000000", "Rua A");
    loja.criarCliente("Maria Costa", "920000000", "Rua B");
    system("cls");

    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Efetuar Vendas\n";
        cout << "2. Gerir Produtos\n";
        cout << "3. Gerir Clientes\n";
        cout << "4. Relatórios\n";
        cout << "0. Sair\n";
        opcao = lernumero("Escolha uma opção: ");

        switch (opcao) {
        case 1: {
            int id = lernumero("ID do cliente: ");
            loja.efetuarVenda(id);
            break;
        }
        case 2: {
            system("cls");
            int subOpcao;
            cout << "\n--- GERIR PRODUTOS ---\n";
            cout << "1. Criar Produto\n";
            cout << "2. Adicionar Stock\n";
            cout << "3. Eliminar Produto\n";
            cout << "4. Listar Produto\n";
            subOpcao = lernumero("Escolha uma opção: ");
            switch (subOpcao) {
            case 1: {
                loja.listarProdutos();
                string nome;
                int qtd;
                float preco;
                cout << "Adicionando Novo Produto... \n";
                cout << "Digite o Nome do Produto a Adicionar:\n ";
                cin.ignore();
                getline(cin, nome);
                qtd = lernumero("Insira a Quantidade:\n ");
                cout << "Insira o Preço custo: ";
                cin >> preco;
                loja.criarProduto(nome, qtd, preco);
                system("cls");
                cout << "\nAtualizando Stock...";
                for (int i = 0; i < 5; i++) {
                    cout << "." << flush;
                    Sleep(1500);
                }
                system("cls");
                loja.listarProdutos();
                break;
            }
            case 2: {
                loja.listarProdutos();
                int id = lernumero("ID Produto: ");
                int qtd = lernumero("Qtd a adicionar: ");
                loja.adicionarStock(id, qtd);
                loja.listarProdutos();
                break;
            }
            case 3: {
                loja.listarProdutos();
                int id = lernumero("Digite o ID do Produto que deseja eliminar: ");
                loja.eliminarProduto(id);
                loja.listarProdutos();
                break;
            }
            case 4: {
                loja.listarProdutos();
                break;
            }
            default:
                cout << "Opção inválida!\n";
            }
            break;
        }
        case 3: {
            int subOpcao;
            cout << "\n--- GERIR CLIENTES ---\n";
            cout << "1. Criar Cliente\n";
            cout << "2. Eliminar Cliente\n";
            cout << "3. Alterar Nome Cliente\n";
            cout << "4. Listar Clientes\n";
            cout << "5. Carteira de Clientes\n";
            subOpcao = lernumero("Escolha uma opção: ");
            switch (subOpcao) {
            case 1: {
                string nome, tel, morada;
                cout << "Nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Telefone: ";
                getline(cin, tel);
                cout << "Morada: ";
                getline(cin, morada);
                loja.criarCliente(nome, tel, morada);
                break;
            }
            case 2: {
                int id = lernumero("ID Cliente: ");
                loja.eliminarCliente(id);
                break;
            }
            case 3: {
                int id = lernumero("ID Cliente: ");
                string novoNome;
                cout << "Novo nome: ";
                cin.ignore();
                getline(cin, novoNome);
                loja.alterarNomeCliente(id, novoNome);
                break;
            }
            case 4:
                loja.listarClientes();
                break;
            default:
                cout << "Opção inválida!\n";
            }
            break;
        }
        case 4: {
            int subOpcao;
            cout << "\n--- RELATÓRIOS ---\n";
            cout << "1. Relatório de Stock\n";
            cout << "2. Relatório de Vendas por Produto\n";
            cout << "3. Relatório Total de Vendas\n";
            subOpcao = lernumero("Escolha uma opção: ");
            switch (subOpcao) {
            case 1:
                loja.relatorioStock();
                break;
            case 2: {
                string nome;
                cout << "Nome do produto: ";
                cin.ignore();
                getline(cin, nome);
                loja.relatorioVendasPorProduto(nome);
                break;
            }
            case 3:
                loja.relatorioTotalVendas();
                break;
            default:
                cout << "Opção inválida!\n";
            }
            break;
        }
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida!\n";
        }
    } while (opcao != 0);

    return 0;
}
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida!\n";
        }
    } while (opcao != 0);

    return 0;
}
