#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>

typedef struct
{
    int ID;
    char nome[101];
} autor;

typedef struct NodoLista
{
    autor info;
    struct NodoLista *prox;
} NodoLista;

typedef struct ListaSimplesEnc
{
    NodoLista *prim;
} ListaSimplesEnc;

void criarLista(ListaSimplesEnc *pList);
void mostrarLista(ListaSimplesEnc *pList);
int inserirfim(ListaSimplesEnc *pList, autor novo_autor);
int inserirIni(ListaSimplesEnc *pList, autor novo_autor);
int removerIni(ListaSimplesEnc *pList);
int FilaVazia(ListaSimplesEnc *pList);

#endif
