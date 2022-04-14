#include <iostream>
#include "Circulo.h"

using namespace std;

int main()
{ 
	float x, y;
	cin >> x >> y;
	Ponto center(x,y);

	float raio;
	cin >> raio;

	Circulo c(center, raio);

	cout << "Imprimindo coordenadas do centro: " << endl;
	center.imprime();

	c.printOutRadiusOfCenter();
	cout << " perimeter is: " << c.perimeterOfCircle() << endl;
	
}
