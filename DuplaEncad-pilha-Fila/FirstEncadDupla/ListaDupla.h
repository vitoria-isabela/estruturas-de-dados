#pragma once
#include "NoDuplo.h"

class ListaDupla
{
public:
    ListaDupla();
    ~ListaDupla();
    bool busca(int val);
    void insereInicio(int val);
    void removeInicio();
    void insereFinal(int val);
    void insereK(int k, int val);
    void removeFinal();
    void removeK(int k);
    void imprime();
    void imprimeReverso();

private:
    NoDuplo* primeiro;
    int n;
    NoDuplo* ultimo;
};

