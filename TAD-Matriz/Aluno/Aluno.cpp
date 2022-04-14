#include <string>
#include <iostream>
using namespace std;

#include "Aluno.h"

Aluno::Aluno(string n, string m) {
	this->n = n;
	this->m = m;
}
Aluno::~Aluno() {
	cout << "Destruindo aluno: " << n << endl;
}
float Aluno::getNota() {
	return nota;
}
void Aluno::setNota(float valor) {
	cout << "Alterando nota do aluno" << endl;
	n = valor;
}

bool Aluno::verificaAprovado() {
	if (nota >= 60.0)
		return true;
	else
		return false;
}
string Aluno::getNome() {
	return n;
}

void Aluno::info()
{
	cout << "Nome: " << n << endl;
	cout << "Matricula: " << m << endl;
	cout << "Nota: " << nota << endl;
	if (verificaAprovado())
		cout << "Situacao: aprovado" << endl;
	else
		cout << "Situacao: reprovado" << endl;
}
