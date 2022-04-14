#include <iostream>
#include "FilaCirc.h"

using namespace std;

int main()
{

    FilaCirc f1(5);

    f1.enfileira(5);
    f1.enfileira(6);
    cout << "Valor fila: " << f1.desenfileira() << endl;
    f1.enfileira(7);
    cout << "Valor fila: " << f1.desenfileira() << endl;
    cout << "Valor fila: " << f1.desenfileira() << endl;
    f1.enfileira(8);
    f1.enfileira(9);
    //    cout << "Valor fila: "<< f1.desenfileira()<< endl;
        //cout << "Valor fila: "<< f1.desenfileira()<< endl;

    f1.enfileira(10);
    f1.imprime();


    /*
        FilaCont f1(100);

        for(int i=3; i<=20; i++)
            f1.enfileira(i*4 - 9);

        while(!f1.vazia())
        {
            int val = f1.desenfileira();
            cout << "Valor fila: "<< val<< endl;
        }
    */
    return 0;
}
