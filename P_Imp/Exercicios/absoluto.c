#include <stdio.h>


int abs(int x){
  if ( x < 0)
  return (-x);
  else return x;

}
int main (){
int a,b;


  scanf("%d %d",&a,&b);

  printf("%d %d \n",abs(a),abs(b));
  return 0;
}
