#include <iostream>
#include "Data.h"

using namespace std;

Data::Data(int d, int m, int a)
{

    if (d < 30 && d>1)
        this->d = d;
    if (m < 12 && m>1)
        this->m = m;
    if (a > 0)
        this->a = a;

}

Data::~Data(){}

void Data::setDiaMesAno(int d, int m, int a)
{
    d = 1;
    m = 1;
    a = 1000;

    if (m == 2 && d == 30)
        d = 29;
    if (d < 30 && d>1)
        this->d = d;
    if (m < 12 && m>1)
        this->m = m;
    if (a > 0)
        this->a = a;
}

void Data::imprime()
{
    cout << d << '/' << m << '/' << a;
}

Data* Data::somaAnos(int numYears)
{
    Data* aux = new Data(d, m, a + numYears);
    return aux;
}