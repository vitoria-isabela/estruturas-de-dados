#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaDupla.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1);
    /// retorna um numero inteiro aleatorio entre a e b
}

/// <summary>
/// Implementar a operação void ListaDupla::removeDepoisMaior(); que
//remove o nó seguinte ao nó com maior valor de uma lista duplamente encadeada.A
//operação deve percorrer a lista uma única vez.Em caso de mais de um valor maior,
//considerar a primeira ocorrência.Imprima uma mensagem de erro caso não seja
//possível remover o nó.
//Exemplo: Considere uma lista com os valores[3, 2, 5, 12, 7, 9].O nó a
//ser removido é nó com valor 7 (seguinte ao nó com valor 12) e a lista resultante é
//[3, 2, 5, 12, 9].
/// </summary>
/// <returns></returns>
int main()
{
    ListaDupla l; /// cria lista vazia
    int NumNos = 10;

    srand(time(NULL));

    for (int i = 1; i <= NumNos; i++)
        l.insereInicio(numAleatorio(0, 50));

    //l.insereFinal(20);
    //l.imprime();

    //l.removeFinal();
    //l.imprime();

    //bool existe = l.busca(20);
    //cout << "O valor 20 esta na lista? ";
    //if (existe)
    //    cout << "Sim" << endl;
    //else
    //    cout << "Nao" << endl;

    //l.imprimeReverso();
/*
    // cria outra lista para ser concatenada
    ListaDupla *l2 = new ListaDupla();

    for(int i = 1; i <= NumNos; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleat�rio entre 0 e 50
        cout << val << ", ";
        l2->insereInicio(val);
    }
    cout << endl;

    ListaDupla *l3 = l.concatena(l2);

    l3->imprime();

*/
    //int valor;
    /*
      cout << "Informe um valor para partir a lista: ";
      cin >> valor;

      // cria lista para receber o retorno da lista partida
      ListaDupla *l4 = l.partir(valor);

      l.imprime();
      l4->imprime();
  */

 /*   cout << "Informe um valor para remover da lista: ";
    cin >> valor;

    l.removeOcorrencias(valor);*/
    l.imprime();
    l.insereDepoisMenor(60);
    l.imprime();

    return 0;
}