#pragma once
#include "C:\Users\6113826\source\repos\EstruturadeDados\EstruturadeDados\01-TADMatriz\Ponto\Ponto.h"
class Circulo
{
private:
	Ponto center;
	float radius;

public:
	Circulo(Ponto center, float radius);
	~Circulo();

	void printOutRadiusOfCenter();
	float perimeterOfCircle();
	
	float getRadius();

	void setRadius(float radius);
};

