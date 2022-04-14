#pragma once
//#ifndef LISTAENCAD_H_INCLUDED
//#define LISTAENCAD_H_INCLUDED
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
    void insereFinal(int val);
    void removeFinal();

    bool busca(int val);
    void imprimir();
};
//#endif // LISTAENCAD_H_INCLUDED
