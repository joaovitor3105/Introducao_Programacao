#include <stdio.h>
#include <math.h>
int main()
{double massa_inicial,massa_final=0.5;
int tempo_total=0,segundos,minutos,horas;
int total;
printf("coloque um numero:");
scanf("%lf",&massa_inicial);

for(;massa_inicial>=massa_final;tempo_total+=50)
{massa_inicial/=2;}
printf("%d",tempo_total);

horas = tempo_total / 3600;
    tempo_total %= 3600;
    minutos = tempo_total / 60;
    segundos = tempo_total % 60;


printf("\t%d horas \t%d minutos \t%d segundos",horas,minutos,segundos);
return 0;
}