#include <cmath>
#pragma once
using namespace std;

class Ponto
{
private:
    float x, y;
public:
    Ponto();
    Ponto(float xx, float yy);
    ~Ponto();
    float getX();
    float getY();
    void setX(float xx);
    void setY(float yy);
    float distancia(Ponto* p2);
};

