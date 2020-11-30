#include "abp.h"
#include "RNG.h"
#include <stdio.h>
#include <stdlib.h>

// Cria um novo nodo em uma ABP
abp_pNodoA* abp_novoNodo(abp_tipoinfo ch)
{
	abp_pNodoA* novoNodo = (abp_pNodoA*) malloc(sizeof(abp_pNodoA));
    novoNodo->info = ch;
 
    novoNodo->esq = NULL;
    novoNodo->dir = NULL;
 
    return novoNodo;
}

// Insere um nodo em uma ABP
abp_pNodoA* abp_insere(abp_pNodoA *a, abp_tipoinfo ch)
{
	abp_pNodoA* novoNodo = abp_novoNodo(ch);
	
	abp_pNodoA **busca = &a;
	while (*busca)
	{
		if (novoNodo->info < (*busca)->info)
		{
		   busca = &(*busca)->esq;
		}
		else
		{
		   busca = &(*busca)->dir;
		}
	}
	*busca = novoNodo;
	novoNodo->esq = novoNodo->dir = NULL;
	return a;
}

// Consulta um valor de tipoinfo em uma ABP
abp_pNodoA* abp_consulta(abp_pNodoA *a, abp_tipoinfo chave)
{
    while (a != NULL)
    {
        if (a->info == chave)
            return a; // Achou então retorna o ponteiro para o nodo
        else if (a->info > chave)
            a = a->esq;
        else
            a = a->dir;
    }
    printf("\nNodo não foi encontrado!\n");
    return NULL; // se nao achou
}

// Imprime os valores dos nodos de uma ABP em um caminhamento Pré-Fixado
// à esquerda
void abp_preFixadoE(abp_pNodoA *a)
{
    if (a != NULL)
    {
        printf("%d-> ",a->info);
        abp_preFixadoE(a->esq);
        abp_preFixadoE(a->dir);
    }
}

/*

// Teste das funções abp.
// Para isso:
//
// >> gcc abp.c -o ABP
// >> ./ABP

int main()
{
    abp_pNodoA *arv1 = NULL, *arv2 = NULL, *result;
    int numero, i, var;
    abp_tipoinfo num, find;
    
    srand(time(NULL));
    
    for(i=0; i<30; i++)
    {
        num = gera_aleatorio();
        arv1 = abp_insere(arv1,num);
    }
    printf("-- Pré-Fixado à Esquerda --\n");
    abp_preFixadoE(arv1);
    printf("\n\n");

    printf("Digite um numero:");
    scanf("%d", &var);

    find = var;

    *result = abp_consulta(arv1,find);

    printf("\n%d", result->info);
}

*/
