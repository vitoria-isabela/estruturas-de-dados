#include <iostream>
#include "MatrizAmpulheta.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    MatrizAmpulheta mat(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            float val = i * n + j;
            mat.set(i, j, val);
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "\t" << mat.get(i, j);
        cout << endl;
    }
    return 0;
}
