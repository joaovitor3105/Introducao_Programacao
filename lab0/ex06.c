#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{double  num1=0.00000;
printf("\ncoloque um numero real:");
scanf("%lf",&num1);
if (num1>=0.0000000)
{
    printf("\na raiz quadrada do seu numero e:%lf",num1=sqrt(num1));
}


else if (num1<0)
{
     printf("\nnao existe raiz quadrada de numero negativo");
}

else
printf("ERROR");

return 0;
}

