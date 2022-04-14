#include <iostream>
#include "Ponto.h"

using namespace std;

Ponto* geometricCenter(Ponto* vPonto, int n);

int main()
{
    Ponto p1(1, 1), p2(3, 3);

    Ponto* p3 = new Ponto(2, 2);

    int n;
    cin >> n;

    Ponto *vector = new Ponto[n];

    for (int i = 0; i < n; i++)
    {
        float x, y;
        cout << "Insira as coordenadas do ponto " << i + 1 << ":" << endl;
        cin >> x >> y;

        vector[i].setX(x);
        vector[i].setY(y);
    }
    Ponto* gc;

    gc = geometricCenter(vector, n);

    /*cout << "(" << p1.getX() << ", " << p1.getY() << ")" << endl;
    cout << "(" << p2.getX() << ", " << p2.getY() << ")" << endl;

    cout << "(" << p3->getX() << ", " << (*p3).getY() << ")" << endl;

    cout << "Distancia: " << p1.distancia(&p2) << endl;*/

    //(*p3).imprime();
    cout << "Imprimindo coordenadas do centro geometrico: " << endl;
    gc->imprime();

    delete p3;
    delete[] vector;
    delete gc;

    return 0;
}

Ponto* geometricCenter(Ponto* vector, int n)
{
    float gcX = 0.0;
    float gcY = 0.0;
    for (int i = 0; i < n; i++)
    {
        gcX = gcX + vector[i].getX();
        gcY = gcY + vector[i].getY();
    }
    Ponto* resultgc = new Ponto(gcX / n, gcY / n);

    return resultgc;
}
