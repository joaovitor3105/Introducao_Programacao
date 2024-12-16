#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
void criarPilha(struct Pilha *pilha)
{
    pilha->topo = NULL;
}

void empilhar(struct Pilha *pilha, documento valor)
{
    struct Nodo *novo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (novo == NULL)
    {
        printf("Memória insuficiente.\n");
        return;
    }
    novo->info = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(struct Pilha *pilha)
{
    if (EstaVazia(pilha))
    {
        printf("Pilha vazia.\n");
        return -1; // Retornar -1 ou outro valor específico quando a pilha está vazia.
    }
    documento valor = pilha->topo->info;
    struct Nodo *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
    return 0;
}

int mostrarTopo(struct Pilha *pilha)
{
    if (EstaVazia(pilha))
    {
        printf("Pilha vazia.\n");
        return -1;
    }
    documento valor = pilha->topo->info;
    printf("Topo:\nID: %d\nTitulo%s\n", valor.ID, valor.titulo);
}

int EstaVazia(struct Pilha *pilha)
{
    return (pilha->topo == NULL);
}

void SalvarPilha(struct Pilha *pilha, const char *nome_arq)
{
    FILE *fp = fopen(nome_arq, "wb");
    if (fp == NULL)
    {
        perror("Falha ao abrir arquivo");
        return;
    }

    struct Nodo *atual = pilha->topo;
    while (atual != NULL)
    {
        fwrite(&atual->info.ID, sizeof(int), 1, fp);
        fwrite(atual->info.titulo, sizeof(char), 101, fp);

        ListaSimplesEnc *autores = atual->info.autores;
        if (autores == NULL)
        {
            int autorCount = 0;
            fwrite(&autorCount, sizeof(int), 1, fp);
        }
        else
        {
            struct NodoLista *autorAtual = autores->prim;
            int autorCount = 0;
            while (autorAtual != NULL)
            {
                autorCount++;
                autorAtual = autorAtual->prox;
            }
            fwrite(&autorCount, sizeof(int), 1, fp);

            autorAtual = autores->prim;
            while (autorAtual != NULL)
            {
                fwrite(&autorAtual->info, sizeof(autor), 1, fp);
                autorAtual = autorAtual->prox;
            }
        }

        atual = atual->prox;
    }

    fclose(fp);
}

void LerPilha(struct Pilha *pilha, const char *nome_arq)
{
    FILE *fp = fopen(nome_arq, "rb");
    if (fp == NULL)
    {
        perror("Falha ao abrir arquivo");
        return;
    }

    while (1)
    {
        documento doc;
        size_t result;

        result = fread(&doc.ID, sizeof(int), 1, fp);
        if (result != 1)
            break;

        result = fread(doc.titulo, sizeof(char), 101, fp);
        if (result != 101)
            break;

        doc.autores = (ListaSimplesEnc *)malloc(sizeof(ListaSimplesEnc));
        criarLista(doc.autores);

        int autorCount;
        result = fread(&autorCount, sizeof(int), 1, fp);
        if (result != 1)
            break;

        for (int i = 0; i < autorCount; i++)
        {
            autor a;
            result = fread(&a, sizeof(autor), 1, fp);
            if (result != 1)
                break;

            inserirIni(doc.autores, a);
        }

        empilhar(pilha, doc);
    }

    fclose(fp);
}
