#include <iostream>
using namespace std;

/* Desenvolver uma função recursiva, int sucessor(int n, int vet[], int x)  para, dados:
o número de elementos n do vetor vet;
o vetor de inteiros positivos vet[] e
um inteiro positivo x.
determinar e retornar o valor de vet que corresponda ao sucessor de x.
Caso vet não possua o sucessor de x, retornar -1. O inteiro sucessor de x é o menor valor de vet maior que x.
 */

int sucessor(int n, int vet[], int x);

int main()
{
	int n;
	cout << "Insira o tamanho do vetor:  " << endl;
	cin >> n;
	int* vet = new int[n];

	cout << "Insira os valores do vetor: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> vet[i];
	}

	int x;
	cout << "Insira o valor a ser analisado o seu sucessor: " << endl;
	cin >> x;

	cout << "O sucessor de x eh: " << sucessor(n, vet, x) << endl;

	delete[] vet;

}

int sucessor(int n, int vet[], int x)
{
	if (n == 0)
		return -1;
	else
	{
		///determina o sucessor, suc, dos n-1 elementos de vet
		int suc = sucessor(n - 1, vet, x);
		if (vet[n - 1] > x) //candidato a sucessor
			if (vet[n - 1] < suc || suc == -1)
				return vet[n - 1]; //novo sucessor
			else
				return suc;//sucessor achado nos n-1 elementos
		else
			return suc; //sucessor achado nos n-1 elementos
	}
}

