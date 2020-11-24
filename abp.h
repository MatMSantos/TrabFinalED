#include <stdio.h>

// Definimos o tipo de informação contida nos nodos
typedef int tipoinfo;

// Definimos um nodo
struct TNodoA
{
    tipoinfo info;
    struct TNodoA *esq;
    struct TNodoA *dir;
};

// Renomeamos a estrutura para simplificar o código
typedef struct TNodoA pNodoA;

// ======= FUNÇÕES ======= //

// Função que gera um número aleatório
tipoinfo gera_aleatorio(void);
// COMENTÁRIO: É provável que eu deixe a função de gerar números aleatórios
// em um arquivo separado

// Funções para ABP
//
// Insere um nodo em uma ABP
pNodoA* InsereArvore(pNodoA *a, tipoinfo ch);
// Consulta um valor de tipoinfo em uma ABP
pNodoA* consultaABP(pNodoA *a, tipoinfo chave);
// Imprime os valores dos nodos de uma ABP em um caminhamento Pré-Fixado
// à esquerda
void preFixadoE(pNodoA *a);
