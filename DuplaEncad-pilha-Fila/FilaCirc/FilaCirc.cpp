#include <iostream>

using namespace std;
#include "FilaCirc.h"
/*
int FilaCirc::inc(int ind)
{
    ind++;
    if (ind == max)
        return 0;
    return ind;
}

int FilaCirc::inc(int ind)
{
    if (ind == max-1)
        return 0;
    else
        return ind+1;
}

*/
int FilaCirc::inc(int ind)
{
    return (ind + 1) % max;
}

FilaCirc::FilaCirc(int tam)
{
    max = tam; // capacidade maxima
    n = 0; // numero de nos na fila
    inicio = fim = 0; // inicio, fim
    vet = new int[max]; // vetor com os dados
}
FilaCirc::~FilaCirc()
{
    delete[] vet;
}

bool FilaCirc::vazia()
{
    return (n == 0);
}

int FilaCirc::getInicio()
{
    if (!vazia())
        return vet[inicio];
    else
    {
        cout << "ERRO: Fila vazia" << endl;
        exit(1);
    }
}

void FilaCirc::enfileira(int val)
{
    if (n == max)
    {
        cout << "ERRO: Fila cheia" << endl;
        exit(1);
    }
    vet[fim] = val;
    fim = inc(fim); ///comportamento c�clico
    n = n + 1;
}

int FilaCirc::desenfileira()
{
    if (!vazia())
    {
        int val = vet[inicio];
        inicio = inc(inicio);
        n = n - 1;
        return val;
    }
    cout << "ERRO: Fila vazia" << endl;
    exit(1);
}

void FilaCirc::imprime()
{
    int cont = 1, i = inicio;

    std::cout << std::endl;
    while (cont <= n)
    {
        std::cout << vet[i] << "  "; ///no v�deo est� trocado. Assim est� correto.
        i = inc(i);
        cont++;
    }
    std::cout << std::endl;
}
