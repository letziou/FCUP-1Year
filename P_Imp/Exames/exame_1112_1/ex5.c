#include <stdio.h>

int quadrado_de_dist(int x,int y);
int conta(int pontos[][2],int n,int r);

int main(){
  int numbers;
  int radius;

  scanf("%d %d",&numbers,&radius);

  int pontos[numbers][2];

  for(int i=0; i<numbers ;i++){
    scanf("%d %d\n",&pontos[i][0],&pontos[i][1]);
  }

  int t = conta(pontos,numbers,radius);

  printf("%d\n",t);

  return 0;
}

int quadrado_de_dist(int x,int y){
  return x*x+y*y;
}

int conta(int pontos[][2],int n,int r){
  int cont = 0;
  for(int i=0; i<n ;i++){
    if(quadrado_de_dist(pontos[i][0],pontos[i][1]) > r*r)
      cont++;
  }
  return cont;
}
