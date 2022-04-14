#include <iostream>
#include "ListaEncad.h"

using namespace std;

/// <summary>
/// Considerando o TAD ListaEncad que representa uma lista simplesmente encadeada de valores
//inteiros, implementar uma func~ao para retornar o numeros de nos da lista que possuem o campo
//info maior que o valor inteiro val.
//Acrescentei tambem o metodo buscaPosmaior, que retorna a posicao do maior elemento da lista comparado ao valor val passado como ref.
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

    /*cout << lista.contaMaiores(6) << endl;
    cout << lista.buscaPosMaior(2) << endl;

    ListaEncad lista2;
    lista2.insereFinal(0);
    lista2.insereFinal(0);
    lista2.insereFinal(0);

    ListaEncad* l = &lista2;

    lista.concatena(l);
    lista.imprimir();
    lista2.imprimir();*/
    cout << "Lista intriseca, antes de partir:" << endl;
    lista.imprimir();
    ListaEncad* l1 = lista.partir(2);
    cout << "Lista intriseca, depois de partir:" << endl;
    lista.imprimir();
    cout << "Lista nova" << endl;
    l1->imprimir();

    return 0;
}