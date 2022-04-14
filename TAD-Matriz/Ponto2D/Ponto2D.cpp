#include "Ponto2D.h"

using namespace std;

Ponto2D::Ponto2D(float a, float b)
{
	x = a;
	y = b;
}
Ponto2D::~Ponto2D() {}

float Ponto2D::PrintOutX(float x) 
{
	cout << "O valor de X eh: " << x << endl;
}

float Ponto2D::PrintOutY(float y)
{
	cout << "O valor de Y eh: " << y << endl;
}