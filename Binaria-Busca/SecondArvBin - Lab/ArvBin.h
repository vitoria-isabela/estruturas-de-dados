#pragma once

#include "NoArv.h"
class ArvBin
{
public:
	ArvBin();
	~ArvBin();
	int getRaiz();
	void cria(int x, ArvBin* sae, ArvBin* sad);
	void anulaRaiz();
	bool vazia();
	bool busca(int x);
	void preOrdem();
	void imprime();
	void montaArvore();
	void insere(int x);
	int contaNos();
	int contaNosFolhas();
	int contaImpar();
	int contaFolhaImpar();
	int altura();
	void imprimeNivel(int k);
	float mediaNivel(int k);
	int min();
	int max();
	void removeFolhas();
	void contaEleganteMult3_And_FolhaNeg();
	bool ehFolha(NoArv* p);
	void contagens_ParesFilhoEsq_And_FolhasAteNivelk(int k);
	void contagens_InfoMaiorQueValESoUmFilhoADir_And_DoisFilhosAteNivelK(int val, int k);
	void contaElegantePares_And_FolhasPositivas();
	void contaEleganteDoisFilhos_And_FolhasMultiplos5();
	void contagens_PossuemUmUnicoFilhoOuSaoFolhas_And_MultiplosDeVal(int val);
	int* criaVetPositivos(int k, int n);
	int* preencheVet(int* n);

private:
	NoArv* raiz;
	NoArv* libera(NoArv *p);
	bool auxBusca(NoArv* p, int x);
	void auxPreOrdem(NoArv *p);
	void auxImprime(NoArv* p, int nivel);
	NoArv* auxMontaArvore(int nivel);
	void auxImpNivel(NoArv *p, int k);
	void auxInverte(NoArv *p);
	NoArv* auxInsere(NoArv* p, int x);
	int auxContaNos(NoArv* p);
	int auxContaNosFolhas(NoArv* p);
	int auxAltura(NoArv* p);
	int auxContaImpar(NoArv* p);
	int auxContaFolhaImpar(NoArv* p);
	void auxMediaNivel(NoArv* p, int k, int* soma, int* cont);
	void auxMin(NoArv* p, int* menor);
	void auxMax(NoArv* p, int* maxVal);
	NoArv* auxRemoveFolhas(NoArv* p);
	void auxContaEleganteMult3_And_FolhaNeg(NoArv* p, int* multTres, int* folhasNeg);
	void auxContagens_ParesFilhoEsq_And_FolhasAteNivelk(NoArv* p, int atual, int k, int* paresFilhosEsq, int* folhasAteNivelk);
	void auxContagens_InfoMaiorQueValESoUmFilhoADir_And_DoisFilhosAteNivelK(NoArv* p, int val, int atual, int k, int* infoMaiorQueValESoUmFilhoAEsq, int* doisFilhosAteNivelK);
	void auxContaElegantePares_And_FolhasPositivas(NoArv* p, int* pares, int* folhasPos);
	void auxContaEleganteDoisFilhos_And_FolhasMultiplos5(NoArv* p, int* doisFilhos, int* multiplos5);
	void auxContagens_PossuemUmUnicoFilhoOuSaoFolhas_And_MultiplosDeVal(NoArv* p, int val, int* possuemUmUnicoFilhoOuSaoFolhas, int* multiplosDeVal);
	void auxPreencheVet(NoArv* p, int* v, int* i);

	void auxCriaVetPositivos(NoArv* p, int k, int atual, int vet[], int* pos);

};