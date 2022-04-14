#include <iostream>
using namespace std;

/* Crie uma função int* encontraMaior(int n1, int n2, int *t, int *m); que recebe como parâmetros dois valores inteiros n1 e n2.
A função deve criar e retornar um vetor de inteiros com o tamanho n2-n1. Caso n2 não seja maior que n1, a função deve retornar NULL.
Além disso, a função deve realizar a leitura dos valores do vetor e armazenar o maior valor em m. O tamanho do vetor deve ser armazenado em t */

int* encontraMaior(int n1, int n2, int* t, int* m);

int main()
{
    int n1, n2;
    cout << "Digite o valor de n1: " << endl;
    cin >> n1;
    cout << "Digite o valor de n2: " << endl;
    cin >> n2;

    int tam = 0;
    int maior = 0;
    int* t = &tam;
    int* m = &maior;

    cout << "O vetor de retorno eh: " << *encontraMaior(n1, n2, &tam, &maior) << endl;
    cout << "O maior elemento do vetor eh: " << *m << endl;
}

int* encontraMaior(int n1, int n2, int* t, int* m)
{
    *t = (n2 - n1);
    int* vet = new int[*t];

    if (n2 > n1)
    {
        cout << "Leia " << *t << " valores para o vetor: " << endl;
        for (int i = 0; i < *t; i++)
        {
            cin >> vet[i];
        }

        for (int i = 0; i < *t; i++)
        {

            if (vet[i] > *m)
            {
                *m = vet[i];
            }
        }
        return vet;
    }
    else
    {
        return NULL;
    }
}