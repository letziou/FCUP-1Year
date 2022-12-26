#include <stdio.h>
#include <string.h>
#include <stdlib.h>

  int* my_strdup(char *src, char *dest, int n){
    int* v = malloc(strlen(src)*sizeof(int));
    for(int i=0;i<n;i++){
      dest[i]=src[i];
    }
    dest[n] = '\0';

    return v;
  }

  char* my_strdup1(char *s){
    char* v = malloc(strlen(s)*sizeof(int));
    for(int i=0;i<strlen(s);i++)
      v[i]=s[i];

    v[strlen(s)] = '\0';

    return v;
  }

  char* my_strncat(char *dest,char *src, int n){
    char* v = malloc((strlen(dest)+strlen(src))*sizeof(int));

    int a = strlen(dest);

    for(int i=0;i<strlen(dest);i++)
      v[i]=dest[i];

    for(int j=0;j<n;j++)
      v[a+j]=src[j];

      return v;
  }


  int main(){

    char* s = "ola xerife :)";
    char* x = " Aii caramba !!";

    char* l = my_strncat(s,x,3);

    printf("%s\n",l);
    return 0;
  }
