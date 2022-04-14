#include <iostream>
#include "Data.h"

using namespace std;


/// <summary>
/// Definir e desenvolver o TAD Data para representar uma data. O TAD deve possuir os
//seguintes atributos :
//● int dia(número inteiro entre 1 e 30 que representa dia do mês);
//● int mes(número inteiro entre 1 e 12 que representa um dos 12 meses);
//● int ano(número inteiro positivo).
//Em nenhuma das operações não se pode gerar objetos inválidos.Isso quer dizer que
//as variáveis membros(atributos) têm que satisfazer as restrições descritas acima.Deve - se
//atribuir 1 para dia e mes e 1000 para ano se o seu respectivo valor for inválido.
//Além disso, o TAD Data deve oferecer as seguintes operações :
//● Construtor, que recebe 3 números inteiros(d, m e a) e os atribui aos atributos dia, mes
//e ano.
//● Operação setDiaMesAno(int d, int m, int a); que deve alterar o valor de
//dia, mes e ano;
//● Operação void imprime(); que deve imprimir uma data no formato : dd / mm / aaaa;
//● Operação Data* somaAnos(int nAnos) para retornar um ponteiro para um objeto
//Data correspondente à soma de nAnos ao ano de uma data.
/// </summary>
/// <returns></returns>
int main()
{
	int d, m, a;
	cin >> d >> m >> a;
	Data x(d, m, a);

	int numYears;
	cin >> numYears;

	Data* y = x.somaAnos(numYears);

	cout << "Primeira data: ";
	x.imprime();
	cout << endl;
	cout << "Segunda data: ";
	y->imprime();
}