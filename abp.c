#include "abp.h"
#include "RNG.h"

// Insere um nodo em uma ABP
abp_pNodoA* abp_insere(abp_pNodoA *a, abp_tipoinfo ch)
{
    if (a == NULL)
    {
        a =  (abp_pNodoA*) malloc(sizeof(abp_pNodoA));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
        return a;
    }
    else if (ch < a->info)
        a->esq = abp_insere(a->esq,ch);
    else if (ch > a->info)
        a->dir = abp_insere(a->dir,ch);
    return a;
}

// Consulta um valor de tipoinfo em uma ABP
abp_pNodoA* abp_consulta(abp_pNodoA *a, abp_tipoinfo chave)
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
void abp_preFixadoE(abp_pNodoA *a)
{
    if (a!= NULL)
    {
        printf("%d - ",a->info);
        abp_preFixadoE(a->esq);
        abp_preFixadoE(a->dir);
    }
}

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
    printf("--Central Esquerda --\n");
    abp_preFixadoE(arv1);
    printf("\n\n");

    printf("Digite um numero:");
    scanf("%d", &var);

    find = var;

    result = abp_consulta(arv1,find);

    printf("\n%d", result->info);
}
