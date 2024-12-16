#ifndef LISTA_H
#define LISTA_H
#define TAM 100
#include <stdbool.h>
typedef struct {
    double cpf;
    char nome[TAM];
    bool prioridade;
} pessoa;

struct Nodo {
pessoa info;
struct Nodo *prox;
};
struct ListaSimplesEnc {
struct Nodo *prim;
};
void criarLista(struct ListaSimplesEnc *pList);
void mostrarLista(struct ListaSimplesEnc *pList);
int inserirfim(struct ListaSimplesEnc *pList, pessoa nova_pessoa);
int inserirPri(struct ListaSimplesEnc *pList, pessoa nova_pessoa);
int removerIni(struct ListaSimplesEnc *pList);
int estaVazia(struct ListaSimplesEnc *pList);
int removerqualquer(struct ListaSimplesEnc *pList,double cpf);
#endif