#include <stdio.h>
int main() {

int a,b,c,d,n,fim,ini,diff,ult;

scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);



if ( (b == c) | (a == d) ){
  printf("Impossivel\n");
}else{

  if ( b > d){
    fim = d;
  }else fim = b;

  if (a > c){
    ini = a;
  }else ini = c;


  diff = fim - ini;

  if (diff < n){
    printf("Impossivel\n");
  }else if ( diff == n){
    printf("%d\n",ini);
  }else {
    ult = fim -n;
    printf("%d %d\n",ini,ult);
}

}

return 0;

}
