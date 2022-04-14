#include <iostream>
#include <cstdlib>
#include "ListaContPonto.h"

using namespace std;

ListaContPonto::ListaContPonto(int tam)
{
    cout << "Criando objeto ListaCont" << endl;
    max = tam;  // define o tamanho maximo
    n = 0;      // tamanho atual da lista vazia � zero
    vet = new Ponto[max]; // aloca o vetor com o tamanho maximo
}

ListaContPonto::~ListaContPonto()
{
    cout << "Destruindo objeto ListaCont" << endl;
    delete[] vet;
}

Ponto ListaContPonto::get(int k)
{
    // nao � o tamanho maximo! � o atual!
    if (k >= 0 && k < n)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

// modifica o valor armazenado naquele indice
void ListaContPonto::set(int k, Ponto p)
{
    // nao � o tamanho maximo! � o atual!
    if (k >= 0 && k < n)
        vet[k] = p;
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaContPonto::insereFinal(Ponto p)
{
    if (n == max) // nao permite inserir se nao tiver espa�o
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    vet[n] = p;
    n = n + 1;    // lembra de atualizar o tamanho atual
}

void ListaContPonto::removeFinal()
{
    if (n == 0) // nao permite remover se a lista for vazia
    {
        cout << "ERRO: Lista Vazia!" << endl;
        exit(1);
    }
    n = n - 1; // nao apaga, apenas diminui o tamanho atual
}

void ListaContPonto::insereK(int k, Ponto p)
{
    if (n == max)  // nao permite inserir se nao tiver espa�o
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    if (k >= 0 && k < n)
    {   // desloca elementos antes de inserir
        for (int i = n - 1; i >= k; i--)
            vet[i + 1] = vet[i];
        vet[k] = p; // insere na posicao k
        n = n + 1;    // atualiza o tamanho atual
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaContPonto::removeK(int k)
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

void ListaContPonto::insereInicio(Ponto p)
{
    if (n == 0)
    {   //lista vazia. Sera o unico no da lista
        vet[n] = p;
        n = n + 1;
    }
    else // se a lista nao for vazia precisa deslocar todos os elementos
        insereK(0, p);
}

void ListaContPonto::removeInicio()
{
    removeK(0);
}

void ListaContPonto::imprime()
{
    cout << "Imprimindo a Lista Contigua (" << n << " elementos)" << endl;
    for (int i = 0; i < n; i++) {
        cout << "(" << vet[i].getX() << ", " << vet[i].getY() << "), ";
    }
    cout << endl;
}

int ListaContPonto::numNos()
{
    return n;
}
