#pragma once
class MatrizDiagonal
{
private:
    int n;
    float* vet;
    bool verifica(int i, int j);
    int detInd(int i, int j);
public:
    MatrizDiagonal(int nn);
    ~MatrizDiagonal();

    float get(int i, int j);
    void set(int i, int j, float valor);
    void imprime();
};
