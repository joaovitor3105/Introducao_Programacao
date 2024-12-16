#include <stdio.h>
int main()
{
char letra;
float valor_total;
printf("insira o valor total de compras:");
scanf("%f",&valor_total);
printf("em qual sentenca o cliente se encaixa \t(f)funcionario\t(e)cliente especial\t(c)cliente comum");
scanf("%s",&letra);
    if(letra=='f')
    {valor_total*=0.95;
    printf("o valor a ser pago:%f",valor_total);
    }
    if(letra=='e')
        {valor_total*=0.90;
    printf("o valor a ser pago:%f",valor_total);
    }
    else
        
    printf("o valor a ser pago:%f",valor_total);

    return 0;


}