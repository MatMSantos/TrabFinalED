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
//
// OBS: Esta função REESCREVE em cima de arquivos!
//
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
		printf("\nERRO na criação do arquivo! Arquivo não inicializado.\n");
		return -1;
	}
	else
	{
		for(i = 0; i < numDados; i++)
		{
			num = gera_aleatorio();
			
			if( fwrite(&num, sizeof(int), 1, arquivoRNG) == 0)
			{
				printf("\nNão foi possível escrever o elemento %d no arquivo.\n", i+1);
			}
			else qtdeEscrita++;
		}
		
		fclose(arquivoRNG);
		
		// Se escrevemos a quantidade de dados correta no arquivo, retornamos 1.
		// Se não, retornamos 0.
		if(qtdeEscrita == numDados)
		{
			printf("\n%d dados salvos em %d.rand!\n", numDados, numDados);
			return 1;
		}
		else
		{
			printf("\nArquivo foi criado mas %d de %d elementos não foram escritos.\n", (numDados - qtdeEscrita), numDados);
			return 0;
		}
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
	char continuar;
	
	sprintf(nome, "%d", numDados);
	strcat(nome, ".rand");
	arquivoRNG = fopen(nome, "rb");
	
	if(arquivoRNG == NULL)
	{
		printf("\nERRO na leitura do arquivo! Arquivo não inicializado.\n");
		free(dados);
		return NULL;
	}
	else
	{
		qtdeLida = fread(dados, sizeof(int), numDados, arquivoRNG);
		
		fclose(arquivoRNG);
		
		// Se lemos a quantidade de dados correta no arquivo, retornamos um array.
		// Se não, retornamos ponteiro NULL.
		if(qtdeLida == numDados)
		{
			printf("\n%d dados lidos de %d.rand!\n", numDados, numDados);
			return dados;
		}
		else
		{
			printf("\nArquivo foi criado mas %d de %d elementos não foram lidos.\n", (numDados - qtdeLida), numDados);
			printf("Continuar mesmo assim? [s/n] ");
			
			do
			{
				scanf("%c", &continuar);
			} while (continuar != 's' && continuar != 'n' && continuar != 'S' && continuar != 'N');
			
			if (continuar == 's' || continuar == 'S')
			{
				return dados;
			}
			else
			{
				free(dados);
				return NULL;
			}
		}
	}	
}

// Para testes
/*

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

*/
