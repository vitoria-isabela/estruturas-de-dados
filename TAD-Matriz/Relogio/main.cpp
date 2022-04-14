#include <iostream>
#include "Relogio.h"


int main()
{
	Relogio r(11, 11, 11);
	r.horario();

	r.acertar(2, 59, 57);
	r.horario();

	r.tique();
	r.horario();

	r.tique();
	r.horario();

	r.tique();
	r.horario();

	r.tique();
	r.horario();

	return 0;
}