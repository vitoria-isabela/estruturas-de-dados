#include <iostream>
#include "MatrizDiagonal.h"

using namespace std;

int main()
{
    int x;
    cin >> x;
    MatrizDiagonal m(x);

    for (int i = 0; i < x; i++)
        m.set(i, i, i * i + x);

    m.imprime();
    return 0;
}
