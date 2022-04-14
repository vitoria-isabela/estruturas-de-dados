#include <iostream>
#include "ListaEncad.h"

/// <summary>
/// Implementar a operação int* ListaEncad::menorProximo(); que cria e
//retorna um vetor contendo os valores 0 ou 1 em referência à ordenação de cada
//elemento de uma lista simplesmente encadeada com descritor com relação ao valor
//do nó da próxima posição.Em outras palavras, se a informação do nó na posição i
//da lista for menor que a informação do nó na posição i + 1, o vetor na posição i
//deve ser preenchido com o valor 1. Caso contrário, o valor do índice i do vetor deve
//ser preenchido com 0. Considere que a última posição está ordenada.Caso a lista
//não possua elementos, deve - se retornar NULL, sem alocar nenhum vetor.
//Exemplo: Considere uma lista com os valores[3, 2, 5, 7, 9, 2, 4, 8].
//Nesse caso, o vetor retornado será[0, 1, 1, 1, 0, 1, 1, 1].
/// </summary>
/// <returns></returns>
int main()
{
    int n;
    std::cin >> n;
    ListaEncad lista;

    lista.insereFinal(3);
    lista.insereFinal(2);
    lista.insereFinal(5);
    lista.insereFinal(7);
    lista.insereFinal(9);
    lista.insereFinal(2);
    lista.insereFinal(4);
    lista.insereFinal(8);

    /*lista.imprimir();*/

    /*lista.removeInicio();
    lista.removeInicio();
    lista.removeInicio();*/

    lista.imprimir();

    /*lista.insereFinal(90);
    lista.insereFinal(98);
    lista.imprimir();*/

    /*lista.removeFinal();
    lista.removeFinal();
    lista.removeFinal();

    lista.imprimir();*/

    int* menorV;

    menorV = lista.menorProximo();

    std::cout << "[";
    for (int i = 0; i < n; i++)
    {
        std::cout << menorV[i];
        if (i + 1 < n)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    lista.imprimir();

    return 0;
}