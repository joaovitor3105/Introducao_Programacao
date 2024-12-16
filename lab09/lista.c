#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void criarLista(ListaSimplesEnc *pList)
{
    pList->prim = NULL;
}

void mostrarLista(ListaSimplesEnc *pList)
{
    NodoLista *p;
    for (p = pList->prim; p != NULL; p = p->prox)
    {
        printf("ID: %d\n", p->info.ID);
        printf("Nome: %s\n", p->info.nome);
    }
    printf("\n");
}

int inserirIni(ListaSimplesEnc *pList, autor novo_autor)
{
    NodoLista *novo = (NodoLista *)malloc(sizeof(NodoLista));
    if (novo == NULL)
    {
        printf("Memória insuficiente.\n");
        return -1;
    }
    novo->info = novo_autor;
    novo->prox = pList->prim;
    pList->prim = novo;
    return 0;
}

int removerIni(ListaSimplesEnc *pList)
{
    if (FilaVazia(pList))
    {
        printf("Lista vazia.\n");
        return -1;
    }
    NodoLista *pAux = pList->prim;
    pList->prim = pList->prim->prox;
    free(pAux);
    return 0;
}

int FilaVazia(ListaSimplesEnc *pList)
{
    return (pList->prim == NULL);
}
