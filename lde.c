#include "lde.h"

// Cria um novo nó a ser inserido em uma LDE
No* cria_no(void)
{
    No* novo = (No*)malloc(sizeof(No));
    return novo;
}

// Insere um nó ao fim de uma LDE
No* insere_fim(No* ptInit,int elem)
{
    No* ptaux;

    No* novo_no=cria_no();
    novo_no->num=elem;

    if(ptInit==NULL)//se lista estiver vazia
    {
        novo_no->prox=NULL;
        novo_no->ant=NULL;
        ptInit=novo_no;
    }
    else //se lista estiver cheia
    {
        ptaux=ptInit;

        while(ptaux->prox!=NULL)
        {
            ptaux=ptaux->prox;
        }

        novo_no->prox=NULL;
        novo_no->ant=ptaux;
        ptaux->prox=novo_no;
    }

    return ptInit;
}

// Consulta um valor int em uma LDE
void busca(No* ptInit,int elem)
{
    No *ptaux=ptInit,*ptguarda_init,*ptguarda_fim;

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
void imprimir(No* ptInit)
{
    No *ptaux=ptInit;

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
    No *lista=NULL;
    int num,x,i;
    char resp;

    srand(time(NULL));

    for(i=0; i<30; i++)
    {
        num=gera_aleatorio();
        lista=insere_fim(lista,num);
    }

    printf("Lista:");
    imprimir(lista);

    printf("\n\nDigite o valor de procura:");
    scanf("%d",&elem);

    busca(lista,elem);

}
