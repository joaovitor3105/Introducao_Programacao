#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 100


char maiusculo(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char nome_arquivo[TAM];
    char leitura[TAM];
    FILE *fp;

   
    printf("Digite o nome do arquivo para salvar os nomes: ");
    fgets(nome_arquivo, TAM, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0'; 

    
    fp = fopen(nome_arquivo, "w");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Insira nomes ou SAIR para encerrar:\n");
    while (1) {
        fgets(leitura, TAM, stdin);
        leitura[strcspn(leitura, "\n")] = '\0';

        if (strcmp(leitura, "SAIR") == 0) {
            break;
        } else {
            fputs(leitura, fp);
            fputs("\n", fp); 
        }
    }
    fclose(fp);

    
    char nome_arquivo_maiusculo[TAM];
    snprintf(nome_arquivo_maiusculo, TAM, "%s_MAIUSCULO", nome_arquivo);

  
    fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    
    FILE *fp_maiusculo = fopen(nome_arquivo_maiusculo, "w");
    if (fp_maiusculo == NULL) {
        perror("Erro ao abrir o arquivo");
        fclose(fp);
        return 1;
    }

    
    while (fgets(leitura, TAM, fp) != NULL) {
        leitura[strcspn(leitura, "\n")] = '\0'; 
        maiusculo(leitura);
        fputs(leitura, fp_maiusculo);
        fputs("\n", fp_maiusculo);
    }

    fclose(fp);
    fclose(fp_maiusculo);

    
    fp_maiusculo = fopen(nome_arquivo_maiusculo, "r");
    if (fp_maiusculo == NULL) {
        perror("Erro ao abrir o arquivo em maiúsculas");
        return 1;
    }

    printf("Conteúdo do arquivo em maiúsculas:\n");
    while (fgets(leitura, TAM, fp_maiusculo) != NULL) {
        printf("%s", leitura);
    }

    fclose(fp_maiusculo);
    return 0;
}
