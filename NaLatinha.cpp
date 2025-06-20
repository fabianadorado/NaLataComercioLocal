#define NOMINMAX
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
#include <limits>
#include <windows.h>
#include <locale>
#include "Loja.h"
#include "menu.h"
#include "auxiliar.h"

#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define BOLD    "\033[1m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    Menu menu;
    Loja loja;

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

    loja.criarCliente("João Silva", "910520630", "Rua A");
    loja.criarCliente("Maria Costa", "920987654", "Rua B");

    system("cls");

    int opcao;

    do {
        opcao = menu.menuPrincipal();

        switch (opcao) {
        case 1: {
            int id = lernumero("ID do cliente: ");
            loja.efetuarVenda(id);
            break;
        }
        case 2: {
            bool continuar = true;
            do {
                int sub = menu.menuGerirProdutos();
                switch (sub) {
                case 1: {
                    loja.listarProdutos();
                    string nome;
                    int qtd;
                    float preco;
                    cout << "Adicionando Novo Produto... \n";
                    cin.ignore();
                    cout << "Digite o Nome do Produto a Adicionar:\n ";
                    getline(cin, nome);
                    qtd = lernumero("Insira a Quantidade:\n ");
                    cout << "Insira o Preço custo: ";
                    cin >> preco;
                    loja.criarProduto(nome, qtd, preco);
                    system("cls");
                    cout << "\nAtualizando Stock...";
                    for (int i = 0; i < 5; i++) {
                        cout << "." << flush;
                        Sleep(500);
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
                    cout << YELLOW << "\nPressione Enter para voltar..." << RESET;
                    cin.ignore();
                    cin.get();
                    continuar = false;
                    continue;
                }
                default:
                    cout << RED << "Opção inválida!\n" << RESET;
                }

                cout << YELLOW << "\nDeseja continuar neste menu? (s/n): " << RESET;
                char resp;
                cin >> resp;
                if (resp != 's' && resp != 'S') continuar = false;

            } while (continuar);
            break;
        }

        case 3: {
            bool continuar = true;
            do {
                int sub = menu.menuGerirClientes();
                switch (sub) {
                case 1: {
                    string nome, tel, morada;
                    cout << "Nome: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, novoNome);
                    loja.alterarNomeCliente(id, novoNome);
                    break;
                }
                case 4: {
                    loja.listarClientes();
                    cout << YELLOW << "\nPressione Enter para voltar..." << RESET;
                    cin.ignore();
                    cin.get();
                    continuar = false;
                    continue;
                }
                case 5: {
                    loja.criarCarteiraClientes();  
                    cout << GREEN << "Carteira de clientes criada com sucesso.\n" << RESET;
                    break;
                }
                case 6: {
                    loja.carregarCarteiraClientes();  
                    cout << GREEN << "Carteira de clientes carregada com sucesso.\n" << RESET;
                    break;
                }
                default:
                    cout << RED << "Opção inválida!\n" << RESET;
                }

                cout << YELLOW << "\nDeseja continuar neste menu? (s/n): " << RESET;
                char resp;
                cin >> resp;
                if (resp != 's' && resp != 'S') continuar = false;

            } while (continuar);
            break;
        }

        case 4: {
            bool continuar = true;
            do {
                int sub = menu.menuRelatorios();
                switch (sub) {
                case 1:
                    loja.relatorioStock();
                    break;
                case 2: {
                    string nome;
                    cout << "Nome do produto: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, nome);
                    loja.relatorioVendasPorProduto(nome);
                    break;
                }
                case 3:
                    loja.relatorioTotalVendas();
                    break;
                case 4:
                    loja.relatorioGraficoVendas();
                    break;
                case 5:
                    loja.listarHistoricoVendas();
                    break;
                default:
                    cout << RED << "Opção inválida!\n" << RESET;
                }

                cout << YELLOW << "\nPressione Enter para voltar..." << RESET;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                continuar = false;

            } while (continuar);
            break;
        }


        case 0:
            cout << GREEN << "Encerrando sistema...\n" << RESET;
            break;

        default:
            cout << RED << "Opção inválida!\n" << RESET;
        }

        system("pause");

    } while (opcao != 0);

    return 0;
}
