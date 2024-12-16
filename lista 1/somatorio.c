#include <stdio.h>
#include <math.h>
int main()
{
float numerador,denominador1,denominador,total,total2;
denominador=15;
numerador=1;

do
{denominador1=denominador*denominador;
    
  total=numerador/denominador1;
  numerador*=2;
  denominador--;
  total2=+total;}
while(denominador>1 && numerador < 16384);
printf ("o resultado e :%f",total2);
}










