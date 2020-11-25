#include "splay.h"

// Cria um novo nodo a ser inserido em uma Splay
splay_PtNodo* splay_novo(int key, splay_PtNodo* esq, splay_PtNodo* dir)
{
    splay_PtNodo* x = (splay_PtNodo*) malloc(sizeof(splay_PtNodo));
    x->key = key;
    x->esq = esq;
    x->dir = dir;
    return x;
}

// Funções para movimento dos nodos dentro de uma Splay:
//
// Rotação de um nodo à esquerda
splay_PtNodo* splay_rotEsq(splay_PtNodo* t)
{
    splay_PtNodo* x = t->dir;
    t->dir = x->esq;
    x->esq = t;
    return x;
}
// Rotação de um nodo à direita
splay_PtNodo* splay_rotDir(splay_PtNodo* t)
{
    splay_PtNodo* x = t->esq;
    t->esq = x->dir;
    x->dir = t;
    return x;
}

// Insere um nodo em uma Splay (recursão)
splay_PtNodo* splay_insereR(splay_PtNodo* t, int key)
{
    if (t == NULL)
        return splay_novo(key, NULL, NULL);
    if (key < t->key)
    {
        if (t->esq == NULL)
            return splay_novo(key, NULL, t);
        if (key < t->esq->key)
        {
            t->esq->esq = splay_insereR(t->esq->esq, key);
            t = splay_rotDir(t);
        }
        else
        {
            t->esq->dir = splay_insereR(t->esq->dir, key);
            t->esq = splay_rotEsq(t->esq);
        }
        return splay_rotDir(t);
    }
    else
    {
        if (t->dir == NULL)
            return splay_novo(key, t, NULL);
        if (t->dir->key < key)
        {
            t->dir->dir = splay_insereR(t->dir->dir, key);
            t = splay_rotEsq(t);
        }
        else
        {
            t->dir->esq = splay_insereR(t->dir->esq, key);
            t->dir = splay_rotDir(t->dir);
        }
        return splay_rotEsq(t);
    }
}
// Insere um nodo em uma Splay
PtNodo* splay_insere(int key, splay_PtNodo* t)
{
    return splay_insereR(t,key);
}
// Consulta um valor int em uma árvore Splay
splay_PtNodo* splay_consulta(splay_PtNodo* t, int key)
{
    if (t == NULL)
        return NULL;
    if (key < t->key)
    {
        if (t->esq == NULL)
            return t;
        if (key < t->esq->key)
        {
            t->esq->esq = splay_consulta(t->esq->esq, key);
            t = splay_rotDir(t);
            if (t->esq == NULL)
                return t;
            else
                return splay_rotDir(t);
        }
        else if (t->esq->key, key)
        {
            t->esq->dir = splay_consulta(t->esq->dir, key);
            if (t->esq->dir != NULL)
                t->esq = splay_rotEsq(t->esq);
            return splay_rotDir(t);
        }
        else
            return splay_rotDir(t);
    }
    else if(t->key < key)
    {
        if (t->dir == NULL)
            return t;
        if (t->dir->key < key)
        {
            t->dir->dir = splay_consulta(t->dir->dir, key);
            t = splay_rotEsq(t);
            if (t->dir == NULL)
                return t;
            else
                return splay_rotEsq(t);
        }
        else if (key < t->dir->key)
        {
            t->dir->esq = splay_consulta(t->dir->esq, key);
            if (t->dir->esq != NULL)
                t->dir = splay_rotDir(t->dir);
            return splay_rotEsq(t);
        }
        else
            return splay_rotEsq(t);
    }
    else
        return t;
}
// Consulta um valor int em uma árvore Splay
// 	+ captura a exceção no caso de árvore vazia
splay_PtNodo* splay_consulta(splay_PtNodo* t, int key)
{
    if (t == NULL)
        return NULL;
    t = splay_consulta(t, key);
    return t;
}
// Imprime os valores dos nodos de uma árvore Splay
void splay_desenha(splay_PtNodo* t, int nivel)
{
    int x;
    if (t !=NULL)
    {
        for (x=1; x<=nivel; x++)
            printf("=");
        printf("%d \n", t->key);
        if (t->esq != NULL)
            slay_desenha(t->esq, (nivel+1));
        if (t->dir != NULL)
            splay_desenha(t->dir, (nivel+1));
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

    splay_PtNodo* arv = NULL;
    arv = splay_insere(arv,30);
    arv = splay_insere(10,arv);
    arv = splay_insere(20,arv);
    splay_desenha(arv,0);
    arv =  splay_consulta(arv, 40);
    splay_desenha(arv,0);
}
