#pragma once
#include <string>
#include <iostream>

using namespace std;

class Relogio
{
public:
	Relogio(int h, int m, int s);
	void acertar(int h, int m, int s);
	int getHora();
	int getMinuto();
	int getSegundo();
	void tique();
	void horario();
private:
	int horas, minutos, segundos;
};
