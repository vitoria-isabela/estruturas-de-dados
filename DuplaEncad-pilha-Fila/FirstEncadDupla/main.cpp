#include <iostream>
#include "ListaDupla.h"

using namespace std;

int main()
{
    ListaDupla l;
    l.insereK(0, 10);
    //l.imprime();
    l.insereFinal(4);
    l.insereFinal(2);
    l.insereFinal(1);
    //l.imprime();
    l.insereInicio(0);
    l.insereInicio(6);
    //l.imprime();
    l.insereK(2, -1);
    //l.imprime();
   /* l.insereK(0, -2);
    l.imprime();
    l.insereK(8, -3);
    l.imprime();
    l.removeK(0);
    l.imprime();
    l.removeK(7);
    l.imprime();
    l.removeK(2);
    l.imprime();*/
    return 0;
}