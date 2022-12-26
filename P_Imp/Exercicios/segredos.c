#include <stdio.h>

int main () {

  int a,i,cont=0,l=1,t,f;

  scanf("%d",&a);
  t = a;
  a = a+a;

  char x[a];

  for(i=0;i<a;i++){
    x[i]= getchar();
  }
  x[a]='\0';

    if(x[0]=='o') cont++;

    while(l<a){
      if(x[l-2]=='o' && x[l]=='#') cont++;
      if(x[l]=='o') cont++;
      l=l+2;
    }
    f = t-cont;

    printf("%d\n",f);

    return 0;
}
