#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont() {};

ListaCont::ListaCont(int tam)
{
	///cout << "Criando objeto ListaCont" << endl;

	n = 0; ///cria uma lista vazia
	max = tam;
	vet = new int[max];
}

ListaCont::~ListaCont()
{
	cout << "Destruindo objeto ListaCont" << endl;
	delete[] vet;
}

int ListaCont::get(int k)
{
	if (k >= 0 && k < n)
		return vet[k];
	else
	{
		cout << "ERRO: Indice invalido!" << endl;
		exit(1);
	}
}

void ListaCont::set(int k, int val)
{
	if (k >= 0 && k < n)
		vet[k] = val;
	else
	{
		cout << "ERRO: Indice invalido!" << endl;
		exit(1);
	}
}

void ListaCont::realoca()
{
	max = max * 1.4;  ///max = max + 30
	cout << max << endl;
	int* v = new int[max];

	for (int i = 0; i < n; i++)
		v[i] = vet[i];

	delete[] vet;

	vet = v;
}

void ListaCont::insereFinal(int val)
{
	if (n == max) ///lista cheia
		realoca();
	vet[n] = val;
	n = n + 1;
}

void ListaCont::removeFinal()
{
	if (n == 0)
	{
		cout << "ERRO: Lista Vazia!" << endl;
		exit(1);
	}
	n = n - 1;
}

void ListaCont::insereK(int k, int val)
{
	if (n == max)
		realoca();

	if (k >= 0 && k < n)
	{
		///desloca todos os n�s a partir de k uma posi��o para direita
		for (int i = n - 1; i >= k; i--)
			vet[i + 1] = vet[i];

		vet[k] = val;
		n = n + 1;
	}
	else
	{
		cout << "ERRO: Indice invalido!" << endl;
		exit(1);
	}
}

void ListaCont::removeK(int k)
{
	if (k >= 0 && k < n)
	{
		for (int i = k; i < n - 1; i++)
			vet[i] = vet[i + 1];
		n = n - 1;
	}
	else
	{
		cout << "ERRO: Indice invalido!" << endl;
		exit(1);
	}
}

void ListaCont::removeInicio()
{
	removeK(0);
}

void ListaCont::imprime()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << vet[i] << "\t";
	cout << "\n\n";
}

void ListaCont::limpar()
{
	n = 0;
}

void ListaCont::intercala(ListaCont* la, ListaCont* lb)
{
	// Limpando a lista interna.
	limpar();
	// Ajusta tamanho da lista interna para caber
	// todos os elementos (apenas se for preciso).
	int tamFinal = la->n + lb->n;
	if (max < tamFinal)
		realocaVetor(tamFinal);
	// Faz a intercalação das duas listas.

	while (la->n > 0 && lb->n > 0) {
		insereFinal(la->vet[0]);
		insereFinal(lb->vet[0]);
		la->removeInicio();
		lb->removeInicio();
	}
	// Caso as listas tenham tamanhos diferentes,
	// copia os elementos restantes da maior lista.
	while (la->n > 0) {
		insereFinal(la->get(0));
		la->removeInicio();
	}
	while (lb->n > 0) {
		insereFinal(lb->get(0));
		lb->removeInicio();
	}
}
/* Operação apresentada na aula de laboratório */
void ListaCont::realocaVetor(int newMax) {
	if (newMax >= n) {
		// Aloca novo vetor com novo tamanho
		int* newVet = new int[newMax];
		// Copia todos os elementos do vetor atual para o novo
		for (int i = 0; i < n; i++)
			newVet[i] = vet[i];
		// Deleta o antigo vetor
		delete[] vet;
		// Atualiza o vetor e o máximo da classe com os novos valores
		vet = newVet;
		max = newMax;
	}
	else {
		cout << "ERRO: Novo tamanho invalido!" << endl;
		exit(1);
	}
}