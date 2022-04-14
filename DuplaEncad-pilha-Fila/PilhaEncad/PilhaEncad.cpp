#include <iostream>
#include <cstdlib>

using namespace std;

#include "PilhaEncad.h"

PilhaEncad::PilhaEncad()
{
	topo = NULL;
	n = 0;
}
PilhaEncad::~PilhaEncad()

{
	No* p = topo;
	while (topo != NULL) {
		topo = p->getProx();
		delete p;
		p = topo;
	}
}

int PilhaEncad::getTopo()
{
	if (topo != NULL)
		return topo->getInfo();
	else
	{
		cout << "ERRO: Pilha vazia!" << endl;
		exit(1);
	}
}
void PilhaEncad::empilha(int val)
{
	No* p = new No();
	p->setInfo(val);
	p->setProx(topo);
	topo = p; // Atualizo topo com o valor de p
	n++; // incremento o numero de nos da Pilha
}

int PilhaEncad::desempilha() {
	No* p;
	int val;
	if (topo != NULL) {
		p = topo;
		topo = p->getProx(); 
		val = p->getInfo();
		n--;
		delete p;
	}
	else
		exit(1);
	return val;
}
bool PilhaEncad::vazia()
{
	if (topo == NULL)
		return (true);
	else
		return (false);
}

void PilhaEncad::imprime()
{
	No* p = topo;
	cout << endl;
	while (p != NULL)
	{
		cout << p->getInfo() << " ";
		p = p->getProx();
	}
	cout << endl;
}

int PilhaEncad::tamanho()
{
	return n;
}