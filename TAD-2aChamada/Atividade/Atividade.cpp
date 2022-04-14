#include "Atividade.h"

#include <iostream>
using namespace std;

Atividade::Atividade(int n)
{
    if (n <= 0)
    {
        cout << "A atividade deve ter pelo menos 1 questao";
        exit(1);
    }
    totalQuestoes = n;
    notas = new float[totalQuestoes];
    valorQuestao = 100.0 / totalQuestoes;
}

Atividade::~Atividade()
{
    delete[] notas;
}

void Atividade::leNotas()
{
    for (int i = 0; i < totalQuestoes; i++)
    {
        cout << "Digite a nota da questao " << i + 1 << ": ";
        cin >> notas[i];
        while (notas[i] < 0 || notas[i] > valorQuestao)
        {
            cout << "Nota invalida! Digite novamente: ";
            cin >> notas[i];
        }
    }
}

void Atividade::imprimeRelatorio()
{
    float notaFinal = 0;
    for (int i = 0; i < totalQuestoes; i++)
    {
        notaFinal += notas[i];
        if (notas[i] < valorQuestao * 0.6)
            cout << "Nota da questao " << i + 1 << " abaixo de 60%" << endl;
    }
    cout << "Nota final: " << notaFinal;
}