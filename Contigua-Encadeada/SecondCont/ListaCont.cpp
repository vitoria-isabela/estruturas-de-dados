#include <iostream>
#include <stdlib.h>

#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    //ctor
    max = tam;
    n = 0;
    inicio = max / 2;  ///poderia ser em qq posi��o (0 e max-1).
    vet = new int[max];
}

ListaCont::~ListaCont()
{
    //dtor
    delete[] vet;
}

int ListaCont::get(int k)
{
    if (valido(k))
        return vet[k];
    else
    {
        cout << "ERRO: indice invalido" << endl;
        exit(1);
    }
}

void ListaCont::set(int k, int val)  ///altera valor na posicao k
{///altera o valor da posi�ao k para novo valor val
    if (valido(k))
        vet[k] = val;
    else
    {
        cout << "ERRO: indice invalido" << endl;
        exit(1);
    }
}

void ListaCont::insereFinal(int val)
{
    if (ultimo() == max - 1)
        realoca(); ///aumenta a capacidade do vetor suporte da lista

    vet[ultimo() + 1] = val;
    n = n + 1;
}

void ListaCont::realoca()
{
    max = max + 50;  ///max + max*10/100; ou max*1.1
    int* auxVet = new int[max];

    ///copia vet para auxVet
    for (int i = inicio; i <= ultimo(); i++)
        auxVet[i] = vet[i];

    delete[] vet;

    vet = auxVet;
}

void ListaCont::insereK(int k, int val)
{
    if (ultimo() == max - 1)
        realoca(); ///aumenta a capacidade do vetor suporte da lista
    if (n == 0)
    {
        if (k >= 0 && k < max)
        {
            inicio = k;
            vet[k] = val;
            n++;
        }
        else
            cout << "ERRO: indice invalido (vetor)" << endl;
    }
    else if (valido(k))
    {
        for (int i = ultimo(); i >= k; i--)
            vet[i + 1] = vet[i];
        vet[k] = val;
        n = n + 1;
    }
    else
    {
        cout << "ERRO: indice invalido" << endl;
        exit(2);
    }
}

void ListaCont::insereInicio(int val)
{
    if (n == 0)
    {///lista vazia. Ser� unico elemento da lista
        inicio = max / 2;
        vet[inicio] = val;
        n++;
    }
    else if (inicio > 0)  ///verifica se tem folga no come�o do vetor
    {
        inicio = inicio - 1;
        vet[inicio] = val;
        n++;
    }
    else
    {
        cout << "Nao ha folga no inicio do vetor";
        exit(3);
    }
}

void ListaCont::removeFinal()
{
    if (n == 0)
    {
        cout << "Erro: lista vazia";
        exit(4);
    }
    n = n - 1;
    if (n == 0)
        inicio = max / 2;
}

void ListaCont::removek(int k)
{
    if (valido(k))
    {
        for (int i = k; i <= ultimo() - 1; i++)  ///desloca para direita
            vet[i] = vet[i + 1];
        n--;

        if (n == 0)
            inicio = max / 2;
    }
    else
    {
        cout << "Erro: indice invalido ou lista vazia";
        exit(5);
    }
}

void ListaCont::removeInicio()
{
    if (n == 0)
    {
        cout << "Erro: lista vazia";
        exit(6);
    }
    else  ///lista n�o est� vazia
    {
        inicio++;
        n--;

        if (n == 0)
            inicio = max / 2;
    }
}

void ListaCont::imprime()
{
    cout << endl;
    for (int i = inicio; i <= ultimo(); i++)
        cout << "  " << vet[i];
    cout << endl << endl;
}

ListaCont* ListaCont::retornaPares()
{
    int* pares = new int(n);
    /*for (int i = 0; i < n; i++)
        pares[i] = vet[i];*/

    int contaPares = 0;

    for (int i = 0; i < n; i++)
    {
        if (vet[i] % 2 == 0)
        {
            pares[contaPares] = vet[i];
            removek(i);
            contaPares = contaPares + 1;
        }
    }

    ListaCont* newPar = new ListaCont(n);

    for (int i = 0; i < contaPares; i++)
        newPar->insereFinal(pares[i]);

    newPar->imprime();
    delete[] pares;
    return newPar;
}
