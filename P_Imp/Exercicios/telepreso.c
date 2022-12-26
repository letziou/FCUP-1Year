#include <stdio.h>

int main () {

  char telemovel[10][4] = {{'+'},
                           {'_'},
                           {'A','B','C'},
                           {'D','E','F'},
                           {'G','H','I'},
                           {'J','K','L'},
                           {'M','N','O'},
                           {'P','Q','R','S'},
                           {'T','U','V'},
                           {'W','X','Y','Z'}};

  int anterior,novo,cont=0;

  scanf("%d",&anterior);

  if(anterior == 99) return 0;

  while (novo != 99){

  scanf("%d",&novo);

    if(novo == anterior) cont++;

    else if(novo == 77){
      printf("%c",telemovel[anterior][cont]);
      cont = 0;
      anterior = novo;
    }

    else {
      if(anterior != 77){
      printf("%c",telemovel[anterior][cont]);
    }
      cont = 0;
      anterior = novo;
    }
  }
  printf("\n");

  return 0;
}
