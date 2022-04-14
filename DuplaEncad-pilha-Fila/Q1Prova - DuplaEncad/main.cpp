#include <iostream>
#include "ListaDupla.h"
using namespace std;

/// <summary>
/// Implementar a operação void ListaDupla::removeEntreInter(int v1, int v2) para, dados dois inteiros v1 e v2, remover todos os nós cujos valores estejam contidos no intervalo fechado [v1, v2]. 
//
//Exemplos:
//L1(Antes) : 9 19 48 39 24 27 38 32 4 12 | v1 = 10, v2 = 20
//L1(Depois) : 9 48 39 24 27 38 32 4
//
//L1(Antes) : 9 19 48 39 24 27 38 32 4 12 | v1 = 20, v2 = 40
//L1(Depois) : 9 19 48 4 12
/// </summary>
/// <returns></returns>
int main()
{
    ListaDupla l;

    l.insereFinal(9);
    l.insereFinal(19);
    l.insereFinal(48);
    l.insereFinal(39);
    l.insereFinal(24);
    l.insereFinal(27);
    l.insereFinal(38);
    l.insereFinal(32);
    l.insereFinal(4);
    l.insereFinal(12);
    l.imprime();
    l.removeEntreInter(10, 20);
    l.imprime();

    /*l2.insereFinal(0);
    l2.insereFinal(1);
    l2.insereFinal(2);
    l2.insereFinal(3);
    l2.insereFinal(4);
    l2.insereFinal(5);*/

    //cout << "l: " << endl;
    //l.imprime();
    //l.removeOcorrencias(2);

    //cout << "l: " << endl;
    //l.imprime();

    //l2.adicionaListaFinal(&l);

    //cout << "l: " << endl;
    //l.imprime();

    //cout << "l2: " << endl;
    //l2.imprime();*/

    return 0;
}