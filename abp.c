#include "abp.h"

// Insere um nodo em uma ABP
pNodoA* InsereArvore(pNodoA *a, tipoinfo ch)
{
    if (a == NULL)
    {
        a =  (pNodoA*) malloc(sizeof(pNodoA));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
        return a;
    }
    else if (ch < a->info)
        a->esq = InsereArvore(a->esq,ch);
    else if (ch > a->info)
        a->dir = InsereArvore(a->dir,ch);
    return a;
}

// Consulta um valor de tipoinfo em uma ABP
pNodoA* consultaABP(pNodoA *a, tipoinfo chave)
{

    while (a!=NULL)
    {
        if (a->info == chave )
            return a; //achou entao retorna o ponteiro para o nodo
        else if (a->info > chave)
            a = a->esq;
        else
            a = a->dir;
    }
    return NULL; //se nao achou
}

// Imprime os valores dos nodos de uma ABP em um caminhamento Pré-Fixado
// à esquerda
void preFixadoE(pNodoA *a)
{
    if (a!= NULL)
    {
        printf("%d - ",a->info);
        preFixadoE(a->esq);
        preFixadoE(a->dir);
    }
}

// Teste das funções abp.
// Para isso:
//
// >> gcc abp.c -o ABP
// >> ./ABP

int main()
{
    pNodoA *arv1 = NULL, *arv2 = NULL,*result;
    int numero,i,var;
    tipoinfo num,find;

    srand(time(NULL));

    for(i=0; i<30; i++)
    {
        num=gera_aleatorio();
        arv1 = InsereArvore(arv1,num);
    }
    printf("--Central Esquerda --\n");
    preFixadoE(arv1);
    printf("\n\n");

    printf("DIgite um numero:");
    scanf("%d",&var);

    find=var;

    result=consultaABP(arv1,find);

    printf("\n%d",result->info);
}
