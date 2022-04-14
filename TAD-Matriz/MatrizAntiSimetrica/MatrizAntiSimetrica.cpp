#include <iostream>
#include "MatrizAntiSimetrica.h"

MatrizAntiSimetrica::MatrizAntiSimetrica(int ordem)
{
    //ctor
    n = ordem;
    int tam = n * (n - 1) / 2;
    vet = new float[tam];
}

MatrizAntiSimetrica::~MatrizAntiSimetrica()
{
    //dtor
    delete[] vet;
}

bool MatrizAntiSimetrica::verifica(int i, int j)
{
    return (i >= 0 && i < n&& j >= 0 && j < n);
};

float MatrizAntiSimetrica::get(int i, int j)
{
    if (verifica(i, j))
    {
        if (i == j)
            return 0.0;
        else if (i < j)
            return -vet[j * (j - 1) / 2 + i];
        else
            return vet[i * (i - 1) / 2 + j];
    }
    else
        std::cout << "Erro: indice invalido\n";
}

void MatrizAntiSimetrica::set(int i, int j, float valor)
{
    if (verifica(i, j))
    {
        if (i < j)
            vet[j * (j - 1) / 2 + i] =-valor;
        else if (i > j)
            vet[i * (i - 1) / 2 + j] = valor;
        /*        else if(valor!=0)
                    std::cout << "Valor nao zero na DP\n";
        */
    }
    else
        std::cout << "Erro: indice invalido\n";
}