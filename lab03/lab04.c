#include <stdio.h>
#include <math.h>
#define tam 8
int funcaos(char string[tam]){
int caracter[127]=0;
for (int i = 0; i <=tam; i++)
    {string[i];
    for (int j = 0; j < 128; j++)
    {
            if(string[i]==j)
            {caracter[j]+=1;
            break;
            }
    } 
    } for (int k = 0; k < 128; k++)
    {
        if (caracter[k]>0){
            printf("%s=%d",k,caracter[k])
        }
    }
    
}
int main()
{printf("2");



}

























































