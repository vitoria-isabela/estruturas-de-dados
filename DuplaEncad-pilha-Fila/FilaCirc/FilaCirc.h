#pragma once
class FilaCirc
{
private:
    int max; // maximo de elementos do vetor
    int inicio; // indice do No que esta no inicio
    int fim; // indice do No que esta no fim
    int n; // numero atual de elementos do vetor
    int* vet; // vetor que armazena a fila
    int inc(int ind); // incrementa indice
public:
    FilaCirc(int tam);
    ~FilaCirc();
    int getInicio(); // consulta No do inicio
    void enfileira(int val); // insere No no fim
    int desenfileira(); // elimina No do inicio
    bool vazia(); // verifica se esta vazia
    void imprime();
};