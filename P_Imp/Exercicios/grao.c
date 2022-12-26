#include <stdio.h>
int main() {

  int ultimo,novo,contador,contadormax,apres,apresmax;

  scanf("%d %d",&ultimo,&novo);

  contador = 1;
  contadormax = 0;
  apres = ultimo;
  apresmax = 0;

    while(novo != 0){
    if(ultimo+1 == novo){
      apres = ultimo;
      contador = contador + 1;
    }else if(contador > contadormax){
        contadormax = contador;
        apresmax = apres;
        contador = 1;
    }
    ultimo = novo;
    scanf("%d",&novo);

}


if (contador > contadormax){contadormax = contador; apresmax = apres;}

  printf("%d %d\n",apresmax,contadormax);

  return 0;
}
