#include <iostream>
#include <random>
#include "ListaCont.h"
#include "ListaContPonto.h"
#include "Ponto.h"

using namespace std;

/// <summary>
/// Este exercicio aborda metodos basicos de uma lista contigua, envolvendo a classe Ponto
/// </summary>
/// <returns></returns>
int main()
{
    ListaCont l(10);

    l.insereFinal(24);
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(-1);
    l.insereFinal(99);

    l.imprime();
    l.insereInicio(10);

    l.imprime();

    int indice = l.buscaMaior(10);
    if (indice != -1)
        cout << "Elemento maior: " << l.get(indice) << endl;
    else
        cout << "Nao foi encontrado valor maior na lista." << endl;

    l.limpar();
    l.imprime();

    int vet[6] = { 11,12,13,14,15,16 };
    l.insereValores(6, vet);

    l.imprime();

    int vet2[4] = { 11,12,13,14 };
    l.insereValores(4, vet2);

    l.imprime();

    ListaCont L1(50), L2(25), L3(25);

    for (int i = 0; i < 50; i++) {
        L1.insereFinal(rand() % 100);
    }
    L1.imprime();


    for (int i = 0; i < 50 / 2; i++) {
        // porque nao pode deixar get(i) e remove(i)???
        L2.insereFinal(L1.get(0));
        L1.removeInicio();
    }

    L2.imprime();

    L1.imprime();

    for (int i = 0; i < 50 / 2; i++) {
        L3.insereFinal(L1.get(0));
        L1.removeInicio();
    }

    L3.imprime();

    L1.imprime();

    // --- Exercicio 4 --- 

    // Lista de Pontos
    ListaContPonto lp(10);
    //cria e inicializa varios pontos
    Ponto p1(0, 0), p2(0, 2), p3(2, 0);
    // e insere cada um na lista
    lp.insereFinal(p1);
    lp.insereFinal(p2);
    lp.insereFinal(p3);

    lp.imprime();

    cout << "Tabela de distancias: " << endl;

    Ponto* ponto2 = new Ponto();

    for (int i = 0; i < lp.numNos(); i++) {
        for (int j = 0; j < lp.numNos(); j++) {
            ponto2->setX(lp.get(j).getX());
            ponto2->setY(lp.get(j).getY());
            cout << lp.get(i).distancia(ponto2) << "\t";
        }
        cout << endl;
    }
    return 0;
}