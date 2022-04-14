#pragma once
class Vetor
{
private:
    int n; // tamanho do vetor
    float* vet; // array que armazena n floats
    bool verifica(int indice);

public:
    Vetor(int tam);
    ~Vetor();
    float get(int indice);
    void set(int indice, float valor);
};
