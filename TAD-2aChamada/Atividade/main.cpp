#include <iostream>

#include "Atividade.h"

using namespace std;

/// <summary>
/// Defina e desenvolva o TAD Atividade, que deve possuir os seguintes atributos:
//int totalQuestoes(número inteiro positivo indicando o total de questões de uma atividade);
//float valorQuestao(valor de cada questão);
//float* notas(vetor contendo as notas obtidas em cada questão);
//Além disso, o TAD Atividade deve oferecer as seguintes operações :
//Construtor, que recebe o total de questões como parâmetro, aloca o vetor e inicializa os demais atributos(assuma que todas as questões possuem o mesmo valor e que o valor total da atividade é 100);
//Destrutor;
//Operação void leNotas(); que solicita ao usuário que digite a nota de cada questão(notas fora do intervalo válido devem ser lidas novamente);
//Operação void imprimeRelatorio(); calcula e imprime a nota total, além de imprimir mensagens indicando em quais questões as notas ficaram abaixo de 60 % .
/// </summary>
/// <returns></returns>
int main()
{
	Atividade a(5);
	a.leNotas();
	a.imprimeRelatorio();
	return 0;
}