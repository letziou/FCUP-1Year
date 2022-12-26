#include <stdio.h>

int sitio(int ncad,int x[]){
  int pref;
    while(ncad!=0){
      scanf("%d",&pref);
      if(x[pref]!=0){
        x[pref]--;
        return 0;
      }else ncad--;
    }
    return 1;
}


int main(){
  int cad,i,n,ncad,cont=0,l,contcad=0,t,v;
  int x[100];

  scanf("%d",&cad);
  for(i=0;i<100;i++){
    x[i]=0;
  }
cad--;
  while(cad != -1){
    scanf("%d %d",&t,&v);
    x[t]=v;
    cad--;
  }

  scanf("%d",&n);
  while (n!=0){
    scanf("%d",&ncad);
    cont += sitio(ncad,x);
    n--;
  }
  for(l=0;l<100;l++){
    if(x[l]!=0){
      contcad += x[l];
    }
  }
  printf("%d\n%d\n",cont,contcad);

  return 0;
}
