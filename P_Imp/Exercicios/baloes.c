#include <stdio.h>
int main() {

  int n,r,g,b,x,y,z,cont;
scanf("%d %d %d %d",&r,&g,&b,&n);

cont = 0;

while( n != 0){

  scanf("%d %d %d",&x,&y,&z);

  if(x==r && y==g && z==b){
    cont++;
  }
  n= n-1;
}
  printf("%d\n",cont);
}
