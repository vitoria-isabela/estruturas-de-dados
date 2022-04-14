#pragma once

#include "C:\Users\6113826\source\repos\EstruturadeDados\Contigua-Encadeada\SecondEncad\No.h"

class ListaEncad
{
private:
    No* primeiro;
    No* ultimo;
    int n;
public:
    ListaEncad();
    ~ListaEncad();

    void insereInicio(int val);
    void removeInicio();  ///remove 1o n� da lista
    void insereFinal(int val);
    void removeFinal();

    bool busca(int val);
    void imprimir();
    int get(int k);
    bool inserePosicaoVal(int k, int val);
};