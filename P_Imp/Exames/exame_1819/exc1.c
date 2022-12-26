#include <stdio.h>

int soma_divs(int n);

int main(int argc, char const *argv[]) {
  int j = soma_divs(12);
  printf("%d\n",j);
  return 0;
}

int soma_divs(int n){
  int cont=0;

  for(int i=1;i<n;i++)
    if((n%i)==0)
      cont += i;

  return cont;
}
