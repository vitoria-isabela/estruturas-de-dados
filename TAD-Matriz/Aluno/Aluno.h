#pragma once
#include <string>
#include <iostream>

using namespace std;
class Aluno
{
public:
	Aluno(string n, string m); // construtor
	~Aluno(); // destrutor
	void info(); // operacoes
	float getNota();
	string getNome();
	void setNota(float valor);
	bool verificaAprovado();
private:
	string n; // dados
	string m;
	float nota;
};
