#ifndef PILHA_H
#define PILHA_H
struct ListaSimplesEnc;
#include "lista.h"

typedef struct
{
    int ID;
    char titulo[101];
    struct ListaSimplesEnc *autores;
} documento;

struct Nodo
{
    documento info;
    struct Nodo *prox;
};
struct Pilha
{
    struct Nodo *topo;
};
void criarPilha(struct Pilha *pilha);
void empilhar(struct Pilha *pilha, documento valor);
int desempilhar(struct Pilha *pilha);
int mostrarTopo(struct Pilha *pilha);
int EstaVazia(struct Pilha *pilha);
void SalvarPilha(struct Pilha *pilha, const char *nome_arq);
void LerPilha(struct Pilha *pilha, const char *nome_arq);
#endif