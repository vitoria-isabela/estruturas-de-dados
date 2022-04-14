#pragma once

class PilhaCont
{
private:
	int max; // capacidade maxima
	int topo; // posicao do topo da pilha
	int* vet; // vetor que armazena os dados da pilha
public:
	PilhaCont(int tam);
	~PilhaCont();
	int getTopo(); // valor do No no Topo
	void empilha(int val);// insere No no Topo
	int desempilha(); // elimina No do Topo
	bool vazia();
};