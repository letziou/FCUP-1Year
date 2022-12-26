#include <stdio.h>

int ler_seq(int x[], int m){

  int i,valor;

  for(i=0;i < m;i++){
  scanf("%d",&valor);
  x[i] = valor;
}
}


int main(){

 int m,valor,tvalor,i,l,k=1,cont=0,contmax=0;
 int x[m],v[m];

 scanf("%d",&m);

 valor = ler_seq(x,m);
 tvalor = ler_seq(v,m);

 while(k < m){
   if(x[k-1]!=v[k-1] && x[k]==v[k] && x[k+1]!=v[k+1]){
     cont +=1;
     contmax++;
     k++;
   }
   else if (x[k-1]==v[k-1] && x[k]==v[k] && x[k+1]!=v[k+1]){
   cont +=3;
   contmax++;
   k++;
 }else if(x[k-1]!=v[k-1] && x[k]==v[k] && x[k+1]==v[k+1]){
   cont +=3;
   contmax++;
   k++;
 }
}
printf("%d\n",contmax);
printf("%d\n",cont);

return 0;
}
