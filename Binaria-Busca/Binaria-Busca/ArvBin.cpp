#include <iostream>
#include <stdlib.h>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv* p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

/*
void ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        libera(p->getEsq());
        libera(p->getDir());
        delete p;
    }
}*/


int ArvBin::auxAltura(NoArv* p)
{
    if (p == NULL)
        return -1;
    else
    {
        int he = auxAltura(p->getEsq());
        int hd = auxAltura(p->getDir());
        ///return ( he>hd ? he : hd) + 1;
        if (he > hd)
            return he + 1;
        else
            return hd + 1;
    }
}


int ArvBin::getRaiz()
{
    if (raiz != NULL) //ou if(!vazia())
        return raiz->getInfo();
    else
    {
        cout << "�rvora vazia!" << endl;
        exit(1);
    }
}

bool ArvBin::vazia()
{
    return raiz == NULL;
}

void ArvBin::imprime()
{
    auxImprime(raiz);
}

void ArvBin::auxImprime(NoArv* r)
{///imprime uma AB por meio de percurso pr�-ordem
    if (r != NULL)
    {
        auxImprime(r->getEsq());
        cout << r->getInfo() << "  ";
        auxImprime(r->getDir());
    }
}

int ArvBin::auxNumNos(NoArv* p)
{
    if (p == NULL)
        return 0;
    else
        return 1 + auxNumNos(p->getEsq()) +
        auxNumNos(p->getDir());
}

int ArvBin::auxNFolhas(NoArv* p)
{
    if (p == NULL)
        return 0;
    else if (EhFolha(p))
        return 1;
    else
    {
        return auxNFolhas(p->getEsq()) + auxNFolhas(p->getDir());
    }
}

void ArvBin::cria(int val, ArvBin* sae, ArvBin* sad)
//dadas duas sub�rvores sae (sub a esquerda) e sad (sub a direita)
//cria uma nova �rvore com raiz contendo valor val e sub�rvores sae e sad
{
    NoArv* p = new NoArv();

    p->setInfo(val);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}


bool ArvBin::auxBusca(NoArv* p, int ch)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == ch)
        return true;
    else if (auxBusca(p->getEsq(), ch))
        return true;
    else
        return auxBusca(p->getDir(), ch);
}
