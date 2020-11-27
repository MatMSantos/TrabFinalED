#include "lde.h"
#include "RNG.h"

// Cria um novo nó a ser inserido em uma LDEC
lde_No* lde_criaNo(void)
{
    lde_No* novo = (lde_No*)malloc(sizeof(lde_No));
    return novo;
}

// Insere um nó ao fim de uma LDEC
lde_No* lde_insereFim(lde_No* ptInit, int elem)
{
    lde_No* ptaux;

    lde_No* novo_no = lde_criaNo();
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
void lde_busca(lde_No* ptInit, int elem)
{
    lde_No *ptauxInit = ptInit,
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
void lde_imprimir(lde_No* ptInit)
{
    lde_No* ptaux;
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

/*

// Teste das funções LDEC.
// Para isso:
//
// >> gcc lde.c -o LDEC
// >> ./LDEC

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
*/
