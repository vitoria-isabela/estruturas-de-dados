#include <iostream>
using namespace std;
/* Implemente uma função que receba uma matriz m x n de valores do
tipo float, crie e retorne sua matriz transposta n x m. */

float** transposta(int m, int n, float** mat);

int main()
{
	int m, n;
	cout << "Digite o n° de Linhas: " << endl;
	cin >> m;
	cout << "Digite o n° de Colunas: " << endl;
	cin >> n;

	float** matriz = new float* [m];

	for (int i = 0; i < m; i++)
	{
		matriz[i] = new float[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Linha " << i << " e Coluna " << j << " ";
			cin >> matriz[i][j];
		}
	}

	float** mat = transposta(n, m, matriz);

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++)
		{
			cout << " " << mat[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < m; i++)
	{
		delete[] matriz[i];
	}

	delete[] matriz;
}


float** transposta(int m, int n, float** mat)
{
	float** vetAux = new float* [m];

	for (int k = 0; k < m; k++)
	{
		vetAux[k] = new float[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vetAux[i][j] = mat[j][i];
		}
	}
	return vetAux;
}