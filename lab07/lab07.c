#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"
#define TAM 100 
int main()
    {pessoa pessoas;
    struct ListaSimplesEnc minhaLista;
    int  op;
    int quantidadeatual;
    criarLista(&minhaLista);
    double cpf_remover;
    
while (1)
    {
        printf("1 - Cadastrar Pessoa\n");
        printf("2 - Cadastrar Pessoa com prioridade\n");
        printf("3 - Remover primeira pessoa\n");
        printf("4 - Remover alguma pessoa\n");
        printf("5 - Mostrar lista\n");
        printf("6 - Verificar se a lista esta vazia\n");
        printf("7 - Sair\n");
        printf("Opcao? ");
        scanf("%d", &op);
        getchar(); // Limpar o buffer após o scanf
        switch (op)

        {
case 1: // inserir elemento no final
            printf("\ncpf: ");
            scanf("%lf",&pessoas.cpf);
            getchar(); // Limpar o buffer após o scanf
            printf("\nNome: ");
            fgets(pessoas.nome,TAM,stdin);
            pessoas.nome[strcspn(pessoas.nome, "\n")] = '\0';
            quantidadeatual = inserirfim(&minhaLista, pessoas);
            printf("\nTotal de pessoas na lista: %d\n", quantidadeatual); 
            break; 
                                                    
case 2: // remover o primeiro NO
            printf("\ncpf: ");
            scanf("%lf",&pessoas.cpf);
            getchar(); // Limpar o buffer após o scanf
            printf("\nNome: ");
            fgets(pessoas.nome,TAM,stdin);
            pessoas.nome[strcspn(pessoas.nome, "\n")] = '\0';
            quantidadeatual=inserirPri(&minhaLista,pessoas);  
            break;
            
case 3: // remover o primeiro NO
           quantidadeatual= removerIni(&minhaLista);
           printf("\nTotal de pessoas que restam na lista: %d\n", quantidadeatual); 
           break;

case 4: // remover determinado elemento          
          printf("\nDigite o cpf a ser removido:");
          scanf("%lf",&cpf_remover);  
          quantidadeatual=removerqualquer(&minhaLista,cpf_remover);
            if(quantidadeatual>=0){
                printf("\nPessoas restantes na lista: %d\n", quantidadeatual);
          }  
            break;

case 5: // mostrar lista
            if (estaVazia(&minhaLista))
                printf("\nlista vazia\n");
                else
                    mostrarLista(&minhaLista);
            break;

case 6: //lista esta vazia
            if (estaVazia(&minhaLista))
                printf("\nlista vazia\n");
                else 
                printf("\nlista não esta vazia\n");
            break;
        
case 7: // abandonar o programa
            exit(0);
            break;
       }
       } return 0;
}