#include <stdio.h>
#include <stdlib.h>
// Função para gerar os primeiros n números da sequência de Fibonacci
void gerar_fibonacci(int n, int* fibonacci) {
    if (n > 0) fibonacci[0] = 0;
    if (n > 1) fibonacci[1] = 1;
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
}
//função que faz uma busca binaria atarvez dos dados de fibonacci
int busca_fibonacci(int *fibonacci,int n,int x){
//pega a escala de fibonacci em um vetor
gerar_fibonacci(n,fibonacci);    
int ini=0,fim=n-1,meio;
//busca binaria
do{meio=(ini+fim)/2;
    if(x>fibonacci[meio]){
        ini=meio+1;
    }
    else if(fibonacci[meio]>x){
        fim=meio-1;
    }
    }
    //a busca binaria termina quando o inicio se cruza com o valor final ou quando meio for igual ao valor buscado
    while(x!=fibonacci[meio] && ini<=fim);
        if(x==fibonacci[meio])
        return meio;
        else 
        return meio=-1;
        }
int main(){
int n,x;
printf("\ninsira o valor de n:");
scanf("%d",&n);
printf("\ninsira o valor de x:");
scanf("%d",&x);
int*fibonacci= malloc(n*sizeof(int));
printf("\nIndice:%d",busca_fibonacci(fibonacci,n,x));
}