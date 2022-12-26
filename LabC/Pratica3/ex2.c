#include <stdio.h>
#include <math.h>

struct Frac{
  int num;
  int den;
  int sinal;

};

  typedef struct Frac FRAC;

  FRAC simp(FRAC f){
    struct Frac px;
    for(int i=2;i<px.num || i<px.den;i++){
      if(f.num%i==0 && f.den%i==0){
        px.num = f.num/i;
        px.den = f.den/i;
      }
    }
    px.sinal = f.sinal;
    return px;
  }

  FRAC soma(FRAC a,FRAC b){
    struct Frac px;

    if(a.sinal == -1)
      a.num = -a.num;
    if(b.sinal == -1)
      b.num = -b.num;

    if(a.den == 0 || b.den == 0){
      px.num = a.num + b.num;
      px.den = a.den + b.den;
    }
    else if(a.den == b.den){
      px.num = a.num + b.num;
      px.den = a.den;
    }
    else {
      a.num *= b.den;
      b.den *= a.den;
      b.num *= a.den;

      px.num = a.num + b.num;
      px.den = b.den;
    }

    if(px.num < 0){
      px.sinal = -1;
      px.num = -px.num;
    }
    else px.sinal = 1;


    return px;
  }

  FRAC sub(FRAC a, FRAC b){
    struct Frac px;

    if(a.sinal == -1)
      a.num = -a.num;
    if(b.sinal == -1)
      b.num = -b.num;

    if(a.den == 0 || b.den == 0){
      px.num = -(a.num + b.num);
      px.den = a.den + b.den;}

    if(a.den == b.den){
      px.num = a.num - b.num;
      px.den = a.den;
    }
    else {
      a.num *= b.den;
      b.num *= a.den;
      b.den *= a.den;

      px.num = a.num - b.num;
      px.den = b.den;
    }
    if(px.num < 0){
      px.sinal = -1;
      px.num = -px.num;
    }
    else px.sinal = 1;

    return px;
  }

  FRAC mult(FRAC a, FRAC b){
    struct Frac px;

    if(a.sinal == -1)
      a.num = -a.num;
    if(b.sinal == -1)
      b.num = -b.num;

    px.num = a.num * b.num;
    px.den = a.den * b.den;

    if(px.num < 0){
      px.sinal = -1;
      px.num = -px.num;
    }
    else px.sinal = 1;

    return px;
  }

  FRAC div(FRAC a, FRAC b){
    struct Frac px;
    if(a.sinal == -1)
      a.num = -a.num;
    if(b.sinal == -1)
      b.num = -b.num;

    px.num = a.num * b.den;
    px.den = a.den * b.num;

    if(px.num < 0){
      px.sinal = -1;
      px.num = -px.num;
    }
    if(px.den<0){
      px.den = -px.den;
      px.sinal = -px.sinal;
    }
    else px.sinal = 1;

    return px;
  }

  void print(FRAC a){
    printf("Fração = %d/%d  %d\n",a.num,a.den,a.sinal );
  }

  int main() {
    int a,b,c;
    char sinal;
    FRAC final;
    FRAC anterior = {1,2,1};

      sinal = getchar();
      scanf("%d %d %d",&a,&b,&c);
      FRAC proximo = {a,b,c};
      if(sinal == '+'){
        final = soma(anterior,proximo);
        print(simp(final));
      }
      if(sinal == '-'){
        final = sub(anterior,proximo);
        print(simp(final));
      }
      if(sinal == '*'){
        final = mult(anterior,proximo);
        print(simp(final));
      }
      if(sinal == '/'){
        final = div(anterior,proximo);
        print(simp(final));
      }

      printf("%c",sinal);
      anterior = proximo;



  return 0;
}
