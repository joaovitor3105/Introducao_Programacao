#include <stdio.h>
#include <string.h>

#define TAM 100

int main() {
    char frase[TAM] = {0};
    char frase2[TAM * 2] = {0};

    printf("Digite uma frase: ");
    fgets(frase, TAM, stdin);
    frase[strcspn(frase, "\n")] = '\0'; 

    int size = strlen(frase);
    int j = 0;

    for (int i = 0; i < size; i++) {
        if (strncmp(&frase[i], "aluno", 5) == 0) {
            strcpy(&frase2[j], "estudante");
            j += 9; 
            i += 4; 
        } else if (strncmp(&frase[i], "escola", 6) == 0) {
            strcpy(&frase2[j], "universidade");
            j += 12; 
            i += 5; 
        } else {
            frase2[j++] = frase[i]; 
        }
    }

    frase2[j] = '\0'; 

    printf("Sua frase modificada é: %s\n", frase2);

    return 0;
}
