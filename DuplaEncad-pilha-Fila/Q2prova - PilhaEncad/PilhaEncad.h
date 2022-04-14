#pragma once

#include "No.h"
class PilhaEncad
{
private:
	No* topo;
	int n;
public:
	PilhaEncad();
	~PilhaEncad();
	int getTopo();
	void empilha(int val);
	int desempilha();
	bool vazia();
	void imprime();
	int tamanho();
};