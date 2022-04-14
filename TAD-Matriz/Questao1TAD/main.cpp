#include <iostream>
#include "Localizacao.h"
using namespace std;

int main()
{
    Localizacao l(23.22123, 28.2424), min(11.2662, 23.2323), max(44.21124, 87.331);
    if (l.contidaNoIntervalo(min, max))
        cout << "Localizacao (" << l.getLatitude() << ", " << l.getLongitude() << ") esta contida no intervalo" << endl;
    else
        cout << "Localizacao (" << l.getLatitude() << ", " << l.getLongitude() << ") nao esta contida no intervalo" << endl;
    return 0;
}
