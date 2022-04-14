#include <iostream>
using namespace std;
#include "MatrizLin.h"

bool simetric(MatrizLin* matriz, int l, int c);
float* prodMatVet(MatrizLin* m, float* v);

int main()
{
	int m, n;
	cin >> m >> n;
	MatrizLin mat(m, n);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			float val;
			cin >> val;
			mat.set(i, j, val);
		}

	mat.imprime(m, n);

	if (simetric(&mat, m, n))
	{
		cout << "Eh simetrica!" << endl;
	}
	else
	{
		cout << "Nao eh simetrica!" << endl;
	}

	cout << "Maior valor da matriz: " << mat.maiorValor() << endl;

	MatrizLin* trans = mat.transposta();
	//cout << "A transposta eh: " << trans->transposta() << endl;
	trans->imprime(n, m);

	float* vetProd = new float[m];

		for (int i = 0; i < n; i++)
		{
			cin >> vetProd[i];
		}

		cout << "Vetor = [";
		for (int i = 0; i < n; i++)
			cout << vetProd[i] << " ";
		cout << "]" << endl;

	float* resultProdMatVet = prodMatVet(trans, vetProd);

	cout << "Vetor 2 = [ " << endl;
	for (int i = 0; i < n; i++)
		cout << resultProdMatVet[i] << " ";
	cout << "]" << endl;

	return 0;
}

bool simetric(MatrizLin* matriz, int l, int c)
{
	if (l != c)
	{
		cout << " A Matriz precisa ser quadrada!" << endl;
		return false;
	}
	else
	{
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (matriz->get(i, j) != matriz->get(j, i))
					return false;
			}
		}
	}
	return true;
}

float* prodMatVet(MatrizLin* m, float* v)
{
	float* x = new float[ m->getNl() ];

	for (int i = 0; i < m->getNl(); i++)
	{
		float prod = 0.0;
		for (int j = 0; j < m->getNc(); j++)
		{
			prod += m->get(i, j) * v[j];
		}
		x[i] = prod;
	}
	return x;
}