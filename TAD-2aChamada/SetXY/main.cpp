#include "Atividade3.h"

#include <iostream>

using namespace std;

/// <summary>
/// Defina e desenvolva o TAD Atividade3, que deve possuir os seguintes atributos:
//int n(quantidade de valores);
//int y(soma ponderada dos valores);
//int* x(valores).
//Além disso, o TAD Atividade3 deve oferecer as seguintes operações :
//Construtor, que recebe a quantidade total de valores e chama a operação para ler os valores de x;
//Destrutor;
//Operação void setX(); que deve realizar a leitura dos valores do vetores x;
//Operação void setY();  que deve calcular a soma ponderada dos valores de x e colocar em m.Cada posição tem o peso relativo a seu índice;
//Operação int getY(); que deve retornar o valor de y.No caso do valor ainda não ter sido calculado, chamar a operação que faz o cálculo da soma ponderada.
/// </summary>
/// <returns></returns>
int main()
{
    int tam;
    cin >> tam;
    Atividade3 a(tam);
    cout << "Y: " << a.getY() << endl;
    return 0;
}