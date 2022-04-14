#include <string>
#include <iostream>
#include "GradeBook.h"

using namespace std;


// o construtor inicializa courseName com a string fornecida como argumento
GradeBook::GradeBook(string name)
{
	setCourseName(name);
}

GradeBook::~GradeBook() {}

// função que configura o nome do curso;
void GradeBook::setCourseName(string name)
{
	if (name.length() <= 25)
		courseName = name;

	if (name.length() > 25)
	{
		courseName = name.substr(0, 25);
		cout << "Name \"" << name << "\" exceeds maximum length(25).\n"
			<< "Limiting courseName to first 25 characters.\n" << endl;
	}
}

// função para obter o nome do curso
string GradeBook::getCourseName()
{
	return courseName;
}

void GradeBook::displayMessage()
{
	// chama getCourseName para obter o courseName
	cout << "Welcome to the grade book for\n" << getCourseName()
		<< "!" << endl;
}