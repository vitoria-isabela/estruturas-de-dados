#pragma once
class ListaCont
{
private:
    int max, n, inicio;
    int* vet;

    ///indice do �ltimo n�
    int ultimo() { return inicio + n - 1; }

    ///verifica se k � um �ndice v�lido
    int valido(int k) { return k >= inicio && k <= ultimo(); }

    void realoca();
public:
    ListaCont(int tam);
    ~ListaCont();

    int get(int k);
    void set(int k, int val);  ///altera valor na posicao k

    void insereFinal(int val);
    void insereK(int k, int val);
    void insereInicio(int val);

    void removeFinal();
    void removek(int k);
    void removeInicio();

    void imprime();
    ListaCont* retornaPares();
};
