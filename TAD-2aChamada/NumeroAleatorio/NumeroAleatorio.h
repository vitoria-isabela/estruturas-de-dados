#pragma once
class NumeroAleatorio
{
private:
	int semente, minimo, maximo;
public:
	NumeroAleatorio(int s, int min, int max);
	void setSemente(int s);
	int* proximos(int n);
};
