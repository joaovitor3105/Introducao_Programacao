#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
//função bool da biblioteca <stdbool.h> indica valores boleanos ou seja True==0 ou False!=0
bool verificar_palindromo(char string[]){
int size;
size=strlen(string);
//retirando quebra de linha
string[size]='\0';
//alocar strings auxiliares
char*string_aux=malloc((size+1)*sizeof(char));
char*string_inversa=malloc((size+1)*sizeof(char)); 
//evitando possivel erro de alocação 
 if (string_aux == NULL || string_inversa == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);}
//tornando caracteres minusculos
for (int i = 0; i < size; i++)
{
  string[i]=tolower(string[i]);
}
//passando caracteres da string sem os espaços ou qualquer tipo de pontuação para a string_aux 
int j=0,aux;
for (int i = 0; i < size;i++)
{   aux=string[i];
    if(aux>=97 && aux<=122){
    string_aux[j]=string[i];
    j++;}
}
//quebra de linha
string_aux[j] = '\0';
//lendo tamanho da string sem espaços
size=strlen(string_aux);
//invertendo matriz para comparação
for (int i = 0; i < size;i++)
{
    string_inversa[i]=string_aux[size - 1 - i];
}
//retirando quebra de linha
string_inversa[size] = '\0';
//função bool da biblioteca <stdbool.h> indica valores boleanos ou seja True==0 ou False!=0
bool resultado = strcmp(string_aux, string_inversa) == 0;
//liberando espaço alocado 
free(string_aux);
free(string_inversa);
//return True ou False
return resultado;
}


 


int main() {
    char string[100]; 

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin); 

    
    string[strcspn(string, "\n")] = '\0';

    if (verificar_palindromo(string)) {
        printf("A string e um palindromo.\n");
    } else {
        printf("A string nao e um palindromo.\n");
    }
    
    return 0;
}