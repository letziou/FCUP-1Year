#include <stdio.h>

int main () {

  int n,m,i,l,k=0,zeros[256]={0};
  char disco[256];

  scanf("%d %d",&n,&m);

  for(i=0;i<n;i++){
    scanf("%s",disco);
    for(l=0;l<m;l++){
      if(disco[l]=='0') zeros[l]++;
    }
  }

  while(k != m){

  if(zeros[k]>=(n/2) && n%2 ==0){
    printf("0");
  }
  else if(zeros[k]>= ((n/2)+1) && n%2!=0){
    printf("0");
  }
  else printf("1");

  k++;
}
  printf("\n");

  return 0;
}
