#include "ldec.h"
#include "RNG.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cria um novo nó a ser inserido em uma LDEC
ldec_No* ldec_criaNo(void)
{
    ldec_No* novo = (ldec_No*)malloc(sizeof(ldec_No));
    return novo;
}

// Insere um nó ao fim de uma LDEC
ldec_No* ldec_insereFim(ldec_No* ptInit, int elem)
{
    ldec_No* ptaux;

    ldec_No* novo_no = ldec_criaNo();
    novo_no->num = elem;

    if(ptInit == NULL)//se lista estiver vazia
    {
        novo_no->prox = novo_no;
        novo_no->ant = novo_no;
        ptInit = novo_no;
    }
    else //se lista estiver cheia
    {
        ptaux = ptInit;

        do
        {
            ptaux = ptaux->prox;
        } while(ptaux->prox != ptInit);

		// Chegou no final da lista
		novo_no->prox = ptInit;
        novo_no->ant  = ptaux;
        ptaux->prox   = novo_no;
        ptInit->ant   = novo_no;
    }

    return ptInit;
}

// Consulta um valor int em uma LDEC
void ldec_busca(ldec_No* ptInit, int elem)
{
    ldec_No *ptauxInit = ptInit,
    	   *ptauxFim  = ptInit->ant;

	// A pesquisa é feita do início ao fim e do fim ao início
	//   para dividir o processo
	while(1)
	{
		if(ptauxInit->num == elem)
		{
			printf("\nElem: %d",ptauxInit->num);
			return;
		}
		if(ptauxInit->prox == ptauxFim)
			break;
		else
			ptauxInit = ptauxInit->prox;
		
		if(ptauxFim->num == elem)
		{
			printf("\nElem: %d",ptauxFim->num);
			return;
		}
		if(ptauxFim->ant == ptauxInit)
			break;
		else
			ptauxFim = ptauxFim->ant;
    }
    printf("\nElemento não encontrado!\n");
}

// Imprime os valores dos nós de uma LDEC a partir de seu início
void ldec_imprimir(ldec_No* ptInit)
{
    ldec_No* ptaux;
    if (ptInit == NULL)
        printf("\n Lista vazia! \n");
    else
    {
        ptaux = ptInit;
        do{
            printf("%d-> ",ptaux->num);
            ptaux=ptaux->prox;
        } while(ptaux!=ptInit); // Se o valor que usamos para percorrer
                                // a lista chegar no valor inicial,
                                // terminamos o loop
    }
}


// Teste das funções LDEC.
// Para isso:
//
// >> gcc ldec.c -o LDEC
// >> ./LDEC

int main()
{
    ldec_No* lista=NULL;
    int num,x,i, elem;
    char resp;

    srand(time(NULL));

    for(i=0; i<1000000; i++)
    {
        num = gera_aleatorio();
        lista = ldec_insereFim(lista,num);
    }

    printf("Lista:");
    ldec_imprimir(lista);

    printf("\n\nDigite o valor de procura:");
    scanf("%d",&elem);

    ldec_busca(lista,elem);

}
