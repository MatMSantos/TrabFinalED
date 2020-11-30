#ifndef _ABP_H_
#define _ABP_H_

// Definimos o tipo de informação contida nos nodos
typedef int abp_tipoinfo;

// Definimos um nodo
struct TNodoA
{
    abp_tipoinfo info;
    struct TNodoA *esq;
    struct TNodoA *dir;
};

// Renomeamos a estrutura para simplificar o código
typedef struct TNodoA abp_pNodoA;

// ======= FUNÇÕES ======= //

// Cria um novo nodo em uma ABP
abp_pNodoA* abp_novoNodo(abp_tipoinfo ch);
// Insere um nodo em uma ABP
abp_pNodoA* abp_insere(abp_pNodoA *a, abp_tipoinfo ch);
// Consulta um valor de tipoinfo em uma ABP
abp_pNodoA* abp_consulta(abp_pNodoA *a, abp_tipoinfo chave);
// Imprime os valores dos nodos de uma ABP em um caminhamento Pré-Fixado
// à esquerda (NÃO será usada no contexto do trabalho)
void abp_preFixadoE(abp_pNodoA *a);

#endif
