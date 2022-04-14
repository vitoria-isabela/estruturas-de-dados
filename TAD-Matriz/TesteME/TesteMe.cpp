#include "TesteME.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

TesteME::TesteME(int mm)
{
	if (mm < 3) {
		cout << "Dimensoes invalidas" << endl;
		exit(1);
	}
	n = mm;
	vetDPouDS = new float[n];
	vetPrimeiraCol = new float[n - 2];
}
TesteME::~TesteME()
{
	//delete[] vetDPouDS;
	//delete[] vetPrimeiraCol;
}

bool TesteME::verifica(int i, int j)
{
	return (i >= 0 && i < n&& j >= 0 && j < n);
}

float TesteME::get(int i, int j)
{
	if (verifica(i, j))
	{
		if (i == j)
			return vetDPouDS[i]; // DP
		if (j + i == (n - 1))
			return -vetDPouDS[i]; //DS
		if (j == 0)
			return vetPrimeiraCol[n - 2]; //Primeira col
		if (j == (n - 1))
			return -vetPrimeiraCol[n - 2]; // Ultima col
		return 0;
	}
	else
	{
		cout << "ERRO: Indice invalido!" << endl;
		exit(1);
	}
}

void TesteME::set(int i, int j, float val)
{
	if (verifica(i, j))
	{
		if (i == j)
			vetDPouDS[i] = val; // DP
		if (j + i == (n - 1))
			vetDPouDS[i] = -val; //DS
		if (j == 0)
			vetPrimeiraCol[n - 2] = val; //Primeira col
		if (j == (n - 1))
			vetPrimeiraCol[n - 2] = -val; // Ultima col
	}

	else
		cout << "ERRO: Indice invalido!" << endl;
}

