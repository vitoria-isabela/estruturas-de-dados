#include <string>
#include <iostream>
using namespace std;
#include "Relogio.h"

Relogio::Relogio(int h, int m, int s) {
	horas = h;
	minutos = m;
	segundos = s;
}

void Relogio::acertar(int h, int m, int s)
{
	horas = 0;
	if (horas > 0 && horas <= 12)
		horas = h;
	minutos = 0;
	if (minutos > 0 && minutos <= 59)
		minutos = m;
	segundos = 0;
	if (segundos > 0 && segundos <= 59)
		segundos = s;
}

int Relogio::getHora() {
	return horas;
}
int Relogio::getMinuto() {
	return minutos;
}
int Relogio::getSegundo() {
	return segundos;
}
void Relogio::tique()
{
	segundos++;
	if (segundos >= 60) {
		minutos++;
		segundos -= 60;
	}
	if (minutos >= 60) {
		horas++;
		minutos -= 60;
	}
	if (horas > 12) {
		horas -= 12;
	}
}

void Relogio::horario()
{
	cout << horas << ":" << minutos << ":" << segundos << endl;
}

