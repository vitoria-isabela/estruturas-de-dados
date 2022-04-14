#pragma once
#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    cout << "Criando objeto ListaCont" << endl;
    max = tam;  // define o tamanho maximo
    n = 0;      // tamanho atual da lista vazia é zero
    vet = new int[max]; // aloca o vetor com o tamanho maximo
}

ListaCont::~ListaCont()
{
    cout << "Destruindo objeto ListaCont" << endl;
    delete[] vet;
}

int ListaCont::get(int k)
{
    // nao é o tamanho maximo! é o atual!
    if (k >= 0 && k < n)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

// modifica o valor armazenado naquele indice
void ListaCont::set(int k, int val)
{
    // nao é o tamanho maximo! é o atual!
    if (k >= 0 && k < n)
        vet[k] = val;
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::realoca()
{
    max = max * 1.4;  ///max = max + 30
    cout << max << endl;
    int* v = new int[max];

    for (int i = 0; i < n; i++)
        v[i] = vet[i];

    delete[] vet;

    vet = v;
}

void ListaCont::insereFinal(int val)
{
    if (n == max) // nao permite inserir se nao tiver espaço
    {
        //cout << "ERRO: Vetor Cheio!" << endl;
        //exit(1);
        realoca();
    }
    vet[n] = val;
    n = n + 1;    // lembra de atualizar o tamanho atual
}

void ListaCont::removeFinal()
{
    if (n == 0) // nao permite remover se a lista for vazia
    {
        cout << "ERRO: Lista Vazia!" << endl;
        exit(1);
    }
    n = n - 1; // nao apaga, apenas diminui o tamanho atual
}

void ListaCont::insereK(int k, int val)
{
    if (n == max)  // nao permite inserir se nao tiver espaço
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    if (k >= 0 && k < n)
    {   // desloca elementos antes de inserir
        for (int i = n - 1; i >= k; i--)
            vet[i + 1] = vet[i];
        vet[k] = val; // insere na posicao k
        n = n + 1;    // atualiza o tamanho atual
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::removeK(int k)
{
    if (k >= 0 && k < n)
    {   // apenas desloca os elementos
        for (int i = k; i < n - 1; i++)
            vet[i] = vet[i + 1];
        n = n - 1; // e atualiza o tamanho
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereInicio(int val)
{
    if (n == 0)
    {   //lista vazia. Sera o unico no da lista
        vet[n] = val;
        n = n + 1;
    }
    else // se a lista nao for vazia precisa deslocar todos os elementos
        insereK(0, val);
}

void ListaCont::removeInicio()
{
    removeK(0);
}

void ListaCont::imprime()
{
    if (n != 0) {
        cout << "Imprimindo a Lista Contigua (" << n << " elementos)" << endl;
        for (int i = 0; i < n; i++) {
            cout << vet[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "Lista vazia" << endl;
}

int ListaCont::numNos()
{
    return n;
}

int ListaCont::buscaMaior(int val)
{
    for (int i = 0; i < n; i++) {
        if (vet[i] > val)
            return i;
    }

    return -1;
}


void ListaCont::limpar()
{
    n = 0;
}

void ListaCont::insereValores(int tam, int vet[])
{
    if (tam > (max - n)) {
        /*cout << "ERRO: Nao ha espaco suficiente!" << endl;
        exit(1);*/
        realoca();
    }
    else {
        for (int i = 0; i < tam; i++)
            insereFinal(vet[i]);
    }
}


ListaCont* ListaCont::copiar(int valor) {

    ListaCont* newList = new ListaCont(max);
    int k;

    for (k = 0; k < n; k++)
        if (vet[k] == valor)
            break;

    while (k < n)
    {
        newList->insereFinal(vet[k]);
        removeK(k);
    }

    return newList;
 }