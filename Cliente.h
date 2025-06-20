#pragma once

#include <iostream>
#include <string>
#include <sstream>

using std::string;

class Cliente {
private:
    static int proximoCliente;
    int idCliente;
    string nome;
    string telefone;
    string morada;
    float totalComprado;

public:
    Cliente();
    Cliente(string nome, string telefone, string morada, float totalComprado = 0.0f);

    // Getters
    int getIdCliente() const;
    string getNome() const;
    string getTelefone() const;
    string getMorada() const;
    float getTotalComprado() const;

    // Setters
    void setIdCliente(int id);
    void setNome(string nome);
    void setTelefone(string telefone);
    void setMorada(string morada);

    // Outros métodos
    void adicionarCompra(float valor);
    string toString() const;
};
