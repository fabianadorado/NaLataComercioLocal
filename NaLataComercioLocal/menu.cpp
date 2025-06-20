#include "menu.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// Cores ANSI
#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define BOLD    "\033[1m"
#define YELLOW  "\033[33m"

int Menu::menuPrincipal() {
    const int largura = 32;
    system("cls");

    cout << CYAN;
    cout << "╔" << string(largura, '═') << "╗\n";
    cout << "║" << BOLD << setw((largura + 18) / 2) << right << "MENU PRINCIPAL"
        << setw((largura - 18) / 2) << left << "" << RESET << CYAN << "║\n";
    cout << "╠" << string(largura, '═') << "╣\n";

    cout << GREEN;
    cout << "║ 1 - Efetuar Vendas          ║\n";
    cout << "║ 2 - Gerir Produtos          ║\n";
    cout << "║ 3 - Gerir Clientes          ║\n";
    cout << "║ 4 - Relatórios              ║\n";
    cout << "║ 0 - Sair                    ║\n";

    cout << CYAN << "╚" << string(largura, '═') << "╝\n" << RESET;
    cout << YELLOW << "Escolha uma opção: " << RESET;

    int opcao;
    cin >> opcao;
    return opcao;
}

int Menu::menuGerirProdutos() {
    system("cls");
    cout << CYAN << "╔════════════════════════════╗\n";
    cout << "║" << BOLD << "       GERIR PRODUTOS       " << RESET << CYAN << "║\n";
    cout << "╠════════════════════════════╣\n";
    cout << GREEN;
    cout << "║ 1 - Criar Produto          ║\n";
    cout << "║ 2 - Adicionar Stock        ║\n";
    cout << "║ 3 - Eliminar Produto       ║\n";
    cout << "║ 4 - Listar Produto         ║\n";
    cout << CYAN << "╚════════════════════════════╝\n" << RESET;
    cout << YELLOW << "Escolha uma opção: " << RESET;

    int op;
    cin >> op;
    return op;
}

int Menu::menuGerirClientes() {
    system("cls");
    cout << CYAN << "╔════════════════════════════╗\n";
    cout << "║" << BOLD << "       GERIR CLIENTES       " << RESET << CYAN << "║\n";
    cout << "╠════════════════════════════╣\n";
    cout << GREEN;
    cout << "║ 1 - Criar Cliente          ║\n";
    cout << "║ 2 - Eliminar Cliente       ║\n";
    cout << "║ 3 - Alterar Nome Cliente   ║\n";
    cout << "║ 4 - Listar Clientes        ║\n";
    cout << "║ 5 - Criar Carteira         ║\n";
    cout << "║ 6 - Carregar Carteira      ║\n";
    cout << CYAN << "╚════════════════════════════╝\n" << RESET;
    cout << YELLOW << "Escolha uma opção: " << RESET;

    int op;
    cin >> op;
    return op;
}


int Menu::menuRelatorios() {
    system("cls");
    cout << CYAN << "╔════════════════════════════╗\n";
    cout << "║" << BOLD << "         RELATÓRIOS         " << RESET << CYAN << "║\n";
    cout << "╠════════════════════════════╣\n";
    cout << GREEN;
    cout << "║ 1 - Relatório de Stock     ║\n";
    cout << "║ 2 - Vendas por Produto     ║\n";
    cout << "║ 3 - Total de Vendas        ║\n";
    cout << "║ 4 - Gráfico de Vendas      ║\n";
    cout << "║ 5 - Histórico de Vendas    ║\n";
    cout << CYAN << "╚════════════════════════════╝\n" << RESET;
    cout << YELLOW << "Escolha uma opção: " << RESET;

    int op;
    cin >> op;
    return op;
}

