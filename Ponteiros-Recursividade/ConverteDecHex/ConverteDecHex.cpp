#include <iostream>
using namespace std;

string converteDecParaHex(int x);

int main()
{
	int n;
	cin >> n;
	cout << converteDecParaHex(n);
}

string converteDecParaHex(int x)
{
	string str = "";
	if (x > 0)
	{
		str = converteDecParaHex(x / 16);
		int resto = x % 16;
		if (resto < 10)
			str += ('0' + resto);
		else
			str += ('A' + resto - 10);
	}
	return str;
}