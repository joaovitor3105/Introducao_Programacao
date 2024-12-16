#include <stdlib.h>
#include <stdio.h>
#include "FILA.H"

int main()
{
    int Opcao;
    cliente novo_cliente;
    int num;
    Fila caixas[Num_Caixas];
    caixa info_caixas[5];
    Fila f;
    int caixa_destino;

    // iniciando todos caixas abertos
    for (int i = 0; i < Num_Caixas; i++)
    {
        info_caixas[i].estado = 0;
    }

    // criando os fila dos caixas
    Fila *caixa[Num_Caixas];
    for (int i = 0; i < Num_Caixas; i++)
    {
        caixa[i] = (Fila *)malloc(sizeof(Fila));
        criar_fila(caixa[i]);
        printf("Fila %d criada e inicializada.\n", i + 1);
    }

    // MENU
    while (1)
    {
        int caixa_valido = 0;
        printf("                   MENU\n");
        printf("----------------------------------------------\n");
        printf("  1-Cadastrar Cliente\n");
        printf("  2-Atender Cliente\n");
        printf("  3-Abrir e Fechar Caixa\n");
        printf("  4-Imprimir a Lista de Clientes em Espera\n");
        printf("  5-Imprimir o Status dos Caixas\n");
        printf("  0-Sair\n");
        printf("----------------------------------------------\n");
        printf("          Digite a Opçao Desejada:\n");

        scanf("%d", &Opcao);
        while (getchar() != '\n')
            ;

        switch (Opcao)
        {
        case 1:

            printf("Digite o CPF do cliente:\n");
            scanf("%lld", &novo_cliente.CPF);
            while (getchar() != '\n')
                ;
            printf("Digite quantos itens no carrinho:\n");
            scanf("%d", &novo_cliente.itens);

            novo_cliente.prioridade = 0;
            while (getchar() != '\n')
                ;
            while (novo_cliente.prioridade > 3 || novo_cliente.prioridade < 1)
            {
                printf("Qual a Prioridade do Cliente:\n");

                printf("\n1-Representa Alta Prioridade 2-Prioridade Média 3-Baixa Prioridade\n");
                scanf("%d", &novo_cliente.prioridade);
                while (getchar() != '\n')
                    ;
                if (novo_cliente.prioridade > 3 || novo_cliente.prioridade < 1)
                {
                    printf("\nVoce digitou algum valor de prioridade inexistente\n");
                }
            }

            printf("Digite o nome do cliente:\n");
            fgets(novo_cliente.nome, 100, stdin);

            printf("Qual caixa que o cliente deseja:\n");

            while (!caixa_valido)
            {
                printf("Caixas Disponiveis:\t\n");
                // loop para mostrar caixas disponiveis
                for (int i = 0; i < Num_Caixas; i++)
                {
                    if (info_caixas[i].estado == 0)
                        printf("%d\t", i + 1);
                }

                scanf("%d", &num);
                if (num >= 1 && num <= Num_Caixas && info_caixas[num - 1].estado == 0)
                {
                    enfileirar(caixa[num - 1], novo_cliente);
                    caixa_valido = 1;
                }
                else
                {
                    printf("\nVoce digitou algum caixa indisponivel ou inexistente\n");
                    caixa_valido = 0;
                }
            }
            while (getchar() != '\n')
                ;

            break;

        case 2:
            if (todas_filas_vazias(Num_Caixas, caixa))
            {
                printf("\nTodas as filas estão vazias nenhum cliente para atender no momento.\n");
                break;
            }
            while (!caixa_valido)
            {
                printf("Caixas Disponiveis:\t\n");
                for (int i = 0; i < Num_Caixas; i++)
                {
                    if (info_caixas[i].estado == 0)
                    {
                        printf("\nCaixa %d:\n", i + 1);
                        mostrar_fila(caixa[i]);
                    }
                }
                printf("\nQual caixa você vai atender:\n");
                scanf("%d", &num);
                if (num >= 1 && num <= Num_Caixas && info_caixas[num - 1].estado == 0)
                {
                    desenfileirar(caixa[num - 1]);
                    caixa_valido = 1;
                }
                else
                {
                    printf("\nVoce digitou algum caixa indisponivel ou inexistente\n");
                    caixa_valido = 0;
                }

                while (getchar() != '\n')
                    ;
            }
            break;
        case 3:
            printf("\nVocê deseja:\n 1-abrir ou 2-fechar um caixa:\n");
            scanf("%d", &num);
            if (num == 2)
            {
                printf("\nCaixas Abertos:\n");
                for (int i = 0; i < Num_Caixas; i++)
                {
                    if (info_caixas[i].estado == 0)
                    {
                        printf("\n%d\t", i + 1);
                    }
                }
                printf("\nQual deseja fechar:\n");
                scanf("%d", &num);
                if (info_caixas[num - 1].estado != 0)
                {
                    printf("Caixa nao disponivel\n");
                    break;
                }

                else

                    printf("\nPara onde deseja mover a fila:");

                printf("\nCaixas Abertos:");
                for (int i = 0; i < Num_Caixas; i++)
                {
                    if (info_caixas[i].estado == 0 || i != num)
                    {
                        printf("\n%d\t", i + 1);
                    }
                }
                scanf("%d", &caixa_destino);
                if (info_caixas[caixa_destino - 1].estado != 0)
                {
                    printf("Caixa nao disponivel\n");
                    break;
                }

                else

                    fechar_caixa(caixa[num - 1], caixa[caixa_destino - 1]);
                info_caixas[num - 1].estado = 1;
                break;
            }

            if (num == 1)
            {
                printf("\nCaixas Fechados:");
                for (int i = 0; i < Num_Caixas; i++)
                {
                    if (info_caixas[i].estado == 1)
                    {
                        printf("\n%d\t", i + 1);
                    }
                }
                printf("\nQual deseja abrir:");
                scanf("%d", &num);
                if (info_caixas[num - 1].estado != 1)
                {
                    printf("\nCaixa nao disponivel\n");

                    break;
                }

                else
                    info_caixas[num - 1].estado = 0;
                printf("\nCaixa aberto com sucesso\n");
            }
            break;
        case 4:
            for (int i = 0; i < Num_Caixas; i++)
            {
                if (info_caixas[i].estado == 0)
                {
                    printf("\nCaixa %d:\n", i + 1);
                    mostrar_fila(caixa[i]);
                }
            }
            break;
        case 5:
            for (int i = 0; i < Num_Caixas; i++)
            {
                if (info_caixas[i].estado == 0)
                {
                    printf("\nCaixa %d Aberto:\n%d clientes\n", i + 1, contar_fila(caixa[i]));
                }
                if (info_caixas[i].estado == 1)
                {
                    printf("\nCaixa %d Fechado:\n%d clientes\n", i + 1, contar_fila(caixa[i]));
                }
            }
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Digite um valor disponivel");
            break;
        }
    }
}