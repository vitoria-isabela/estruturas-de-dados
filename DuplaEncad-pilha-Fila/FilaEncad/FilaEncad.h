#pragma once

#include "C:\Users\6113826\source\repos\EstruturadeDados\DuplaEncad-pilha-Fila\PilhaEncad\No.h"

using namespace std;

class FilaEncad
{
private:
    No* inicio;
    No* fim;      /// ponteiros para os No's extremos
public:
    FilaEncad();
    ~FilaEncad();
    int getInicio();           /// retorna valor do primeiro No
    void enfileira(int val);   /// insere No no fim
    int desenfileira();        /// elimina No do inicio
    bool vazia();              /// verifica se fila esta vazia
    void imprime();
    bool jaContido(int val);
};