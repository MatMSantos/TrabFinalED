#include <stdio.h>

// Definimos a estrutura de uma árvore Splay
struct SplayTree
{
    int key;
    PtNodo* esq;
    PtNodo* dir;
};

// Renomeamos a estrutura para simplificar o código
typedef struct SplayTree PtNodo;

// ======= FUNÇÕES ======= //

// Cria um novo nodo a ser inserido em uma Splay
PtNodo* Novo(int key, PtNodo* esq, PtNodo* dir);

// Funções para movimento dos nodos dentro de uma Splay:
//
// Rotação de um nodo à esquerda
PtNodo* RotEsq(PtNodo* t);
// Rotação de um nodo à direita
PtNodo* RotDir(PtNodo* t);

// Insere um nodo em uma Splay
PtNodo* Splay(PtNodo* t, int key);
// Insere um nodo em uma Splay
// COMENTÁRIO: Função inútil, talvez eu esteja enganado.
// 	Ela só retorna o que for repassado pra função Splay.
PtNodo* Insere(int key, PtNodo* t);
// Consulta um valor int em uma árvore Splay
PtNodo* ConsultaSplay(PtNodo* t, int key);
// Consulta um valor int em uma árvore Splay
// 	+ captura a exceção no caso de árvore vazia
PtNodo* Consulta(PtNodo* t, int key);
// Imprime os valores dos nodos de uma árvore Splay
void Desenha(PtNodo* t, int nivel);
