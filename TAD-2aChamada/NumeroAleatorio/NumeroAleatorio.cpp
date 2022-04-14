#include "NumeroAleatorio.h"

#include <iostream>
using namespace std;

NumeroAleatorio::NumeroAleatorio(int s, int min, int max)
{
	setSemente(s);
	if (min == max)
	{
		cout << "Os limites minimo e maximo devem ser diferentes!";
		exit(1);
	}
	else if (min > max)
	{
		minimo = max;
		maximo = min;
	}
	else
	{
		minimo = min;
		maximo = max;
	}
}
void NumeroAleatorio::setSemente(int s)
{
	if (s < 0 || s >= 101)
	{
		cout << "Semente invalida!";
		exit(1);
	}
	semente = s;
}
int* NumeroAleatorio::proximos(int n)
{
	int* numeros = new int[n];
	int anterior = semente;
	for (int i = 0; i < n; i++)
	{
		numeros[i] = (7 * anterior + 13) % 101;
		anterior = numeros[i];
	}
	for (int i = 0; i < n; i++)
		numeros[i] = minimo + numeros[i] % maximo;
	return numeros;
}