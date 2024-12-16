#include <stdio.h>
int main()
{
int num1=0;
printf("\ndigite um numero:");
scanf("%d",&num1);

if (num1 < 0)
{
    printf("\no numero %d e negativo",num1);
} 

else if (num1 > 0)
{
    printf("\no numero %d e positivo",num1);
}
else
{
    printf("\nseu numero e zero");
}


}