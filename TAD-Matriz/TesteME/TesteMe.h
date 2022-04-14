#pragma once
class TesteME
{
private:
	int n;
	float* vetDPouDS;
	float* vetPrimeiraCol;
	bool verifica(int i, int j);

public:
	TesteME(int mm);
	~TesteME();
	float get(int i, int j);
	void set(int i, int j, float val);
};
