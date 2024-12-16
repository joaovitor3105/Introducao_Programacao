#include <stdio.h>
int main()
{
int maior,menor,numero,cont,quantidade;
printf("insira a quantidade de numeros:");
scanf("%d",&quantidade);
printf("insira um dos numeros");
scanf("%d",&numero);
maior=menor=numero;
for(cont=1;quantidade<cont;cont++)
 {printf("insira um dos numeros");
  scanf("%d",numero);
    if(numero>=maior)
        maior=numero;
    if(numero<=menor)
    menor=numero;
    else
    numero=0;
 }

printf("o maior numero:%d\to menor numero:%d",maior,menor);
return 0;

}