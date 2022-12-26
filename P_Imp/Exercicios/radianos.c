#include <stdio.h>


float rad (float x){

  return ((x*3.1459)/180);
}

int main(){
float x;
  scanf("%f",&x);

printf("%f graus são %f radianos\n",x,rad(x));

return 0;
}
