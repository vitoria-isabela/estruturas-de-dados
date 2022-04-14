#include <iostream>
#include <string>
using namespace std;

/* Desenvolver uma função recursiva que recebe um vetor de
reais e seu tamanho n, calcular e retornar o menor valor do
vetor. */

float menor(int n, float vet[]);

int main() {
    int i, n;
    float menorNum;

    cout << "Insira o tamanho do vetor:" << endl;
    cin >> n;

    float* vet = new float[n];

    cout << "Insira todos os valores do vetor:" << endl;
    for (i = 0; i < n; i++) {
        cin >> vet[i];
    }

    menorNum = menor(n, vet);
    cout << "O menor numero do vetor eh " << menorNum << endl;

    delete[] vet;

    return 0;
}

float menor(int n, float vet[]) {
    float menorNum;

    if (n == 1)
    {
        return vet[0];
    }
    else
    {
        menorNum = menor((n - 1), vet);

        if (menorNum < vet[n - 1])
        {
            return menorNum;
        }
        else
        {
            return vet[n - 1];
        }
    }
}