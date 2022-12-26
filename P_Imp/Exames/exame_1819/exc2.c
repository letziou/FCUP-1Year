#include <stdio.h>

#define NMAX 9999

int main(int argc, char const *argv[]) {
  char test[NMAX];
  int cont,contmax=0;
  int k;

  for(k=0;(test[k] = getchar()) != '\n';k++){};
    test[k] = '\0';


  for(int i=0;test[i] != '\0';i++){
    if(test[i]==test[i+1]){
      cont=1;
      for(int j=i+1;test[j]==test[i];j++){
        cont++;
      }
    }
    if(cont>contmax)
      contmax = cont;
  }

  printf("%d\n",contmax );
  return 0;
}
