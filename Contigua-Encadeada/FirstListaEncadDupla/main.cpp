#include <iostream>
#include "ListaDupla.h"

using namespace std;

int main()
{
    ListaDupla l;
    l.insereFinal(4);
    l.insereFinal(2);
    l.insereFinal(1);
    l.imprime();
    l.imprimeReverso();
    l.insereInicio(0);
    l.insereInicio(6);
    l.imprime();
    l.imprimeReverso();
    return 0;
}