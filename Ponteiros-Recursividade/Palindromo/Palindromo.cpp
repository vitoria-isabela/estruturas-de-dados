#include <iostream>
using namespace std;

/* Escreva uma funcao recursiva que determina se um vetor de caracteres e um palindromo. A
funcao recebe como parametros o tamanho e o vetor e deve retornar true ou false. */

bool ehPalindromo(char a[], int n);

int main()
{
    int n;
    cout << "Indique o tamanho da string: " << endl;
    cin >> n;
    char* a = new char[n];
    cout << "Escreva a palavra: " << endl;
    cin >> a;

    cout << ehPalindromo(a, n) << endl;
}

bool ehPalindromo(char a[], int n)
{
    if (n <= 1)
        return 1;
    else {
        bool x, y;
        x = a[0] == a[n - 1];
        y = ehPalindromo(a + 1, n - 2); //a + 1 é equivalente à &a[1] e n-2 é a penúltima letra.
        return x && y;
    }
}