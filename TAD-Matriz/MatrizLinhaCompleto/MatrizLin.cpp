#include <iostream>
#include <cstdlib>

#include "MatrizLin.h"

using namespace std;

MatrizLin::MatrizLin(int mm, int nn)
{
    cout << "Criando um objeto MatrizLin" << endl;
    nl = mm;
    nc = nn;
    vet = new float[nl * nc];
}

MatrizLin::~MatrizLin()
{
    cout << "Destruindo um objeto MatrizLin" << endl;
    delete[] vet;
}

int MatrizLin::detInd(int i, int j)
{
    if (i >= 0 && i < nl && j >= 0 && j < nc)
        return nc * i + j;
    else
        return -1;
}

float MatrizLin::get(int i, int j)
{
    int k = detInd(i, j);
    if (k != -1)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void MatrizLin::set(int i, int j, float val)
{
    int k = detInd(i, j);
    if (k != -1)
        vet[k] = val;
    else
        cout << "ERRO: Indice invalido!" << endl;
}

void MatrizLin::imprime(int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            float val = vet[detInd(i, j)];
            cout << val << "\t";
        }
        cout << endl;
    }
}

float MatrizLin::maiorValor()
{
    float maior = vet[0];
    for (int i = 1; i < nl*nc; i++)
    {
        if (vet[i] > maior)
            maior = vet[i];
    }
    return maior;
}

MatrizLin* MatrizLin::transposta()
{
    MatrizLin* mat2 = new MatrizLin(nc, nl);

    for (int i = 0; i < nl; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            int k = detInd(i, j);
            float val = vet[k];
            mat2->set(j, i, val);
        }
    }
    return mat2;
}

int MatrizLin::getNl()
{
    return nl;
}

int MatrizLin::getNc()
{
    return nc;
}
