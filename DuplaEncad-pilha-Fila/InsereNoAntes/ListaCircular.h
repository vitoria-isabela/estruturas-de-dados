#pragma once
#include "NoDuplo.h"

class ListaCircular
{
public:
    ListaCircular();
    void imprime();
    void insereFinal(int val);

    bool vazia() { return n == 0; }
private:
    NoDuplo* primeiro;
    int n;
    NoDuplo* ultimo;
    NoDuplo* insereNoAntes(NoDuplo* p, int val);
};