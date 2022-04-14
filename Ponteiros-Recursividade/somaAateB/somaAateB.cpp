#include <iostream>
using namespace std;

/* Escreva uma func~ao recursiva que calcule a soma dos numeros de a ate b, onde a e b s~ao dados
como par^ametro para a func~ao e s~ao tais que a < b. */

int somaAateB(int a, int b);

int main() {
	int a, b;
	cout << "Insira o numero que vai comecar a soma:  " << endl;
	cin >> a;
	cout << "Insira o numero que vai terminar a soma:  " << endl;
	cin >> b;

	cout << somaAateB(a, b);
}

int somaAateB(int a, int b)
{
	if (b == a)
	{
		return a;
	}
	else if (b > a)
	{
		return a + somaAateB(a + 1, b);
	}

}