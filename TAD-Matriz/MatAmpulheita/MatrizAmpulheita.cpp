#include <iostream>
#include "MatrizAmpulheita.h"

MatrizAmpulheita::MatrizAmpulheita(int ordem)
{
    //ctor
    n = ordem;
    dp = new float[n - 2];
    l1 = new float[n];
}

MatrizAmpulheita::~MatrizAmpulheita()
{
    //dtor
    delete[] dp;
    delete[] l1;
}

bool MatrizAmpulheita::verifica(int i, int j)
{
    return (i >= 0 && i < n&& j >= 0 && j < n);
}

float MatrizAmpulheita::get(int i, int j)
{
    if (verifica(i, j))
    {
        if (i == 0)
            return l1[j];
        else if (i == n - 1)
            return -l1[j];
        else if (i == j)
            return dp[i - 1];
        else if (i + j == n - 1)
            return -dp[i - 1];
        else
            return 0.0;
    }
    else
        std::cout << "Erro: indice invalido\n";
}

void MatrizAmpulheita::set(int i, int j, float valor)
{
    if (verifica(i, j))
    {
        if (i == 0)
            l1[j] = valor;
        else if (i == n - 1)
            l1[j] = -valor;
        else if (i == j)
            dp[i - 1] = valor;
        else if (i + j == n - 1)
            dp[i - 1] = -valor;
    }
    else
        std::cout << "Erro: indice invalido\n";
}
