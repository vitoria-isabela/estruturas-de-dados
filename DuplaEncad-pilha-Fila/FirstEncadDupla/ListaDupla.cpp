#include <iostream>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    primeiro = ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    NoDuplo* p = primeiro; // p = ultimo;
    while (p != NULL)
    {
        NoDuplo* t = p->getProx(); // t = p->getAnt();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    //for(NoDuplo p = primeiro; p != NULL; p = p->getProx())
    for (NoDuplo* p = ultimo; p != NULL; p = p->getAnt())
        if (p->getInfo() == val)
            return true;
    return false;
}

void ListaDupla::insereInicio(int val)
{
    NoDuplo* p = new NoDuplo(); // cria No apontado por p
    p->setInfo(val); // preenche informacao
    p->setProx(primeiro); // preenche proximo
    p->setAnt(NULL); // preenche anterior
    if (primeiro == NULL) // ultimo == NULL
        ultimo = p;
    else
        primeiro->setAnt(p);
    primeiro = p; // no apontado por p passa a ser o primeiro da lista
    n++;
}

void ListaDupla::insereFinal(int val)
{
    NoDuplo* p = new NoDuplo(); // cria No apontado por p
    p->setInfo(val); // preenche informacao
    p->setAnt(ultimo); // preenche anterior
    p->setProx(NULL); // preenche proximo
    if (primeiro == NULL) // ultimo == NULL
        primeiro = p;
    else
        ultimo->setProx(p);
    ultimo = p; // no apontado por p passa a ser o primeiro da lista
    n++;
}

void ListaDupla::insereK(int k, int val)
{
    if (k < 0 || k > n)
        cout << "Indice invalido" << endl;
    else if (k == 0)
        insereInicio(val);
    else if (k == n) // possibilidade
        insereFinal(val);
    else
    {
        NoDuplo* novo = new NoDuplo();
        novo->setInfo(val);
        NoDuplo* p = primeiro;
        for (int i = 0; i < k; i++)
            p = p->getProx();
        NoDuplo* ant = p->getAnt();
        novo->setProx(p);
        novo->setAnt(ant);
        p->setAnt(novo);
        ant->setProx(novo);
        n++;
    }
}

void ListaDupla::removeInicio()
{
    if (primeiro != NULL)
    {
        NoDuplo* p = primeiro;
        primeiro = p->getProx();
        delete p;
        if (primeiro == NULL)
            ultimo = NULL;
        else
            primeiro->setAnt(NULL);
        n--;
    }
    else
        cout << "ERRO: Lista vazia." << endl;
}

void ListaDupla::removeFinal()
{
    if (primeiro != NULL)
    {
        NoDuplo* p = ultimo;
        ultimo = p->getAnt();
        delete p;
        if (ultimo == NULL)
            primeiro = NULL;
        else
            ultimo->setProx(NULL);
        n--;
    }
    else
        cout << "ERRO: Lista vazia." << endl;
}

void ListaDupla::removeK(int k)
{
    if (k < 0 || k >= n)
        cout << "Indice invalido" << endl;
    else if (k == 0)
        removeInicio();
    else if (k == n - 1)
        removeFinal();
    else
    {
        NoDuplo* p = primeiro;
        for (int i = 0; i < k; i++)
            p = p->getProx();
        NoDuplo* ant = p->getAnt();
        NoDuplo* prox = p->getProx();
        ant->setProx(prox);
        prox->setAnt(ant);
        delete p;
        n--;
    }
}

void ListaDupla::imprime()
{
    cout << "Lista: ";
    for (NoDuplo* p = primeiro; p != NULL; p = p->getProx())
        cout << p->getInfo() << " ";
    cout << endl;
}

void ListaDupla::imprimeReverso()
{
    cout << "Lista Reversa: ";
    for (NoDuplo* p = ultimo; p != NULL; p = p->getAnt())
        cout << p->getInfo() << " ";
    cout << endl;
}