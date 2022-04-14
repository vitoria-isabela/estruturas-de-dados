#pragma once
class Venda
{
public:
    Venda(int n);
    ~Venda();
    double calculaTotal();
    double itemMaisCaro();

private:
    int numItensVendidos;
    double* valorItens;
};


