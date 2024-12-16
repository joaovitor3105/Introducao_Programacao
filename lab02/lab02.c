#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    
    int inverternumero(int x)
    {
    int inv=0;
        while (x > 0){
        inv = 10 * inv + x % 10;
        x/=10;    
        }
    return inv;
    }
int main()
{
int num1;
do
{

printf("\nDigite o exercicio 1,2,3,4 ou digite 0 para encerrar o programa:");
scanf("%d",&num1);




switch (num1)
{
case 1:
    {
    int num=0,resultado;
    printf("coloque um numero:");
    scanf("%d",&num);
    int cont;

    printf("seu resultado e:");
        for (cont = 0; cont <= 10; cont++)
        {    
            resultado=cont*num;
            printf("\n%d",resultado);
        }
        break;
        return 0;
}
case 2:
    {
    double num2=0,total=1;
    printf("coloque um numero:");
    scanf("%lf",&num2);   
        if(num2>=0)
        {
            do
            { 
            total=num2*total;
            num2--;   
            }
            while (num2>=1);
            printf("seu fatorial e:%lf",total);
        }
        else
        printf("ERROR");

         break;
         return 0;
}
case 3 :
{int num4;
    printf("Coloque um numero:");
    scanf("%d",&num4);

    printf("seu numero invertido e :%d",inverternumero(num4));
break;
return 0;
}

case 4 :
{
int num3,cont1,resto;
printf("Coloque um numero:");
scanf("%d",&num3);
      
    for ( cont1=2; cont1<=num3; cont1++)
    {
        resto=num3%cont1;
        if(resto==0)
        break;
    }
            if(num3==cont1)
            printf("\nO numero %d e primo.",num3);
            else    
            printf ("\nO numero %d nao e primo.",num3);
break;
return 0;
}


}
} while (num1>=1);
}