#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testa_compara(char pal1[],char pal2[]);

int main(int argc, char const *argv[]) {
  char pal1[] = "ALA";
  char pal2[] = "OLA";

  int j = testa_compara(pal1,pal2);
  printf("%d\n",j);
  return 0;
}

int testa_compara(char pal1[],char pal2[]){

  for(int i=0;pal1[i] != '\0';i++){
    if(pal1[i]<'A' || pal1[i]>'Z'){
      return -10000;
    }
  }

  for(int j=0;pal2[j] != '\0';j++){
    if(pal2[j]<'A' || pal2[j]>'Z'){
      return -10000;
    }
  }
    for(int k=0;pal2[k] != '\0';k++){
      if(pal1[k]>pal2[k])
        return 3;
      if(pal1[k]<pal2[k])
        return -3;
  }
  return 0;
}
