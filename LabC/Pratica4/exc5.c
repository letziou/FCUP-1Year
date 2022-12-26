#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

void scanstring(char *s);
void printstring(char *s);
char* my_strncat(char* dest, char* src, int n);
char* my_strdup(char* s);

int main(int argc, char* argv[]){
  int size = 9999;
  char *s = malloc(size*sizeof(char));
  char *n = malloc(size*sizeof(char));
  scanstring(s);
  scanstring(n);
  char *sn = my_strncat(s,n,5);
  printstring(sn);
  
  return 0;
}

void printstring(char *s){
  for(int i=0;i<strlen(s);i++)
    printf("%c",s[i]);
  printf("\n");
}

void scanstring(char *s){
  int i;
  for(i = 0;(s[i] = getchar()) != '\n';i++){};
  s[i] = '\0';
}

char* my_strncat(char* dest, char* src, int n){
  int a = strlen(dest) + n;
  char* res = malloc(a*sizeof(char));
  for(int i=0;i<strlen(dest);i++)
    res[i] = dest[i];
  for(int i=0;i<n;i++)
    res[i+strlen(dest)] = src[i];
  return res;
}

char* my_strdup(char* s){
  char* res = malloc(strlen(s)*sizeof(char));
  for(int i=0;i<strlen(s);i++)
    res[i] = s[i];
  return res;
}