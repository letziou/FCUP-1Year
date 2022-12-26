#include <stdio.h>
#include <stdlib.h>

int proximo_primo(int n);
int isPrimo(int n);

int main(int argc, char const *argv[]) {
  int k;
  scanf("%d",&k);

  int i = proximo_primo(k);
  printf("%d\n",i);
  return 0;
}

int proximo_primo(int n){
  int i;
  for(i=n+1;isPrimo(i)!=1;i++){};
  return i;
}

int isPrimo(int n){
  for(int i=2;i<n;i++)
    if(n%i==0)
      return 0;
  return 1;
}
