#include "lde.h"
#include "RNG.h"
#include <time.h>

// Cria um novo nó a ser inserido em uma LDE
lde_No* lde_criaNo(void)
{
    lde_No* novo = (lde_No*)malloc(sizeof(lde_No));
    return novo;
}

// Insere um nó ao fim de uma LDE
lde_No* lde_insereFim(lde_No* ptInit,int elem)
{
    lde_No* ptaux;

    lde_No* novo_no = lde_criaNo();
    novo_no->num = elem;

    if(ptInit == NULL)//se lista estiver vazia
    {
        novo_no->prox = NULL;
        novo_no->ant = NULL;
        ptInit = novo_no;
    }
    else //se lista estiver cheia
    {
        ptaux = ptInit;

        while(ptaux->prox != NULL)
        {
            ptaux = ptaux->prox;
        }

        novo_no->prox = NULL;
        novo_no->ant = ptaux;
        ptaux->prox = novo_no;
    }

    return ptInit;
}

// Consulta um valor int em uma LDE
void lde_busca(lde_No* ptInit,int elem)
{
    lde_No *ptaux=ptInit,*ptguarda_init,*ptguarda_fim;

    ptguarda_init=ptInit;

    while(ptInit->num!=elem)
    {
        ptInit=ptInit->prox;
    }

    ptaux=ptInit;

    do
    {
        printf("\nElem:%d",ptaux->num);
        ptaux=ptaux->prox;
        if(ptaux->prox==NULL)
        {
            ptguarda_fim=ptaux;
            ptaux->prox=ptguarda_init;
        }
    }
    while(ptaux->num!=ptInit->num);

    printf("\n\n");

    ptaux=ptInit;

    do
    {
        printf("\nElem:%d",ptaux->num);
        ptaux=ptaux->ant;
        if(ptaux->ant==NULL)
        {
            ptaux->ant=ptguarda_fim;
        }
    }
    while(ptaux->num!=ptInit->num);
}

// Imprime os valores dos nós de uma LDE a partir de seu início
void lde_imprimir(lde_No* ptInit)
{
    lde_No *ptaux=ptInit;

    while(ptaux!=NULL)
    {
        printf("%d",ptaux->num);
        ptaux=ptaux->prox;
        printf("->");
    }
}

// Teste das funções LDE.
// Para isso:
//
// >> gcc lde.c -o LDE
// >> ./LDE

int main()
{
    lde_No* lista=NULL;
    int num,x,i;
    char resp;

    srand(time(NULL));

    for(i=0; i<30; i++)
    {
        num = gera_aleatorio();
        lista = lde_insereFim(lista,num);
    }

    printf("Lista:");
    lde_imprimir(lista);

    printf("\n\nDigite o valor de procura:");
    scanf("%d",&elem);

    lde_busca(lista,elem);

}
