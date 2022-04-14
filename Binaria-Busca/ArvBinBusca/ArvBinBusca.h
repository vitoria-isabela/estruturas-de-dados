#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
private:
    NoArv* raiz;
    void libera(NoArv* p);
    void auxImprime(NoArv* p, int nivel);
    bool auxBusca(NoArv* p, int val);
    NoArv* auxInsere(NoArv* p, int val);

public:
    ArvBinBusca();
    ~ArvBinBusca();
    int getRaiz();
    bool vazia();
    void imprime();
    bool busca(int val);
    void insere(int val);
    void remove(int val);
};

#endif // ARVBINBUSCA_H_INCLUDED
