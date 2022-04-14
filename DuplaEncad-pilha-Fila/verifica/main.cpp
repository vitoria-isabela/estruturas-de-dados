#include <iostream>

using namespace std;

#include "PilhaEncad.h"
#include "C:\Users\6113826\source\repos\EstruturadeDados\DuplaEncad-pilha-Fila\reorganiza (FilaEncad) - FilaEncad\FilaEncad.h"

int* inverte(int vet[], int n);
bool verifica();
PilhaEncad* transfere(PilhaEncad* p1, PilhaEncad* p2, FilaEncad* f);


/// <summary>
/// Implementar a função bool verifica() que avalia uma expressão aritmética, imprime o
//seu resultado e retorna verdadeiro ou falso, indicando se a expressão é ou não
//sintaticamente correta.A expressão é fornecida pelo usuário em notação pós - fixa, ou seja,
//o operador é posicionado após os operandos.Por exemplo, a expressão(2 + 3) * 5, seria
//expressada como 2 3 + 5 *, enquanto a alternativa 2 + 3 * 5 seria dada por 2 3 5 * +.
//Utilizando uma pilha, a função deve ser capaz de avaliar a expressão digitada da seguinte
//forma :
//1. O usuário digitará os valores da expressão um por um(considere que somente
//	valores inteiros positivos serão aceitos);
//2. Os operadores + , -, * e / serão representados, respectivamente, pelos valores
//inteiros negativos - 1, -2, -3 e - 4;
//3. O valor 0 será usado como flag para encerramento da leitura;
//4. Se um valor positivo for lido, este deve ser empilhado;
//5. Se um operador for lido, dois valores devem ser desempilhados, e o resultado da
//operação correspondente deve ser empilhado;
//6. Se a pilha ficar vazia a qualquer momento durante a leitura da expressão pelo
//usuário, a expressão possui erro de sintaxe;
//7. Se, após o encerramento da leitura, a pilha contiver mais de um valor, a expressão
//também possui erro de sintaxe;
//8. O resultado a ser impresso é o único valor remanescente na pilha após o
//encerramento da leitura.
//Exemplos:
//● A sequência 2 3 7 0 constitui um erro de sintaxe e deve retornar falso, sem
//imprimir resultado.
//● A sequência 2 3 - 1 0 corresponde à expressão 2 + 3 e possui resultado 5,
//retornando verdadeiro.
//
//● A sequência 2 3 7 - 1 - 2 0 corresponde à expressão 2 - (3 + 7) e possui
//resultado - 8, retornando verdadeiro.
//● A sequência 2 - 1 0 corresponde à expressão 2 + , o que também constitui um
//erro de sintaxe, devendo retornar falso, sem imprimir resultado.
//● A sequência 2 3 - 1 7 - 3 5 3 - 2 - 4 0 corresponde à expressão(2 + 3) *
//7 / (5 - 3) e possui resultado 17, retornando verdadeiro.
/// </summary>
/// <returns></returns>
int main()
{
	//PilhaEncad p;

	//for (int i = 0; i < 3; i++)
	//	p.empilha(i);

	/*cout << "Pilha apos inserir 5 valores:" << endl;*/

	//p.desempilha();

	/*for(int i = 20; i < 25; i++)
		p.empilha(i);

	cout << "Pilha apos inserir mais 5 valores:" << endl;

	p.imprime();
	int tam = p.tamanho();
	cout << tam << endl;

	bool vazia = p.vazia();
	cout << vazia << endl;
	cout << p.getTopo();

	p.desempilha();
	p.desempilha();
	p.desempilha();*/

	//p.imprime();
	/*int v[] = { 0, 1, 2 };
	int* vet = inverte(v, 3);
	for (int i = 0; i < 3; i++)
		cout << vet[i] << " ";*/
	verifica();
}

int* inverte(int vet[], int n)
{
	int* newVet = new int[n];
	PilhaEncad p;
	for (int i = 0; i < n; i++)
		p.empilha(vet[i]);

	for (int i = 0; !p.vazia(); i++)
		newVet[i] = p.desempilha();

	return newVet;
}

bool verifica()
{
	PilhaEncad p;
	int entrada;
	cin >> entrada;
	while (entrada != 0)
	{
		if (entrada > 0)
			p.empilha(entrada);
		else
		{
			int vals[2];
			for (int i = 0; i < 2; i++)
			{
				if (p.vazia())
					return false;
				vals[i] = p.desempilha(); // o vetor vals recebe os elementos de p desempilhados 
			}
			switch (entrada)
			{
			case -1: p.empilha(vals[0] + vals[1]); break;
			case -2: p.empilha(vals[1] - vals[0]); break;
			case -3: p.empilha(vals[0] * vals[1]); break;
			case -4: p.empilha(vals[1] / vals[0]); break;
			default: cout << "Operacao invalida!";
			}
		}
		cin >> entrada;
	}
	int result = p.desempilha();
	if (p.vazia())
		cout << "Resultado final: " << result << endl;
	return p.vazia();
}

PilhaEncad* transfere(PilhaEncad* p1, PilhaEncad* p2, FilaEncad* f)
{
	int entrada;
	cin >> entrada;
	PilhaEncad* novaPilha = new PilhaEncad;
	//fila com elementos no intervalo [-1,1]
	if (!f->vazia())
	{
		
		if (entrada >= -1 || entrada <= 1)
			f->enfileira(entrada);
		

		while (entrada != NULL)
		{
			if(!p1->vazia() && !p2->vazia() || !f->vazia())
			switch (entrada)
			{
			case -1: (*novaPilha).empilha(p1->desempilha());
			case 1: (*novaPilha).empilha(p1->desempilha());
			case 0: (*novaPilha).empilha(p1->desempilha() + p1->desempilha());
			default: cout << "Valor Invalido! ";
			}
		}
	}
	return novaPilha;
}