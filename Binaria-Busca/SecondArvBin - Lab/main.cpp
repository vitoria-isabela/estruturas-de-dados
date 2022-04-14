
#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
	ArvBin arv;

	arv.montaArvore();

	/*arv.insere(0);
	arv.insere(2);
	arv.insere(4);
	arv.insere(6);
	arv.insere(8);
	arv.insere(10);*/
	/*arv.insere(12);
	arv.insere(14);
	arv.insere(16);
	arv.insere(18);
	arv.insere(20);*/

	/*arv.insere(10);
	arv.preOrdem();

	a1.cria(16, &vazia, &vazia);
	a2.cria(19, &vazia, &vazia);
	a3.cria(18, &a1, &a2);

	a1.cria(38, &vazia, &vazia);
	a2.cria(14, &vazia, &vazia);
	a4.cria(25, &a1, &a2);

	arv.cria(10, &a3, &a4);

	a1.anulaRaiz();
	a2.anulaRaiz();*/
	/*a3.anulaRaiz();
	a4.anulaRaiz();*/

	arv.preOrdem();

	cout << arv.criaVetPositivos(3, 10);

	/*arv.contaElegantePares_And_FolhasPositivas();
	arv.contaEleganteDoisFilhos_And_FolhasMultiplos5();
	arv.contagens_PossuemUmUnicoFilhoOuSaoFolhas_And_MultiplosDeVal(2);*/

	/*arv.removeFolhas();*/

	/*arv.preOrdem();*/

	/*arv.ContaEleganteMult3Neg();

	arv.contagens_ParesFilhoEsq_And_FolhasAteNivelk(1);*/

	/*arv.contagens_InfoMaiorQueValESoUmFilhoADir_And_DoisFilhosAteNivelK(0, 1);*/
	
	//arv.imprime();

	//cout << endl;
	//cout << "Total de nos: " << arv.contaNos() << endl;
	//cout << "Total de folhas: " << arv.contaNosFolhas() << endl;
	//cout << "Altura: " << arv.contaNosFolhas() << endl;
	////cout << "Total de Impares: " << arv.contaFolhaImpar() << endl;
	//int k = 3;
	//cout << "Imprime Nível: " << k << ": ";
	//arv.imprimeNivel(k);
	//cout << endl;
	//cout << "Media Nivel: " << k << ": " << arv.mediaNivel(k) << endl;
	//cout << "Menor valor da Arvore: " << arv.min() << endl;
	//cout << "Maior valor da Arvore: " << arv.max() << endl;
}