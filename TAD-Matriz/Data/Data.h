#include <iostream>

using namespace std;

class Data
{
private:
    int d;
    int m;
    int a;

public:
    Data(int d, int a, int m);
    ~Data();

    void setDiaMesAno(int d, int m, int a);
    void imprime();
    Data* somaAnos(int numYears);
};

