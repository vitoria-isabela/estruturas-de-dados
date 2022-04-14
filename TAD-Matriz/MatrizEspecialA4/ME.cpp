//int MatrizEspecial::detInd(int i, int j)
//{
//	if (i >= 0 && i < n && j >= 0 && j < n)
//	{
//		int k;
//		if ((i == j) || (i + j == (n - 1))) // DP ou DS
//			k = i; // Aqui está sendo representada a DP, em i==j. Ex.: A1,1, A2,2 ...//
//		else
//			if (j == 0) //Primeira Coluna
//				k = n + (i - 1); /* Aqui, no vetor linear, a primeira coluna fica no indice do meio (n=1);
//								 Por isso é necessario somar n (tamanho da DP) e subtrair  1 no indice de linhas,
//								 (pq começa a contar na linha abaixo da DP)*/
//								 ///Olhar desenho para entender melhor!
//			else
//				if (j == (n - 1)) //Ultima Coluna
//					k = n + n - 2 + (i - 1); /* Com racíocinio análogo ao de cima, somamos o n da DP, o (n - 2)
//											 da primeira coluna e subtraimos 1 no indice de linhas da ultima coluna
//											 (pq começa a contar na linha abaixo da DS)*/
//											 ///Olhar desenho para entender melhor!
//				else
//					return -2; /* Aqui retornamos -2 para no Get indicar que elementos com esse retorno terão valor 0 */
//		return k;
//	}
//	else {
//		return -1; /* Aqui retornamos -1 para no Get indicar que elementos com esse retorno NÃO estão dentro dos elementos que podem ser representados na matriz */
//	}
//}

int MatrizEspecial::detInd(int i, int j)
{
	if (i >= 0 && i < n && j >= 0 && j < n)
	{
		int* vetDPouDS;
		int* vetPrimeiraCol;
		int* vetultimaCol;
		if ((i == j) || (i + j == (n - 1))) // DP ou DS
			vetDPouDS[i];
		else
			if (j == 0) //Primeira Coluna
				vetPrimeiraCol[n-2];
			else
				if (j == (n - 1)) //Ultima Coluna
					vetultimaCol[n-2];
				else
					return -2; /* Aqui retornamos -2 para no Get indicar que elementos com esse retorno terão valor 0 */
		return k;
	}
	else {
		return -1; /* Aqui retornamos -1 para no Get indicar que elementos com esse retorno NÃO estão dentro dos elementos que podem ser representados na matriz */
	}
}

float MatrizEspecial::get(int i, int j)
{
	if (detInd(i, j) != -1)
	{
		if (i == j)
			return vetPrimeiraCol[n - 2];
		if (j + i == (n - 1))
			return -vet[k];
		if (k == -2)
			return 0;
		return vet[k];
	}
	else
	{
		cout << "ERRO: Indice invalido!" << endl;
		exit(1);
	}
}

void MatrizEspecial::set(int i, int j, float val)
{
	int k = detInd(i, j);
	if (k != -1)
		vet[k] = val;
	else
		cout << "ERRO: Indice invalido!" << endl;
}
