// -*-coding: utf - 8 - *-
// Venda.cpp
#include "venda.h"
#include <iomanip>   // para usar manipuladores de entrada e saida para controlar a formatação dos dados
#include <ctime>     // para adicionar horas e datas (talao)
#include <sstream>   // para poder usar setprecision em strings || deixa-me usar manipulador de strings
#include <iostream>
#include <limits>
#include <random>     // Para geração de números aleatórios
#include <chrono>     // Para geração de sementes aleatórias


#define RESET "\033[0m"  // Define a cor de texto para padrão
#define RED "\033[31m"   // Define a cor de texto para vermelho
#define GREEN "\033[32m" // Define a cor de texto para verde

//using namespace std;

ItemVenda::ItemVenda(int linha, const string& nomeProduto, int quantidade, double precoUnit)
    :   numeroLinha(linha), 
        nomeProduto(nomeProduto), 
        quantidade(quantidade),
        precoSemIVA (precoUnit * quantidade),
        iva (precoSemIVA * 0.23), // 23% IVA
        totalComIVA (precoSemIVA + iva)
{
       
}

// Inicialização do gerador aleatório
mt19937 Venda::gerador(std::random_device{}());
uniform_int_distribution<int> Venda::distribuidor(10000, 99999);

//Venda::Venda() 
//    :   numeroFatura(""),
//        idCliente(0), 
//        valorEntregue(0.0f), 
//        troco(0.0f) 
//{
//
//}

// Construtores da Venda
Venda::Venda() 
    :   idCliente(0),
        valorEntregue(0.0),
        troco(0.0)
{
        ostringstream criarNFatura;
        criarNFatura << distribuidor(gerador);
        numeroFatura = criarNFatura.str();
}

//Venda::Venda(int numeroFatura, int idCliente)
//    : numeroFatura(numeroFatura), idCliente(idCliente), valorEntregue(0.0f), troco(0.0f) {
//}

Venda::Venda(int idCliente) 
    :   idCliente(idCliente), 
        valorEntregue(0.0), 
        troco(0.0) 
{
    ostringstream criarNFatura;
    criarNFatura << distribuidor(gerador);
    numeroFatura = criarNFatura.str();
}

// Métodos da Venda
void Venda::adicionarItem(const string& nomeProduto, int quantidade, double precoUnit)
{
    // Validações essenciais
    if (quantidade <= 0) 
    {
        throw invalid_argument("Quantidade deve ser maior que zero");
    }

    if (precoUnit < 0) 
    {
        throw invalid_argument("Preço unitário não pode ser negativo");
    }
    int linha = itens.size() + 1;
    ItemVenda item(linha, nomeProduto, quantidade, precoUnit);
    itens.push_back(item);
}

void Venda::finalizarVenda(double valorEntregue)
{
    this->valorEntregue = valorEntregue;
    double total = getValorTotal();
    troco = valorEntregue - total;
    if (troco < 0)
    {
        troco = 0;
    }
}

double Venda::getValorTotal() const
{
    double total = 0.0;
    for (const auto& item : itens)
    {
        total += item.totalComIVA;
    }
    return total;
}

double Venda::getTroco() const
{
    return troco;
}

string Venda::getNumeroFatura() const
{
    return numeroFatura;
}

int Venda::getIdCliente() const
{
    return idCliente;
}

void Venda::imprimirTalao() const
{
    // Configurações de cores ANSI
    const string endColor = "\033[0m";
    const string FUNDO_BRANCO = "\033[47m";
    const string TEXTO_PRETO = "\033[30m";
    const string NEGRITO = "\033[1m";
    const string VERDE = "\033[32m";

    // Obter data atual
    time_t agora = time(0);
    tm tempoLocal;
    localtime_s(&tempoLocal, &agora);
    string data = to_string(tempoLocal.tm_mday) + "/" +
        to_string(tempoLocal.tm_mon + 1) + "/" +
        to_string(tempoLocal.tm_year + 1900);

    // Configurações de layout
    const int LARGURA = 60;
    auto linhaHorizontal = [&](char inicio, char fim) {
        cout << NEGRITO << inicio << string(LARGURA, '─') << fim << RESET << endl;
        };

    auto linhaComBordas = [&](const string& conteudo) {
        return NEGRITO + "│ " + conteudo +
            string(LARGURA - 2 - conteudo.length(), ' ') + " │" + RESET;
        };

    // Início do talão
    cout << FUNDO_BRANCO << TEXTO_PRETO;
    linhaHorizontal('┌', '┐');

    // Cabeçalho
    cout << linhaComBordas("TALÃO DE COMPRA") << endl;
    linhaHorizontal('├', '┤');

    // Informações da venda
    cout << linhaComBordas("Data: " + data) << endl;
    cout << linhaComBordas("Fatura Nº: " + numeroFatura) << endl;
    cout << linhaComBordas("Cliente ID: " + to_string(idCliente)) << endl;
    linhaHorizontal('├', '┤');

    // Cabeçalho dos itens
    cout << linhaComBordas("ITENS COMPRADOS") << endl;
    linhaHorizontal('├', '┤');

    // Lista de itens
    for (const auto& item : itens) {
        ostringstream oss;
        oss << item.numeroLinha << ". " << left << setw(20) << item.nomeProduto
            << right << setw(3) << item.quantidade << " x "
            << fixed << setprecision(2) << (item.precoSemIVA / item.quantidade)
            << " = " << item.totalComIVA << " €";

        cout << linhaComBordas(oss.str()) << endl;
    }

    // Totais
    linhaHorizontal('├', '┤');

    double total = getValorTotal();
    if (gratis) {
        cout << linhaComBordas(VERDE + "COMPRA GRATUITA!" + RESET) << endl;
    }
    else {
        double semIVA = total / 1.23;
        double iva = total - semIVA;

        auto formatar = [](string label, double valor) {
            ostringstream oss;
            oss << right << setw(10) << fixed << setprecision(2) << valor << " €";
            return label + oss.str();
            };

        cout << linhaComBordas(formatar("Subtotal: ", semIVA)) << endl;
        cout << linhaComBordas(formatar("IVA (23%): ", iva)) << endl;
        cout << linhaComBordas(formatar("TOTAL: ", total)) << endl;
        linhaHorizontal('├', '┤');
        cout << linhaComBordas(formatar("Valor pago: ", valorEntregue)) << endl;
        cout << linhaComBordas(formatar("Troco: ", troco)) << endl;
    }

    // Rodapé
    linhaHorizontal('├', '┤');
    cout << linhaComBordas("Obrigado pela sua preferência!") << endl;
    linhaHorizontal('└', '┘');

    // Reset cores
    cout << endColor;

   /* system("CLS");
    system("color 70");
    cout << "\n\n==================== TALAO DE COMPRA ====================\n";
    time_t agora = time(0);
    tm tempoLocal;
    localtime_s(&tempoLocal, &agora);
    cout << "Data: " << tempoLocal.tm_mday << "/" << tempoLocal.tm_mon + 1 << "/" << tempoLocal.tm_year + 1900 << "\n";
    cout << "Fatura Nº: " << numeroFatura << " | Cliente Nº: " << idCliente << endl;
    cout << "---------------------------------------------------------\n";
    cout << left << setw(15) << "Item" << setw(15) << "Produto" << setw(10) << "Qtd" << setw(15) << "Preco S/IVA" << setw(10) << "IVA" << setw(10) << "Total" << endl;
    cout << "---------------------------------------------------------\n";
    for (const auto& item : itens) {
        cout << left << setw(15) << item.numeroLinha
            << setw(15) << item.nomeProduto
            << setw(10) << item.quantidade
            << setw(10) << fixed << setprecision(2) << item.precoSemIVA
            << setw(10) << fixed << setprecision(2) << item.iva
            << setw(10) << fixed << setprecision(2) << item.totalComIVA << endl;
    }

    if (gratis)
    {
        cout << GREEN
            << "COMPRA GRATUITA!\n"
            << RESET;
    }
    else
    {
        cout << "Total: " << fixed << setprecision(2) << getValorTotal() << " euros\n";
        cout << "Valor pago: " << fixed << setprecision(2) << valorEntregue << " euros\n";
        cout << "Troco: " << fixed << setprecision(2) << troco << " euros\n";
    }

    cout << "=========================================================\n";
    cout << "Obrigado pela sua preferencia!\n";*/
}