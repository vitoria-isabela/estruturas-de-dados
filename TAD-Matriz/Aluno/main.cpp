#include <iostream>
#include <string>
#include "Aluno.h"

int main()
{
	string name, registration;

	cout << "Digite o nome do aluno: " << endl;
	cin >> name;

	cout << "Digite a matricula do aluno:  " << endl;
	cin >> registration;

	Aluno a(name, registration);
	cout << "Digite a nota de "
		<< a.getNome() << endl;
	float n;
	cin >> n;
	a.setNota(n);
	a.info();
	return 0;
}