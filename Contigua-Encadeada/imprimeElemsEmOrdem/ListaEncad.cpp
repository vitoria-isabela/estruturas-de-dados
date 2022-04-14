#include <iostream>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
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

    primeiro = p; // no apontado por p passa a ser o primeiro da lista

    n++;

    if (n == 1)  ///ultimo == NULL
        ultimo = p;
}

void ListaEncad::removeInicio()
{
    if (primeiro != NULL)
    {
        No* p = primeiro;
        primeiro = primeiro->getProx();
        delete p;

        n--;
        if (n == 0);  ///primeiro == NULL
        ultimo == NULL;
    }
}

void ListaEncad::insereFinal(int val)
//agora tem complexidade O(1)
{
    ///insere um novo n� no fim da lista com valor val
    No* p = new No(); // cria No apontado por p
    p->setInfo(val); // preenche informacao
    p->setProx(NULL);

    if (ultimo != NULL)
        ultimo->setProx(p);
    else
        primeiro = p;

    ultimo = p;
    n++;
}

void ListaEncad::removeFinal()

{
    ///remove n� no fim da lista com valor val

    if (primeiro != NULL) ///lista n�o vazia (n >0)
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

        ultimo = ap;  ///ap � NULL se lista tem 1 �nico n�.
                      ///ap aponta para o penultimo (ser� o ultimo)
        n--;
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

void ListaEncad::imprimeElemsEmOrdem()
{
    No* p = primeiro;
    No* ant = NULL;
    while (p != NULL)
    {
        // SOLUÇÃO 2
        if((ant == NULL && p->getProx() == NULL) || // anterior é nulo e proximo de p é nulo --1° elemento e único
        (ant == NULL && p->getInfo() <= p->getProx()->getInfo()) || // anterior é nulo e p <= proximo (1° elemento)
        (ant != NULL && p->getProx() == NULL && p->getInfo() >= ant->getInfo()) || // ( (anterior não é nulo && proximo é nulo) && p >= ant ) --ultimo elemento
        (ant != NULL && p->getProx() != NULL && p->getInfo() >= ant->getInfo() && p->getInfo() <= p->getProx()->getInfo())) // ( (anterior não é nulo && proximo não é nulo) && p >= ant && p <= proximo )  --caso geral para os elementos do 'meio'
            cout << p->getInfo() << "    ";
        
        ant = p;
        p = p->getProx();
    }
}