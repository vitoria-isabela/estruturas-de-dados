#include <iostream>
#include "Atividade3.h"

using namespace std;

Atividade3::Atividade3(int n)
{ 
	this->n = n;
	x = new int[n];
	m = 0.0;
	setX();
}

Atividade3::~Atividade3()
{
	delete [] x;
}

void Atividade3::setX()
{
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
}

void Atividade3::setM()
{
	float media = 0.0;
	for (int i = 0; i < n; i++)
	{
		media += x[i];
	}
	m = media / n;

	/*cout << "media dos " << n << "valores lidos: " << m << endl;*/
}

float Atividade3::getM()
{
	if (m == 0)
		setM();
	return m;
}