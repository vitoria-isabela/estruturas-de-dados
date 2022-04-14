#ifndef MATRIZANTISIMETRICA_H_INCLUDED
#define MATRIZANTISIMETRICA_H_INCLUDED

class MatrizAntiSimetrica
{
private:
    int n;
    float* vet;
    bool verifica(int i, int j);
public:
    ///interface
    MatrizAntiSimetrica(int ordem);
    ~MatrizAntiSimetrica();
    float get(int i, int j);
    void set(int i, int j, float valor);
};

#endif // MATRIZANTISIMETRICA_H_INCLUDED
