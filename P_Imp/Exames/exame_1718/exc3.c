#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int montanhas(char str[]);

int main(int argc, char const *argv[]) {
  char str[] = {"SSDSDDSDDDSS"};
  int i=montanhas(str);
  printf("%d\n",i);
  return 0;
}

int montanhas(char str[]){
  int pos=0,montanhas=0;

  for(int i=0;str[i] != '\0';i++){
    if(str[i]=='S' && pos==0){
      pos++;
      for(int i=0;str[i] != '\0' || pos !=0;i++){
        if(str[i]=='S')
          pos++;
        else pos--;
      }
      montanhas++;
    }
    else pos--;
  }
  return montanhas;
}
