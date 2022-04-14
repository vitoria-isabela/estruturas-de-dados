#pragma once
class VetorFlexivel
{
private:
    int n; // tamanho do vetor
    float* vet; // array que armazena n floats
    int c, f; // c: limite inferior do indice
    // f: limite superior do indice
    int detInd(int indice); // operador privado
public:
    VetorFlexivel(int a, int b);
    ~VetorFlexivel();
    float get(int indice);
    void set(int indice, float valor);
};

