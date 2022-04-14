//#ifndef LISTAENCAD_H_INCLUDED
//#define LISTAENCAD_H_INCLUDED
#pragma once
#include "No.h"

class ListaEncad
{
private:
    No* primeiro;
public:
    ListaEncad();
    ~ListaEncad();

    void insereInicio(int val);
    void removeInicio();  ///remove 1o n� da lista

    void imprimir();
};
//#endif // LISTAENCAD_H_INCLUDED