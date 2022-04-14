#include <iostream>
#include "ListaEncad.h"

ListaEncad::ListaEncad()
{
    primeiro = NULL;
}

ListaEncad::~ListaEncad()
{
    No* p = primeiro;

    while (p != NULL)
    {
        primeiro = primeiro->getProx();
        delete p;
        p = primeiro;
    }
}

void ListaEncad::insereInicio(int val)
{
    ///insere um novo n� no inicio da lista com valor val

    No* p = new No();
    p->setInfo(val);
    p->setProx(primeiro);
    primeiro = p;
}

void ListaEncad::removeInicio()
{
    if (primeiro != NULL)
    {
        No* p = primeiro;

        primeiro = primeiro->getProx();

        delete p;
    }
}

void ListaEncad::imprimir()
{
    No* p = primeiro;
    while (p != NULL)
    {
        std::cout << p->getInfo() << "    ";
        p = p->getProx();
    }
    std::cout << std::endl << std::endl << std::endl;
}