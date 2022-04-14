#pragma once
#include "NoArv.h"

class ArvBinBusca
{
private:
    NoArv* raiz;
    void libera(NoArv* p);
    void auxImprime(NoArv* p, int nivel);
    void auxImprime_in(NoArv* p, int nivel); // in-ordem
    bool auxBusca(NoArv* p, int val);
    NoArv* auxInsere(NoArv* p, int val);
    NoArv* auxRemove(NoArv* p, int val); //remove n�
    NoArv* removeFolha(NoArv* p); //caso 1
    NoArv* remove1Filho(NoArv* p); //caso 2
    NoArv* menorSubArvDireita(NoArv* p); //caso 3
    // Ex: 6
    NoArv* maiorSubArvEsq(NoArv* p); //caso 3 (alternativa)
    int auxContaNos(NoArv* p);
    void auxContaNos2(NoArv* p, int* cont);
    int auxSomaNos(NoArv* p);
    void auxMediaNos2(NoArv* p, int* cont, int* soma);
    void auxImprimeNivel(NoArv* p, int atual, int k);
    int auxMaior(NoArv* p);
    int auxMenor(NoArv* p);
    int auxContaParesCaminho(NoArv* p, int x);
    void auxImprimeMenores(NoArv* p, int val);
    void auxPreencheVet(NoArv* p, int* v, int* i);
    bool auxEhABB(NoArv* p, int* ultimo);
    int impressaoParcialCAux(NoArv* p, int a, int b);
    void auxUltimoNivel(NoArv* p, int a, int b, int nivel, int* ultimoNivel, int* cont);
    int AntecessorAbb(NoArv* p, int val, int* ultimoNivel, int nivel, int* cont);
    int impressaoParcialGAux(NoArv* p, int a, int b);
    int auxAntecessor(NoArv* p, int val, int* ultVisitado);
    int auxSucessor(NoArv* p, int x, int y, int val);
    int auxContaNosNivel(NoArv* p, int a, int b, int n, int atual);
    void auxInsereAbbEsquerda(ArvBinBusca* arvbb, int val);

public:
    ArvBinBusca();
    ~ArvBinBusca();
    int getRaiz();
    bool vazia();
    void imprime();
    void imprime_in_ordem();
    bool busca(int val);
    bool buscaIt(int val);
    void insere(int val);
    void remove(int val);
    int contaNos();
    int contaNos2();
    int somaNos();
    float mediaNos();
    float mediaNos2();
    void imprimeNivel(int k);
    int maior();
    int menor();
    void removeMaior();
    void removeMenor();
    int contaParesCaminho(int x);
    int* preencheVet(int* n);
    void contaParesImparesCaminho(int chave, int* pares, int* impares);
    void removeFilhoEsquerdaK(int k, int val);
    void insereFilhoDireitaK(int k, int val);
    int noMaisEsquerda();
    int noMaisEsquerdaVal(NoArv*p,int val);
    int noMaisDireita();
    int noMaisDireitaVal(NoArv* p, int val);
    bool EhABB();
    int impressaoParcialC(int a, int b);
    void removeMenorMaisEsqVal(int val);
    int ultimoNivel(int a, int b);
    int menorPar(int val);
    int auxAntecessor(int val, int* ultimoNivel, int nivel, int* cont);
    void removeFilhoEsquerdaMenor(int val);
    int impressaoParcialG(int a, int b);
    int antecessor(int val);
    int sucessor(int x, int y, int val);
    int contaNosNivel(int a, int b, int n);
    void removeFolhaVal(int val);
    bool maiores(int val);
    void insereAbbEsquerda(ArvBinBusca* arvbb);
};