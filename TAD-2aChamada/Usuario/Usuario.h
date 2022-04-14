#pragma once

class Usuario
{
private:
	int identificador;
	float* historico; //vet

public:
	Usuario(int identificador);
	~Usuario();
	void leHistorico();
	float relatorio(int* maior);
};