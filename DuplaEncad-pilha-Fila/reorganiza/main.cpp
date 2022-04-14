#include <iostream>
#include "FilaEncad.h"
#include "C:\Users\6113826\source\repos\EstruturadeDados\DuplaEncad-pilha-Fila\PilhaEncad\PilhaEncad.h"

using namespace std;

void inverteFila(FilaEncad* f);
FilaEncad* concatena(FilaEncad* f1, FilaEncad* f2);
void removeDaPilha(PilhaEncad* p, int x);
void reorganiza(FilaEncad* f);

/// <summary>
/// Implementar a função void reorganiza(FilaEncad *f) que recebe uma fila f como
//parâmetro e modifica a ordem dos elementos de forma a posicionar aqueles de maior
//prioridade no início da fila.Um nó será considerado como prioritário se possuir valor maior
//que 70. A função deve garantir que a ordem original dos nós de mesma prioridade ficará
//inalterada, ou seja, todos os valores pertencentes ao mesmo grupo(grupo dos menores ou
//iguais a 70 ou grupo maiores que 70) manterão a mesma ordem relativa entre si.
//    Exemplo: se a fila original contiver a sequência :
//
//    15 85 69 40 71 70 30 92 100 54
//
//então, após execução da função, a nova ordem dos elementos deverá ser a seguinte :
//
//    85 71 92 100 15 69 40 70 30 54
/// </summary>
/// <returns></returns>
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
	/*PilhaEncad p;

	for (int i = 0; i < 5; i++)
		p.empilha(i);
	int x = 2;
	removeDaPilha(&p, x);
	p.imprime();*/
	FilaEncad f;
	f.enfileira(15);
	f.enfileira(85);
	f.enfileira(71);
	f.enfileira(75);
	f.enfileira(62);
	f.enfileira(70);
	f.enfileira(30);
	f.enfileira(92);
	f.enfileira(100);
	f.enfileira(54);

	f.imprime();
	reorganiza(&f);
	f.imprime();

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

void reorganiza(FilaEncad* f)
{
	FilaEncad maior70, menor70;

	while (!f->vazia())
	{
		if (f->getInicio() > 70)
			maior70.enfileira(f->desenfileira());
		else
			menor70.enfileira(f->desenfileira());
	}

	while (!maior70.vazia())
		f->enfileira(maior70.desenfileira());
	while (!menor70.vazia())
		f->enfileira(menor70.desenfileira());
}