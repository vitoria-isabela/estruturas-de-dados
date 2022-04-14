#include <iostream>
#include "MatAlternada.h"


using namespace std;

int main()
{
    int n;
    cin >> n;
    MatAlternada mat(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat.set(i, j, i + j + 5);


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "\t" << mat.get(i, j);
        cout << endl;
    }
    return 0;
}
