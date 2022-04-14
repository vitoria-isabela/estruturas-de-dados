#include <iostream>

#include "FilaCont.h"

FilaCont::FilaCont(int tam)
{

    max = tam;
    inicio = 0;
    fim = 0;
    vet = new int[max];
}

FilaCont::~FilaCont()
{
    delete[] vet;
}

int FilaCont::getInicio()
{
    if (!vazia())
        return vet[inicio];
    else
    {
        std::cout << "ERRO: Fila vazia" << std::endl;
        exit(1);
    }
}

void FilaCont::enfileira(int val)
{
    if (fim == max) // fila cheia
    {
        std::cout << "ERRO: Fila cheia" << std::endl;
        exit(2);
    }
    vet[fim] = val;
    fim = fim + 1;
}

void FilaCont::imprime()
{
    std::cout << std::endl;
    for (int i = inicio; i < fim; i++)
        std::cout << vet[i] << "  ";
    std::cout << std::endl;
}

int FilaCont::desenfileira()
{
    if (!vazia())///fila n�o est� vazia
    {
        inicio = inicio + 1;
        return vet[inicio - 1];
    }
    std::cout << "ERRO: Fila vazia" << std::endl;
    exit(1);
}
