#include <iostream>
#include <cstdlib>
#include "Venda.h"

using namespace std;


Venda::Venda(int n)
{
    if (n > 0)
    {
        numItensVendidos = n;
        // aloca o vetor de forma dinamica
        valorItens = new double[numItensVendidos];

        // leitura dos itens
        for (int i = 0; i < numItensVendidos; i++)
        {
            cout << "Digite o valor do item " << i + 1 << ": ";
            cin >> valorItens[i];
        }
    }
    else
    {
        cout << "Numero invalido" << endl;
        exit(1);
    }
}

Venda::~Venda()
{
    delete[] valorItens;
}

double Venda::calculaTotal()
{
    double soma = 0;
    for (int i = 0; i < numItensVendidos; i++)
        soma += valorItens[i];
    return soma;
}

double Venda::itemMaisCaro()
{
    double maisCaro = valorItens[0];
    for (int i = 1; i < numItensVendidos; i++)
        if (valorItens[i] > maisCaro)
            maisCaro = valorItens[i];
    return maisCaro;
}
