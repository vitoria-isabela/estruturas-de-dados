#pragma once 

#include "NoArv.h"
class ArvBin
{
private:
	NoArv* raiz; // ponteiro para o n� raiz da �rvore
	void auxImprime(NoArv* r);
	NoArv* sae(NoArv* p) { return p->getEsq(); };
	NoArv* sad(NoArv* p) { return p->getDir(); };
	int auxNumNos(NoArv* p);

	NoArv* libera(NoArv* r);

	int auxAltura(NoArv* p);
	bool auxBusca(NoArv* p, int ch);

	bool EhFolha(NoArv* p) {
		return p->getEsq() == NULL &&
			p->getDir() == NULL;
	};
	int auxNFolhas(NoArv* p);

public:
	int nFolhas() { return auxNFolhas(raiz); };

	int altura() { return auxAltura(raiz); };
	ArvBin();
	~ArvBin();
	int getRaiz();
	// cria novo n� como raiz das sub-�rvores �
	//esquerda (sae) e � direita (sad)
	void cria(int val, ArvBin* sae, ArvBin* sad);
	bool vazia(); // verifica se a �rvore est� vazia
	void imprime();

	bool busca(int val) { return auxBusca(raiz, val); }

	int numNos() { return auxNumNos(raiz); };
};