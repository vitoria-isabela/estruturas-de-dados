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
    void removeFinal();
    void imprime();
    void imprimeReverso();

private:
    NoDuplo* primeiro;
    int n;
    NoDuplo* ultimo;
};
