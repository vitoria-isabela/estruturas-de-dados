#include <iostream>
#include "Venda.h"

using namespace std;

int main()
{
    int n;
    cout << "Digite o total de itens vendidos: ";
    cin >> n;
    Venda v(n);
    cout << v.calculaTotal() << endl;
    cout << v.itemMaisCaro() << endl;
    return 0;
}
