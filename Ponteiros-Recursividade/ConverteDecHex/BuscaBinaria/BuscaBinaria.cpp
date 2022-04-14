#include <iostream>
using namespace std;

/* Escreva uma func~ao recursiva que faca a busca por uma chave (um valor especco) em um
array ordenada usando o algoritmo da busca binaria. A func~ao recebe como par^ametros o array
de inteiros, seu tamanho e a chave a ser procurada e deve retornar se encontrou ou n~ao o valor
da chave. */

bool buscaBinaria(int vet[], int n, int chave);
int auxBuscaBinaria(int vet[], int inicio, int fim, int chave);

int main() {
	int n;
	cout << "Insira o tamanho do vetor:  " << endl;
	cin >> n;

	int* vet = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> vet[i];
	}

	int chave;
	cout << "Insira a chave: " << endl;
	cin >> chave;

	int inicio, fim;
	inicio = 0;
	fim = n - 1;

	auxBuscaBinaria(vet, inicio, fim, chave);

	cout << "Chave encontrada? " << buscaBinaria(vet, n, chave) << endl;
}

bool buscaBinaria(int vet[], int n, int chave)
{
	int inicio, fim;
	inicio = 0;
	fim = n - 1;
	int result;
	result = auxBuscaBinaria(vet, inicio, fim, chave);
	if (result != -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int auxBuscaBinaria(int vet[], int inicio, int fim, int chave) {
	int meio;

	if (inicio > fim) {
		return -1;
	}
	else {
		meio = (inicio + fim) / 2;
		if (vet[meio] == chave)
		{
			return meio;
		}
		else if (chave < vet[meio])
		{
			return auxBuscaBinaria(vet, inicio, meio - 1, chave);
		}
		else
		{
			return auxBuscaBinaria(vet, meio + 1, fim, chave);
		}
	}
}