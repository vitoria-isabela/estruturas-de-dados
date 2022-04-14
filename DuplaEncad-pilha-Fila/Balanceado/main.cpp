#include <iostream>

using namespace std;

#include "PilhaEncad.h"

int* inverte(int vet[], int n);
bool verifica();
void caminho();
bool balanceado(const char* Vet, int n);

/// <summary>
/// Um vetor Vet com n caracteres pode ter o seguinte padrão de formação: Vet é composto
//apenas pelos caracteres a e b, todos os a’s precedem todos os b’s e a quantidade de b’s é
//dobro da de a’s.Portanto, por exemplo, abb, aabbbb e aaabbbbbb são cadeias que
//satisfazem o padrão, mas ab, aabb e aab não o satisfaz.Desenvolver uma função de PA para
//retornar true se Vet satisfaz o padrão e false caso contrário(ver protótipo).Esta função não
//pode usar nenhum contador de caracteres.Sendo assim, deve - se usar uma pilha e
//considerar a seguinte estratégia para verificar se Vet satisfaz o padrão :
//● Se o caractere atual de Vet for a e a pilha estiver vazia ou seu topo for a, empilhar aa
//(empilhar 2 a’s);
//● Se o caractere atual de Vet for b e a pilha estiver vazia, retornar false (não satisfaz o
//    padrão);
//● Se o caractere atual de Vet for b e topo da pilha for a, desempilhar a;
//O vetor Vet com a’s e b’s satisfaz o padrão se, após a sua completa varredura – caractere por
//caractere –, a pilha ficar vazia.
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
		/*verifica();*/
	/*caminho();*/
	cout << balanceado("abb", 3) <<endl;
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
				vals[i] = p.desempilha();
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

void caminho()
{
	PilhaEncad p;
	char dir;
	cin >> dir;

	while (dir != 'q')
	{
		if (dir == 'n' || dir == 's' || dir == 'l' || dir == 'o')
			p.empilha(dir);
		cin >> dir;
	}

	while (!p.vazia())
	{
		dir = p.desempilha();

		switch (dir)
		{
		case 'n': cout << 's'; break;
		case 's': cout << 'n'; break;
		case 'l': cout << 'o'; break;
		case 'o': cout << 'l'; break;
		}
	}
	cout << endl;
}

bool balanceado(const char* Vet, int n)
{
    PilhaEncad pilha;
    int i = 0;
    while (i < n && Vet[i] == 'a')//consome apenas os a's de Vet
    {
        if (pilha.vazia() || pilha.getTopo() == 'a')
        {
            pilha.empilha('a');
            pilha.empilha('a');
        }
        i++;
    }
    //consome os demais chars
    while (i < n && Vet[i] == 'b')
    {
		if (pilha.vazia())
			return false;
        else if (pilha.getTopo() == 'a')
			pilha.desempilha();
		i++;
    }
    //verifica se consumiu toda a entrada e se a pilha está vazia
    return pilha.vazia();
}