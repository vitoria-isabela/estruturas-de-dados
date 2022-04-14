#include <iostream>
#include "ListaCont.h"

using namespace std;

/// <summary>
/// Este exercicio aborda metodos basicos de uma lista contigua
/// </summary>
/// <returns></returns>
int main()
{
    ListaCont l(2);

    l.insereFinal(24);
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(-1);
    l.insereFinal(99);
    l.imprime();

    return 0;
}