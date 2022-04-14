#include <iostream>
#include "TesteME.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    TesteME mat(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            float val = i * n + j;
            mat.set(i, j, val);
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            float val = mat.get(i, j);
            cout << val << "\t";
        }
        cout << endl;
    }
    return 0;
}