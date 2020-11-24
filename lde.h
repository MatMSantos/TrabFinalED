#include <stdio.h>

// Definimos um nó
struct no
{
    int num;
    struct no *prox;
    struct no *ant;
};

// Renomeamos a estrutura para simplificar o código
typedef struct no No;

// ======= FUNÇÕES ======= //

// Cria um novo nó a ser inserido em uma LDE
No* cria_no(void);
// Insere um nó ao fim de uma LDE
No* insere_fim(No* ptInit, int elem);
// Consulta um valor int em uma LDE
void busca(No* ptInit, int elem);
// Imprime os valores dos nós de uma LDE a partir de seu início
void imprimir(No* ptInit);
