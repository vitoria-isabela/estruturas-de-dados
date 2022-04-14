#include "Jogador.h"
#include <iostream>

using namespace std;

/// <summary>
/// Defina e desenvolva o TAD Jogador, que deve possuir os seguintes atributos:
//● int pontuacao(valor inteiro no intervalo fechado[0, 20000]);
//● int melhorClassificacao(valor inteiro positivo);
//● int totalTitulos(valor inteiro positivo);
//Além disso, o TAD Jogador deve oferecer as seguintes operações :
//● Construtor, que recebe que recebe por parâmetro os valores correspondentes aos três
//atributos e os inicializa;
//● Operações void setPontuacao(int p); , void setMelhorClassificacao
//(int m); e void setTotalTitulos(int t); que atualizam os respectivos
//atributos, garantindo que o objeto da classe permaneça válido;
//● Operação void posicaoRanking(int ranking[], int n, int* pos); que
//recebe como parâmetro um vetor de pontuações referentes a n jogadores, ordenadas
//de forma decrescente, e imprime a posição do jogador neste ranking.Caso a posição do
//jogador seja melhor que a armazenada em melhorClassificacao, atualizar este
//atributo e imprimir uma mensagem indicando isto.Retornar a posição do jogador por
//referência.
/// </summary>
/// <returns></returns>
int main()
{
	int pos;
	int ranking[] = { 8500, 6643, 3444, 1201, 1102, 1085, 998, 853, 554,
	323 };
	Jogador jogador(730, 3, 15);
	jogador.posicaoRanking(ranking, 10, &pos);
	return 0;
}