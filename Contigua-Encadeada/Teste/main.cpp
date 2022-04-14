#include <iostream>
#include "ListaCont.h"

using namespace std;

/// <summary>
/// Implementar a operação ListaCont* ListaCont::copiar(int valor); para copiar
//todos os elementos da lista intrínseca(elementos da lista para a qual foi chamada a
//    operação) a partir da primeira ocorrência de valor(inclusive) para uma nova lista.
//    Retornar a nova lista.Caso o valor não seja encontrado, retornar uma lista contígua vazia.
//    Os valores adicionados à nova lista devem ser removidos da lista intrínseca, e a ordem, em
//    ambas as listas, deve ser preservada.
//    Exemplo: Considere a lista intrínseca inicial com os valores L = [3, 2, 5, 5, 9] e
//    valor = 5. Abaixo estão as listas esperadas após a execução da operação
//    L.copiar(5) :
//    L →[3, 2]
//    novaLista →[5, 5, 9]
/// </summary>
/// <returns></returns>
int main()
{
    int n, valorCopia;
    cin >> n >> valorCopia;
    ListaCont lista(n);
    ListaCont* ptCopiada;
    int i;

    // Setta e imprime lista inicial

    for (i = 0; i < n; i++) {
        lista.setValor(i + 1, i);
    }

    cout << "Lista inicial: ";
    lista.imprime();

    // Chama a funcao de copiar no 3

    ptCopiada = lista.copiar(valorCopia);

    // Imprime nova lista

    cout << endl << "Lista copiada: ";
    ptCopiada->imprime();

    return 0;
}