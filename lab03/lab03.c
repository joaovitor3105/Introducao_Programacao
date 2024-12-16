#include <stdio.h>
#include <math.h>

      float ex01(float a, float b)
      {float resto,total=0,cont;
      int num;
      for(cont=a+1;cont<b;cont++)
      {
            num=cont;
         resto=num%2;
            if(resto==0)
            total+=pow(num,3);
               else
                  total+=0;    
         }return total;
         }
      double fatorial(double x){
      
      if(x==1)
      return 1;
      if(x==0)
      return 0;
      else
      return x*fatorial(x-1);
      }
      
      int main(){
    int questao=1;
      do
      {
      printf("\ndigite o numero da questao ou digite 5 para encerrar: ");
            scanf("%d",&questao);
    
      
      switch(questao){
         case 1:
         {  
         float a=1,b=1; 
        
         while (a!=0 && b!=0){ 
         printf("insira o valor de A e B separado por espaço ou 0 para encerrar:");
         scanf("%f %f",&a,&b);
       
           if (a!=0 && b!=0)
           {
           printf("a soma dos cubos de valores pares do intervalo %.0f e %.0f = %.0f ",a,b, ex01(a,b) );  
         }
       
           }break;
           
       
         }
      
         case 2:{
         double x=0,total=1;
         printf("\ninsira um numero x : " );
         scanf("%lf",&x);
        for (int i=1; i!=100;i++)
        {
        total+= pow(x,i)/fatorial(i);
        }
        printf("\n\nresultado :%.4lf \n\nresultado biblioteca matematica:%.4lf",total,exp(x));
         break;}
        
        

case 3 :{int cpf[11];
                int total1=0;
               
        printf("coloque o cpf sem digito verificador,digito por digito:");
        for (int i = 0; i < 9; i++)
        {
        scanf("%d",&cpf[i]);
        }
      cpf[9]=0;
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
       break;
      }
case 4 :{int cnpj[14],total2=0;

       printf("coloque o cpf sem digito verificador,digito por digito:");
        for (int i = 0; i < 12; i++)
        {
        scanf("%d",&cnpj[i]);
        }
        cnpj[12]=0;
        cnpj[13]=0;
        for (int i = 0,j=5; j>1; i++,j--)
        {
        total2+=cnpj[i]*j;
        }
        for (int i = 4,j=9; j>1; i++,j--)
        {
        total2+=cnpj[i]*j;
        }
        total2%=11;
              if(total2==0 || total2==1){
              cnpj[12]=0;
              }
              else cnpj[12]=11-total2;
              total2=0;
      for (int i = 0,j=6; j>1; i++,j--)
        {
        total2+=cnpj[i]*j;
        }
      for (int i = 5,j=9; j>1; i++,j--)
        {
        total2+=cnpj[i]*j;
        }
        total2%=11;
                if(total2==0 || total2==1){
                cnpj[13]=0;
                }
                else cnpj[13]=11-total2;
      printf("o CNPJ com digito verificador e :");
      printf("%d",cnpj[0]);
      printf("%d",cnpj[1]);
      printf(".%d",cnpj[2]);
      printf("%d",cnpj[3]);
      printf("%d",cnpj[4]);
      printf(".%d",cnpj[5]);
      printf("%d",cnpj[6]);
      printf("%d",cnpj[7]);
      printf("/%d",cnpj[8]);
      printf("%d",cnpj[9]);
      printf("%d",cnpj[10]);   
      printf("%d",cnpj[11]);  
      printf("-%d",cnpj[12]);  
      printf("%d",cnpj[13]);  
       break;
         } }
      }while (questao<5 && questao>0);}
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      