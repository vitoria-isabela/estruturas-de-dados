#include <iostream>
#include "Poligono.h"

using namespace std;

int main()
{
    Poligono p(3, 10);
    Poligono p2 (4,32);
    p.imprimePoligono();
    p2.imprimePoligono();

    cout << "Area: " << p.area() << endl;
    cout << "Perimetro: " << p.perimetro() << endl;
    cout << "Angulo interno: " << p.angInterno() << endl;

    cout << "Area: " << p2.area() << endl;
    cout << "Perimetro: " << p2.perimetro() << endl;
    cout << "Angulo interno: " << p2.angInterno() << endl;

    return 0;
}
