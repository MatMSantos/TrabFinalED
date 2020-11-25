#include "RNG.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Gera um número aleatório
int gera_aleatorio(void)
{
    int min=0,max=100;
    int num;

    num = min + ( rand() % (max - min + 1) );
    return num;
}

// Escreve uma certa quantidade de números
// aleatórios em um arquivo
int salvaParaArquivo(int numDados)
{
	FILE* arquivoRNG;
	char nome[13];
	
	int i;
	int num;
	int qtdeEscrita = 0;
	
	sprintf(nome, "%d", numDados);
	strcat(nome, ".rand");
	arquivoRNG = fopen(nome, "wb");

	if(arquivoRNG == NULL)
	{
		printf("ERRO na criação do arquivo!");
	}
	else
	{
		for(i = 0; i < numDados; i++)
		{
			num = gera_aleatorio();
			
			if( fwrite(&num, sizeof(int), 1, arquivoRNG) == 0)
			{
				printf("Não foi possível escrever o elemento %d no arquivo.", i+1);
			}
			else qtdeEscrita++;
		}
		
		fclose(arquivoRNG);
		
		// Se escrevemos a quantidade de dados correta no arquivo, retornamos 1.
		// Se não, retornamos 0.
		if(qtdeEscrita == numDados)
			return 1;
		else
			return 0;
	}
}

// Lê uma certa quantidade de números
// aleatórios de um arquivo
int* carregaDeArquivo(int numDados)
{
	FILE* arquivoRNG;
	char nome[13];
	
	int* dados = malloc(sizeof(int) * numDados);
	int qtdeLida;
	
	sprintf(nome, "%d", numDados);
	strcat(nome, ".rand");
	arquivoRNG = fopen(nome, "rb");
	
	if(arquivoRNG == NULL)
	{
		printf("ERRO na leitura do arquivo!");
		free(dados);
	}
	else
	{
		qtdeLida = fread(dados, sizeof(int), numDados, arquivoRNG);
		
		fclose(arquivoRNG);
		
		// Se lemos a quantidade de dados correta no arquivo, retornamos um array.
		// Se não, retornamos ponteiro NULL.
		if(qtdeLida == numDados)
			return dados;
		else
			free(dados);
			return NULL;
	}	
}

// Para testes
int main()
{
	int* resultados;
	int i = 0;
	
	printf("Teste\n");
	
	if ( salvaParaArquivo(10) )
		printf("OK\n");
	else
		printf("N OK\n");
	
	if ( ( resultados = carregaDeArquivo(10) ) != NULL)
	{
		for(i = 0; i < 10; i++)
		{
			printf("%d ", resultados[i]);
		}
		printf("\nOK");
	}
	else
		printf("N OK");
	
	free(resultados);	
	return 0;
}
