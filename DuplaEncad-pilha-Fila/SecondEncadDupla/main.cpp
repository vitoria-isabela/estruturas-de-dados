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

int main()
{
    ListaDupla l; /// cria lista vazia
    int NumNos = 5;

    srand(time(NULL));

    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: ";
    for (int i = 1; i <= NumNos; i++)
    {
        /// cria um valor aleat�rio entre 0 e 50
        int val = numAleatorio(0, 10);
        cout << val << ", ";
        //l.insereInicio(val);
        l.insereFinal(val);
    }
    cout << endl;
    l.imprime();

    l.removeAntProx(5);

    l.imprime();

    ////l.insereFinal(20);
    ////l.imprime();

    ////l.removeFinal();
    ////l.imprime();

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
    /*
      cout << "Informe um valor para partir a lista: ";
      cin >> valor;

      // cria lista para receber o retorno da lista partida
      ListaDupla *l4 = l.partir(valor);

      l.imprime();
      l4->imprime();
  */

    /*cout << "Informe um valor para remover da lista: ";
    cin >> valor;

    l.removeOcorrencias(valor);*/
    l.imprime();

    return 0;
}