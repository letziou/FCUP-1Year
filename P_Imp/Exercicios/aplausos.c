#include <stdio.h>
#include<string.h>

int main(){

  char x1[]="bata palmas";
  char x2[]="clap your hands";
  char frase[100];
  int n = 2;
  while (n != 0 ){
    fgets(frase,100,stdin);
    if(strcmp(frase,"aplauda suas maos")){
    printf("%s\n",x2);
  }else if(strcmp(frase,"it has beaten palms")){
    printf("%s\n",x2);
  }else printf("%s",frase);

    n--;
  }

  return 0;
}
