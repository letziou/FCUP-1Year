#include <stdio.h>
#include <string.h>
#define MAX 9999

void inverte(char x[]);

int main(){
  char x[MAX];
  scanf("%s",x);
  printf("%s\n",x);
  inverte(x);
  printf("%s\n",x);
}

void inverte(char x[]){
  int max = strlen(x);
  char temp;

  for(int i=0; i<(max/2) ;i++){
    temp = x[i];
    x[i] = x[max-1-i];
    x[max-1-i] = temp;
  }
}
