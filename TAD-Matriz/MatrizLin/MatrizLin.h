#pragma once
class MatrizLin
{
private:
    int nl, nc; // numero de is e js
    float* vet; // vetor de tamanho nl*nc
    int detInd(int i, int j);
public:
    MatrizLin(int mm, int nn);
    ~MatrizLin();
    void set(int i, int j, float val);
    float get(int i, int j);
};

