#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
#include "abp.h"
#include "splay.h"
#include "lde.h"
*/

#include "RNG.h"

#define SEQ  1
#define RAND 0

int main(void)
{
	int* d5000;
	int i;
	/*
	int* d10.000;
	int* d100.000;
	int* d1.000.000;
	*/
	
	printf("\nTESTE 1: Números aleatórios, arquivo .rand\n");
	salvaParaArquivo(5000, RAND);
	d5000 = carregaDeArquivo(5000, RAND);
	
	printf("\n");
	for(i=0; i<5000; i++)
	{
		printf("%d ", d5000[i]);
	}
	printf("\n");
	
	free(d5000);
	printf("\n5000 dados excluídos da memória.\n");
	
	printf("\nTESTE 2: Números em sequência, arquivo .srand\n");
	salvaParaArquivo(5000, SEQ);
	d5000 = carregaDeArquivo(5000, SEQ);
	
	printf("\n");
	for(i=0; i<5000; i++)
	{
		printf("%d ", d5000[i]);
	}
	printf("\n");
	
	free(d5000);
	printf("\n5000 dados excluídos da memória.\n");
	
	printf("\nFechando a aplicação.\n\n");
	return 0;
}
