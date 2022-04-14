#include "Jogador.h"

#include <iostream>

using namespace std;

Jogador::Jogador(int pontuação, int melhorClassificacao, int totalTitulos)
{
	setPontuacao(pontuação);
	setMelhorClassificacao(melhorClassificacao);
	setTotalTitulos(totalTitulos);
}

void Jogador::setPontuacao(int p)
{
	if (p >= 0 || p <= 2000)
		pontuacao = p;
	else
		cout << "Pontuacao invalida!" << endl;
}
 void Jogador::setMelhorClassificacao(int m)
{
	if (m < 0)
		cout << "Classificação invalida!" << endl;
	else
		melhorClassificacao = m;
}
 void Jogador::setTotalTitulos(int t)
{
	if (t < 0)
		cout << "Total invalido!" << endl;
	else
		totalTitulos = t;
}
 void Jogador::posicaoRanking(int ranking[], int n, int* pos)
{
	 int i;
	 for (i = 0; i < n; i++)
	 {
		 if (pontuacao > ranking[i])
			 break;
	 }
	 *pos = i + 1;
	 cout << "Jogador eh o numero " << *pos << " do ranking" << endl;
	 if (i > melhorClassificacao)
	 {
		 cout << "Essa eh a melhor classificacao do jogador";
		 melhorClassificacao = i;
	 }
}
