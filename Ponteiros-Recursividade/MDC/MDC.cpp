#include <iostream>
using namespace std;

int mdc(int m, int n);

int main()
{
	int x, y;
	cout << "Digite x: " << endl;
	cin >> x;
	cout << "Digite y: " << endl;
	cin >> y;

	cout << "O MDC eh:  " << mdc(x, y);
}

int mdc(int m, int n)
{
	if (m < n)
	{
		return mdc(n, m);
	}
	else if (m % n == 0)
	{
		return n;
	}
	else
	{
		return mdc(n, m % n);
	}
}
