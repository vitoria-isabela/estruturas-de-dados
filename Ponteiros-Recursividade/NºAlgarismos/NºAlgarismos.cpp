#include <iostream>
#include <string>
using namespace std;

/* O nuumero de digitos de um numero inteiro positivo pode ser determinado atraves de sucessivas
divisoes por 10 (sem guardar o resto) ate que o numero seja menor do que 10, consistindo
de apenas 1 digito. Implemente uma funcao recursiva que calcule o numero de digitos de um
inteiro positivo n. */

int numDigitos(int n);

int main() {

    int  n;
    cout << "Insira o numero: " << endl;
    cin >> n;

    cout << "O numero de algarismos eh : " << numDigitos(n) << endl;

    return 0;
}

int numDigitos(int n) {
    int cont = 1;
    if (n < 10) {
        return 1;
    }
    else if (n >= 10)
    {
        n = n / 10;
        cont = cont + numDigitos(n);
    }
    return cont;
}