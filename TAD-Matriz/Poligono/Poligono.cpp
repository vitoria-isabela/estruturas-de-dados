#include <iostream>
#include <cmath>
#include "Poligono.h"

using namespace std;

Poligono::Poligono()
{
    cout << "Construtor vazio" << endl;
}

Poligono::Poligono(int n, int t)
{
    setNumLados(n);
    setTamLado(t);
}

Poligono::~Poligono()
{
    cout << "Destrutor" << endl;
}

float Poligono::area()
{
    return numLados * pow(tamLado, 2) / (4 * tan(3.141592 / numLados));
}

float Poligono::perimetro()
{
    return numLados * tamLado;
}

float Poligono::angInterno()
{
    return 180 * (numLados - 2) / numLados;
}

void Poligono::imprimePoligono()
{
    cout << "Numero de lados: " << numLados << endl;
    cout << "Tamanho de cada lado: " << tamLado << endl;
}

int Poligono::getNumLados()
{
    return numLados;
}

int Poligono::getTamLado()
{
    return tamLado;
}

void Poligono::setNumLados(int n)
{
    if (n > 2)
        numLados = n;
    else
        cout << "Numero de lados invalido" << endl;
}

void Poligono::setTamLado(int t)
{
    if (t > 0)
        tamLado = t;
    else
        cout << "Tamanho de cada lado invalido" << endl;
}
