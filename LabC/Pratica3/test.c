#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct frac{
  int sign;
  int num;
  int den;
  int error;
} FRAC;

FRAC scan();
void write(FRAC f);
FRAC neg(FRAC f);
FRAC simf(FRAC f);
FRAC sum(FRAC f1, FRAC f2);

int main(int argv, char* argc[]){
  FRAC f1 = scan();
  f1 = simf(f1);
  write(f1);
  return 0;
}

FRAC scan(){
  FRAC f;
  scanf("%d %d %d %d",&f.sign,&f.num,&f.den,&f.error);
  return f;
}

void write(FRAC f){
  if(f.sign == 1)
    printf("%d\n%d\n",f.num,f.den);
  else printf("-%d\n%d\n",f.num,f.den);
}

FRAC neg(FRAC f){
  f.num = -f.num;
  return f;
}

FRAC simf(FRAC f){
  for(int i=2; i<f.num || i<f.den;i++)
    if(f.num%i==0 && f.den%i==0){
      f.num /= i;
      f.den /= i;
    }
  return f;
}

FRAC sum(FRAC f1, FRAC f2){
  FRAC f3;
  if(f1.sign == -1) f1 = sign(f1);
  if(f2.sign == -1) f2 = sign(f2);
  f1.num *= f2.den;
  f1.den *= f2.den;
  f2.num *= f2.den;
  f3.num = f1.num + f2.num;
  f3.den = f1.den; 
  return f3;
}