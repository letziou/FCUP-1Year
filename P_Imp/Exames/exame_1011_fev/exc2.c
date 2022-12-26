#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9999

void lerResultado(char eq1[],char eq2[],char golos[]);
char comenta(char eq1[],char eq2[],char res[]);

int main(int argc, char const *argv[]) {

  char eq1[MAX], eq2[MAX], res[MAX];
  char c;

  lerResultado(eq1,eq2,res);
  c = comenta(eq1,eq2,res);
  printf("%c\n",c );

  return 0;
}

void lerResultado(char eq1[],char eq2[],char golos[]){
  int i,j,k;
  for(i=0; (eq1[i] = getchar()) != '\n';i++){};
    eq1[i] = '\0';

  for(j=0; (eq2[j] = getchar()) != '\n';j++){};
    eq2[j] = '\0';

  for(k=0; (golos[k] = getchar()) != '\n';k++){};
    golos[k] = '\0';
}

char comenta(char eq1[],char eq2[],char res[]){
  if(res[0]>res[1]){
    printf("%s venceram %s por %c a %c\n",eq1,eq2,res[0],res[1]);
    return '1';
  }
  else if(res[0]<res[1]){
    printf("%s venceram %s por %c a %c\n",eq2,eq1,res[1],res[0]);
    return '2';
  }
  else{
    printf("%s e %s empataram a %c\n",eq1,eq2,res[0]);
    return 'x';
  }
}
