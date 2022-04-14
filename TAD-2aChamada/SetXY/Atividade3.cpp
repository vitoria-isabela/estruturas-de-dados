#include "Atividade3.h"

#include <iostream>

using namespace std;

Atividade3::Atividade3(int tam)
{
    n = tam;
    x = new int[n];
    y = 0;
    setX();
}

Atividade3::~Atividade3()
{
    delete[] x;
}

void Atividade3::setX()
{
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

void Atividade3::setY()
{
    y = 0;
    for (int i = 0; i < n; i++)
        y += x[i] * i;
}

int Atividade3::getY()
{
    if (y == 0)
        setY();
    return y;
}