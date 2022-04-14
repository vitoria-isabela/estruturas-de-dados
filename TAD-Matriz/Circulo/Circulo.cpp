#include "Circulo.h"
#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

Circulo::Circulo(Ponto center, float raio)
{
	center.setX(center.getX());
	center.setY(center.getY());
	this->radius = raio;
}

Circulo::~Circulo(){}

float Circulo::getRadius()
{
	if (radius == 0)
		setRadius(radius);
	return radius;
}

void Circulo::setRadius(float radius)
{
	this->radius = radius;
}

void Circulo::printOutRadiusOfCenter()
{
	cout << "O raio do centro eh: " << getRadius() << endl;
}

float Circulo::perimeterOfCircle()
{
	return M_PI * radius * 2;
}
