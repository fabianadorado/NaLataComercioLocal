//#include <iostream>
//#include <iomanip>
//#include <windows.h>  // Para SetConsoleOutputCP
//
//using namespace std;
//
//#define RESET   "\033[0m"
//#define CYAN    "\033[36m"
//#define GREEN   "\033[32m"
//#define BOLD    "\033[1m"
//#define YELLOW  "\033[33m"
//
//int main() {
//    SetConsoleOutputCP(CP_UTF8);
//    SetConsoleCP(CP_UTF8);
//
//    const int largura = 28;
//    cout << CYAN;
//    cout << u8"╔═════════════════════════════╗\n";
//    cout << u8"║" << BOLD << setw((largura + 18) / 2) << right << "MENU PRINCIPAL"
//        << setw((largura - 16) / 2) << left << "" << RESET << CYAN << u8"║\n";
//    cout << u8"╠═════════════════════════════╣\n";
//
//    cout << CYAN;
//    cout << u8"║ 1 - Efetuar Vendas          ║\n";
//    cout << u8"║ 2 - Gerir Produtos          ║\n";
//    cout << u8"║ 3 - Gerir Clientes          ║\n";
//    cout << u8"║ 4 - Relatórios              ║\n";
//    cout << u8"║ 0 - Sair                    ║\n";
//
//    cout << CYAN << u8"╚═════════════════════════════╝\n" << RESET;
//    cout << YELLOW << "Escolha uma opção: " << RESET;
//
//    int op;
//    cin >> op;
//    return 0;
//}
