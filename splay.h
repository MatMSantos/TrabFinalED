#include <stdio.h>

// Definimos a estrutura de uma árvore Splay
struct SplayTree
{
    int key;
    splay_PtNodo* esq;
    splay_PtNodo* dir;
};

// Renomeamos a estrutura para simplificar o código
typedef struct SplayTree splay_PtNodo;

// ======= FUNÇÕES ======= //

// Cria um novo nodo a ser inserido em uma Splay
splay_PtNodo* splay_novo(int key, splay_PtNodo* esq, splay_PtNodo* dir);

// Funções para movimento dos nodos dentro de uma Splay:
//
// Rotação de um nodo à esquerda
splay_PtNodo* splay_rotEsq(splay_PtNodo* t);
// Rotação de um nodo à direita
splay_PtNodo* splay_rotDir(splay_PtNodo* t);

// Insere um nodo em uma Splay
splay_PtNodo* splay_insere(splay_PtNodo* t, int key);

// Consulta um valor int em uma árvore Splay (recursão)
splay_PtNodo* splay_consultaR(splay_PtNodo* t, int key);
// Consulta um valor int em uma árvore Splay
splay_PtNodo* splay_consulta(splay_PtNodo* t, int key);
// Imprime os valores dos nodos de uma árvore Splay
void splay_desenha(splay_PtNodo* t, int nivel);
