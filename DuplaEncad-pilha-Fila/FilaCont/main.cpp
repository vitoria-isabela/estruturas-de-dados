#include <iostream>

#include "FilaCont.h"

using namespace std;

int main()
{

    FilaCont f1(5);

    f1.enfileira(5);
    f1.enfileira(6);
    //cout << "Valor fila: "<< f1.desenfileira()<< endl;
    f1.enfileira(7);
    //cout << "Valor fila: "<< f1.desenfileira()<< endl;
    //cout << "Valor fila: "<< f1.desenfileira()<< endl;
    f1.enfileira(8);
    f1.enfileira(9);
    //cout << "Valor fila: "<< f1.desenfileira()<< endl;
    //cout << "Valor fila: "<< f1.desenfileira()<< endl;

    f1.imprime();

    //f1.enfileira(10);
}