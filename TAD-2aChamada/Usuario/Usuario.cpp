#include "Usuario.h"

#include <iostream>

using namespace std;

Usuario::Usuario(int identificador)
{
	if (identificador > 0)
	{
		this->identificador = identificador;
		historico = new float[12];
	}
	else
		cout << "O identificador eh invalido! " << endl;
}
Usuario::~Usuario()
{
	delete[] historico;
}
void Usuario::leHistorico()
{
	cout << "Digite o total de horas para cada mes: " << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << "Mes " << i + 1 << ": " << endl;
		cin >> historico[i];
	}
}
float Usuario::relatorio(int* maior)
{
	float media = 0;
	float soma = 0;
	for (int i = 0; i < 12; i++)
	{
		soma = soma + historico[i];
	}
	media = soma / 12;

	for (int i = 0; i < 12; i++)
	{
		(*maior) = 0;
		if (historico[i] > (*maior))
			(*maior) = historico[i];
	}
	cout << "O mes com maior qtd de horas eh: " << (*maior) << endl;

	return media;
}