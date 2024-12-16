#include <stdio.h>
#include "fila.h"
int main() { Fila *f = criar_fila(); // Cria uma fila vazia 
int opcao,verificar;
pessoa dado; // Variáveis para armazenar a opção do menu e o dado a ser inserido ou removido
do {printf("Escolha uma opção:\n"); 
printf("1 - Inserir na fila\n"); 
printf("2 - Remover da fila\n"); 
printf("3 - Imprimir a fila\n"); 
printf("4 - verificar se esta vazia\n");
printf("0 - Sair\n"); 
scanf("%d", &opcao);
getchar();
switch (opcao) { 
    case 1: // Inserir na fila
printf("Digite o CPF : ");
    scanf("%11s",&dado.cpf);
    getchar();
printf("Digite o nome : ");
    fgets(dado.nome,50,stdin);

 printf("Possui Prioridade?\n1-sim\n2-nao ");
    scanf("%d",&dado.preferencia);
    getchar();
 enfileirar(f, dado);
 break; 

 
 
 
 
 
 case 2: // Remover da fila 
    dado = desenfileirar(f);
    if (dado.verificador != -1) { 
    printf("Dado removido: %d\n", dado); 
    } 
    else 
    printf("Fila vazia ou nao existente");
    break;
case 3: // Imprimir a fila 
    mostrar_fila(f); 
    break; 
    

break; 
 case 4:
  verificar=fila_vazia(f);
     if( verificar==-1)
     printf("fila nao existe");
     if( verificar==1)
     printf("fila esta vazia");
     else
      printf("fila nao esta vazia");
    break;
case 0: // Sair

 default: // Opção inválida 
    printf("Opção inválida.\n"); 
    break; }
    } while (opcao != 0);
    liberar_fila(f); // Libera a memória da fila 
    }