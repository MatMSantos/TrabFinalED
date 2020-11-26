#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
#include "abp.h"
#include "splay.h"
#include "lde.h"
*/

#include "RNG.h"

int main(void)
{
	int* d5000;
	int i;
	/*
	int* d10.000;
	int* d100.000;
	int* d1.000.000;
	*/
	
	salvaParaArquivo(5000);
	d5000 = carregaDeArquivo(5000);
	
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
