#pragma once

#include <string>
#include <iostream>

using namespace std;

class Ponto2D
{
private:
	int x, y;

public:
	Ponto2D(float a, float b);
	float PrintOutX(float x);
	float PrintOutY(float y);
	float CalcDistance();
};

