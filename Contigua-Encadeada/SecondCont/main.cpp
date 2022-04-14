#include <iostream>
#include "ListaCont.h"

/// <summary>
/// Este exercicio aborda metodos basicos de uma lista contigua 
/// </summary>
/// <returns></returns>
int main()
{
    int n = 10;
    ListaCont lista(n);

    /*for (int i = 0; i <= n; i++)
    {
        lista.insereInicio(i + 1);
        lista.imprime();
        lista.insereFinal(n - i);
        lista.imprime();
    }*/
    lista.insereFinal(3);
    lista.insereFinal(2);
    lista.insereFinal(5);
    lista.insereFinal(4);
    lista.insereFinal(9);

    lista.retornaPares();

    return 0;
}