#pragma once
class MatrizEspecial
{
private:
	int n;
	float* vet;
	int detInd(int i, int j);

public:
	MatrizEspecial(int mm);
	~MatrizEspecial();
	float get(int i, int j);
	void set(int i, int j, float val);
};

