#include <iostream>
using namespace std;

/* Escreva uma func~ao recursiva que calcule 1 + 2 + 3 + : : : + n, isto e, a soma dos numeros de 1
ate n, onde n e dado como par^ametro para a func~ao. */

int somaAteN(int n);

int main() {
	int n;
	cout << "Insira o limite da soma:  " << endl;
	cin >> n;

	cout << somaAteN(n);
}

int somaAteN(int n)
{
	if (n > 0)
	{
		if (n == 1)
		{
			return n;
		}
		else
		{
			return n + somaAteN(n - 1);
		}
	}
}