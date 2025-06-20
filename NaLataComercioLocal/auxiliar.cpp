#include "auxiliar.h"
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

int lernumero(const string& mensagem) {
    int valor;
    while (true) {
        cout << mensagem;
        if (cin >> valor && valor > 0) {
            cin.ignore(1000, '\n');
            return valor;
        }
        cout << "\033[31mEntrada inválida. Digite um número inteiro maior que 0.\033[0m\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

float lerFloatPositivo(const string& mensagem) {
    float valor;
    while (true) {
        cout << mensagem;
        if (cin >> valor && valor >= 0.0f) {
            cin.ignore(1000, '\n');
            return valor;
        }
        cout << "\033[31mEntrada inválida. Digite um número válido (>= 0).\033[0m\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

string toLower(const string& str) {
    string resultado = str;
    for (char& c : resultado) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return resultado;
}