#include "Ponto.h"

Ponto::Ponto() {};
Ponto::Ponto(float xx, float yy)
{
    x = xx;
    y = yy;
};
Ponto::~Ponto() {};
float Ponto::getX()
{
    return x;
};
float Ponto::getY()
{
    return y;
};
void Ponto::setX(float xx)
{
    x = xx;
};
void Ponto::setY(float yy)
{
    y = yy;
};
float Ponto::distancia(Ponto* p2)
{
    return sqrt(pow(x - p2->x, 2) + pow(y - p2->y, 2));
};