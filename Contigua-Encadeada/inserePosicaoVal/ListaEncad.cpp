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
	No* p = primeiro;

	while (p != NULL)
	{
		primeiro = primeiro->getProx();
		delete p;
		p = primeiro;
	}
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
	///insere um novo n� no fim da lista com valor val
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

	if (primeiro != NULL) ///lista n�o vazia (n >0)
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
	if (k >= 0 && k < n)
	{
		No* p = primeiro;
		while (p != NULL)
		{
			if (p->getInfo() == k)
				return p->getInfo();
			p = p->getProx();
		}
	}
	else
	{
		std::cout << "ERRO: Indice invalido!" << std::endl;
		exit(5);
	}
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