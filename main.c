#include "RNG.h"
#include "lde.h"
#include "abp.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
#include "abp.h"
#include "splay.h"
#include "lde.h"
*/

#define SEQ  1
#define RAND 0

int main(void)
{
	int *d5000;
	int *d1000000;
	int i, j, k;
	lde_No *lde = NULL;
	abp_pNodoA *abp = NULL, *consultaAbp = NULL;
	
	/*
	int* d10.000;
	int* d100.000;
	int* d1.000.000;
	*/
	
	salvaParaArquivo(1000000, RAND);
	d1000000 = carregaDeArquivo(1000000, RAND);
	
	printf("\nLDE: Números aleatórios, arquivo .rand\n");
	salvaParaArquivo(5000, RAND);
	d5000 = carregaDeArquivo(5000, RAND);
	
	printf("\n");
	for(i=0; i<5000; i++)
	{
		printf("%d ", d5000[i]);
	}
	printf("\n");
	
	for (j=0; j<5000; j++)
	{
		lde = lde_insereFim(lde, d5000[j]);
	}
	
	printf("\n");
	lde_imprimir(lde);
	
	printf("\n");
	lde_busca(lde, d5000[1250]);
	
	printf("\nABP: Números aleatórios, arquivo .rand\n");
	for (k=0; k<1000000; k++)
	{
		abp = abp_insere(abp, d1000000[k]);
	}
	
	printf("\n");
	abp_preFixadoE(abp);
	
	printf("\n");
	consultaAbp = abp_consulta(abp, d1000000[190000]);
	if(consultaAbp != NULL)
		printf("\nValor encontrado na ABP!\n");
	else
		printf("\nValor não encontrado!\n");
	
	free(d5000);
	free(d1000000);
	free(lde);
	free(abp);
	
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
