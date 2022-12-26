#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


  void esp(char *s){
    for(int i=0;i<strlen(s);i++){
      if(!isalpha(s[i]))
        s[i] = ' ';
    }
  }

  char* esp1(char *s){
    char* v = malloc(strlen(s)*sizeof(int));

    for(int i=0;i<strlen(s);i++){
      if(!isalpha(s[i]))
        s[i] = ' ';
    }
    return v;
  }

  int main(int argc,char* argv[]){

    char s[] = "Ola -i-r-mao !!";
    printf("%s\n",s);
    esp1(s);
    printf("%s\n",s);
   return 0;
}
