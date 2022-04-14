#include <iostream>
#include "Vetor.h"

using namespace std;

int main()
{
    int tam;
    cin >> tam;

    Vetor v(tam);

    for (int i = 0; i < tam; i++) // armazena seq
        v.set(i, i + 1);

    for (int i = 0; i < tam; i++)
    {
        float val = v.get(i);
        cout << val << " \t";
    }
    return 0;
}