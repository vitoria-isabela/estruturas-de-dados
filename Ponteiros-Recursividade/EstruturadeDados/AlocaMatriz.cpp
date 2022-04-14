#include <iostream>
using namespace std;

/* Matriz com vetor de ponteiros. Crie uma func~ao que aloque dinamicamente uma matriz
de tamanho m x n de valores do tipo
oat e inicialize todos os seus elementos com o valor 0.*/

float** alocaMatrizF(int m, int n);

int main()
{
	int tamLinha, tamColuna;
	cout << "Digite o n° de Linhas:" << endl;
	cin >> tamLinha;
	cout << "Digite o n° de Colunas:" << endl;
	cin >> tamColuna;

	float** matriz = alocaMatrizF(tamLinha, tamColuna);

	cout << "todos os índices inicializados com 0: " << endl;

	for (int i = 0; i < tamLinha; i++) {

		for (int j = 0; j < tamColuna; j++)
		{
			cout << " " << matriz[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < tamLinha; i++)
	{
		delete[] matriz[i];
	}

	delete[] matriz;

	return 0;
}

float** alocaMatrizF(int m, int n)
{
	float** matriz = new float* [m];

	for (int i = 0; i < m; i++)
	{
		matriz[i] = new float[n];
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			matriz[i][j] = 0;
		}
	return matriz;
}