#include <stdio.h>
int main () {

int h1,m1,h2,m2,enc1,enc2,diff,min,hora;

scanf("%d %d",&h1,&m1);
scanf("%d %d",&h2,&m2);

enc1 = h1*60 + m1;

enc2 = h2*60 + m2;

diff = enc2 - enc1;

min = diff%60;
hora = (diff - min)/60;

  if (diff == 1){
  printf("Passou apenas %d minuto!\n",diff);
}else{

  printf("Passaram apenas %d minutos!\n",diff);
}
  if ( diff < 60){
    printf("De facto!\n");
  }else if ( min == 0 && hora == 1 ){
    printf("Queres dizer, %d hora?!\n",hora);

  } else if ( min == 0 && hora >=2 ){
    printf("Queres dizer, %d horas?!\n",hora);

  }else if ( min == 1 && hora == 1){
    printf("Queres dizer, %d hora e %d minuto?!\n",hora,min);
  }else if ( min == 1 && hora >= 2){
    printf("Queres dizer, %d horas e %d minuto?!\n",hora,min);
  }else if ( hora != 0) printf("Queres dizer, %d horas e %d minutos?!\n",hora,min);


  return 0;

}
