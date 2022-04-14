#include <iostream>
#include "Atividade3.h"

using namespace std;


/// <summary>
/// Defina e desenvolva o TAD Atividade3, que deve possuir os seguintes atributos:
//● int n(quantidade de valores);
//● float m(média dos valores);
//● int* x(valores).
//Além disso, o TAD Atividade3 deve oferecer as seguintes operações :
//● Construtor, que recebe a quantidade total de valores e chama a operação para ler os
//valores de x;
//● Destrutor;
//● Operação void setX(); que deve realizar a leitura dos valores do vetor x;
//● Operação void setM(); que deve calcular a média dos valores de x e colocar em m;
//● Operação float getM(); que deve retornar a média m.No caso do valor ainda não
//ter sido calculado, chamar a operação que faz o cálculo da média.
/// </summary>
/// <returns></returns>
int main()
{
	int n;
	cout << "Digite a qtd de valores " << ": " << endl;
	cin >> n;

	Atividade3 a(n);
	cout << "Media: " << a.getM() << endl;
	return 0;
}