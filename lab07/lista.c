#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"
void criarLista(struct ListaSimplesEnc *pList) {
pList->prim = NULL;
}

void mostrarLista(struct ListaSimplesEnc*pList) {
struct Nodo *p;
    for (p = pList->prim; p != NULL; p = p->prox)
    {
    printf("\nNome: %s\n CPF: %.0lf\n", p->info.nome, p->info.cpf);}
    printf("\n");
    }

int inserirfim(struct ListaSimplesEnc *pList,pessoa nova_pessoa) {
struct Nodo *novo;
novo = (struct Nodo*)malloc(sizeof(struct Nodo));

    if (novo == NULL) {
        printf("\nErro ao alocar memória.\n");}
        novo->info = nova_pessoa;
        novo->prox = NULL;//como e o ultimo então ele aponta para NULL

    if(pList->prim==NULL)
    pList->prim = novo;//se a lista estiver vazia

        else{
        //para percorrer até o ultimo nó
        struct Nodo *p = pList->prim; 
        p=pList->prim;

   while (p->prox!=NULL)
   {
    p=p->prox;
   }
   p->prox=novo;
   } 

  int count = 0;//contar quantas pessoas tem na fila
    struct Nodo *p = pList->prim;
    while (p != NULL) {
        count++;
        p = p->prox;
    }return count;
    
}

int removerIni(struct ListaSimplesEnc *pList) {
    struct Nodo *pAux = pList->prim;
    pList->prim = pList->prim->prox;
    free(pAux);
    int count = 0;//contar quantas pessoas tem na fila
        struct Nodo *p = pList->prim;
        while (p != NULL) {
            count++;
            p = p->prox;
    }return count;
}

int estaVazia(struct ListaSimplesEnc *pList) 
{return (pList->prim == NULL);}

int removerqualquer(struct ListaSimplesEnc *pList,double cpf){

    if(pList->prim==NULL){// Lista vazia
    printf("\nA lista está vazia, não há nada para remover.\n");
        return 0;}

    struct Nodo *atual = pList->prim;
    struct Nodo *anterior = NULL;
    int count = 0;
    //se for o primeiro da lista
    if(atual->info.cpf==cpf){
     return removerIni(pList);
    }

    // Procurar a pessoa na lista
    while (atual != NULL && atual->info.cpf != cpf) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Pessoa com CPF %.0lf não encontrada.\n", cpf);
        return -1; // Indica que a pessoa não foi encontrada
    }
    
    //processo para remoção do nodo
    struct Nodo*aux;
    aux=atual;
    atual=atual->prox;
    anterior->prox=atual;
     free(aux);
     struct Nodo *p = pList->prim;
     //contando quantas pessoas estao na lista
    while (p != NULL) {
        count++;
        p = p->prox;
    }return count;
    }

int inserirPri(struct ListaSimplesEnc *pList,pessoa nova_pessoa){
struct Nodo *novo;
novo = (struct Nodo*)malloc(sizeof(struct Nodo));

    if (novo == NULL) {
        printf("\nErro ao alocar memória.\n");}
    novo->info = nova_pessoa;  
    novo->prox = pList->prim;  // aponta o novo  para o atual primeiro 
    pList->prim = novo;        // faz o novo  ser o primeiro 
    int count = 0;
    struct Nodo *p = pList->prim;
        while (p != NULL) {
            count++;//contar quantas pessoas tem na fila
            p = p->prox;
    }return count;
}




