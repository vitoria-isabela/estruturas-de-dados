#include <iostream>
using namespace std;

/* Soma de vetores. Crie uma func~ao que receba dois ponteiros (vetores) do tipo
oat e um numero inteiro n indicando o tamanho dos vetores. Esta func~ao deve:
 Alocar um novo vetor result de tamnho n de forma din^amica.
 Calcular a soma dos vetores e armazenar em result.
 Retornar o vetor (i.e. ponteiro para o primeiro elemento do vetor) que contem os resultados. */

float* calculaSoma(int n, float vetA[], float vetB[]);

int main() {
	int n;
	cout << "Insira o tamanho do vetor:  " << endl;
	cin >> n;
	float* vetA = new float[n];
	float* vetB = new float[n];

	float* result = calculaSoma(n, vetA, vetB);

	for (int i = 0; i < n; i++) {
		cout << result[i] << endl;
	}
}

float* calculaSoma(int n, float vetA[], float vetB[])
{
	float* result = new float[n];

	for (int i = 0; i < n; i++) {
		cin >> vetA[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> vetB[i];
	}
	for (int i = 0; i < n; i++) {
		result[i] = vetA[i] + vetB[i];
	}
	return result;
}