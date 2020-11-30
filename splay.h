#ifndef _SPLAY_H_
#define _SPLAY_H

// Definimos a estrutura de uma árvore Splay
struct SplayTree
{
    int key;
    struct SplayTree *pai;
    struct SplayTree *esq;
    struct SplayTree *dir;
};

// Renomeamos a estrutura para simplificar o código
typedef struct SplayTree splay_PtNodo;
// ======= FUNÇÕES ======= //

// Cria um novo nodo a ser inserido em uma Splay
splay_PtNodo* splay_novoNodo(int key);

// Função para buscar uma certa chave em uma Splay
// OBS.: Usada na função splay_insere()
splay_PtNodo* splay_buscaInsere(splay_PtNodo* raiz, int key);

// Função para buscar uma certa chave em uma Splay
// OBS.: Usada na função splay_consulta()
splay_PtNodo* splay_buscaConsulta(splay_PtNodo* raiz, int key);

// Função para movimentação de um nodo dentro de uma Splay
splay_PtNodo* splay_splay(splay_PtNodo* nodo);

// Insere um nodo em uma Splay
splay_PtNodo* splay_insere(splay_PtNodo* raiz, int key);

// Consulta um valor int em uma árvore Splay
splay_PtNodo* splay_consulta(splay_PtNodo* raiz, int key);

#endif
