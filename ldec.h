#ifndef _LDEC_H_
#define _LDEC_H_

// Definimos um nó
struct no
{
    int num;
    struct no *prox;
    struct no *ant;
};

// Renomeamos a estrutura para simplificar o código
typedef struct no ldec_No;

// ======= FUNÇÕES ======= //

// Cria um novo nó a ser inserido em uma LDE
ldec_No* ldec_criaNo(void);
// Insere um nó ao fim de uma LDE
ldec_No* ldec_insereFim(ldec_No* ptInit, int elem);
// Consulta um valor int em uma LDE
void ldec_busca(ldec_No* ptInit, int elem);
// Imprime os valores dos nós de uma LDE a partir de seu início
void ldec_imprimir(ldec_No* ptInit);

#endif
