#include <iostream>

using namespace std;

#include "PilhaEncad.h"

int* inverte(int vet[], int n);

int main()
{
	//PilhaEncad p;

	//for (int i = 0; i < 3; i++)
	//	p.empilha(i);

	/*cout << "Pilha apos inserir 5 valores:" << endl;*/

	//p.desempilha();

	/*for(int i = 20; i < 25; i++)
		p.empilha(i);

	cout << "Pilha apos inserir mais 5 valores:" << endl;

	p.imprime();
	int tam = p.tamanho();
	cout << tam << endl;

	bool vazia = p.vazia();
	cout << vazia << endl;
	cout << p.getTopo();

	p.desempilha();
	p.desempilha();
	p.desempilha();*/

	//p.imprime();
	int v[] = {0, 1, 2};
	int* vet = inverte(v, 3);
	for(int i = 0; i<3; i++)
		cout << vet[i] << " ";
}

int* inverte(int vet[], int n)
{
	int *newVet = new int[n];
	PilhaEncad p;
	for (int i = 0; i < n; i++)
		p.empilha(vet[i]);

	for (int i = 0; !p.vazia(); i++)
		newVet[i] = p.desempilha();

	return newVet;
}