#include <stdio.h>
#define NUMCODIGOS 40

void stock_existente(int stock[]);
void despachar_encomendas(int stock[],int balanco[]);

int main(){
  int stock[NUMCODIGOS+1];
  int balanco[2];
  stock_existente(stock);
  despachar_encomendas(stock,balanco);
  printf("%d no total de %d\n",balanco[0],balanco[1]);
  return 0;
}

void stock_existente(int stock[]){
  int p,s;
  for(int i=0; i<NUMCODIGOS ;i++)
    stock[i]=0;

  scanf("%d %d",&p,&s);
  while(p!=0 && s!=0){
    stock[p] = s;
    scanf("%d %d",&p,&s);
  }
}

void despachar_encomendas(int stock[],int balanco[]){
  int p,s;
  for(int i=0; i<2 ;i++)
    balanco[i] = 0;

  scanf("%d %d",&p,&s);
  while(p!=0 && s!=0){
    if(stock[p] >= s){
      stock[p] -= s;
      balanco[1] += s;
    }else{
      balanco[0] += s;
    }
    scanf("%d %d\n",&p,&s);
  }
}
