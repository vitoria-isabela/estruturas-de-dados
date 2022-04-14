#include <iostream>
using namespace std;

/* Desenvolver uma função recursiva para calcular e retornar
uma string de caracteres contendo ‘0’ e ‘1’ correspondente
à versão binária de um número inteiro positivo dado. */

string converteBinario(int n);

int main()
{
    int n;
    cout << "Insira o numero a ser convertido para binario: " << endl;
    cin >> n;

    cout << converteBinario(n);
}

string converteBinario(int n)
{
    if (n == 0)
        return "0";
    if (n == 1)
        return "1";
    if (n % 2 == 0)
        return converteBinario(n / 2) + "0";
    return converteBinario(n / 2) + "1";
}
