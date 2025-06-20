#include "cliente.h"
#include <string>
#include <sstream>
using namespace std;


int Cliente::proximoCliente = 1;

// Construtor padrão
Cliente::Cliente()
    : idCliente(proximoCliente++), nome(""), telefone(""), morada(""), totalComprado(0.0f) {
}

// Construtor com parâmetros
Cliente::Cliente(string nome, string telefone, string morada, float totalComprado)
    : idCliente(proximoCliente++), nome(nome), telefone(telefone), morada(morada), totalComprado(totalComprado) {
}

// Getters
int Cliente::getIdCliente() const {
    return idCliente;
}

string Cliente::getNome() const {
    return nome;
}

string Cliente::getTelefone() const {
    return telefone;
}

string Cliente::getMorada() const {
    return morada;
}

float Cliente::getTotalComprado() const {
    return totalComprado;
}

// Setters
void Cliente::setIdCliente(int id) {
    idCliente = id;
    if (id >= proximoCliente) {
        proximoCliente = id + 1;
    }
}

void Cliente::setNome(string nome) {
    this->nome = nome;
}

void Cliente::setTelefone(string telefone) {
    this->telefone = telefone;
}

void Cliente::setMorada(string morada) {
    this->morada = morada;
}


void Cliente::adicionarCompra(float valor) {
    totalComprado += valor;
}

string Cliente::toString() const {
    stringstream dadosCliente;
    dadosCliente << "ID: " << idCliente
        << " | Nome: " << nome
        << " | Telefone: " << telefone
        << " | Morada: " << morada;
    return dadosCliente.str();
}
