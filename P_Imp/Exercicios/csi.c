#include <stdio.h>
int main() {

int c,i,j,s,t;

scanf("%d",&c);

while (c != 0){

scanf("%d %d %d %d",&i,&j,&s,&t);

  if(s<=i && t>=j){printf("Com alibi\n");}
  else printf("Sem alibi\n");




c--;
}
return 0;

}
