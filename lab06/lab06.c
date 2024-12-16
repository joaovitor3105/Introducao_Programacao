#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main(){int x,y;

FILE *arq;

//leitura do arquivo
 arq=fopen("matriz.txt", "r");
    if(!arq){
        printf("erro ao abrir arquivo");
        exit(0);}
    else
     fscanf(arq,"%d %d",&x,&y);
     
//Alocação da matriz
        int**matriz;
        matriz= malloc(x*sizeof(int*));
        for (int i = 0; i < x; i++)
        {
            matriz[i]=malloc(y*sizeof(int));
        } 

 //verificando possivel erro na alocação de matriz
        if (matriz == NULL) {
        printf("Erro ao alocar memória\n");
        fclose(arq);
        exit(0);}

 //Lendo os valores da matriz
    for (int i = 0; i < x; i++)
    {
     for(int j=0; j<y; j++){
    fscanf(arq,"%d",&matriz[i][j]);}
    }

//Fechando o arquivo de leitura
    fclose(arq);

//criando arquivo para transpor
    arq=fopen("transposta.txt", "w");

//possivel erro na criação do arquivo
        if(!arq){
            printf("erro ao criar arquivo");
            exit(0);

//liberação de memoria alocada caso de errado
                for(int i = 0; i < x; i++) {
                    free(matriz[i]);}
                    free(matriz);}
                
//adicionando valores transpostos no arquivo   
    for (int j = 0; j < y; j++)
    {
        for(int i=0; i<x; i++){
        fprintf(arq,"%d ",matriz[i][j]);}
        fprintf(arq,"\n");
    }
    fclose(arq);
   
//liberação de memoria alocada
   for(int i = 0; i < x; i++) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;}