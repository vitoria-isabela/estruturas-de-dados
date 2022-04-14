#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

void preencheABB(ArvBinBusca* a, int p, int q) {
    if (p <= q) {
        int m = (p + q) / 2;
        a->insere(m);
        preencheABB(a, p, m - 1);
        preencheABB(a, m + 1, q);
    }
}

//int antecessor(int val);

int main()
{
    /*ArvBinBusca arv;
    arv.insere(15);
    arv.insere(10);
    arv.insere(20);
    arv.insere(6);
    arv.insere(12);
    arv.insere(17);
    arv.insere(25);
    arv.insere(-3);
    arv.insere(8);
    arv.insere(30);
    arv.insere(40);
    arv.imprime();*/

    /*cout << "Conta:  " << arv.contaNos() << endl;
    cout << "Conta2: " << arv.contaNos2() << endl;
    cout << "Soma:   " << arv.somaNos() << endl;
    cout << "Media:  " << (float)arv.somaNos()/arv.contaNos() << endl;
    cout << "Media:  " << arv.mediaNos() << endl;
    cout << "Media2: " << arv.mediaNos2() << endl;

    arv.imprimeNivel(2);
    */
    /*
    arv.remove(8);
    arv.imprime();
    arv.remove(25);
    arv.imprime();
    arv.remove(20);
    arv.imprime();
    arv.remove(15);
    arv.imprime();
    */

    /*
    cout << arv.busca(18) << endl;
    cout << arv.buscaIt(18) << endl;
    cout << arv.busca(25) << endl;
    cout << arv.buscaIt(25) << endl;
    */
    /*
    // Ex 1:
    cout << "Maior valor: " << arv.maior() << endl;

    // Ex 2:
    cout << "Menor valor: " << arv.menor() << endl;
    //Ex 3:
    arv.removeMaior();
    // Ex 4:
    arv.removeMenor();
    // Ex 5:
    int x;
    cin >> x;
    cout << "Pares da raiz ate " << x << ": ";
    cout << arv.contaParesCaminho(x) << endl;*/

    //arv.remove(15);

    // Ex 7:

    /*ArvBinBusca* arv2 = new ArvBinBusca();
    preencheABB(arv2, 1, 10);
    arv2->imprime();*/

    ArvBinBusca arv;

    /*arv.insere(15);
    arv.insere(10);
    arv.insere(6);
    arv.insere(8);
    arv.insere(3);
    arv.insere(20);
    arv.insere(17);
    arv.insere(25);
    arv.insere(30);
    arv.imprime();*/

    preencheABB(&arv, 1, 10);

    arv.imprime();

    /*arv.impressaoParcialC(1, 8);*/

    //arv.removeMenorMaisEsqVal(2);

    //cout << arv.impressaoParcialC(2, 10);
    ///arv.imprimeMenores(15);
/*
    int n;
    int* v = arv.preencheVet(&n);

    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";

    delete [] v;
*/
    //arv.removeFilhoEsquerdaK(1, 10);
    /*cout << endl;
    cout << "O antecessor de 5 eh: " << arv.antecessor(5);
    cout << endl;

    arv.imprime();*/

    /*cout << endl;
    cout << "O sucessor de 5 eh: " << arv.sucessor(1, 10, 5);
    cout << endl;

    arv.imprime();*/

    //cout <<"O numero de nos do nivel eh: " << arv.contaNosNivel(7, 10, 3);
    /*cout << endl << endl << arv.EhABB(); */

    return 0;
}