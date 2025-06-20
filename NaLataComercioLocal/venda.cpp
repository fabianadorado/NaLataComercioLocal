// Venda.cpp
#include <iomanip>   // para usar manipuladores de entrada e saida para controlar a formatação dos dados
#include <string>    // para usar strings
#include <ctime>     // para adicionar horas e datas (talao)
#include <sstream>   // para poder usar setprecision em strings || deixa-me usar manipulador de strings
#include <iostream>
#include <limits>
#include "Venda.h"
#include <ctime>     // para adicionar horas e datas (talao)

#define RESET "\033[0m"  // Define a cor de texto para padrão
#define RED "\033[31m"   // Define a cor de texto para vermelho
#define GREEN "\033[32m" // Define a cor de texto para verde

using namespace std;

ItemVenda::ItemVenda(int linha, const string& nomeProduto, int quantidade, float precoUnit)
    : numeroLinha(linha), nomeProduto(nomeProduto), quantidade(quantidade) {
    precoSemIVA = precoUnit * quantidade;
    iva = precoSemIVA * 0.23f; // 23% IVA
    totalComIVA = precoSemIVA + iva;
}

Venda::Venda() : numeroFatura(0), idCliente(0), valorEntregue(0.0f), troco(0.0f) {}

Venda::Venda(int numeroFatura, int idCliente)
    : numeroFatura(numeroFatura), idCliente(idCliente), valorEntregue(0.0f), troco(0.0f) {
}

void Venda::adicionarItem(const string& nomeProduto, int quantidade, float precoUnit)
{
    int linha = itens.size() + 1;
    ItemVenda item(linha, nomeProduto, quantidade, precoUnit);
    itens.push_back(item);
}

void Venda::finalizarVenda(float valorEntregue)
{
    this->valorEntregue = valorEntregue;
    float total = getValorTotal();
    troco = valorEntregue - total;
    if (troco < 0)
    {
        troco = 0;
    }
}

float Venda::getValorTotal() const
{
    float total = 0.0f;
    for (const auto& item : itens)
    {
        total += item.totalComIVA;
    }
    return total;
}

float Venda::getTroco() const
{
    return troco;
}

int Venda::getNumeroFatura() const
{
    return numeroFatura;
}

int Venda::getIdCliente() const
{
    return idCliente;
}

void Venda::imprimirTalao()
{
    system("CLS");
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
    cout << "Obrigado pela sua preferencia!\n";
}