#include "Ponto.h"
#pragma once

class ListaContPonto
{
private:
    int max;
    int n;
    Ponto* vet;

public:
    ListaContPonto(int tam);
    ~ListaContPonto();

    Ponto get(int k);
    void set(int k, Ponto p);
    void insereFinal(Ponto p);
    void insereK(int k, Ponto p);
    void insereInicio(Ponto p);
    void removeFinal();
    void removeK(int k);
    void removeInicio();
    void imprime();
    int numNos();
};