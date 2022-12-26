#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

void esp(char *s);
void scanstring(char *s);
void printstring(char *s);
char* esp1(char *s);

int main(int argc, char* argv[]){
  int size = 9999;
  char *s = malloc(size*sizeof(char));
  scanstring(s);
  char *n = esp1(s);
  printstring(s); printstring(n);
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

void esp(char *s){
  for(int i=0;i<strlen(s);i++)
    if(!isalpha(s[i]) && !isdigit(s[i]))
      s[i] = ' ';
}

char* esp1(char *s){
  char *n = malloc(strlen(s)*sizeof(char));
  for(int i=0;i<strlen(s);i++)
    if(!isalpha(s[i]) && !isdigit(s[i]))
      n[i] = ' ';
    else n[i] = s[i];
  return n;
}