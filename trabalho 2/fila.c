#include <stdlib.h>
#include <stdio.h>
#include "FILA.H"

void criar_fila(Fila *f)
{
    f->ini = NULL;
    f->fim = NULL;
}

int fila_vazia(Fila *f)
{
    return (f->ini == NULL);
}

void enfileirar(Fila *f, cliente novo_cliente)
{
    Nodofila *atual = f->ini;
    Nodofila *anterior = NULL;

    if (f != NULL)
    {
        Nodofila *novo = (Nodofila *)malloc(sizeof(Nodofila));
        if (novo == NULL)
        {
            printf("Erro na alocação de memória.\n");
            exit(1);
        }

        novo->info = novo_cliente;
        novo->prox = NULL;

        if (fila_vazia(f))
        {
            f->ini = novo;
            f->fim = novo;
        }
        else
        {
            // Inserindo conforme a prioridade
            while (atual != NULL && atual->info.prioridade <= novo_cliente.prioridade)
            {
                anterior = atual;
                atual = atual->prox;
            }

            if (anterior == NULL)
            {
                novo->prox = f->ini;
                f->ini = novo;
            }
            else
            {
                anterior->prox = novo;
                novo->prox = atual;
            }

            if (atual == NULL)
            {
                f->fim = novo;
            }
        }
    }
    printf("\nCliente aguardando na Fila\n");
}

void desenfileirar(Fila *f)
{
    if (fila_vazia(f))
    {
        printf("Fila Vazia");
        return;
    }

    Nodofila *aux = f->ini;
    f->ini = aux->prox;
    free(aux);

    if (f->ini == NULL)
    {
        f->fim = NULL;
    }

    printf("\nCliente retirado da Fila\n");
}

void fechar_caixa(Fila *f, Fila *f2)
{
    cliente dado;
    while (!fila_vazia(f))
    {
        dado = f->ini->info;
        desenfileirar(f);
        enfileirar(f2, dado);
    }
    printf("Caixa fechado com sucesso\n");
}

void mostrar_fila(Fila *f)
{
    if (fila_vazia(f))
    {
        printf("Fila vazia ou não inicializada.\n");
        return;
    }

    Nodofila *aux;
    for (aux = f->ini; aux != NULL; aux = aux->prox)
    {
        printf("Nome: %s", aux->info.nome);
        printf("CPF: %lld\n", aux->info.CPF);
        printf("Quantidade de itens: %d\n", aux->info.itens);
        printf("Prioridade: %d\n\n", aux->info.prioridade);
    }
}

int contar_fila(Fila *f)
{
    int count = 0;
    if (f == NULL)
    {
        return 0;
    }

    Nodofila *aux = f->ini;
    while (aux != NULL)
    {
        count++;
        aux = aux->prox;
    }
    return count;
}

int todas_filas_vazias(int num_caixas, Fila *caixa[])
{
    for (int i = 0; i < num_caixas; i++)
    {
        if (!fila_vazia(caixa[i]))
        {
            return 0;
        }
    }
    return 1;
}