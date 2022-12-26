#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
  
  int size, number; scanf("%d",&size);
  bool array[99];
  for(int i=0;i<99;i++){
    array[i] = false;
  }

  while (size!=0){
    scanf("%d",&number);
    if(array[number]==false) array[number] = true;
    else printf("%d\n",number);
    size--;
  }
  
  
  return 0;
}
