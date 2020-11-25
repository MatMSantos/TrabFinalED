#ifndef _LDE_H_
#define _LDE_H_

#include <stdio.h>

// Definimos um nó
struct no
{
    int num;
    struct no *prox;
    struct no *ant;
};

// Renomeamos a estrutura para simplificar o código
typedef struct no lde_No;

// ======= FUNÇÕES ======= //

// Cria um novo nó a ser inserido em uma LDE
lde_No* lde_criaNo(void);
// Insere um nó ao fim de uma LDE
lde_No* lde_insereFim(lde_No* ptInit, int elem);
// Consulta um valor int em uma LDE
void lde_busca(lde_No* ptInit, int elem);
// Imprime os valores dos nós de uma LDE a partir de seu início
void lde_imprimir(lde_No* ptInit);

#endif
