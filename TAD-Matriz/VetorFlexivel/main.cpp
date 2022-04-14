#include <iostream>
#include "VetorFlexivel.h"
using namespace std;

int main()
{
    int cc;
    int ff;
    cin >> cc >> ff;

    VetorFlexivel v(cc, ff);
    for (int i = cc; i <= ff; i++)
    {
        double val = i - cc + 1;
        v.set(i, val);
    }

    for (int i = cc; i <= ff; i++)
    {
        double val = v.get(i);
        cout << val << endl;
    }
    return 0;
}
