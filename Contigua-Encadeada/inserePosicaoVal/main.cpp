#include <iostream>

#include "ListaEncad.h"

using namespace std;

/// <summary>
/// Implementar a operação bool ListaEncad::inserePosicaoVal(int k,
//int val); que, dados um valor val e uma posição k, obtém o valor x
//armazenado no nó da posição k da lista e insere val na posição x.Caso x indique
//uma posição inválida, ou seja, fora dos limites da lista, deve - se retornar false.
//Caso contrário, deve - se proceder à inserção de val na posição x e retornar true.
//Exemplo: Considere uma lista com os valores[3, 2, 5, 7, 9, 2, 4, 8].Se
//k for igual a 3, o nó na posição k será o nó cujo valor é 7. Logo, x é igual a 7.
//Tratando x como uma posição da lista, o valor val deve ser inserido na posição 7,
//que é onde se encontra o valor 8. Assim, assumindo que val é igual a 1, a lista final
//ficará da seguinte forma : [3, 2, 5, 7, 9, 2, 4, 1, 8] .
/// </summary>
/// <returns></returns>
int main()
{
    ListaEncad lista;

    lista.insereFinal(3);
    lista.insereFinal(2);
    lista.insereFinal(5);
    lista.insereFinal(7);
    lista.insereFinal(9);
    lista.insereFinal(2);
    lista.insereFinal(4);
    lista.insereFinal(8);
    
    cout << "Foi possivel inserir o valor da posicao k na nova posicao? " << lista.inserePosicaoVal(3, 1); //retorno '1': true; retorno '0': false
    cout << endl;

    return 0;
}