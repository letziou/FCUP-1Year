#include <stdio.h>

int main() {

  int c,n,p,cont=0,i;
  char x[5];
  scanf("%d",&c);
  while (c != 0){

    scanf("%d %d",&n,&p);
    while (n >= p){
      n-=p;
      cont++;
    }

    for(i=0; i<5 && (x[i]= getchar()) != '\n';i++);

    if(x[1]== 'R'){
      printf("R: %d Q: %d\n",n,cont);
    }
    else printf("Q: %d R: %d\n",cont,n);

    cont = 0;
    c--;
  }
  return 0;
}
