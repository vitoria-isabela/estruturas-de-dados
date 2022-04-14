/******************************************************************************
Exercicio
*contar o números pares de um vetor
*contar o números impares
* contar os números negativos

*******************************************************************************/
#include <iostream>
using namespace std;

int* aloc(int tam, int vet[])
{
    for (int i = 0; i < tam; i++)
    {
        cout << "Digite valores para o vetor: " << endl;
        cin >> vet[i];
    }
    return vet;
}

bool contando(int tam, int vet[], int* par, int* neg, int* impar)
{
    for (int i = 0; i < tam; i++)
    {
        if (vet[i] < 0)
        {
            *neg += 1;
            return true;
        }
        if (vet[i] % 2 == 0)
        {
            *par += 1;
        }
        if (vet[i] % 2 == 0)
        {
            *impar += 1;
        }
    }
    return false;
}

int main()
{
    int p = 0, im = 0, n = 0;
    int tam;

    int* par, * impar, * neg;
    par = &p;
    impar = &im;
    neg = &n;

    cout << "Digite o tamanho do vetor: " << endl;
    cin >> tam;

    int* vet = new int[tam];
    aloc(tam, vet);

    cout << "Vetor possui negativo ou nao: " << contando(tam, vet, &p, &n, &im) << endl;
    cout << "Elementos pares, impares, negativos,: " << *par << " " << *impar << " " << *neg;

    return 0;
}

