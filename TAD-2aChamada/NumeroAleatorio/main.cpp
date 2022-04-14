#include <iostream>

#include "NumeroAleatorio.h"

using namespace std;

/// <summary>
/// Defina o TAD NumeroAleatorio que deve possuir os seguintes atributos:
/// - int semente ( valor positivo e menor que 101, usado para iniciar o processo de
/// geração dos números aleatórios);
/// - int minimo( valor inteiro indicando o limite inferior do intervalo dos números);
/// - int maximo (valor inteiro indicando o limite superios do intervalo dos números);
/// Além disso o tad deve oferecer as seguintes operações:
/// - Construtor, que recebe por parâmetro os valores correspondentes aos três atributos e
/// os inicializa (considere que minimo e maximo devem ser diferentes e, caso minimo seja maior
/// que máximo, o mínimo deve se tornar o máximo e vice-versa);
/// - Operação void setSemente (int s); que inicializa a semente do gerador, emitindo uma
/// mensagem de erro caso a semente seja inválida;
/// - Operação int* proximos(int n); que retorna um vetor contendo os proximos n numeros 
/// aleatórios da sequencia (assuma que a sequencia é definida pela formula "x i+1 = 
/// (7*xi + 13) % 101", sendo xo = semente). Após calcular os n números, esses devem ser ajustados
/// no intervalo [minimo, maximo -1].
/// </summary>
/// <returns></returns>
int main()
{
	NumeroAleatorio gerador(31, 0, 20);
	int* numeros = gerador.proximos(10);

	cout << "Numeros gerados: ";
	for (int i = 0; i < 10; i++)
		cout << numeros[i] << " ";

	delete[] numeros;
	return 0;
}