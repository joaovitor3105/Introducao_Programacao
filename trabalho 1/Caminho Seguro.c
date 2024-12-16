#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>


bool caminho_seguro(int x,int y,bool**caminho,char**mapa,int linha,int coluna){
 return (x>=0 && x<linha && y>=0 && y<coluna && mapa[x][y]!='R' && !caminho[x][y]);}

bool dfs(int x,int y,bool**caminho,char**mapa,int linha,int coluna){
if(!caminho_seguro(x,y,caminho,mapa,linha,coluna))
    return false;
if(mapa[x][y]=='Z')
    return true;

caminho[x][y]=true;

if(dfs(x-1,y,caminho,mapa,linha,coluna)){
    if (mapa[x][y] != 'H') 
        mapa[x][y]='*';
        return true;}
if(dfs(x+1,y,caminho,mapa,linha,coluna)){
    if (mapa[x][y] != 'H') 
        mapa[x][y]='*';
        return true;}
if(dfs(x,y-1,caminho,mapa,linha,coluna)){
    if (mapa[x][y] != 'H') 
        mapa[x][y]='*';
        return true;}
if(dfs(x,y+1,caminho,mapa,linha,coluna)){
    if (mapa[x][y] != 'H') 
        mapa[x][y]='*';
        return true;}
caminho[x][y] = false;
	return false;



}
void print_matriz(char**mapa,int linha,int coluna){

    for (int i = 0; i < linha; i++) {
		for (int j = 0; j < coluna; j++) {
			printf("%c ", mapa[i][j]);

}printf("\n");}}

int fuga_humana(bool**caminho,char**mapa,int linha,int coluna){
//inicializa a matriz booleana toda em false
for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            caminho[i][j] = false;
        }
    }
     int ini_x=-1,ini_y=-1;
     bool encontrado=false;
     for (int i = 0; i < linha; i++)
     {for (int j = 0; j < coluna; j++)
     {
        if(mapa[i][j]=='H'){
            ini_x=i;
            ini_y=j;
            encontrado=true;
           }
     }
     
       
     }
     if (ini_x == -1 || ini_y == -1) {
        printf("O humano nao existe\n");
        return 0;
    }
     if (dfs(ini_x,ini_y,caminho,mapa,linha,coluna))
     {
        printf("O humano esta salvo aqui esta o caminho feito:\n");
        print_matriz(mapa,linha,coluna);
        return 1;
     }
     else 
     printf("caminho nao existe");
     return 0;



}
int main(){FILE *arq;
int linha,coluna;
//leitura do arquivo

 arq=fopen("mapa.txt", "r");
    if(!arq){
        printf("erro ao abrir arquivo");
        exit(0);}
    else
     fscanf(arq,"%d %d",&linha,&coluna);
     
//Alocação da matriz 
        char**mapa;
        mapa= malloc(linha*sizeof(char*));
        for (int i = 0; i < linha; i++)
        {
            mapa[i]=malloc(coluna*sizeof(char));
        } 

 //verificando possivel erro na alocação de matriz
        if (mapa == NULL) {
        printf("Erro ao alocar memória\n");
        fclose(arq);
        exit(0);}


 //Lendo os valores da matriz
   for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            int ch = fgetc(arq);
            while (ch == '\n' || ch == EOF) {
                ch = fgetc(arq); // Ignorar caracteres de nova linha e EOF
            }
            mapa[i][j] = (char)ch;
        }
        fgetc(arq); // Ignorar o caractere de nova linha após cada linha
    }
//Alocação da matriz boleana 
        bool**caminho;
        caminho= malloc(linha*sizeof(bool*));
        for (int i = 0; i < linha; i++)
        {
            caminho[i]=malloc(coluna*sizeof(bool));
        } 

 //verificando possivel erro na alocação de matriz
        if (caminho == NULL) {
        printf("Erro ao alocar memória\n");
        fclose(arq);
        exit(0);}
//Fechando o arquivo de leitura
    fclose(arq);

fuga_humana(caminho,mapa,linha,coluna);
//liberação de memoria alocada
   for(int i = 0; i < linha; i++) {
        free(mapa[i]);
        free(caminho[i]);
    }
    free(mapa);
    free(caminho);
   
    
    
    
    
    return 0;}
