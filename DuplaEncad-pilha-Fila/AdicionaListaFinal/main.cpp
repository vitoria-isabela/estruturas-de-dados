
#include <iostream>
#include "ListaDupla.h"
using namespace std;

/// <summary>
/// Implementar a operação void ListaDupla::adicionaListaFinal(ListaDupla* l2); que, de acordo com
//os tamanhos das listas, adiciona todos os nós de uma lista no final de uma outra lista
//duplamente encadeada.A lista que tiver maior número de nós deve ficar com os
//elementos no início e a outra no final.Se os tamanhos forem iguais, tanto faz.Ao final
//da operação a lista com menor número de nós é alterada e fica vazia.A operação não
//deve percorrer as listas.
//Exemplo: Considere uma lista com os valores[3, 2, 5, 12, 7, 9] e uma
//lista l2 com os valores[6, 13, 8].Como a lista implícita é maior que l2, a lista
//resultante é[3, 2, 5, 12, 7, 9, 6, 13, 8] e a l2 resultante é[].
/// </summary>
/// <returns></returns>
int main()
{
    ListaDupla l, l2;

    l.insereFinal(0);
    l.insereFinal(1);
    l.insereFinal(2);
    l.insereFinal(3);
    l.insereFinal(4);

    l2.insereFinal(0);
    l2.insereFinal(1);
    l2.insereFinal(2);
    l2.insereFinal(3);
    l2.insereFinal(4);
    l2.insereFinal(5);

    cout << "l: " << endl;
    l.imprime();

    cout << "l2: " << endl;
    l2.imprime();

    l2.adicionaListaFinal(&l);

    cout << "l: " << endl;
    l.imprime();

    cout << "l2: " << endl;
    l2.imprime();
}