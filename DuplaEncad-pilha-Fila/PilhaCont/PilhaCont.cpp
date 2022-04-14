#include <iostream>

using namespace std;

#include "PilhaCont.h"

PilhaCont::PilhaCont(int tam)
{
	max = tam;
	topo = -1;
	vet = new int[max];
}
PilhaCont::~PilhaCont()
{
	delete[] vet;
}

int PilhaCont::getTopo()
{
	if (topo != -1)
		return vet[topo];
	else
	{
		cout << "ERRO: Pilha vazia!" << endl;
		exit(1);
	}
}
bool PilhaCont::vazia()
{
	return (topo == -1);
}

void PilhaCont::empilha(int val)
{
	if (topo == (max - 1)) {
		cout << "ERRO: Vetor Cheio!" << endl;
		exit(2);
	}
	topo = topo + 1;
	vet[topo] = val;
}
int PilhaCont::desempilha()
{
	if (topo == -1) {
		cout << "ERRO: Pilha vazia!" << endl;
		exit(1);
	}
	topo = topo - 1;
	return vet[topo + 1];
}