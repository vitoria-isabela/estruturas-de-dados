#pragma once
class ListaCont
{
private:
	int max;
	int n;
	int* vet;

public:
	ListaCont(int tam);
	~ListaCont();

	void insereFinal(int val);
	void imprime();
	bool insereIntervalo(int a, int b);
	void setValor(int valor, int posicao);
	void inserirVet(int tam, int v[]);
	ListaCont* copiar(int valor);
	void removeK(int k);

};
