#include <string>
#include <iostream>

using namespace std;

//PA - Programa de implementação (o que) 

// Definição da classe GradeBook. Esse arquivo apresenta a interface pública de
// GradeBook sem revelar as implementações de funções-membro de GradeBook
// que são definidas em GradeBook.cpp.

class GradeBook
{
public:
	GradeBook(string);
	~GradeBook();
	void setCourseName(string);
	string getCourseName();
	void displayMessage();
private:
	string courseName;

};
