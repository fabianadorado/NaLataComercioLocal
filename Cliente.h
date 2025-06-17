#pragma once
#include<iostream>
#include <string>
#include <sstream>

using namespace std;


class Cliente
{
private:
	static int proximoCliente;
	int idCliente;
	string nome;
	string telefone;
	string morada;
	float totalComprado;

public:

	Cliente();
	Cliente(string nome, string telefone, string morada, float totalComprado = 0);



	int getIdCliente() const;
	string getNome()const;
	string getTelefone()const;
	string getMorada()const;
	float getTotalComprado()const;

	void setIdCliente(int idCliente);
	void setNome(string nome);
	void setTelefone(string telefone);
	void setMorada(string morada);
	void adicionarCompra(float valor);

	string toString() const;
};