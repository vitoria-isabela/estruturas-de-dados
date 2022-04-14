#include <iostream>
#include "ListaCont.h"

using namespace std;

/// <summary>
/// Implementar a operação void ListaCont::inserirVet(int tam, int v[]); para
//inserir os tam elementos do vetor v[] no início de uma lista contígua.A ordem dos valores
//do vetor deve ser preservada na lista.A folga no fim do vetor que armazena a lista deve
//permanecer do mesmo tamanho.Por isso, será necessário realocar o vetor suporte da lista
//para um novo valor de max.
//Exemplo: Considere a lista inicial com os valores L = [9, 3, 5, ? , ? ] e vet =
//{ -5, 6, 7 }. Abaixo encontra - se a lista esperada após a execução da operação
//L.inserirVet(3, { -5, 6, 7 }) :
//
//    L →[-5, 6, 7, 9, 3, 5, ? , ? ]
/// </summary>
/// <returns></returns>
int main()
{
    ListaCont lista(6);

    lista.insereFinal(9);
    lista.insereFinal(3);
    lista.insereFinal(5);

    lista.imprime();

    int vet[] = { -5, 6, 7 };

    lista.insereVet(3, vet);

    lista.imprime();

    return 0;
}