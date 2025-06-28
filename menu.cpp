#include "Menu.h"
#include <iostream>
#include <iomanip>
#include <windows.h> 

using namespace std;

#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define BOLD    "\033[1m"
#define YELLOW  "\033[33m"



int Menu::menuPrincipal() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int largura = 28;
    cout << CYAN;
    cout << u8"╔═════════════════════════════╗\n";
    cout << u8"║" << BOLD << setw((largura + 18) / 2) << right << "MENU PRINCIPAL"
        << setw((largura - 16) / 2) << left << "" << RESET << CYAN << u8"║\n";
    cout << u8"╠═════════════════════════════╣\n";

    cout << CYAN;
    cout << u8"║ 1 - Efetuar Vendas          ║\n";
    cout << u8"║ 2 - Gerir Produtos          ║\n";
    cout << u8"║ 3 - Gerir Clientes          ║\n";
    cout << u8"║ 4 - Relatórios              ║\n";
    cout << u8"║ 0 - Sair                    ║\n";

    cout << CYAN << u8"╚═════════════════════════════╝\n" << RESET;
    cout << YELLOW << "Escolha uma opção: " << RESET;

    int opcao;
    cin >> opcao;
    return opcao;
}

int Menu::menuGerirProdutos() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int largura = 28;
    cout << CYAN;
    cout << u8"╔═════════════════════════════╗\n";
    cout << u8"║" << BOLD << setw((largura + 18) / 2) << right << "GERIR PRODUTOS"
        << setw((largura - 16) / 2) << left << "" << RESET << CYAN << u8"║\n";
    cout << u8"╠═════════════════════════════╣\n";

    cout << CYAN;
    cout << u8"║ 1 - Criar Produto          ║\n";
    cout << u8"║ 2 - Adicionar Stock        ║\n";
    cout << u8"║ 3 - Eliminar Produto       ║\n";
    cout << u8"║ 4 - Listar Produto         ║\n";
    
    cout << CYAN << u8"╚═════════════════════════════╝\n" << RESET;
    cout << YELLOW << "Escolha uma opção: " << RESET;

    int opcao;
    cin >> opcao;
    return opcao;
}

int Menu::menuGerirClientes() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int largura = 28;
    cout << CYAN;
    cout << u8"╔═════════════════════════════╗\n";
    cout << u8"║" << BOLD << setw((largura + 18) / 2) << right << "GERIR CLIENTES"
        << setw((largura - 16) / 2) << left << "" << RESET << CYAN << u8"║\n";
    cout << u8"╠═════════════════════════════╣\n";
    cout << u8"║ 1 - Criar Cliente          ║\n";
    cout << u8"║ 2 - Eliminar Cliente       ║\n";
    cout << u8"║ 3 - Alterar Nome Cliente   ║\n";
    cout << u8"║ 4 - Listar Clientes        ║\n";
    cout << u8"║ 5 - Criar Carteira         ║\n";
    cout << u8"║ 6 - Carregar Carteira      ║\n";
   
    cout << CYAN << u8"╚═════════════════════════════╝\n" << RESET;
    cout << YELLOW << "Escolha uma opção: " << RESET;

    int opcao;
    cin >> opcao;
    return opcao;
}

int Menu::menuRelatorios() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int largura = 28;
    cout << CYAN;
    cout << u8"╔═════════════════════════════╗\n";
    cout << u8"║" << BOLD << setw((largura + 18) / 2) << right << "RELATÓRIOS"
        << setw((largura - 16) / 2) << left << "" << RESET << CYAN << u8"║\n";
    cout << u8"╠═════════════════════════════╣\n";
    cout << u8"║ 1 - Relatório de Stock     ║\n";
    cout << u8"║ 2 - Vendas por Produto     ║\n";
    cout << u8"║ 3 - Total de Vendas        ║\n";
    cout << u8"║ 4 - Gráfico de Vendas      ║\n";
    cout << u8"║ 5 - Histórico de Vendas    ║\n";

    cout << CYAN << u8"╚═════════════════════════════╝\n" << RESET;
    cout << YELLOW << "Escolha uma opção: " << RESET;

    int op;
    cin >> op;
    return op;
}