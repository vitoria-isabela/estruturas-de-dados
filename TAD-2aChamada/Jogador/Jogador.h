#pragma once
class Jogador
{
private:
	int pontuacao;
	int melhorClassificacao;
	int totalTitulos;

public:
	Jogador(int pontuacao, int melhorClassificacao, int totalTitulos);
	void setPontuacao(int p);
	void setMelhorClassificacao(int m);
	void setTotalTitulos(int t);
	void posicaoRanking(int ranking[], int n, int* pos);

};

