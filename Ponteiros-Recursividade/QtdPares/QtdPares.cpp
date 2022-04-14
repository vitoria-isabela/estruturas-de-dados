#include <iostream>
using namespace std;

/* Desenvolver uma função recursiva para calcular e retornar
a quantidade de valores pares de um vetor v com n
números inteiros. */

int pares(int vet[], int n);

int main()
{
	int n;
	cout << "Insira o tamanho do vetor:  " << endl;
	cin >> n;
	int* vet = new int[n];

	for (int i = 0; i < n; i++)
		cin >> vet[i];

	cout << pares(vet, n);
}

int pares(int vet[], int n)
{
	n = n - 1;

	if (n < 0)
	{
		return 0;
	}
	else if ((vet[n] % 2) == 0)
	{
		return (1 + pares(vet, n));
	}
	else
	{
		return pares(vet, n);
	}
}