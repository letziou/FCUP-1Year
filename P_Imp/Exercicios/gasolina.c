#include <stdio.h>
int main(){

  float gasolina,consumo,n,metros,preco,efetivo,efetivomax,dist,desper,pos;

efetivomax = 0;
pos = 0;
  scanf("%f %f %f",&gasolina,&consumo,&n);
  consumo = consumo/100; //consumo por km//
  while(n != 0){

    scanf("%f %f",&metros,&preco);
    metros = metros*0.001;
    dist = metros*2;
    desper = dist/consumo;

    efetivo = (gasolina*preco)/(gasolina-desper);

    if(efetivo > efetivomax){
      efetivomax = efetivo;
      pos = n;
      printf("%d",n);
    }


    n--;
  }
  printf("%d\n",efetivo);

  return 0;
}
