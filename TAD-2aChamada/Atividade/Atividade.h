#pragma once
class Atividade
{
private:
    int totalQuestoes;
    float valorQuestao;
    float* notas; //vet

public:
    Atividade(int n);
    ~Atividade();
    void leNotas();
    void imprimeRelatorio();
};