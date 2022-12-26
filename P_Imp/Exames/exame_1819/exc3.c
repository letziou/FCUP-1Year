#include <stdio.h>
#include <string.h>

#define MAXC 9999

int binario(char number[]);
int upper(int n);

int main(int argc, char const *argv[]) {
  char number[MAXC];
  int i;
  for(i=0;(number[i] = getchar()) != '\n';i++){};
  number[i] = '\0';

  int j = binario(number);
  printf("%d\n",j);
  return 0;
}

int binario(char number[]){
  int cont=0;
  int elevation;
  for(int i=0;i<strlen(number);i++){
    elevation = upper((strlen(number)-i-1));
    cont += (number[i]-'0')*elevation;
  }
  return cont;
}

int upper(int n){
  int cont = 1;
  for(int i=0;i<n;i++){
    cont *= 2;
  }
  return cont;
}
