#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
	raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
	libera(raiz);
	raiz = NULL;
}

void ArvBinBusca::libera(NoArv* p)
{
	if (p != NULL)
	{
		libera(p->getEsq());
		libera(p->getDir());
		delete p;
	}
}

void ArvBinBusca::imprime()
{
	cout << "Arvore:" << endl;
	auxImprime(raiz, 0);
	cout << endl;
}

void ArvBinBusca::auxImprime(NoArv* p, int nivel)
{
	if (p != NULL)
	{
		cout << "Nivel:(" << nivel << ") " << p->getInfo() << endl;
		auxImprime(p->getEsq(), nivel + 1);
		auxImprime(p->getDir(), nivel + 1);
	}
}

// in-ordem
void ArvBinBusca::imprime_in_ordem()
{
	cout << "Arvore:" << endl;
	auxImprime_in(raiz, 0);
	cout << endl;
}

void ArvBinBusca::auxImprime_in(NoArv* p, int nivel)
{
	if (p != NULL)
	{
		auxImprime_in(p->getEsq(), nivel + 1);
		cout << "(" << nivel << ") " << p->getInfo() << endl;
		auxImprime_in(p->getDir(), nivel + 1);
	}
}


int ArvBinBusca::getRaiz()
{
	if (raiz != NULL)
		return raiz->getInfo();
	cout << "Arvore vazia" << endl;
	exit(1);
}

bool ArvBinBusca::vazia()
{
	return raiz == NULL;
}

bool ArvBinBusca::busca(int val)
{
	return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv* p, int val)
{
	if (p == NULL)
		return false;// �rvore vazia
	else if (p->getInfo() == val)
		return true;// chave encontrada
	else if (val < p->getInfo()) // val pertence a SAE de p
		return auxBusca(p->getEsq(), val);
	else // val > p->getInfo(), val pertence a SAD de p
		return auxBusca(p->getDir(), val);
}

bool ArvBinBusca::buscaIt(int val)
{
	NoArv* p = raiz;
	while (p != NULL)
	{
		if (p->getInfo() == val)
			return true;
		if (val < p->getInfo())
			p = p->getEsq();
		else // val > p->getInfo()
			p = p->getDir();
	}
	return false;
}

void ArvBinBusca::insere(int val)
{
	raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv* p, int val)
{
	if (p == NULL)
	{
		p = new NoArv();
		p->setInfo(val);
		p->setEsq(NULL);
		p->setDir(NULL);
	}
	else if (val < p->getInfo())
		p->setEsq(auxInsere(p->getEsq(), val));
	else
		p->setDir(auxInsere(p->getDir(), val));
	return p;
}

void ArvBinBusca::remove(int val)
{
	raiz = auxRemove(raiz, val);
}

NoArv* ArvBinBusca::auxRemove(NoArv* p, int val)
{
	if (p == NULL)
		return NULL;
	else if (val < p->getInfo())
		p->setEsq(auxRemove(p->getEsq(), val));
	else if (val > p->getInfo())
		p->setDir(auxRemove(p->getDir(), val));
	else // val == p->getInfo()
	{
		if (p->getEsq() == NULL && p->getDir() == NULL) //folha
			p = removeFolha(p);
		else if (p->getEsq() == NULL || p->getDir() == NULL) //1 filho
			p = remove1Filho(p);
		else //2 filhos
		{
			//NoArv *aux = menorSubArvDireita(p); 
			NoArv* aux = maiorSubArvEsq(p);
			p->setInfo(aux->getInfo());
			aux->setInfo(val);
			//p->setDir(auxRemove(p->getDir(), val));
			p->setEsq(auxRemove(p->getEsq(), val));
		}
	}
	return p;
}

NoArv* ArvBinBusca::removeFolha(NoArv* p)
{
	delete p;
	return NULL;
}

NoArv* ArvBinBusca::remove1Filho(NoArv* p)
{
	NoArv* aux;
	if (p->getEsq() == NULL)
		aux = p->getDir(); //filho unico da direita
	else
		aux = p->getEsq();//filho unico da esquerda
	delete p;
	return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv* p)
{
	NoArv* aux = p->getDir(); //no a direita de p
	while (aux->getEsq() != NULL)
		aux = aux->getEsq();
	return aux;
}

NoArv* ArvBinBusca::maiorSubArvEsq(NoArv* p)
{
	NoArv* aux = p->getEsq(); //no a esquerda de p
	while (aux->getDir() != NULL)
		aux = aux->getDir();
	return aux;
}

int ArvBinBusca::contaNos()
{
	return auxContaNos(raiz);
}

int ArvBinBusca::auxContaNos(NoArv* p)
{
	if (p != NULL)
		return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir()); // incrementa no + 1
	return 0;
}

int ArvBinBusca::contaNos2()
{
	int cont = 0;
	auxContaNos2(raiz, &cont);
	return cont;
}

void ArvBinBusca::auxContaNos2(NoArv* p, int* cont)
{
	if (p != NULL)
	{
		*cont = *cont + 1; // equiv. a (*cont)++
		auxContaNos2(p->getEsq(), cont);
		auxContaNos2(p->getDir(), cont);
	}
}

int ArvBinBusca::somaNos()
{
	return auxSomaNos(raiz);
}

int ArvBinBusca::auxSomaNos(NoArv* p)
{
	if (p != NULL)
		return p->getInfo() + auxSomaNos(p->getEsq()) + auxSomaNos(p->getDir()); // soma no getInfo()
	return 0;
}

float ArvBinBusca::mediaNos()
{
	return (float)auxSomaNos(raiz) / auxContaNos(raiz);
}

float ArvBinBusca::mediaNos2()
{
	int cont = 0, soma = 0;
	auxMediaNos2(raiz, &cont, &soma); // no fim de todas as chamadas recursivas, teremos cont e soma totais!
	return (float)soma / cont;
}

void ArvBinBusca::auxMediaNos2(NoArv* p, int* cont, int* soma)
{
	if (p != NULL)
	{
		*cont = *cont + 1; // equiv. a (*cont)++
		*soma = *soma + p->getInfo(); // equiv. a (*soma)++
		auxMediaNos2(p->getEsq(), cont, soma);
		auxMediaNos2(p->getDir(), cont, soma);
	}
}

void ArvBinBusca::imprimeNivel(int k) // quando estirvermos querendo comparar niveis, podemos comparar um nivel atual com um k para checarmos se chegamos no nivel correto.
{
	cout << "Nivel " << k << ": ";
	auxImprimeNivel(raiz, 0, k);
	cout << endl;
}

void ArvBinBusca::auxImprimeNivel(NoArv* p, int atual, int k)
{
	if (p != NULL)
	{
		if (atual == k)
			cout << p->getInfo() << " ";
		else
		{
			auxImprimeNivel(p->getEsq(), atual + 1, k);
			auxImprimeNivel(p->getDir(), atual + 1, k);
		}
	}
}

//int ArvBinBusca::maiorInfoArv()
//{
//	return auxMaior(raiz);
//}
//int ArvBinBusca::auxMaior(NoArv* p)
//{
//	if (p->getDir() != NULL)
//		return auxMaior(p->getDir()); // na ultima chamada teremos a info do ultimo no a direita e retornaremos ele.
//	else
//		return p->getInfo();
//}

int ArvBinBusca::menor()
{
	return auxMenor(raiz);
}
int ArvBinBusca::auxMenor(NoArv* p)
{
	if (p->getEsq() != NULL)
		return auxMenor(p->getEsq()); // na ultima chamada teremos a info do ultimo no a esquerda e retornaremos ele.
	else
		return p->getInfo();
}

void ArvBinBusca::removeMaior()
{
	int val = maior();
	remove(val);
}

void ArvBinBusca::removeMenor()
{
	int val = menor();
	remove(val);
}

int ArvBinBusca::contaParesCaminho(int x)
{
	return auxContaParesCaminho(raiz, x);
}

int ArvBinBusca::auxContaParesCaminho(NoArv* p, int x)
{
	if (p->getInfo() < x)
	{
		if (p->getInfo() % 2 == 0)
			return auxContaParesCaminho(p->getDir(), x) + 1;
		else
			return auxContaParesCaminho(p->getDir(), x);
	}
	else if (p->getInfo() > x)
	{
		if (p->getInfo() % 2 == 0)
			return auxContaParesCaminho(p->getEsq(), x) + 1;
		else
			return auxContaParesCaminho(p->getEsq(), x);
	}
	else
		if (p->getInfo() % 2 == 0)
			return 1;
		else
			return 0;
}

/// <summary>
/// Desenvolver uma operação para imprimir todos os valores
//menores que val de uma ABB.Visitando o menor numero de nós
//da ABB.
/// </summary>
/// <param name="p"></param>
/// <param name="val"></param>
void ArvBinBusca::auxImprimeMenores(NoArv* p, int val)
{
	if (p != NULL)
	{
		if (p->getInfo() >= val)
			auxImprimeMenores(p->getEsq(), val);
		else // p é menor que val
		{
			cout << p->getInfo() << " ";
			auxImprimeMenores(p->getEsq(), val);
			auxImprimeMenores(p->getDir(), val);
		}
	}
}

/// <summary>
/// Desenvolver uma operação para alocar e preencher um vetor
//com os valores da ABB no intervalo[a, b] e em ordem crescente
//(percorrer a árvore no máxima 2x).Caso imprima o vetor, será
//considerado uma visita a todos os nós da ABB.
/// </summary>
/// <param name="p"></param>
/// <param name="v"></param>
/// <param name="i"></param>
void ArvBinBusca::auxPreencheVet(NoArv* p, int* v, int* i)
{
	if (p != NULL)
	{
		auxPreencheVet(p->getEsq(), v, i);
		v[*i] = p->getInfo();
		(*i)++; // incrementa indice
		auxPreencheVet(p->getDir(), v, i);
	}
}

int* ArvBinBusca::preencheVet(int* n)
{
	int tam = auxContaNos(raiz);
	int i = 0;
	int* vetor = new int[tam];

	auxPreencheVet(raiz, vetor, &i);
	*n = i;
	return vetor;
}

/// <summary>
/// Desenvolver uma operação NÃO RECURSIVA para calcular e
//retornar a quantidade de nós pares e a quantidade de nós
//impares durante a busca por uma chave numa ABB.
/// </summary>
/// <param name="chave"></param>
/// <param name="pares"></param>
/// <param name="impares"></param>
void ArvBinBusca::contaParesImparesCaminho(int chave, int* pares, int* impares)
{
	NoArv* p = raiz;
	*pares = 0;
	*impares = 0;

	while (p != NULL)
	{
		if (p->getInfo() % 2 == 0)
			*pares = *pares + 1;
		else
			*impares = *impares + 1;

		if (chave < p->getInfo())
			p = p->getEsq();
		else if (chave > p->getInfo())
			p = p->getDir();
		else ///encontrou chave
			p = NULL;
	}
}

///Atividade do arquivo: "Atividade 10 2021.1.D.pdf"
///Apresento 2 solu��es
///solucao 1 - estava no gabarito
/*
void ArvBinBusca::removeFilhoEsquerdaK(int k, int val)
{
	NoArv *p = raiz;
	int nivel = 0;
	while (p!=NULL && p->getInfo() != val && nivel<k)
	{
		if ( val < p->getInfo() )
		{
			p = p->getEsq();
		}
		else
		{
			p = p->getDir();
		}
		nivel++;
	}

	if (p == NULL)
	{
		cout << "Nao alcancou nenhum no caminho para o valor val na arvore." << endl;
	}
	else if (nivel==k)
	{
		if (p->getEsq() == NULL)
		{
			cout << "No com valor val nao possui subarvore a esquerda." << endl;
		}
		else
		{
			p->setEsq( auxRemove(p->getEsq(), p->getEsq()->getInfo()) );
		}
	}
	else
	{
		cout << "Nao foi possivel alcancar o valor val ate o nivel k ou o valor esta num nivel inferior." << endl;
	}
}
*/

///solucao 2
/// <summary>
/// Desenvolver a operação NÃO RECURSIVA void
//ArvBinBusca::removeFilhoEsquerdaK(int k, int val); para buscar o nó de
//nível k que faz parte do caminho de busca (com sucesso ou não) do valor val em uma
//árvore binária de busca.Após encontrar o nó de nível k, remover o nó à esquerda deste nó,
//caso exista.Imprima mensagens que indiquem os casos de não remoção.
/// </summary>
/// <param name="k"></param>
/// <param name="val"></param>
void ArvBinBusca::removeFilhoEsquerdaK(int k, int val)
{
	NoArv* p = raiz;
	int nivel = 0;

	while (p != NULL)
	{
		if (nivel < k)
		{
			if (val == p->getInfo()) //encontrou val
			{
				cout << "Achou val antes do nivel " << k;
				break;
			}
			else
			{
				nivel++;
				if (val < p->getInfo())
					p = p->getEsq();
				else if (val > p->getInfo())
					p = p->getDir();
			}
		}
		else ///nivel == k
		{
			libera(p->getEsq());
			p->setEsq(NULL);
			break;
		}
	}
	if (p == NULL)
		cout << "Nivel " << k << " nao atigido na busca de " << val;
}

int ArvBinBusca::noMaisEsquerdaVal(NoArv* p, int val)
{
	p->setInfo(val);
	while (p->getEsq() != NULL)
		p = p->getEsq();
	return p->getInfo();
}

int ArvBinBusca::noMaisEsquerda()
{
	NoArv* p = raiz;
	while (p->getEsq() != NULL)
		p = p->getEsq();
	return p->getInfo();
}

int ArvBinBusca::noMaisDireita()
{
	NoArv* p = raiz;
	while (p->getDir() != NULL)
		p = p->getDir();
	return p->getInfo();
}

int ArvBinBusca::noMaisDireitaVal(NoArv* p, int val)
{
	p->setInfo(val);
	while (p->getDir() != NULL)
		p = p->getDir();
	return p->getInfo();
}

bool ArvBinBusca::EhABB()
{
	int ultimo = noMaisEsquerda(); // ultimo inicializado com o primeiro, que é o mais a esquerda.
	return auxEhABB(raiz, &ultimo);
}

/// <summary>
/// Desenvolver uma operação para verificar se dada uma AB é
//ABB.
/// </summary>
/// <param name="p"></param>
/// <param name="ultimo"></param>
/// <returns></returns>
bool ArvBinBusca::auxEhABB(NoArv* p, int* ultimo)
{
	// ( ) pre - ordem: raiz, sae, sad
	// ( ) pos - ordem: sae, sad, raiz
	// (x) In - ordem: sae, raiz, sad

	if (p == NULL)
		return true;
	else
	{
		bool abbEsq = auxEhABB(p->getEsq(), ultimo);

		if (*ultimo > p->getInfo())
			return false; //nao visita em ordem crescente os valores dos nos da ABB

		else
		{
			*ultimo = p->getInfo();

			bool abbDir = auxEhABB(p->getDir(), ultimo);

			return abbEsq && abbEsq;
		}
	}
}

int ArvBinBusca::impressaoParcialC(int a, int b)
{
	return impressaoParcialCAux(raiz, a, b);
}

/// <summary>
/// Implementar a operação int ArvBinBusca::impressaoParcial(int a,
//int b); que percorre a árvore binária de busca e imprime os valores do intervalo
//aberto(a, b) que estão presentes em nós da árvore em que a soma dos valores
//dos nós filhos(caso existam) é par.Os filhos considerados na soma podem ou não
//pertencer ao intervalo.Ao final da operação, retornar a soma dos valores impressos.
//Obs.: A operação deve utilizar a propriedade das árvores binárias de busca e
//visitar o menor número possível de nós.
/// </summary>
/// <param name="p"></param>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int ArvBinBusca::impressaoParcialCAux(NoArv* p, int a, int b)
{
	if (p == NULL)
		return 0;
	if (p->getInfo() <= a) // Fora do intervalo
		return impressaoParcialCAux(p->getDir(), a, b);
	else if (p->getInfo() >= b) // Fora do intervalo
		return impressaoParcialCAux(p->getEsq(), a, b);
	else
	{
		// ( ) pre - ordem: raiz, sae, sad
		// ( ) pos - ordem: sae, sad, raiz
		// (x) In - ordem: sae, raiz, sad

		int soma = 0;
		soma += impressaoParcialCAux(p->getEsq(), a, b);

		int filhoEsq = (p->getEsq() == NULL) ? 0 : p->getEsq()->getInfo();

		int filhoDir = (p->getDir() == NULL) ? 0 : p->getDir()->getInfo();

		if ((filhoEsq + filhoDir) % 2 == 0)
		{
			cout << p->getInfo() << " ";
			soma += p->getInfo();
		}
		soma += impressaoParcialCAux(p->getDir(), a, b);

		return soma;
	}
}

/// <summary>
/// Desenvolver a operação NÃO RECURSIVA void ArvBinBusca::removeMenor(int
//val); para buscar o valor val em uma árvore binária de busca e remover o menor valor
//da subárvore à esquerda do nó com valor val.Cada nó pode ser visitado uma única vez.
//Imprima uma mensagem para cada caso em que não ocorra a remoção.
/// </summary>
/// <param name="val"></param>
void ArvBinBusca::removeMenorMaisEsqVal(int val)
{
	NoArv* p = raiz;
	int aux;

	while (p != NULL)
	{
		if (p->getInfo() == val) // achou val na ABB 
		{
			if (p->getEsq() != NULL) // garanto que o esq de val não é nulo
			{
				aux = noMaisEsquerdaVal(p, val); // atribuo a um nóArv auxiliar aux o nó da arvore mais a esquerda de val
				remove(aux); // removo aux, que tem como valor o nó mais a esquerda de val
				p = NULL;
			}
			else // se o nó a esq de val é nulo, entao nao tem como remover!
			{
				cout << "Nao foi possivel remover, pois val nao tem filho a esquerda!" << endl;
				break;
			}
		}
		else if (val < p->getInfo()) // se ainda nao achou val na arv, entao continua procurando a esq e a dir de p
			p = p->getEsq();
		else if (val > p->getInfo())
		{
			p = p->getDir();
			if (val < noMaisEsquerda() || val > noMaisDireita()) // se não achou val, entao ele nao esta na arvore!
			{
				cout << "Nao foi possivel remover, pois val nao foi encontrado!" << endl;
				break;
			}
		}
	}
}

/// <summary>
/// Desenvolver a operação NÃO RECURSIVA void
//ArvBinBusca::insereFilhoDireitaK(int k, int val); para buscar o
//nó de nível k que faz parte do caminho de busca(com sucesso ou não) do valor val
//em uma árvore binária de busca.Após encontrar o nó de nível k, inserir um novo nó,
//com valor igual ao valor do nó encontrado, à direita deste nó, se o nó não possuir
//filho à direita.Imprima mensagens que indiquem os casos de não inserção.
/// </summary>
/// <param name="k"></param>
/// <param name="val"></param>
void ArvBinBusca::insereFilhoDireitaK(int k, int val)
{
	if (raiz == NULL)
		cout << "Arvore vazia!" << endl;
	else
	{
		NoArv* p = raiz, * q = NULL;
		int nivel = 0;
		while (p != NULL && nivel <= k)
		{
			if (nivel == k)
			{
				q = p;
				break;
			}
			if (p->getInfo() == val)
				break;

			else if (val < p->getInfo())
				p = p->getEsq();
			else
				p = p->getDir();

			nivel++;
		}
		if (q != NULL && q->getDir() == NULL)
		{
			NoArv* novo = new NoArv();
			novo->setInfo(q->getInfo());
			novo->setEsq(NULL);
			novo->setDir(NULL);
			q->setDir(novo); // novo setado como no a direita de q
		}
		else
			cout << "Nao eh possivel inserir!" << endl;
	}
}

/// <summary>
/// Considerando uma ABB de inteiros. Desenvolver a operação
//int ArvBinBusca::ultimoNivel(int a, int b);
//Sua operação deve usar a propriedade de ABB para visitar a quantidade mínima de nós.
//Os inteiros a e b são passados por parâmetro e a < b.
//	Essa operação deve determinar, e retornar, o último nível da ABB dos nós que estão
//	dentro do intervalo[a, b].Caso não haja nós dentro do intervalo, retornar - 1.
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int ArvBinBusca::ultimoNivel(int a, int b)
{
	int ultimoNivel = -1;
	int nivel = 0;
	int cont = 0;
	auxUltimoNivel(raiz, a, b, nivel, &ultimoNivel, &cont);
	return ultimoNivel;
}
void ArvBinBusca::auxUltimoNivel(NoArv* p, int a, int b, int nivel,
	int* ultimoNivel, int* cont)
{
	if (p != NULL)
	{
		if (p->getInfo() >= a && p->getInfo() <= b) // dentro do intervalo
		{

			auxUltimoNivel(p->getEsq(), a, b, nivel + 1, ultimoNivel, cont);

			auxUltimoNivel(p->getDir(), a, b, nivel + 1, ultimoNivel, cont);

			if (*cont == 0)
			{
				*ultimoNivel = nivel;
				(*cont)++;
			}
		}
		else if (p->getInfo() > b) // se info eh maior que b, entao as chances de ter um no dentro do intervalo eh indo pra esquerda
		{
			auxUltimoNivel(p->getEsq(), a, b, nivel + 1, ultimoNivel, cont);
		}
		else if (p->getInfo() < a) // se info eh menor que a, entao as chances de ter um no dentro do intervalo eh indo pra direita
		{
			auxUltimoNivel(p->getDir(), a, b, nivel + 1, ultimoNivel, cont);
		}
	}
}

/// <summary>
/// Desenvolver a operação NÃO RECURSIVA int ArvBinBusca::menorPar(int
//	val); para buscar pelo nó que possua o valor val em uma árvore binária de busca e
//	retornar o menor valor par no caminho, mesmo que val não esteja na árvore.O valor val
//	não deve ser considerado para o retorno e cada nó pode ser visitado uma única vez.
//	Imprima uma mensagem caso não haja valores pares no caminho e finalize o programa.
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
int ArvBinBusca::menorPar(int val)
{
	if (raiz == NULL)
	{
		cout << "ERRO: A arvore está vazia!";
		exit(1);
	}
	else
	{
		int x = 0;
		int par;
		NoArv* p = raiz;
		while (p != NULL && p->getInfo() != val)
		{
			if (p->getInfo() % 2 == 0 && x == 0) // encontra um primeiro no par
			{
				par = p->getInfo();
				x++;
			}
			else if (p->getInfo() % 2 == 0 && x != 0 && p->getInfo() < par) // verifica se o novo noh par encontrado´eh menor que o no par encontrado anteriormente
			{
				par = p->getInfo(); // atualizo meu noh par
			}
			if (p->getInfo() > val) // caso base
			{
				p = p->getEsq();
			}
			else
			{
				p = p->getDir(); // caso base 
			}
		}
		if (x == 0)
		{
			cout << "ERRO: Não há valores pares no caminho";
			exit(1);
		}
		else
		{
			return par;
		}
	}
}

/// <summary>
/// O inteiro antecessor de val corresponde ao nó da ABB com o maior valor menor que val.
//Desenvolver uma operação int antecessor(int val) para, dado(parâmetro) um
//inteiro positivo val, determinar e retornar o valor do nó de uma árvore binária de busca
//(ABB) que corresponda ao antecessor de val.
//Caso a ABB não possua o antecessor de val, retornar - 1. Usar a propriedade de ABB
//para visitar a quantidade mínima de nós.Observar que val pode não ser valor de nenhum
//nó da ABB mas o antecessor tem que ser(se existir).
//Dica: usar um parâmetro por referência para saber o valor do último nó visitado.Seu valor
//inicial deve ser - 1.
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
int ArvBinBusca::antecessor(int val)
{
	int ultimo = -1, antece;
	antece = auxAntecessor(raiz, val, &ultimo);
	///o ultimo visitado é maior valor da arvore
	if (val > ultimo)
		///se val>ultimo, a operação aux, da
		///forma que foi implementada, não acha o antecessor
		antece = ultimo;
	return antece;
}
int ArvBinBusca::auxAntecessor(NoArv* p, int val, int* ultVisitado)
{
	///todos valores da ABB são inteiros positivos (por isso
	///-1 como exceção funcionará). Faz busca em ordem (nós são
	///visitados em ordem crescente). Assim, o antecessor, se
	///existir, é o último nó visitado antes do nó atual p
	///tal que val <= p->getInfo()
	if (p == NULL)
		return -1;
	else
	{
		int ant; ///antecessor
		ant = auxAntecessor(p->getEsq(), val, ultVisitado);
		if (ant == -1)
		{
			///achou o antecessor.Interrompe a busca
			if (val <= p->getInfo())
				ant = *ultVisitado;
			else
			{
				*ultVisitado = p->getInfo();
				///ainda não encontrou o antecessor. Vai para
				///subárvore direita
				ant = auxAntecessor(p->getDir(), val, ultVisitado);
			}
		}
		return ant;
	}
}

/// <summary>
/// Desenvolver uma operação int sucessor(int x, int y, int val) para dados
//(parâmetros) :
//	-o intervalo[x, y], onde x < y com x e y inteiros positivos;
//-um inteiro positivo val.
//determinar e retornar o valor do nó, dentro do intervalo[x, y], de uma árvore binária de
//busca(ABB) que corresponda ao sucessor de val.Observar que val pode não ser valor
//de nenhum nó da ABB mas o sucessor sim(se existir).
//Caso a ABB não possua o sucessor de val dentro do intervalo, retornar - 1. O inteiro
//sucessor de val corresponde ao nó da ABB com o menor valor, dentro do intervalo, maior
//que val.Usar a propriedade de ABB para visitar a quantidade mínima de nós.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="val"></param>
/// <returns></returns>
int ArvBinBusca::sucessor(int x, int y, int val)
{
	return auxSucessor(raiz, x, y, val);
}

int ArvBinBusca::auxSucessor(NoArv* p, int x, int y, int val)
{
	if (p == NULL)
		return -1;
	else
	{
		int suc;
		if (p->getInfo() > y)
			suc = auxSucessor(p->getEsq(), x, y, val);
		else if (p->getInfo() < x)
			suc = auxSucessor(p->getDir(), x, y, val);
		else
		{
			suc = auxSucessor(p->getEsq(), x, y, val);
			if (suc == -1)
			{
				if (val < p->getInfo())
					suc = p->getInfo();
				else
					suc = auxSucessor(p->getDir(), x, y, val);
			}
		}
		return suc;
	}
}

/// <summary>
/// Desenvolver a operação NÃO RECURSIVA void ArvBinBusca::removeFilhoEsquerdaMenor(int val); para buscar o menor nó que faz parte do caminho de busca 
/// (com sucesso ou não) do valor val em uma árvore binária de busca. Após encontrar o menor nó, remover seu filho à esquerda, se esse nó (filho) possuir
///  filho à esquerda e seu filho não possuir filho à direita. Imprima mensagens que indiquem os casos de não remoção.
/// </summary>
/// <param name="val"></param>
void ArvBinBusca::removeFilhoEsquerdaMenor(int val)
{
	if (raiz == NULL)
		cout << "Arvore vazia" << endl;
	else
	{
		NoArv* p = raiz, * menor = raiz;
		while (p != NULL)
		{
			if (p->getInfo() < menor->getInfo())
				menor = p;
			if (p->getInfo() == val)
				break;
			else if (val < p->getInfo())
				p = p->getEsq();
			else
				p = p->getDir();
		}
		if (menor->getEsq() != NULL)
		{
			NoArv* q = menor->getEsq();
			if (q->getDir() == NULL)
			{
				menor->setEsq(q->getEsq());
				delete q;
			}
			else
				cout << "Nao eh possivel remover" << endl;
		}
		else
			cout << "Nao eh possivel remover" << endl;
	}
}

int ArvBinBusca::impressaoParcialG(int a, int b)
{
	return impressaoParcialGAux(raiz, a, b);
}

/// <summary>
/// Implementar a operação int ArvBinBusca::impressaoParcial(int a, int b); que percorre a árvore binária de busca e imprime, 
/// em ordem decrescente, os valores do intervalo (a,b] (aberto em a, fechado em b) que estão presentes na árvore e cujos nós 
/// contêm apenas um filho, sendo que esse filho deve ser ímpar. O filho pode ou não pertencer ao intervalo. Ao final da operação,
///  retornar o total de valores impressos. 
//Obs.: A operação deve utilizar a propriedade das árvores binárias de busca e visitar o menor número possível de nós.
/// </summary>
/// <param name="p"></param>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int ArvBinBusca::impressaoParcialGAux(NoArv* p, int a, int b)
{
	if (p == NULL)
		return 0;

	if (p->getInfo() <= a) // fora intervalo
		return impressaoParcialGAux(p->getDir(), a, b);
	else if (p->getInfo() > b)
		return impressaoParcialGAux(p->getEsq(), a, b); // fora intervalo
	else
	{
		int total = 0;
		total += impressaoParcialGAux(p->getDir(), a, b);

		NoArv* filhoUnico = NULL;
		if (p->getEsq() == NULL && p->getDir() != NULL)
			filhoUnico = p->getDir();
		else if (p->getEsq() != NULL && p->getDir() == NULL)
			filhoUnico = p->getEsq();

		if (filhoUnico != NULL && (filhoUnico->getInfo() % 2 == 1))
		{
			cout << p->getInfo() << " ";
			total++;
		}

		total += impressaoParcialGAux(p->getEsq(), a, b);
		return total;
	}
}

/// <summary>
/// Desenvolver a operação
//int ArvBinBusca::contaNosNivel(int a, int b, int n);
//para uma ABB de inteiros.Os inteiros a e b são passados por parâmetro e a < b.Sua
//	operação deve usar a propriedade de ABB para visitar a quantidade mínima de nós.
//	Essa operação deve contar, e retornar, o número de nós que possuem valor dentro
//	do intervalo[a, b] e que estão no nível n.
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="n"></param>
/// <returns></returns>
int ArvBinBusca::contaNosNivel(int a, int b, int n)
{
	int atual = 0;
	//// a < b
	//// n é nível
	//// contar quantos nós estão entre a e b, inclusive, no nível n
	//int nivel = 0, nivel2 = 0, i = 0, contador = 0, aux[200];
	//// Como contar todos os nós em um nível? Percurso em largura
	/*NoArv* p = raiz;*/
	//while (p != NULL)
	//{
	//	if (nivel2 == n)
	//	{
	//		while (int j = 0)
	//		{
	//			if (aux[j] >= a && aux[j] <= b)
	//				contador++;
	//			if (aux[j] > b)
	//				break;
	//			j++;
	//		}
	//		break;
	//	}
	//	if (p->getEsq() != NULL)
	//	{
	//		aux[i] = p->getEsq()->getInfo();
	//		i++;
	//	}
	//	aux[i] = p->getInfo();
	//	i++;
	//	if (p->getDir() != NULL)
	//	{
	//		aux[i] = p->getDir()->getInfo();
	//		i++;
	//	}
	//	nivel2++;
	//}

	//return contador;
	return auxContaNosNivel(raiz, a, b, n, atual + 1);
}

int ArvBinBusca::auxContaNosNivel(NoArv* p, int a, int b, int n, int atual)
{
	int nosNivel = 0;
	if (p != NULL)
	{
		if (p->getInfo() >= a && p->getInfo() <= b)
		{
			if (n == atual)
				nosNivel++;
			/*auxContaNosNivel(p->getDir(), a, b, n, atual + 1);
			auxContaNosNivel(p->getEsq(), a, b, n, atual+1);*/
		}
		else if (p->getInfo() <= a)
		{
			auxContaNosNivel(p->getDir(), a, b, n, atual + 1);
		}
		else if (p->getInfo() >= b)
		{
			auxContaNosNivel(p->getEsq(), a, b, n, atual + 1);
		}
	}
	return nosNivel;
}

/// <summary>
/// Desenvolver uma operação NÃO RECURSIVA void removeFolhaVal(int val) para,
//dado(parâmetro) um inteiro positivo val, remover a folha com valor val de uma árvore
//binária de busca(ABB).Emitir uma mensagem caso o valor val não se encontre na ABB
//ou se não há folha com o valor val.Usar a propriedade de ABB para visitar a quantidade
//mínima de nós da ABB.
/// </summary>
/// <param name="val"></param>
void ArvBinBusca::removeFolhaVal(int val)
{
	NoArv* p = raiz, * paip = NULL;
	bool paiEsq; ///true, se p é filho a esquerda de paip
	///false,a direita
	while (p != NULL && p->getInfo() != val)
	{
		paip = p;
		if (val < p->getInfo())
		{
			p = p->getEsq();
			paiEsq = true;
		}
		else ///val > p->getInfo()
		{
			p = p->getDir();
			paiEsq = false;
		}
	}
	///verifica se p aponta para nó com valor valor e se p é folha
	if (p != NULL && p->getEsq() == NULL && p->getDir() == NULL)
	{
		if (paiEsq)
			paip->setEsq(NULL);
		else
			paip->setDir(NULL);
		delete p;
	}
	else
		cout << "Valor nao se encontra na ABB ou noh com valor encontrado nao eh folha";
}

bool ArvBinBusca::maiores(int val)
{
	bool ehMaior;
	ehMaior = maior();

	if (val > ehMaior || vazia())
		return true;
	else
		return false;
}

int ArvBinBusca::maior()
{
	return auxMaior(raiz);
}
int ArvBinBusca::auxMaior(NoArv* p)
{
	if (p->getDir() != NULL)
		return auxMaior(p->getDir()); // na ultima chamada teremos a info do ultimo no a direita e retornaremos ele.
	else
		return p->getInfo();
}

void ArvBinBusca::insereAbbEsquerda(ArvBinBusca* arvbb)
{
	int val = maior();
	auxInsereAbbEsquerda(arvbb, val);
}

void ArvBinBusca::auxInsereAbbEsquerda(ArvBinBusca* arvbb, int val)
{
	NoArv* p = arvbb->raiz;
	while (p != NULL)
	{
		if (maior() >= arvbb->maiores(val) && p->getInfo() == noMaisEsquerda())
		{
			if (p == NULL)
			{
				p = new NoArv();
				p->setInfo(val);
				p->setEsq(NULL);
				p->setDir(NULL);
			}
			else if (val < p->getInfo())
				p->setEsq(auxInsere(p->getEsq(), val));
			else
				p->setDir(auxInsere(p->getDir(), val));
		}
		p->setEsq(auxInsere(p->getEsq(), val));
		p->setDir(auxInsere(p->getDir(), val));
	}
}