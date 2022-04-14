#include <iostream>
#include "FilaEncad.h"

using namespace std;

void inverteFila(FilaEncad* f);
FilaEncad* concatena(FilaEncad* f1, FilaEncad* f2);
bool verifica_troco(FilaEncad* f);

/// <summary>
/// Suponha uma fila de pessoas esperando para comprar sorvete que custa 5 dinheiros. Inicialmente, 
/// o caixa tem zero dinheiros para oferecer de troco e cada elemento da fila representa a nota que
///  a pessoa vai utilizar para o pagamento. Escreva uma função no programa principal 
/// bool verifica_troco(FilaEncad *f) que recebe a fila como parâmetro e verifica se a 
/// sorveteria tem troco para todos que estão na fila. 
//Dica: para simplificar, considere para troco apenas as notas de 5 e de 10 e 
//considere que 20 será o valor máximo usado para pagamento.Considere também que
//a verificação do troco será feita somente no momento em que a pessoa estiver sendo
//atendida, ou seja, a pessoa não poderá aguardar pelo troco de outra que está atrás dela na fila.
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
	f.enfileira(5);
	f.enfileira(5);
	f.enfileira(5);
	f.enfileira(10);
	f.enfileira(20);
	bool temTroco = verifica_troco(&f);
	cout << temTroco << endl;
	/*FilaEncad* f1 = f.reorganiza(&f);
	f.imprime();

	f1->imprime();

	delete f1;*/

	return 0;
}

//void inverteFila(FilaEncad* f)
//{
//	PilhaEncad p;
//
//	while (!f->vazia())
//		p.empilha(f->desenfileira());
//
//	while (!p.vazia())
//		f->enfileira(p.desempilha());
//}

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

bool verifica_troco(FilaEncad* f) {
	int troco = 0;

	//verifica se a fila não está vazia
	if (!f->vazia())
	{
		if (f->getInicio() == 5) //Como no início o caixa está sem troco, a primeira pessoa tem que estar com o dinheiro trocado
		{
			troco += 5; // incrementa o troco da primeira pessoa
			f->desenfileira();
		}
		else 
		{
			if ((troco - f->getInicio()) < 0) // para as outras pessoas da fila, deve ser verificado se há troco, caso precise.
			{ 
				return false;
			}
			else
				return true;
		}
	}
	else {
		cout << "Fila Vazia!" << endl;
	}
}

//bool verifica_troco(FilaEncad* f) {
//	int troco = 0;
//	//fila nao vazia
//	if (f->vazia() == false) {
//		if (f->getInicio() == 5) {
//			troco += 5;
//			f->desenfileira();
//		}
//		else {
//			if ((troco - f->getInicio()) < 0) {
//				return false;
//			}
//		}
//	}
//	else {
//		cout << "Fila Vazia!" << endl;
//	}
//	return true;
//}