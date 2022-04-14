#include <iostream>
#include "ListaEncad.h"

using namespace std;
/// <summary>
/// Considere o TAD ListaEncad que representa uma lista simplesmente encadeada com elementos
//repetidos.Implemente uma operac~ao para eliminar todas as ocorr^ encias do valor val da lista.
/// </summary>
/// <returns></returns>
int main()
{
    ListaEncad lista;

    lista.insereFinal(3);
    lista.insereFinal(2);
    lista.insereFinal(5);
    lista.insereFinal(5);
    lista.insereFinal(9);

    lista.removeValor(5);

    lista.imprimir();

    return 0;
}