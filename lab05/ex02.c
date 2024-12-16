
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 100
#define colunas 100
int main()
{
     char frases[colunas][TAM];
     char nome_arquivo[TAM];
     FILE *fp;
 printf("Digite o nome do arquivo para salvar os dados: ");
    fgets(nome_arquivo, TAM, stdin);
   nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0'; 
      fp = fopen(nome_arquivo, "w");

    if (fp == NULL) {
        perror("Erro ao abrir o arquivo ");
        return 1;}
          int i=0;
           printf("Digite até 20 frases digite FIM para encerrar:\n");
           while(i<colunas){
            fgets(frases[i], TAM, stdin);
        frases[i][strcspn(frases[i], "\n")] = '\0';
          if (strcmp(frases[i], "FIM") == 0) 
            {
            break;
            }
           fprintf(fp, "%s\n", frases[i]);
        i++;
    }
    fclose(fp);
           
           
            fp = fopen(nome_arquivo, "r");
            if (fp == NULL) {
        perror("Erro ao abrir o arquivo ");
        return 1;}
        i=0;
        while (fgets(frases[i], TAM, fp) && i< colunas) 
    {
        frases[i][strcspn(frases[i], "\n")] = '\0';
        i++;
    }
    fclose(fp);
    char palavra[TAM];
    printf("Digite uma palavra para achar: ");
    fgets(palavra, TAM, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';
      printf("Linhas contendo '%s':\n", palavra);
    for (int j = 0; j < i; j++) 
    {
        if (strstr(frases[j], palavra)) 
        {
            printf("Linha %d: %s\n", j + 1, frases[j]);
        }
    }
    return 0;
}
