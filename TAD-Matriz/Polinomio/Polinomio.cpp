#include <iostream>
#include "polinomio.h"
#include "math.h"
Polinomio::Polinomio(int nn)
{
    //ctor
    if (nn >= 0)
        n = nn;
    else
        n = 1;
    vet = new float[n + 1];
}

Polinomio::Polinomio(int nn, float coef[])
{
    //ctor
    if (nn >= 0)
        n = nn;
    else
        n = 1;
    vet = new float[n + 1];
    set(nn, coef);
}

Polinomio::~Polinomio()
{
    //dtor
    delete[] vet;
}


void Polinomio::set(int nn, float coef[])
{
    if (nn == n)
    {
        for (int i = 0; i <= n; i++)
            vet[i] = coef[i];
    }
    else
        std::cout << "valor de n inv�lido";
}


float Polinomio::avalia(float x)
{
    float soma = 0.0;
    for (int i = 0; i <= n; i++)
        soma = soma + vet[i] * pow(x, i);
    return soma;
}

Polinomio* Polinomio::soma(Polinomio* p)
{

    if (n == p->n)
    {

        Polinomio* paux = new Polinomio(p->n);
        for (int i = 0; i <= this->n; i++)
            paux->vet[i] = this->vet[i] + p->vet[i];

        return paux;
    }
    else
    {
        std::cout << "graus diferentes";
        return NULL;
    }
}
