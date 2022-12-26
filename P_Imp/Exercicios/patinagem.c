#include <stdio.h>
int main() {

  int n,min,max,valor,cont,contmax,soma,com;

min = 100;
max = 0;
cont =0;
contmax = 0;
soma = 0;
  scanf("%d ",&n);
  com = n;

  while(n != 0){

    scanf("%d",&valor);
      soma = soma + valor;

    if(valor == min){cont++;}
    if(valor == max){contmax++;}
    if(valor < min){min = valor; cont = 1;}
    if(valor > max){max = valor; contmax = 1;}




    n--;
  }

    if(cont == 1 && contmax == 1){
      soma = soma-min;
      soma = soma-max;
      soma = soma/(com-2);
    }else if(cont != 1 && contmax == 1){
      soma = soma-max;
      soma = soma/(com-1);
    }else if(cont == 1 && contmax != 1){
      soma = soma-min;
      soma = soma/(com-1);
    }else {soma = soma/com;}

    printf("%d\n",soma);

    return 0;


}
