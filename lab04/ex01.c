#include <stdio.h>
#include <math.h>
#define tam 100
int main(){
    char string[tam]={0};
int caracter[128]={0};
printf("escreva uma frase:");
fgets(string,tam,stdin);

for (int i = 0; i <=tam; i++)
    {
    for (int j = 65; j < 123; j++)
    {
            if(string[i]==j)
            {caracter[j]+=1;
            break;
            }
    } 
    } for (int k = 0; k < 128; k++)
    {
        if (caracter[k]>0){
            printf("%c=%d\t",k,caracter[k]);
        }
    }return 0;
}