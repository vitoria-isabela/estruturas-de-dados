#include <iostream>
#include <stdlib.h>
#include "Ponto.h"

using namespace std;

Ponto::Ponto(float xx, float yy)
{
    setX(xx);
    setY(yy);
}

Ponto::~Ponto(){}

Ponto::Ponto()
{
    setX(0.0);
    setY(0.0);
}

float Ponto::getX()
{
    if (x == 0)
        setX(x);
    return x;
}

float Ponto::getY()
{
    return y;
}

void Ponto::setX(float x)
{
    this->x = x;
}

void Ponto::setY(float y)
{
    this->y = y;
}

float Ponto::distancia(Ponto* p)
{
    float dx = x - (*p).x;
    float dy = y - p->y;
    return sqrt(dx * dx + dy * dy);
}

void Ponto::imprime()
{
    cout << "O valor de x eh: "<< getX() << endl;
    cout << "O valor de y eh: " << getY() << endl;
}
