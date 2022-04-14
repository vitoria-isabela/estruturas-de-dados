#include <iostream>
#include "ListaCircular.h"
using namespace std;

/// <summary>
/// Implementar a operação para inserir um novo nó com valor val antes do nó apontado por p
//em uma lista circular(duplamente encadeada com descritor).Protótipo:
//
//NoDuplo * ListaCircular::insereNoAntes(NoDuplo* p, int val)
//Caso a lista esteja vazia, inserir o novo nó com valor val como primeiro nó da lista(nesse
//    caso, não importa o valor de p).Retornar o ponteiro do novo nó inserido na lista.
//    Exemplo : O nó “azul” foi inserido antes do nó p em uma lista circular não vazia(ver figura).
//    O endereço do novo nó deve ser retornado.
/// </summary>
/// <returns></returns>
int main()
{
    ListaCircular lista;

    for (int i = 1; i <= 10; i++)
        lista.insereFinal(i);

    lista.imprime();
    return 0;
}