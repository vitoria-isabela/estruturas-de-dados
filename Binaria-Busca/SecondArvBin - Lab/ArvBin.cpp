#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
	raiz = NULL;
}

int ArvBin::getRaiz()
{
	if (raiz != NULL)
		return raiz->getInfo();
	else
	{
		cout << "Arvore vazia!" << endl;
		exit(1);
	}
}

void ArvBin::cria(int x, ArvBin* sae, ArvBin* sad)
{
	NoArv* p = new NoArv();
	p->setInfo(x);
	p->setEsq(sae->raiz); // seta a raiz de sae como sub arv a esq
	p->setDir(sad->raiz); // seta a raiz de sad como sub arv a dir
	raiz = p; // raiz 'principal' setada como p
}

void ArvBin::anulaRaiz()
{
	raiz = NULL;
}

void ArvBin::montaArvore()
{
	int nivel = 0;
	if (!vazia())
		cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
	else
	{
		cout << "Montagem da arvore em pre-ordem:" << endl;
		raiz = auxMontaArvore(nivel);
	}
}

NoArv* ArvBin::auxMontaArvore(int nivel)
{
	string linha;
	cout << "Valor: ";
	cin >> linha;
	if (linha != "NULL" && linha != "null")
	{
		istringstream ent(linha);
		int valor;
		ent >> valor;
		NoArv* p = new NoArv();

		p->setInfo(valor);

		cout << "Esquerda: " << endl;
		p->setEsq(auxMontaArvore(nivel + 1)); // Monta arv para no a esq de p
		cout << "(Nivel " << nivel << ") " << "Volta no noh " << p->getInfo() << endl;

		cout << "Direita" << endl;
		p->setDir(auxMontaArvore(nivel + 1)); // Monta arv para no a dir de p
		cout << "(Nivel " << nivel << ") " << "Volta no noh " << p->getInfo() << endl;

		return p;
	}
	else
		return NULL;
}

void ArvBin::insere(int x)
{
	raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv* p, int x)
{
	if (p == NULL)
	{
		p = new NoArv();
		p->setInfo(x);
		p->setEsq(NULL);
		p->setDir(NULL);
	}
	else
	{
		char direcao;
		cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
		cin >> direcao;
		if (direcao == 'e' || direcao == 'E')
			p->setEsq(auxInsere(p->getEsq(), x));
		else
			p->setDir(auxInsere(p->getDir(), x));
	}
	return p;
}

bool ArvBin::vazia()
{
	return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
	return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv* p, int x)
{
	if (p == NULL)
		return false;
	else if (p->getInfo() == x)
		return true;
	else if (auxBusca(p->getEsq(), x))
		return true;
	else
		return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
	raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv* p)
{
	if (p != NULL)
	{
		p->setEsq(libera(p->getEsq()));
		p->setDir(libera(p->getDir()));
		delete p;
		p = NULL;
	}
	return NULL;
}

void ArvBin::preOrdem()
{
	cout << "Arvore Binaria em Pre-Ordem: ";
	auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv* p)
{
	if (p != NULL)
	{
		cout << p->getInfo() << " "; // raiz
		auxPreOrdem(p->getEsq());	// sae
		auxPreOrdem(p->getDir());	// sad
	}
}

void ArvBin::imprime()
{
	cout << "Arvore:" << endl;
	auxImprime(raiz, 0);
	cout << endl;
}

void ArvBin::auxImprime(NoArv* p, int nivel)
{
	if (p != NULL)
	{
		cout << "Nivel:(" << nivel << ") " << p->getInfo() << endl;
		auxImprime(p->getEsq(), nivel + 1);
		auxImprime(p->getDir(), nivel + 1);
	}
}

void ArvBin::contaEleganteMult3_And_FolhaNeg()
{
	int multTres = 0;
	int folhasNeg = 0;

	auxContaEleganteMult3_And_FolhaNeg(raiz, &multTres, &folhasNeg);

	cout << "Multiplos de 3: " << multTres << endl;
	cout << "Folhas Negativas: " << folhasNeg << endl;
}

/// <summary>
///Implementar a operação void ArvBin::contaEleganteMult3_And_FolhaNeg(); que
/// percorre recursivamente a árvore binária, calculando as
//seguintes informações :
//1) quantos nós possuem valores multiplos de três;
//2) quantos nós são folhas e negativos.
//Ao final, a operação deve imprimir os resultados.Você deve percorrer a árvore
//binária uma única vez em pós - ordem!
/// </summary>
/// <param name="p"></param>
/// <param name="multTres"></param>
/// <param name="folhasNeg"></param>
void ArvBin::auxContaEleganteMult3_And_FolhaNeg(NoArv* p, int* multTres, int* folhasNeg)
{
	if (p != NULL)
	{
		// ( ) pre - ordem: raiz, sae, sad
		// (x) pos - ordem: sae, sad, raiz
		// ( ) In - ordem: sae, raiz, sad

		auxContaEleganteMult3_And_FolhaNeg(p->getEsq(), multTres, folhasNeg); // sae
		auxContaEleganteMult3_And_FolhaNeg(p->getDir(), multTres, folhasNeg); // sad

		//raiz
		if (p->getInfo() % 3 == 0)
			(*multTres)++;
		if (ehFolha(p) && p->getInfo() < 0)
			(*folhasNeg)++;
	}
}

bool ArvBin::ehFolha(NoArv* p)
{
	return p->getEsq() == NULL && p->getDir() == NULL;
}

void ArvBin::contagens_ParesFilhoEsq_And_FolhasAteNivelk(int k)
{
	int paresFilhosEsq = 0;
	int folhasAteNivelk = 0;

	auxContagens_ParesFilhoEsq_And_FolhasAteNivelk(raiz, 0, k, &paresFilhosEsq, &folhasAteNivelk);

	cout << "Pares com filhos a Esquerda: " << paresFilhosEsq << endl;
	cout << "Folhas ate nivel K: " << folhasAteNivelk << endl;
}

/// <summary>
/// Implementar a operação void ArvBin::contagens_ParesFilhoEsq_And_FolhasAteNivelk(int k); que recebe um
//nível k como parâmetro e percorre recursivamente a árvore binária, calculando as
//seguintes informações :
//1) quantos nós possuem valores pares e somente um filho à esquerda;
//2) quantos nós são folhas até o nível k.
//Ao final, a operação deve imprimir os resultados.Você deve percorrer a árvore
//binária uma única vez em pós - ordem!
/// </summary>
/// <param name="k"></param>
void ArvBin::auxContagens_ParesFilhoEsq_And_FolhasAteNivelk(NoArv* p, int atual, int k, int* paresFilhosEsq, int* folhasAteNivelk)
{
	if (p != NULL)
	{
		// ( ) pre - ordem: raiz, sae, sad
		// (x) pos - ordem: sae, sad, raiz
		// ( ) In - ordem: sae, raiz, sad

		auxContagens_ParesFilhoEsq_And_FolhasAteNivelk(p->getEsq(), atual + 1, k, paresFilhosEsq, folhasAteNivelk); // sae
		auxContagens_ParesFilhoEsq_And_FolhasAteNivelk(p->getDir(), atual + 1, k, paresFilhosEsq, folhasAteNivelk); // sad

		//raiz
		if (p->getInfo() % 2 == 0 && p->getEsq() != NULL && p->getDir() != NULL)
			(*paresFilhosEsq)++;
		if (ehFolha(p) && atual <= k)
			(*folhasAteNivelk)++;
	}
}

void ArvBin::contagens_InfoMaiorQueValESoUmFilhoADir_And_DoisFilhosAteNivelK(int val, int k)
{
	int infoMaiorQueValESoUmFilhoAEsq = 0;
	int doisFilhosAteNivelK = 0;

	auxContagens_InfoMaiorQueValESoUmFilhoADir_And_DoisFilhosAteNivelK(raiz, val, 0, k, &infoMaiorQueValESoUmFilhoAEsq, &doisFilhosAteNivelK);

	cout << "Info maior que val e somente um filho a dir: " << infoMaiorQueValESoUmFilhoAEsq << endl;
	cout << "Dois filhos ate o nivel K: " << doisFilhosAteNivelK << endl;
}

/// <summary>
///Implementar a operação void 
///ArvBin::contagens_InfoMaiorQueValESoUmFilhoADir_And_DoisFilhosAteNivelK(int val, int k); que recebe um
//nível k e um valor val como parâmetro e percorre recursivamente a árvore binária, calculando as
//seguintes informações :
//1) quantos nós possuem valores maiores que val e somente um filho a direita;
//2) quantos nós possuem dois filhos até o nível k.
//Ao final, a operação deve imprimir os resultados.Você deve percorrer a árvore
//binária uma única vez em pré - ordem! 
/// </summary>
/// <param name="p"></param>
/// <param name="val"></param>
/// <param name="atual"></param>
/// <param name="k"></param>
/// <param name="infoMaiorQueValESoUmFilhoAEsq"></param>
/// <param name="doisFilhosAteNivelK"></param>
void ArvBin::auxContagens_InfoMaiorQueValESoUmFilhoADir_And_DoisFilhosAteNivelK(NoArv* p, int val, int atual, int k, int* infoMaiorQueValESoUmFilhoAEsq, int* doisFilhosAteNivelK)
{
	if (p != NULL)
	{
		// (x) pre - ordem: raiz, sae, sad
		// ( ) pos - ordem: sae, sad, raiz
		// ( ) In - ordem: sae, raiz, sad

		//raiz
		if (p->getInfo() > val && p->getEsq() == NULL && p->getDir() != NULL)
			(*infoMaiorQueValESoUmFilhoAEsq)++;
		if (p->getEsq() != NULL && p->getDir() != NULL && atual <= k)
			(*doisFilhosAteNivelK)++;

		auxContagens_InfoMaiorQueValESoUmFilhoADir_And_DoisFilhosAteNivelK(p->getEsq(), val, atual + 1, k, infoMaiorQueValESoUmFilhoAEsq, doisFilhosAteNivelK); // sae
		auxContagens_InfoMaiorQueValESoUmFilhoADir_And_DoisFilhosAteNivelK(p->getDir(), val, atual + 1, k, infoMaiorQueValESoUmFilhoAEsq, doisFilhosAteNivelK); // sad
	}
}

int ArvBin::contaNos()
{
	return auxContaNos(raiz);
}

int ArvBin::auxContaNos(NoArv* p)
{
	if (p == NULL)
		return 0;

	return auxContaNos(p->getEsq()) + auxContaNos(p->getDir()) + 1;
}

int ArvBin::contaNosFolhas()
{
	return auxContaNosFolhas(raiz);
}

int ArvBin::auxContaNosFolhas(NoArv* p)
{
	if (p == NULL)
		return 0;

	int total = auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir());
	if (p->getEsq() == NULL && p->getDir() == NULL)
		total++;
	return total;
}

int ArvBin::altura()
{
	return auxAltura(raiz);
}

int ArvBin::auxAltura(NoArv* p)
{
	if (p == NULL)
		return -1;

	int he = auxAltura(p->getEsq());
	int hd = auxAltura(p->getDir());
	if (he > hd)
		return he + 1;
	else
		return hd + 1;
}

int ArvBin::contaImpar()
{
	return auxContaImpar(raiz);
}

int ArvBin::auxContaImpar(NoArv* p)
{
	if (p == NULL)
		return 0;

	int total = auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
	if (p->getInfo() % 2 == 1)
		total++;
	return total;
}

void ArvBin::imprimeNivel(int k)
{
	auxImpNivel(raiz, k);
}

void ArvBin::auxImpNivel(NoArv* p, int k)
{
	if (p != NULL && k >= 0)
	{
		if (k == 0)
			cout << p->getInfo() << " ";

		auxImpNivel(p->getEsq(), k - 1);
		auxImpNivel(p->getDir(), k - 1);
	}
}

float ArvBin::mediaNivel(int k)
{
	int soma = 0, cont = 0;
	auxMediaNivel(raiz, k, &soma, &cont);
	if (cont > 0)
		return soma / (float)cont;
	else
		return 0;
}

void ArvBin::auxMediaNivel(NoArv* p, int k, int* soma, int* cont)
{
	if (p != NULL && k >= 0)
	{
		if (k == 0)
		{
			*soma = *soma + p->getInfo();
			(*cont)++;
		}

		auxMediaNivel(p->getEsq(), k - 1, soma, cont);
		auxMediaNivel(p->getDir(), k - 1, soma, cont);
	}
}

int ArvBin::min()
{
	if (raiz == NULL)
	{
		cout << "Arvore vazia!";
		exit(1);
	}

	int menor = raiz->getInfo();
	auxMin(raiz, &menor);
	return menor;
}

void ArvBin::auxMin(NoArv* p, int* menor)
{
	if (p != NULL)
	{
		if (p->getInfo() < *menor)
			*menor = p->getInfo();

		auxMin(p->getEsq(), menor);
		auxMin(p->getDir(), menor);
	}
}
void ArvBin::removeFolhas()
{
	auxRemoveFolhas(raiz);
}

NoArv* ArvBin::auxRemoveFolhas(NoArv* p)
{
	if (p != NULL)
	{
		if (ehFolha(p))
		{
			delete p;
			p = NULL;
		}
		else
		{
			p->setEsq(auxRemoveFolhas(p->getEsq()));
			p->setDir(auxRemoveFolhas(p->getDir()));
		}
	}
	return p;
}

void ArvBin::contaElegantePares_And_FolhasPositivas()
{
	int pares = 0;
	int folhasPos = 0;

	auxContaElegantePares_And_FolhasPositivas(raiz, &pares, &folhasPos);

	cout << "Pares: " << pares << endl;
	cout << "Folhas Positivas: " << folhasPos << endl;
}

/// <summary>
/// Implementar a operação void ArvBin::contaElegantePares_And_FolhasPositivas(); que percorre
//recursivamente a árvore binária, contando quantos nós possuem valores pares e
//também quantos nós folha possuem valores não negativos(>= 0).Ao final, a função
//deve imprimir os resultados.Você deve percorrer a árvore binária uma única vez
//em pré - ordem!
/// </summary>
/// <param name="p"></param>
/// <param name="pares"></param>
/// <param name="folhasPos"></param>
void ArvBin::auxContaElegantePares_And_FolhasPositivas(NoArv* p, int* pares, int* folhasPos)
{
	if (p != NULL)
	{
		// (x) pre - ordem: raiz, sae, sad
		// ( ) pos - ordem: sae, sad, raiz
		// ( ) In - ordem: sae, raiz, sad

		//raiz
		if (p->getInfo() % 2 == 0)
			(*pares)++;
		if (ehFolha(p) && p->getInfo() > 0)
			(*folhasPos)++;

		auxContaElegantePares_And_FolhasPositivas(p->getEsq(), pares, folhasPos); // sae
		auxContaElegantePares_And_FolhasPositivas(p->getDir(), pares, folhasPos); // sad
	}
}

void ArvBin::contaEleganteDoisFilhos_And_FolhasMultiplos5()
{
	int doisFilhos = 0;
	int folhasMultiplos5 = 0;

	auxContaEleganteDoisFilhos_And_FolhasMultiplos5(raiz, &doisFilhos, &folhasMultiplos5);

	cout << endl;
	cout << "Contem Dois Filhos: " << doisFilhos << endl;
	cout << "Folhas que sao multiplo de 5: " << folhasMultiplos5 << endl;
}

/// <summary>
/// Implementar a operação void ArvBin::contaEleganteDoisFilhos_And_FolhasMultiplos5(); que percorre
//recursivamente a árvore binária, contando a quantidade de nós que possuem dois
//filhos e também a quantidade de nós folha que possuem valores múltiplos de 5. Ao
//final, a função deve imprimir os resultados.Você deve percorrer a árvore binária
//uma única vez em pré - ordem!
/// </summary>
/// <param name="p"></param>
/// <param name="doisFilhos"></param>
/// <param name="multiplos5"></param>
void ArvBin::auxContaEleganteDoisFilhos_And_FolhasMultiplos5(NoArv* p, int* doisFilhos, int* folhasMultiplos5)
{
	if (p != NULL)
	{
		// (x) pre - ordem: raiz, sae, sad
		// ( ) pos - ordem: sae, sad, raiz
		// ( ) In - ordem: sae, raiz, sad

		//raiz
		if (p->getEsq() != NULL && p->getDir() != NULL)
			(*doisFilhos)++;
		if (ehFolha(p) && p->getInfo() % 5 == 0)
			(*folhasMultiplos5)++;

		auxContaEleganteDoisFilhos_And_FolhasMultiplos5(p->getEsq(), doisFilhos, folhasMultiplos5); // sae
		auxContaEleganteDoisFilhos_And_FolhasMultiplos5(p->getDir(), doisFilhos, folhasMultiplos5); // sad
	}
}

void ArvBin::contagens_PossuemUmUnicoFilhoOuSaoFolhas_And_MultiplosDeVal(int val)
{
	int possuemUmUnicoFilhoOuSaoFolhas = 0;
	int multiplosDeVal = 0;

	auxContagens_PossuemUmUnicoFilhoOuSaoFolhas_And_MultiplosDeVal(raiz, val, &possuemUmUnicoFilhoOuSaoFolhas, &multiplosDeVal);

	cout << "possuem Um Unico Filho Ou Sao Folhas: " << possuemUmUnicoFilhoOuSaoFolhas << endl;
	cout << "Multiplos De Val: " << multiplosDeVal << endl;
}

/// <summary>
/// Implementar a operação void ArvBin::contagens_PossuemUmUnicoFilhoOuSaoFolhas_And_MultiplosDeVal(int val); que recebe um
//valor val como parâmetro e percorre recursivamente a árvore binária, calculando
//as seguintes informações :
//1) quantos nós são folhas ou possuem somente um filho;
//2) quantos nós possuem valores múltiplos de val.
//Ao final, a operação deve imprimir os resultados.Você deve percorrer a árvore
//binária uma única vez em  ordem!
/// </summary>
/// <param name="p"></param>
/// <param name="val"></param>
/// <param name="possuemUmUnicoFilhoOuSaoFolhas"></param>
/// <param name="multiplosDeVal"></param>
void ArvBin::auxContagens_PossuemUmUnicoFilhoOuSaoFolhas_And_MultiplosDeVal(NoArv* p, int val, int* possuemUmUnicoFilhoOuSaoFolhas, int* multiplosDeVal)
{
	if (p != NULL)
	{
		// ( ) pre - ordem: raiz, sae, sad
		// ( ) pos - ordem: sae, sad, raiz
		// (x) In - ordem: sae, raiz, sad

		auxContagens_PossuemUmUnicoFilhoOuSaoFolhas_And_MultiplosDeVal(p->getEsq(), val, possuemUmUnicoFilhoOuSaoFolhas, multiplosDeVal); // sae

		//raiz
		if (ehFolha(p) || (p->getEsq() == NULL && p->getDir() != NULL || p->getEsq() != NULL && p->getDir() == NULL))
			(*possuemUmUnicoFilhoOuSaoFolhas)++;
		if (p->getInfo() % val == 0)
			(*multiplosDeVal)++;

		auxContagens_PossuemUmUnicoFilhoOuSaoFolhas_And_MultiplosDeVal(p->getDir(), val, possuemUmUnicoFilhoOuSaoFolhas, multiplosDeVal); // sad
	}
}

void ArvBin::auxPreencheVet(NoArv* p, int* v, int* i)
{
	if (p != NULL)
	{
		auxPreencheVet(p->getEsq(), v, i);
		v[*i] = p->getInfo();
		(*i)++; // incrementa indice
		auxPreencheVet(p->getDir(), v, i);
	}
}

int* ArvBin::preencheVet(int* n)
{
	int tam = auxContaNos(raiz);
	int i = 0;
	int* vetor = new int[tam];

	auxPreencheVet(raiz, vetor, &i);
	*n = i;
	return vetor;
}

int* ArvBin::criaVetPositivos(int k, int n)
{
	n = 0;
	if (raiz == NULL)
		return NULL;
	n = pow(2, k) + pow(2, k + 1);
	int* vet = new int[n];
	int pos = 0;
	auxCriaVetPositivos(raiz, k, 0, vet, &pos);
	for (int i = pos; i < n; i++)
		vet[i] = -1;
	return vet;
}

void ArvBin::auxCriaVetPositivos(NoArv* p, int k, int atual, int vet[], int* pos)
{
	if (p != NULL)
	{
		if ((atual == k || atual == k + 1) && p->getInfo() > 0)
			vet[(*pos)++] = p->getInfo();
		if (atual < k + 1)
		{
			auxCriaVetPositivos(p->getEsq(), k, atual + 1, vet, pos);
			auxCriaVetPositivos(p->getDir(), k, atual + 1, vet, pos);
		}
	}
}
