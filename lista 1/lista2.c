#include <stdio.h>

int potencia(int x,int n)
{
  if(n==0)
  return 1;
  if(n==1)
  return x;
else
x=x*potencia(x,n-1);
}

int main()
{
  int x, n,total;  
printf("digite uma base e um expoente:");
scanf("%d %d",&x, &n);
    total=potencia(x,n);
printf("%d",total);

}