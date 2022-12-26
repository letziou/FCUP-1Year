#include <stdio.h>
#include <stdlib.h>

char rodar_letra(char ch);

int main(int argc, char const *argv[]) {
  char c = rodar_letra('b');
  printf("%c\n",c);
  return 0;
}

char rodar_letra(char ch){
  if(ch=='Z')
    return 'A';

  if(ch=='z')
    return 'a';

  return ch+1;
}
