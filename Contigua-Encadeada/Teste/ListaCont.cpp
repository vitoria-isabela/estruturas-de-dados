#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont()
{
    delete[] vet;
}

void ListaCont::insereFinal(int val)
{
    if (n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    vet[n] = val;
    n = n + 1;
}

void ListaCont::imprime()
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << vet[i];
        if (i + 1 < n)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// ----------------------------------------------------------------------------
//Q2

bool ListaCont::insereIntervalo(int a, int b)
{
    // Implemente aqui a sua solu��o para a quest�o 2.
    // Se necess�rio, remova o c�digo abaixo.

    return false;
}
//-Q2
// ----------------------------------------------------------------------------
void ListaCont::setValor(int valor, int posicao)
{
    vet[posicao] = valor;
    n++;
}
void ListaCont::inserirVet(int tam, int v[])
{
    // Criar vetor novo (max + tamVet)
    int* vetNovo;
    vetNovo = new int[tam + max];

    // Inserir vetor

    int i;

    for (i = 0; i < tam; i++) {
        vetNovo[i] = v[i];
        n++;
    }

    // Inserir valores da lista anterior

    for (i = tam; i < (tam + max); i++) {
        vetNovo[i] = vet[i - tam];
    }

    // Mudar lista original

    max = max + tam;
    vet = vetNovo;

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

    //int i, j;
    //int tamanhoListaNova = 0;

    //for (i = 0; i < max; i++) {
    //    if (vet[i] == valor) {

    //        int vetorNovo[max - i];

    //        for (j = i; j < max; j++) {
    //            vetorNovo[j - 2] = vet[j];
    //            tamanhoListaNova++;
    //        }

    //        // Atualiza max e n da lista antiga

    //        max = max - tamanhoListaNova;
    //        n = n - tamanhoListaNova;

    //        // Cria lista nova

    //        ListaCont listaNova(tamanhoListaNova);
    //        listaNova.n = listaNova.max;
    //        listaNova.vet = vetorNovo;

    //        listaNova.imprime();
    //        return &listaNova;
    //    }
    //}

    //// Caso em que nao se encontra o valor

    //ListaCont listaNula(max);

    //for (i = 0; i < max; i++) {
    //    vet[i] = 0;
    //}

    //return &listaNula;
}