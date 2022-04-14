#include <iostream>
#include "MatrizAmpulheta.h"

MatrizAmpulheta::MatrizAmpulheta(int ordem)
{
	//ctor
	n = ordem;
	vet = new float[3 * n - 4];
}

MatrizAmpulheta::~MatrizAmpulheta()
{
	//dtor
	delete[] vet;
}

bool MatrizAmpulheta::verifica(int i, int j)
{
	return (i >= 0 && i < n && j >= 0 && j < n);
}

float MatrizAmpulheta::get(int i, int j)
{
	if (verifica(i, j))
	{
		if (i == 0)
			return vet[j];
		else if (i == n - 1)
			return -vet[j];
		else if (i == j)
			return vet[n + n - 2 + (i - 1)];
		else if (i + j == n - 1)
			return -vet[n + n - 2 + (i - 1)];
		else
			return 0.0;
	}
	else
		std::cout << "Erro: indice invalido\n";
}

void MatrizAmpulheta::set(int i, int j, float valor)
{
	if (verifica(i, j))
	{
		if (i == 0)
			vet[j] = valor;
		else if (i == n - 1)
			vet[j] = -valor;
		else if (i == j)
			vet[n + n - 2 + (i - 1)] = valor;
		else if (i + j == n - 1)
			vet[n + n - 2 + (i - 1)] = -valor;
	}
	else
		std::cout << "Erro: indice invalido\n";
}
