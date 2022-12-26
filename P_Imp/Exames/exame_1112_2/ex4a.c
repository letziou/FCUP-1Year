#include <stdio.h>
#include <string.h>
#define MAX 999999

int acordo_porto(char s[]);

int main(){

  char s[MAX];
  scanf("%s",x);
  int a = strlen(s);
  int b = acordo_porto(s);
  printf("Frase antiga tem : %d\nNova frase tem : %d",a,b);

  return 0;
}

int acordo_porto(char s[]){
  int max = strlen(s);
  for(int i=0, int livre =0; i<max ; i++){
    if(s[i]=='v')
      s[livre++] = 'b';
    else if(s[i]=='V')
      s[livre++] = 'B';
    else if(s[i]=='c' && s[i+1]==s[i]){
      s[livre++] = 'c'
      i++;
    }
    else if(s[i]=='C' && s[i+1]==s[i]){
      s[livre++] = 'C'
      i++;
    }
    else s[livre++] = s[i];
  }
  s[livre] = '\0';
  return livre;
}
