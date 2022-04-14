
#include <iostream>
using namespace std;

#include "Usuario.h"

int main()
{
    int identificador = 1234;

    Usuario user(identificador);

    user.leHistorico();

    int* maior = 0;

    float media = user.relatorio(maior);

    cout << "A média das horas de acesso ao longo do ano eh:" << media << endl;

    return 0;
}