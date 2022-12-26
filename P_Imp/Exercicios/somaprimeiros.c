#include <stdio.h>

double leibniz(int k){

  float soma;
  soma = 0;
  while(k != 0){
    if(k % 2 == 0){
      soma = 1/(2*k+1);}
    else{
      soma = -1/(2*k+1);
    }

    k--;
  }
  soma = 4*soma;

  return soma;
}

int main(){
  int k;
  scanf("%d",&k);
  printf("%d",leibniz(k));

  return 0;
}
