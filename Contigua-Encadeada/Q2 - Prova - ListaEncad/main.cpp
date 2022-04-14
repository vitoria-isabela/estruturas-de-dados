#include <iostream>
#include "ListaEncad.h"

using namespace std;

/// <summary>
/// Implementar a operação void ListaEncad::setn(int novo_n); para alterar o valor de n 
/// para o novo valor novo_n, onde n é o número de nós de uma lista simplesmente encadeada 
/// com descritor. O parâmetro novo_n tem que estar entre 0 e n, sendo assim o valor de n 
/// pode diminuir até 0 (ou permanecer o mesmo). Não basta apenas atribuir à n o seu novo valor, 
/// um número adequado de nós deve ser liberado para que a quantidade de nós alocados fique 
/// coerente com o novo valor para n. Deve-se desalocar os nós iniciais para que a lista fique 
/// com os últimos novo_n nós. Emitir a mensagem "Valor invalido" caso novo_n não esteja entre 0 e n.
//Exemplo: Considere a lista simplesmente encadeada com descritor L com os valores L = [9 49 37 41 0] :
//    O comando L.setn(2) torna L = [41 0].
//    O comando L.setn(0) torna L = [](lista vazia)
/// </summary>
/// <returns></returns>
int main()
{
    ListaEncad lista;

    lista.insereFinal(1);
    lista.insereFinal(2);
    lista.insereFinal(3);
    lista.insereFinal(4);
    lista.insereFinal(5);
    cout << "Lista intriseca:" << endl;
    lista.imprimir();

    cout << "Lista com novo n:" << endl;
    lista.setn(2);

    lista.imprimir();
    return 0;
}