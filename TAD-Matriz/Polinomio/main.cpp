#include <iostream>
#include "polinomio.h"

using namespace std;

int main()
{
    //cria um vetor de tamanho 4
    int n = 3;
    float* vet = new float[n + 1];
    for (int i = 0; i <= n; i++)
        vet[i] = 2.0 + i + 2;

    //cria 2 polin�mios iguais p1 e p2 de grau 3
    Polinomio p1(n, vet), p2(n, vet), * somaPoli;

    cout << p1.avalia(0.5) << endl;

    somaPoli = p2.soma(&p1);  ///somaPoli = p1 + p2

    cout << somaPoli->avalia(0.0) << endl;

    delete somaPoli;
    delete[] vet;
    return 0;
}
