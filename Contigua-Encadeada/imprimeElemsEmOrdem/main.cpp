#include <iostream>

#include "ListaEncad.h"

using namespace std;

/// <summary>
/// Implementar a operação void ListaEncad::imprimeElemsEmOrdem(); que
//imprime os elementos da lista encadeada que estão ordenados em relação aos seus
//vizinhos imediatos.Em outras palavras, se P é um nó da lista, você deve imprimir a
//sua informação somente se esta for maior ou igual à informação contida no seu
//antecessor e menor ou igual à informação contida no seu sucessor.No caso dos
//elementos que estão nas bordas da lista(primeiro e último), a ordenação deve ser
//verificada com relação ao único vizinho existente.
//Exemplo: Considere uma lista com os valores[3, 2, 5, 7, 9].Os valores a
//serem impressos serão o 5 (está entre 2 e 7), o 7 (entre 5 e 9) e o 9 (que é maior
//	que 7).
/// </summary>
/// <returns></returns>
int main()
{
    ListaEncad lista;

    lista.insereFinal(3);
    lista.insereFinal(2);
    lista.insereFinal(5);
    lista.insereFinal(7);
    lista.insereFinal(9);
   
    cout << "Lista sem a operacao imprimeElemsEmOrdem: " << endl;
    lista.imprimir();

    cout << "Lista com a operacao imprimeElemsEmOrdem: " << endl;
    lista.imprimeElemsEmOrdem();

    return 0;
}
