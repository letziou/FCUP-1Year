#include <stdio.h>
int main() {
int a,b,cont,contmax;

scanf("%d %d",&a,&b);

contmax = 0;
cont = 1;

while (a != -1 && b!= -1){

  if(a == 1 && b==1) {
    cont = cont +1;
  }else{

    if(a == 0 || a == 2){
      while(a != 1){
        scanf("%d",&a);
      }

    if(cont > contmax)
    contmax = cont;
    cont = 1;
  }

}

  scanf("%d %d",&a,&b);

}
printf("%d\n",contmax);

return 0;

}
