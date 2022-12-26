#include <stdio.h>

int main () {

  int i,anterior=0,seguinte=2;
  char x[999];

  for (i=0; (x[i]= getchar()) != '#';i++);

  printf("%c\n",x[anterior]);

  while(anterior < i){
    if(x[anterior]==x[seguinte]) printf("%c\n",x[anterior]);

    if( (x[anterior]=='a' && x[seguinte]=='c')||(x[anterior]=='c' && x[seguinte]=='a') ) printf("t\n");

    if( (x[anterior]=='a' && x[seguinte]=='t')||(x[anterior]=='t' && x[seguinte]=='a') ) printf("c\n");

    if( (x[anterior]=='t' && x[seguinte]=='c')||(x[anterior]=='c' && x[seguinte]=='t') ) printf("a\n");

    anterior += 2;
    seguinte += 2;
}

return 0;
}
