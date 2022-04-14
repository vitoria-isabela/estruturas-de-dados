#include <iostream>
#include "ListaEncad.h"

ListaEncad::ListaEncad()
{
	primeiro = NULL;
	ultimo = NULL;
	n = 0;
}

ListaEncad::~ListaEncad()
{
	std::cout << "Destruindo o objeto listaEncad!" << std::endl;
	limpar();
}

void ListaEncad::insereInicio(int val)
{
	///insere um novo n� no inicio da lista com valor val
	No* p = new No(); // cria No apontado por p
	p->setInfo(val); // preenche informacao

	p->setProx(primeiro); // preenche proximo

	primeiro = p; // no apontado por p passa a ser o primeiro da lista

	n++;

	if (n == 1)  ///ultimo == NULL
		ultimo = p;
}

void ListaEncad::removeInicio()
{
	if (primeiro != NULL)
	{
		No* p = primeiro;
		primeiro = primeiro->getProx();
		delete p;

		n--;
		if (n == 0);  ///primeiro == NULL
		ultimo == NULL;
	}
}

void ListaEncad::insereFinal(int val)
//agora tem complexidade O(1)
{
	///insere um novo no no fim da lista com valor val
	No* p = new No(); // cria No apontado por p
	p->setInfo(val); // preenche informacao
	p->setProx(NULL);

	if (ultimo != NULL)
		ultimo->setProx(p);
	else
		primeiro = p;

	ultimo = p;
	n++;
}

void ListaEncad::removeFinal()
{
	///remove n� no fim da lista com valor val
	// primeira forma:
	/*if (primeiro != NULL) ///lista n�o vazia (n >0)
	{
		///ap aponta para n� anterior ao n� p
		No* ap = NULL, * p = primeiro;

		///faz p apontar para o �ltimo n� da LSE
		while (p->getProx() != NULL)
		{
			ap = p;
			p = p->getProx();
		}

		if (ap == NULL)  ///caso II. Lista com 1 n�. A lista se torna vazia
			primeiro = NULL;
		else ///caso I. Lista com 2 ou mais n�s
			ap->setProx(NULL);

		ultimo = ap;  ///ap � NULL se lista tem 1 �nico n�.
					  ///ap aponta para o penultimo (ser� o ultimo)
		n--;
		delete p;
	}*/

	No* p = NULL;
	if (ultimo != NULL)
	{
		if (primeiro == ultimo)
		{
			primeiro = NULL;
		}
		else
		{
			p = primeiro;
			while (p->getProx() != ultimo)
				p = p->getProx();
			p->setProx(NULL);
		}
		delete ultimo;
		ultimo = p;
		n--;
	}
}

bool ListaEncad::busca(int val)
{
	No* p = primeiro;
	while (p != NULL)
	{
		if (p->getInfo() == val)
			return true;
		p = p->getProx();
	}
	return false;
}

void ListaEncad::imprimir()
//exercicio 1, slide 41
{
	No* p = primeiro;
	while (p != NULL)
	{
		std::cout << p->getInfo() << "    ";
		p = p->getProx();
	}
	std::cout << std::endl << std::endl << std::endl;
}

int ListaEncad::get(int k)
{
	No* p = primeiro;
	int i = 0;
	while (i < k && p != NULL)
	{
		i++;
		p = p->getProx();
	}
	if (p == NULL)
	{
		std::cout << "ERRO: Indice invalido!" << std::endl;
		exit(1);
	}
	else
		return p->getInfo();
}

void ListaEncad::set(int k, int val)
{
	No* p = primeiro;
	int i = 0;
	while (i < k && p != NULL)
	{
		i++;
		p = p->getProx();
	}
	if (p == NULL)
	{
		std::cout << "ERRO: Indice invalido!" << std::endl;
		exit(1);
	}
	else
		return p->setInfo(val);
}

int ListaEncad::numNos()
{
	/*No* p;
	int cont = 0;
	for (p = primeiro; p != NULL; p = p->getProx())
	{
		cont++;
	}
	return cont;*/
	return n;
}

void ListaEncad::limpar()
{
	No* p = primeiro;

	while (p != NULL)
	{
		primeiro = primeiro->getProx();
		delete p;
		p = primeiro;
	}
	primeiro = NULL;
	ultimo = NULL;
	n = 0;
}

float ListaEncad::calculaMedia()
{
	int soma = 0;
	for (No* i = primeiro; i != NULL; i = i->getProx())
	{
		soma += i->getInfo();
	}
	return soma / (float)n;
}

void ListaEncad::concatena(ListaEncad* l2)
{
	for (No* p = l2->primeiro; p != NULL; p = p->getProx())
		insereFinal(p->getInfo());
}

ListaEncad* ListaEncad::partir(int x)
{
	ListaEncad* newList = new ListaEncad();
	No* ant = NULL;
	No* p = primeiro;
	int i = -1;

	// percorre lista intriseca ate o indice x
	while (p != NULL && i < x) {
		ant = p;
		p = p->getProx();
		i = i + 1;
	}

	if (p != NULL)
	{
		// Nova lista
		newList->primeiro = p;
		newList->ultimo = ultimo;
		newList->n = n - i;

		if (i == 0)
			primeiro = NULL;
		else
			ant->setProx(NULL);

		// Lista intriseca
		ultimo = ant;
		n = n - newList->n;
	}
	return newList;
}

bool ListaEncad::inserePosicaoVal(int k, int val)
{
	int valK = get(k);

	if (valK >= n || valK < 0)
		return false;

	if (valK == 0)
		insereInicio(val);
	else
	{
		No* ant = NULL, * p = primeiro;
		for (int i = 0; i < valK; i++)
		{
			ant = p;
			p = p->getProx();
		}

		No* novo = new No();
		novo->setInfo(val);
		novo->setProx(p);
		ant->setProx(novo);
		n++;
	}
	return true;
}

void ListaEncad::removeValor(int val)
{
	for (No* i = primeiro, *ant = NULL; i != NULL; i = i->getProx())
	{
		if (i->getInfo() == val)
		{
			if (i == primeiro)
			{
				removeInicio();
				i = primeiro;
			}

			else if (i == ultimo)
			{
				removeFinal();
				i = ultimo;
			}

			else
			{
				ant->setProx(i->getProx());
				delete i;
				i = ant;
			}
		}

		ant = i;
	}
}

int ListaEncad::contaMaiores(int val)
{
	int k = 0;
	for (No* i = primeiro; i != NULL; i = i->getProx())
	{
		if (i->getInfo() > val)
		{
			return i->getInfo();
		}
		k++;
	}
	std::cout << "Nao ha elemento na lista que seja maior!" << std::endl;
}

int ListaEncad::buscaPosMaior(int val)
{
	int k = 0;
	for (No* i = primeiro; i != NULL; i = i->getProx())
	{
		if (i->getInfo() > val)
		{
			return k;
		}
		k++;
	}
	std::cout << "Nao ha elemento na lista que seja maior!" << std::endl;
}