#include "Ponto.h"
#include "ListaContPonto.h"
#pragma once

class ListaCont
{
private:
    int max;
    int n;
    int* vet;

public:
    ListaCont(int tam);
    ~ListaCont();

    int get(int k);
    void set(int k, int val);
    void insereFinal(int val);
    void insereK(int k, int val);
    void insereInicio(int val);
    void removeFinal();
    void removeK(int k);
    void removeInicio();
    void imprime();
    int numNos();
    int buscaMaior(int val);
    void limpar();
    void insereValores(int tam, int vet[]);
};