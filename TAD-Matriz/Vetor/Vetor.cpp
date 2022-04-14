#include <iostream>     //cout, cin, ...
#include <stdlib.h>  //exit()
#include "Vetor.h"


Vetor::Vetor(int tam)
{
    /// inicializa a variavel interna n e aloca memoria para o vetor vet
    n = 0;
    if (tam > 0)
        n = tam;
    vet = new float[n];

    // opcional: inicializar vet com zeros
    for (int i = 0; i < n; i++)
        vet[i] = 0.0;
}

Vetor::~Vetor()
{
    // desaloca a memoria alocada no construtor
    delete[] vet;
}

bool Vetor::verifica(int indice)
{
    return indice >= 0 && indice < n;
};

float Vetor::get(int indice)
{
    if (verifica(indice))
        return vet[indice];
    else
    {
        std::cout << "Indice invalido: get" << std::endl;
        exit(1); // finaliza o programa
    }
}

void Vetor::set(int indice, float valor)
{
    if (verifica(indice))
        //armazena valor na posicao indice de vet
        vet[indice] = valor;
    else
        std::cout << "Indice invalido: set" << std::endl;
}
