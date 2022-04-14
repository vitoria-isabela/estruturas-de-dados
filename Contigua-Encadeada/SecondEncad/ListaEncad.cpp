#include <iostream>
#include "ListaEncad.h"
#include "No.h"
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

    No* p = new No(); // cria No apontado por p
    p->setInfo(val); // preenche informacao
    p->setProx(primeiro); // preenche proximo
    primeiro = p; // no apontado por p passa
    // a ser o primeiro da lista
}

void ListaEncad::insereFinal(int val)
//exercicio 3, slide 41
{
    ///insere um novo n� no fim da lista com valor val

    No* p = new No(); // cria No apontado por p
    p->setInfo(val); // preenche informacao
    p->setProx(NULL);

    if (primeiro != NULL)
    {
        No* q = primeiro; ///faz q apontar para o �ltimo n� da LSE
        while (q->getProx() != NULL)
            q = q->getProx();

        q->setProx(p);  ///encadeia p como �ltimo n�
    }
    else
        primeiro = p;
}

void ListaEncad::removeFinal()
//exercicio 4, slide 44
{
    ///remove n� no fim da lista com valor val

    if (primeiro != NULL)
    {
        ///ap aponta para n� anterior ao n� p
        No* ap = NULL, * p = primeiro;

        ///faz p apontar para o �ltimo n� da LSE
        while (p->getProx() != NULL)
        {
            ap = p;
            p = p->getProx();
        }

        if (ap == NULL)  ///caso II. Lista com 1 n�. A lista se torna vazia
            primeiro = NULL;
        else ///caso I. Lista com 2 ou mais n�s
            ap->setProx(NULL);

        delete p;
    }
}

///fazer os exerc�cios 5 e 6 do slide 44

void ListaEncad::removeInicio()
{
    if (primeiro != NULL)
    {
        No* p = primeiro;

        primeiro = primeiro->getProx();

        delete p;
    }
}

bool ListaEncad::busca(int val)
{
    No* p = primeiro;
    while (p != NULL)
    {
        if (p->getInfo() == val)
            return true;
        p = p->getProx();
    }
    return false;
}
void ListaEncad::imprimir()
//exercicio 1, slide 41
{
    No* p = primeiro;
    while (p != NULL)
    {
        std::cout << p->getInfo() << "    ";
        p = p->getProx();
    }
    std::cout << std::endl << std::endl << std::endl;
}
