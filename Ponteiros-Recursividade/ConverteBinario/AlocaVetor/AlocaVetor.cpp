#include <iostream>
using namespace std;

/* Procedimento para alocar vetores. Crie agora um procedimento para preencher vetores
de tamanho n com valores digitados pelo usuario. */

void preencheVetorF(int n, float* vet);

int main() {
	int n;
	cout << "Insira o tamanho do vetor:  " << endl;
	cin >> n;
	float* vet = new float[n];
	preencheVetorF(n, (vet));

	delete[] vet;

	return 0;
}

void preencheVetorF(int n, float* vet)
{
	for (int i = 0; i < n; i++) {
		cin >> vet[i];
	}
	for (int i = 0; i < n; i++) {
		cout << vet[i] << " ";
	}
}