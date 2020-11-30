#include "splay.h"
#include <stdio.h>
#include <stdlib.h>

// Cria um novo nodo a ser inserido em uma Splay
splay_PtNodo* splay_novoNodo(int key)
{
    splay_PtNodo* x = (splay_PtNodo*) malloc(sizeof(splay_PtNodo));
    x->key = key;
    x->pai = NULL;
    x->esq = NULL;
    x->dir = NULL;
    return x;
}

// Função que busca o nodo mais próximo de uma certa chave repassada
splay_PtNodo *splay_buscaInsere(splay_PtNodo *raiz, int key)
{
	splay_PtNodo *aux = raiz;
	
	if(aux == NULL)
		return raiz;
	
	while(1)
	{
		if(key < aux->key)
		{
			if(aux->esq != NULL)
				aux = aux->esq;
			else return aux;
		}
		else
		{
			if(aux->dir != NULL)
				aux = aux->dir;
			else return aux;
		}
	}
}

// Função que busca um nodo com uma certa chave repassada.
// Se não encontrar, retorna o nodo mais próximo.
// Difere da consulta para Inserção APENAS porque retorna o nodo
// quando encontra o valor.
splay_PtNodo *splay_buscaConsulta(splay_PtNodo *raiz, int key)
{
	splay_PtNodo *aux = raiz;
	
	if(aux == NULL)
		return raiz;
	
	while(1)
	{
		if(key == aux->key)
		{
			return aux;
		}
		if(key < aux->key)
		{
			if(aux->esq != NULL)
				aux = aux->esq;
			else return aux;
		}
		else
		{
			if(aux->dir != NULL)
				aux = aux->dir;
			else return aux;
		}
	}
}

// Função para movimentação de um nodo dentro de uma Splay
splay_PtNodo *splay_splay(splay_PtNodo *nodo)
{
	// OBS.: Eu estou considerando que o nodo passado NÃO é a raiz!!
	
	splay_PtNodo *bisavo;
	
	// Enquanto o nodo não for a nova raiz, ou seja, seu pai não é nulo!
	while(nodo->pai != NULL)
	{
		// Se o nodo não tiver avô
		if(nodo->pai->pai == NULL)
		{
			// ZIG
			if(nodo->pai->key > nodo->key)
			{
				// Atualizo o nodo do pai
				nodo->pai->pai = nodo;
				nodo->pai->esq = nodo->dir;
				
				// Atualizo o nodo à direita do novo nodo
				nodo->dir->pai = nodo->pai;
				
				// Atualizo o novo nodo
				nodo->dir = nodo->pai;
								
				// ÚLTIMA COISA!
				nodo->pai = NULL;
			}
			// ZAG
			else
			{				
				// Atualizo o nodo do pai
				nodo->pai->pai = nodo;
				nodo->pai->dir = nodo->esq;
								
				// Atualizo o nodo à esquerda do novo nodo
				nodo->esq->pai = nodo->pai;
				
				// Atualizo o novo nodo
				nodo->esq = nodo->pai;
				
				// ÚLTIMA COISA!
				nodo->pai = NULL;
			}
		}
		// Se o nodo tiver avô
		else
		{
			// Preciso guardar o valor do bisavô para
			// completar as operações!
			bisavo = nodo->pai->pai->pai;
			// ZAG-ZAG ou ZAG-ZIG
			if(nodo->pai->key <= nodo->key)
			{
				// ZAG-ZAG
				if(nodo->pai->pai->key <= nodo->pai->key)
				{
					// Atualizo o nodo do pai
					nodo->pai->dir = nodo->esq;
					// Atualizo o nodo à esquerda do novo nodo
					nodo->esq->pai = nodo->pai;
					// Atualizo o novo nodo
					nodo->esq = nodo->pai;
					
					// Atualizo o nodo do avô
					nodo->pai->pai->dir = nodo->pai->esq;
					// Atualizo o nodo à esquerda do pai
					nodo->pai->esq->pai = nodo->pai->pai;
					// Atualizo o pai
					nodo->pai->esq = nodo->pai->pai;
					
					// Atualizar parentescos
					nodo->pai->pai->pai = nodo->pai;
					nodo->pai->pai = nodo;
				}
				// ZAG-ZIG
				else
				{
					// Atualizo o nodo do pai
					nodo->pai->dir = nodo->esq;
					// Atualizo o nodo à esquerda do novo nodo
					nodo->esq->pai = nodo->pai;
					// Atualizo o novo nodo
					nodo->esq = nodo->pai;
					
					// Atualizo o nodo do avô
					nodo->pai->pai->esq = nodo->dir;
					// Atualizo o nodo à direita do novo nodo
					nodo->dir->pai = nodo->pai->pai;
					// Atualizo o novo nodo
					nodo->dir = nodo->pai->pai;
					
					// Atualizar parentescos
					nodo->pai->pai->pai = nodo;
					nodo->pai->pai = nodo;
				}
			}
			// ZIG-ZAG ou ZIG-ZIG
			else
			{
				// ZIG-ZAG
				if(nodo->pai->pai->key <= nodo->pai->key)
				{
					// Atualizo o nodo do pai
					nodo->pai->esq = nodo->dir;
					// Atualizo o nodo à direita do novo nodo
					nodo->dir->pai = nodo->pai;
					// Atualizo o novo nodo
					nodo->dir = nodo->pai;
					
					// Atualizo o nodo do avô
					nodo->pai->pai->dir = nodo->esq;
					// Atualizo o nodo à esquerda do novo nodo
					nodo->esq->pai = nodo->pai->pai;
					// Atualizo o novo nodo
					nodo->esq = nodo->pai->pai;
					
					// Atualizar parentescos
					nodo->pai->pai->pai = nodo;
					nodo->pai->pai = nodo;
				}
				// ZIG-ZIG
				else
				{
					// Atualizo o nodo do pai
					nodo->pai->esq = nodo->dir;
					// Atualizo o nodo à direita do novo nodo
					nodo->dir->pai = nodo->pai;
					// Atualizo o novo nodo
					nodo->dir = nodo->pai;
					
					// Atualizo o nodo do avô
					nodo->pai->pai->esq = nodo->pai->dir;
					// Atualizo o nodo à direita do pai
					nodo->pai->dir->pai = nodo->pai->pai;
					// Atualizo o pai
					nodo->pai->dir = nodo->pai->pai;
					
					// Atualizar parentescos
					nodo->pai->pai->pai = nodo->pai;
					nodo->pai->pai = nodo;
				}
			}
			// ÚLTIMA COISA!
			if(bisavo == NULL)
				nodo->pai = NULL;
			else
				nodo->pai = bisavo;
		}
	}
	
	// O novo nodo agora é a raiz
	return nodo;
}

// Insere um nodo em uma Splay
splay_PtNodo *splay_insere(splay_PtNodo* raiz, int key)
{
	splay_PtNodo *aux;
	splay_PtNodo *novo_nodo;
	
	// Criamos um novo nodo com a chave repassada
	novo_nodo = splay_novoNodo(key);
	
	// Se a árvore Splay repassada não tiver elementos
	if(raiz == NULL)
		return novo_nodo;
	
	// Se a árvore tiver elementos, busca o último nodo
	// antes da chave que estamos querendo inserir
	aux = splay_buscaInsere(raiz, key);
	
	// Se este último nodo for maior que nossa chave,
	// inserimos o novo nodo à esquerda e devolvemos
	// a árvore tendo feito Splay e com o novo nodo como raiz
	if(aux->key > key)
	{
		aux->esq = novo_nodo;
		aux->esq->pai = aux;
		
		return splay_splay(aux->dir);
	}
	// Se este último nodo for menor ou igual a nossa chave,
	// inserimos o novo nodo à direita e devolvemos
	// a árvore tendo feito Splay e com o novo nodo como raiz
	else
	{
		aux->dir = novo_nodo;
		aux->dir->pai = aux;
		
		return splay_splay(aux->esq);
	}
}

// Consulta um valor int em uma árvore Splay
splay_PtNodo *splay_consulta(splay_PtNodo* raiz, int key)
{
	splay_PtNodo *aux;
	splay_PtNodo *novo_nodo;
	
	// Se a árvore Splay repassada não tiver elementos	
	if(raiz == NULL)
		return NULL;
	// Se a árvore Splay repassada tiver elementos mas sua raiz
	// já tiver o mesmo valor da chave procurada, devolvemos a raiz
	else if(raiz->key == key)
		return raiz;
	else
		// Se a árvore tiver elementos, busca o nodo que contenha
		// a chave. Se não encontrar, devolve o último nodo antes
		// do nodo buscado.
		aux = splay_buscaConsulta(raiz, key);
	
	// Devolvemos a árvore tendo feito Splay e com o nodo consultado
	// (ou o último nodo antes deste) como raiz
	return splay_splay(aux);
}

/*
// Teste das funções Splay.
// Para isso:
//
// >> gcc splay.c -o SPLAY
// >> ./SPLAY

int main(void)
{
	splay_PtNodo* arv = NULL;
	splay_PtNodo* consulta = NULL;
	
	arv = splay_insere(arv, 30);
	arv = splay_insere(arv, 10);
	arv = splay_insere(arv, 20);
	
	consulta = splay_consulta(arv, 40);
	
	if ( consulta->key != 40)
		printf("Achado\n");
	else
		printf("Não achado\n");
	
	free(arv);
}
*/
