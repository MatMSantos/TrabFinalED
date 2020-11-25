#include "splay.h"

// Cria um novo nodo a ser inserido em uma Splay
PtNodo* Novo(int key, PtNodo* esq, PtNodo* dir)
{
    PtNodo* x = (PtNodo*) malloc(sizeof(PtNodo));
    x->key = key;
    x->esq = esq;
    x->dir = dir;
    return x;
}

// Funções para movimento dos nodos dentro de uma Splay:
//
// Rotação de um nodo à esquerda
PtNodo* RotEsq(PtNodo* t)
{
    PtNodo* x = t->dir;
    t->dir = x->esq;
    x->esq = t;
    return x;
}
// Rotação de um nodo à direita
PtNodo* RotDir(PtNodo* t)
{
    PtNodo* x = t->esq;
    t->esq = x->dir;
    x->dir = t;
    return x;
}

// Insere um nodo em uma Splay
PtNodo* insereSplay(PtNodo* t, int key)
{
    if (t == NULL)
        return Novo(key, NULL, NULL);
    if (key < t->key)
    {
        if (t->esq == NULL)
            return Novo(key, NULL, t);
        if (key < t->esq->key)
        {
            t->esq->esq = insereSplay(t->esq->esq, key);
            t = RotDir(t);
        }
        else
        {
            t->esq->dir = insereSplay(t->esq->dir, key);
            t->esq = RotEsq(t->esq);
        }
        return RotDir(t);
    }
    else
    {
        if (t->dir == NULL)
            return Novo(key, t, NULL);
        if (t->dir->key < key)
        {
            t->dir->dir = insereSplay(t->dir->dir, key);
            t = RotEsq(t);
        }
        else
        {
            t->dir->esq = insereSplay(t->dir->esq, key);
            t->dir = RotDir(t->dir);
        }
        return RotEsq(t);
    }
}
// Consulta um valor int em uma árvore Splay
PtNodo* ConsultaSplay(PtNodo* t, int key)
{
    if (t == NULL)
        return NULL;
    if (key < t->key)
    {
        if (t->esq == NULL)
            return t;
        if (key < t->esq->key)
        {
            t->esq->esq = ConsultaSplay(t->esq->esq, key);
            t = RotDir(t);
            if (t->esq == NULL)
                return t;
            else
                return RotDir(t);
        }
        else if (t->esq->key, key)
        {
            t->esq->dir = ConsultaSplay(t->esq->dir, key);
            if (t->esq->dir != NULL)
                t->esq = RotEsq(t->esq);
            return RotDir(t);
        }
        else
            return RotDir(t);
    }
    else if(t->key < key)
    {
        if (t->dir == NULL)
            return t;
        if (t->dir->key < key)
        {
            t->dir->dir = ConsultaSplay(t->dir->dir, key);
            t = RotEsq(t);
            if (t->dir == NULL)
                return t;
            else
                return RotEsq(t);
        }
        else if (key < t->dir->key)
        {
            t->dir->esq = ConsultaSplay(t->dir->esq, key);
            if (t->dir->esq != NULL)
                t->dir = RotDir(t->dir);
            return RotEsq(t);
        }
        else
            return RotEsq(t);
    }
    else
        return t;
}
// Consulta um valor int em uma árvore Splay
// 	+ captura a exceção no caso de árvore vazia
PtNodo* Consulta(PtNodo* t, int key)
{
    if (t == NULL)
        return NULL;
    t = ConsultaSplay(t, key);
    return t;
}
// Imprime os valores dos nodos de uma árvore Splay
void Desenha(PtNodo* t, int nivel)
{
    int x;
    if (t !=NULL)
    {
        for (x=1; x<=nivel; x++)
            printf("=");
        printf("%d \n", t->key);
        if (t->esq != NULL)
            Desenha(t->esq, (nivel+1));
        if (t->dir != NULL)
            Desenha(t->dir, (nivel+1));
    }
    else
        printf("Arvore Vazia");
}

// Teste das funções Splay.
// Para isso:
//
// >> gcc splay.c -o SPLAY
// >> ./SPLAY

int main(int argc, char *argv[])
{

    PtNodo* arv = NULL;
    arv = insereSplay(arv,30);
    arv = insereSplay(10,arv);
    arv = insereSplay(20,arv);
    Desenha(arv,0);
    arv =  Consulta(arv, 40);
    Desenha(arv,0);
}
