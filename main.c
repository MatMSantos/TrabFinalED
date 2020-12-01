#include "RNG.h"
#include "lde.h"
#include "abp.h"
#include "splay.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQ  1
#define RAND 0

#define NUM_DADOS 5000

// Variável global para contagem de comparações
int g_cont = 0;

int main(void)
{
	int *dNUM_DADOS;
	int i, j, k;
	lde_No *lde = NULL;
	abp_pNodoA *abp = NULL, *consultaAbp = NULL;
	splay_PtNodo *splay = NULL, *consultaSplay = NULL;
	
	/*
	int* d10.000;
	int* d100.000;
	int* d1.000.000;
	*/
	
	salvaParaArquivo(NUM_DADOS, RAND);
	dNUM_DADOS = carregaDeArquivo(NUM_DADOS, RAND);
	
	printf("\nLDE: Números aleatórios, arquivo .rand\n");	
	for (i=0; i<NUM_DADOS; i++)
	{
		lde = lde_insereFim(lde, dNUM_DADOS[i]);
	}
	printf("\n");
	
	lde_imprimir(lde);
	
	printf("\n");
	lde_busca(lde, dNUM_DADOS[1250]);
	
	
	printf("\nABP: Números aleatórios, arquivo .rand\n");
	for (j=0; j<NUM_DADOS; j++)
	{
		abp = abp_insere(abp, dNUM_DADOS[j]);
	}
	printf("\n");
	
	consultaAbp = abp_consulta(abp, dNUM_DADOS[1250]);
	if(consultaAbp != NULL)
		printf("\nValor encontrado na ABP!\n");
	else
		printf("\nValor não encontrado!\n");
	
	
	printf("\nSplay: Números aleatórios, arquivo .rand\n");
	for (k=0; k<NUM_DADOS; k++)
	{
		splay = splay_insere(splay, dNUM_DADOS[k]);
	}
	consultaAbp = splay_consulta(splay, dNUM_DADOS[1250]);
	if(consultaAbp != dNUM_DADOS[1250])
		printf("\nValor encontrado na Splay!\n");
	else
		printf("\nValor não encontrado!\n");
	
	free(dNUM_DADOS);
	free(lde);
	free(abp);
	free(splay);
	
	/*
	printf("\n500 dados excluídos da memória.\n");
	
	printf("\nTESTE 2: Números em sequência, arquivo .srand\n");
	salvaParaArquivo(500, SEQ);
	d500 = carregaDeArquivo(500, SEQ);
	
	printf("\n");
	for(i=0; i<500; i++)
	{
		printf("%d ", d500[i]);
	}
	printf("\n");
	
	free(d500);
	printf("\n500 dados excluídos da memória.\n");
	*/
	
	printf("\nFechando a aplicação.\n\n");
	return 0;
}
