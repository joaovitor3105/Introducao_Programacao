#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
int main()

 {   int num;
 printf("Escolha um exercicio:\nexercicio-1\nexercicio-2\nexercicio-3\nexercicio-4\n"); 
    scanf("%d",&num);
 switch(num)
 {
    case 1:
    {
    float num1,num2,num3,desvio,media;
    printf ("\nVoce escolheu media e desvio padrao,Coloque um numero :");    
    scanf ("%f",&num1);
    printf ("\nColoque outro numero: ");
    scanf ("%f",&num2);
    printf ("\nColoque outro numero: ");
    scanf ("%f",&num3);
    printf ("\nSeu resultado e:%f\n",media=(num1 + num2 + num3)/3);
      desvio=sqrt((pow(num1-media,2)+pow(num2-media,2)+pow(num3-media,2))/2);
     printf ("\nSeu desvio padrao e :%f",desvio);

    break;
    }
    case 2:
    {
    int num4,total;
    printf("Digite o valor de X:");
    scanf("%d",&num4);
    total=(num4+1)/((-2*num4)+3);
      if(total<=0)
      printf("Seu numero satisfaz a inequacao");
      else
      printf("Seu numero nao satisfaz a inequacao");
      break;
    }
    case 3:
    {   
    int num5;  
    printf("Qual media voce deseja\n1-aritmetica\n2-ponderada\n3-harmonica\n");
    scanf("%d",&num5);
      float num6,num7,num8,total2; 
        if(num5==1) 
        {  
        
        printf("Voce escolheu media aritmetica digite tres numeros:");
        scanf("%f %f %f",&num6,&num7,&num8);
        total2=(num6+num7+num8)/3;
        printf("Seu resultado e:%f",total2);
        }
        if(num5==2)
        {
        printf("Voce escolheu media ponderada digite tres numeros:");
        scanf("%f %f %f",&num6,&num7,&num8);
        total2=((num6*3)+(num7*3)+(num8*4))/3;
        printf("Seu resultado e:%f",total2);
        }
        if(num5==3)
        {
        printf("Voce escolheu media harmonica digite tres numeros:");
        scanf("%f %f %f",&num6,&num7,&num8);
        total2=(3/((1/num6)+(1/num7)+(1/num8)));
        printf("Seu resultado e:%f",total2);
        break;
        }
    }
    case 4:
    {   
   float sexo,tempo,salario,bonus;
   printf("\nDigite o sexo:\n1-Masculino\n2-Feminino\n");
   scanf("%f",&sexo);
   printf("\nTempo de trabalho (em anos):");
   scanf("%f",&tempo);
   printf("\nDigite o salario:");
   scanf("%f",&salario); 
      if(sexo==1 && tempo>=15)
      printf("\nO bonus e:%.2f reais",bonus=salario*0.2);
      else if(sexo==2 && tempo>=10)
      printf("\nO bonus e:%.2f reais",bonus=salario*0.25);
      else
      printf("\nO bonus sera 100.00 reais");
   
   
   break;
   }
  }
 return 0;
 }