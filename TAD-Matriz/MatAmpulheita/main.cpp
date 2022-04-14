#include <iostream>
#include "MatrizAmpulheita.h"
using namespace std;

///NESSA IMPLEMENT�O OS CANTOS N�O FORAM CONSIDERADOS NEGATIVOS SIM�TRICOS
///A(0,0) = A(N-1, N-1)
///A(N-1, 0) = A(0, N-1) = -A(0,0)
///tem que considerar separadamente esse valor

int main()
{
    int n = 10;
    MatrizAmpulheita mat(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat.set(i, j, i + j - 10);


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "\t" << mat.get(i, j);
        cout << endl;
    }
    return 0;
}
