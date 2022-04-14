#include <iostream>
#include "MatAlternada.h"
#include <math.h>
MatAlternada::MatAlternada(int ordem)
{
    //ctor
    n = ordem;
    int tam;

    /*    if(n % 2 == 0)
            tam = (n*n)/2;
        else
            tam = (n/2 + 1) * n;
    */
    tam = ceil(n / 2.0) * n;
    vet = new float[tam];
}

MatAlternada::~MatAlternada()
{
    //dtor
    delete[] vet;
}

bool MatAlternada::verifica(int i, int j)
{
    return (i >= 0 && i < n&& j >= 0 && j < n);
}

float MatAlternada::get(int i, int j)
{
    if (verifica(i, j))
    {
        int k = (i / 2) * n + j;
        if (i % 2 == 0)
            return vet[k];
        else
            return -vet[k];
    }
    else
        std::cout << "Erro: indice invalido\n";
}

void MatAlternada::set(int i, int j, float valor)
{
    if (verifica(i, j))
    {
        int k = (i / 2) * n + j;

        if (i % 2 == 0)
            vet[k] = valor;
        else
            vet[k] = -valor;
    }
    else
        std::cout << "Erro: indice invalido\n";
}
