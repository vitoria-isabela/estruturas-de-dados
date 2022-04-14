#include "MatrizEspecial.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

MatrizEspecial::MatrizEspecial(int mm)
{
	if (mm < 3) {
		cout << "Dimensoes invalidas" << endl;
		exit(1);
	}
	n = mm;
	vet = new float[(2 * n) + (n / 3 - 4)]; // segue a ordem: vet [ DP, DS, quadrado central]
}
MatrizEspecial::~MatrizEspecial()
{
	delete[] vet;
}

int MatrizEspecial::detInd(int i, int j)
{
	if (i >= 0 && i < n && j >= 0 && j < n)
	{
		int k;
		if ((i == j) || (i + j == (n - 1))) // DP ou DS
			k = i;
		else
			if ((i >= n / 3)  && n-1 <= (n / 3) &&  j >= (n/3) && n-1 <= (n / 3)) //Quadrado central 
				k = i;
			else
				return -2; /* Aqui retornamos -2 para no Get indicar que elementos com esse retorno terão valor 0 */
		return k;
	}
	else {
		return -1; /* Aqui retornamos -1 para no Get indicar que elementos com esse retorno NÃO estão dentro dos elementos que podem ser representados na matriz */
	}
}

float MatrizEspecial::get(int i, int j)
{
	int k = detInd(i, j);
	if (k != -1)
	{
		if (i == j)
			return vet[k];
		if (j + i == (n - 1))
			return vet[k];
		if (k == -2)
			return 0;
		return vet[k];
	}
	else
	{
		cout << "ERRO: Indice invalido!" << endl;
		exit(1);
	}
}

void MatrizEspecial::set(int i, int j, float val)
{
	int k = detInd(i, j);
	if (k != -1)
		vet[k] = val;
	else
		cout << "ERRO: Indice invalido!" << endl;
}


//else
			//	if (j == (n - 1)) //Ultima Coluna
			//		k = n + n - 2 + (i - 1); /* Com racíocinio análogo ao de cima, somamos o n da DP, o (n - 2) 
			//								 da primeira coluna e subtraimos 1 no indice de linhas da ultima coluna 
			//								 (pq começa a contar na linha abaixo da DS)*/
			//								 ///Olhar desenho para entender melhor!
