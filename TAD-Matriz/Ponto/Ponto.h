#pragma once

class Ponto
{
private:
    float x, y;

public:
    Ponto(float xx, float yy);
    ~Ponto();
    Ponto();

    float getX();
    float getY();

    void setX(float xx);
    void setY(float yy);

    float distancia(Ponto* p3);
    void imprime();
};
