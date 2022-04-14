#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
    libera(raiz);
    raiz = NULL;
}
void ArvBinBusca::libera(NoArv* p)
{
    if (p != NULL)
    {
        libera(p->getEsq());
        libera(p->getDir());
        delete p;
    }
}

void ArvBinBusca::imprime()
{
    cout << "Arvore:" << endl;
    auxImprime(raiz, 0);
    cout << endl;
}
void ArvBinBusca::auxImprime(NoArv* p, int nivel)
{
    if (p != NULL)
    {
        cout << "(" << nivel << ") " << p->getInfo() << endl;
        auxImprime(p->getEsq(), nivel + 1);
        auxImprime(p->getDir(), nivel + 1);
    }
}

//int ArvBinBusca::getRaiz()
//{
//
//}
//
//bool ArvBinBusca::vazia()
//{
//
//}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}
bool ArvBinBusca::auxBusca(NoArv* p, int val)
{
    if (p == NULL)
        return false;// �rvore vazia
    else if (p->getInfo() == val)
        return true;// chave encontrada
    else if (val < p->getInfo()) // val pertence a SAE de p
        return auxBusca(p->getEsq(), val);
    else // val > p->getInfo(), val pertence a SAD de p
        return auxBusca(p->getDir(), val);
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}
NoArv* ArvBinBusca::auxInsere(NoArv* p, int val)
{
    if (p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if (val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}
//void ArvBinBusca::remove(int val)
//{
//
//}