#include <string>
#include <iostream>


class Poligono
{
private:
    int numLados; // numero de lados do poligono
    float tamLado; // tamanho de cada lado

public:
    Poligono();
    Poligono(int n, int t);
    ~Poligono();
    float area(); // calcula area
    float perimetro(); // calcula perimetro
    float angInterno(); // calcula angulo interno
    void imprimePoligono();
    int getNumLados();
    int getTamLado();
    void setNumLados(int n);
    void setTamLado(int t);
};
