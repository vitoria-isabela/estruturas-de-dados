#include <iostream>

#include "Localizacao.h"

using namespace std;

/// <summary>
/// Defina e desenvolva o TAD Localizacao, que deve possuir os seguintes atributos:
//float latitude(valor real no intervalo fechado[-90, 90]);
//float longitude(valor real no intervalo fechado[-180, 180]);
//
//Além disso, o TAD Localizacao deve oferecer as seguintes operações :
//Construtor, que recebe as coordenadas de uma localização;
//Operações float getLatitude(); e float getLongitude(); que devem retornar os valores armazenados nos respectivos atributos;
//Operações void setLatitude(float lat); e void setLongitude(float lng); que deve alterar os valores dos respectivos atributos, 
// garantindo que o resultado seja uma localização válida;
//Operação bool contidaNoIntervalo(Localizacao min, Localizacao max); que verifica se as coordenadas da localização acessadas 
//através dos métodos públicos do TAD no TAD estão dentro dos limites mínimo e máximo passados como parâmetros.
/// </summary>
/// <returns></returns>
int main()
{
	Localizacao l(23.22123, 28.2424), min(11.2662, 23.2323), max(44.21124, 87.331);
	if (l.contidaNoIntervalo(&min, &max))
		cout << "Localizacao (" << l.getLatitude() << ", " << l.getLongitude() << ") esta contida no intervalo" << endl;
	else
		cout << "Localizacao (" << l.getLatitude() << ", " << l.getLongitude() << ") nao esta contida no intervalo" << endl;
	return 0;
}