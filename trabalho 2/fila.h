#ifndef FILA_H
#define FILA_H
#define Num_Caixas 5
typedef struct
{
    long long CPF;
    char nome[101];
    // 1-representa alta prioridade 2-prioridade média 3-baixa prioridade
    int prioridade;
    int itens;
} cliente;

typedef struct
{
    int num;
    // estado 0-aberto e 1-fechado
    int estado;
} caixa;

typedef struct nodofila
{
    cliente info;
    struct nodofila *prox;
} Nodofila;

typedef struct fila
{
    struct nodofila *ini;
    struct nodofila *fim;
} Fila;

void criar_fila(Fila *f);
void enfileirar(Fila *f, cliente novo_cliente);
void desenfileirar(Fila *f);
void mostrar_fila(Fila *f);
int fila_vazia(Fila *f);
void fechar_caixa(Fila *f, Fila *f2);
int contar_fila(Fila *f);
int todas_filas_vazias(int num_caixas, Fila *caixa[]);
#endif
