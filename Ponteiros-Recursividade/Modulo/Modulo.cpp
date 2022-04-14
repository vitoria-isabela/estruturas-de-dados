#include <iostream>
using namespace std;

int modulo(int x, int y);

int main() {
	int x, y;
	cout << "Digite x: " << endl;
	cin >> x;
	cout << "Digite y: " << endl;
	cin >> y;

	cout << "O resto dessa divisao eh:  " << modulo(x, y);
}

int modulo(int x, int y)
{
	if (x == y)
		return 0;
	if (x < y)
		return x;
	return modulo(x - y, y);
}