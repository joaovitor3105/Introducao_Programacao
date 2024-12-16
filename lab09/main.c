#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "lista.h"
int main()
{
    struct Pilha minhaPilha;

    int valor, opcao;
    criarPilha(&minhaPilha);
    autor autor;
    char nome_arq[100];

    documento doc;

    while (1)
    {
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Mostrar topo\n");
        printf("4 - Verificar se está vazia\n");
        printf("5 - Salvar pilha\n");
        printf("6 - Carregar pilha salva\n");
        printf("7 - Sair\n");
        printf("Opção? ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            printf("\nID do documento:\n ");
            scanf("%d", &doc.ID);
            getchar();
            printf("\nQual o titulo do documento:\n");
            fgets(doc.titulo, 100, stdin);
            doc.autores = (ListaSimplesEnc *)malloc(sizeof(ListaSimplesEnc));
            criarLista(doc.autores);
            for (int cont = 0; cont == 0;)
            {
                printf("\nDigite o nome do autor:\n ");
                fgets(autor.nome, 100, stdin);
                printf("\nDigite o ID do autor:\n ");
                scanf("%d", &autor.ID);
                getchar();
                inserirIni(doc.autores, autor);
                printf("\nTem mais autores:\n0-sim\n1-nao");
                scanf("%d", &cont);
                getchar();
            }

            empilhar(&minhaPilha, doc);
            break;

        case 2:
            valor = desempilhar(&minhaPilha);
            if (valor != -1)
            {
                printf("Desempilhado:\nID: %d\nTitulo%s\n", doc.ID, doc.titulo);
            }
            break;
        case 3:
            valor = mostrarTopo(&minhaPilha);
            if (valor != -1)
            {
                printf("Topo:\nID: %d\nTitulo:%s\n", doc.ID, doc.titulo);
            }
            break;
        case 4:
            if (EstaVazia(&minhaPilha))
            {
                printf("Pilha vazia\n");
            }
            else
            {
                printf("Pilha não está vazia\n");
            }
            break;
        case 5:

            printf("Digite o nome do arquivo a ser salvo");
            fgets(nome_arq, 100, stdin);
            nome_arq[strcspn(nome_arq, "\n")] = '\0';
            SalvarPilha(&minhaPilha, nome_arq);
            break;
        case 6:

            printf("Digite o nome do arquivo a ser lido");
            fgets(nome_arq, 100, stdin);
            nome_arq[strcspn(nome_arq, "\n")] = '\0';

            LerPilha(&minhaPilha, nome_arq);

            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}