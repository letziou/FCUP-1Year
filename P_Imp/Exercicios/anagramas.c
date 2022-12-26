#include <stdio.h>

int main () {

  char linha[201];
  char x[201];
  int cont = 0,contlinha = 0,i,l;

  for(i=0; (x[i]= getchar()) != '\n';i++){

    if( (96 < x[i]) && (x[i] < 123)) cont += (x[i] - 96);

    else if( (64 < x[i]) && (x[i] < 91)) cont += (x[i]-64);

    else cont += 0;
  }

  for(l=0; (linha[l]= getchar()) != '\n';i++){

    if( (96 < linha[l]) && (linha[l] < 123)) contlinha += (linha[l] - 96);

    else if( (64 < linha[l]) && (linha[l] < 91)) contlinha += (linha[l]-64);

    else cont += 0;
  }

  if (cont == contlinha) printf("yes\n");

  else printf("no\n");

  return 0;

}
