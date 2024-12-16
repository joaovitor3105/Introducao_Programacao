#include <stdio.h>
#include <math.h>

int main(){ 
int cpf[11];
int total1=0;
for (int i = 0; i < 12; i++)
{cpf[i]=0;
    cpf[i]= i+1;
}cpf[9]=0;
cpf[10]=0;
for (int i = 0,j=10; i < 10; i++,j--)
{
    total1+=cpf[i]*j;
}
 total1%=11;
     if(total1==0 || total1==1){
     cpf[9]=0;
     }
     else cpf[9]=11-total1;
total1=0;
for (int i = 0,j=11; i < 10; i++,j--)
   {
    total1+=cpf[i]*j;
   }
   total1%=11;
     if(total1==0 || total1==1){
     cpf[10]=0; }
     else cpf[10]=11-total1;



printf("o CPF com digito verificador e :");
printf("%d",cpf[0]);
printf("%d",cpf[1]);
printf("%d",cpf[2]);
printf(".%d",cpf[3]);
printf("%d",cpf[4]);
printf("%d",cpf[5]);
printf(".%d",cpf[6]);
printf("%d",cpf[7]);
printf("%d",cpf[8]);
printf("-%d",cpf[9]);
printf("%d",cpf[10]);

}