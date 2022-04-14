#include <iostream>
#include "FilaEncad.h"
#include "C:\Users\6113826\source\repos\EstruturadeDados\DuplaEncad-pilha-Fila\PilhaEncad\PilhaEncad.h"

using namespace std;

void inverteFila(FilaEncad* f);
FilaEncad* concatena(FilaEncad* f1, FilaEncad* f2);
void removeDaPilha(PilhaEncad* p, int x);

int main()
{

	/// TESTE COM FILA

	/*FilaEncad f1, f2;
	for (int i = 0; i < 5; i++)
		f1.enfileira(i);*/

	/*cout << "Fila apos inserir 5 valores" << endl;*/
	/*f1.imprime();*/

	//for (int i = 3; i < 9; i++)
	//    f2.enfileira(i);

	//cout << "Fila apos inserir mais 5 valores" << endl;
	/*f1.imprime();
	f2.imprime();

	FilaEncad* f3 = concatena(&f1, &f2);
	f3->imprime();*/

	//inverteFila(&f);

	//cout << "Fila invertida: " << endl;
	//f.imprime();
	PilhaEncad p; 

	for (int i = 0; i < 5; i++)
		p.empilha(i);
	int x = 2;
	removeDaPilha(&p, x);
	p.imprime();
	return 0;
}

void inverteFila(FilaEncad* f)
{
	PilhaEncad p;

	while (!f->vazia())
		p.empilha(f->desenfileira());

	while (!p.vazia())
		f->enfileira(p.desempilha());
}

FilaEncad* concatena(FilaEncad* f1, FilaEncad* f2)
{
	FilaEncad* newfila = new FilaEncad();

	while (!f1->vazia())
		newfila->enfileira(f1->desenfileira());

	//enfileira valores da f2, apenas se eles não estiverem contidos na nova fila 
	while (!f2->vazia())
	{
		int val = f2->desenfileira();
		if (!newfila->jaContido(val))
			newfila->enfileira(val);
	}
	return newfila;
}

void removeDaPilha(PilhaEncad* p, int x)
{
	PilhaEncad pAux;

	while (!p->vazia())
	{
		int val = p->desempilha();

		if (val == x)
			break;
		else
			pAux.empilha(val);
	}
	while (!pAux.vazia())
		p->empilha(pAux.desempilha());
}