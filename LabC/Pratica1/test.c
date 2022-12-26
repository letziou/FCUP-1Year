#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9999

int contar_maiores(int vec[], int size, int val);            // 1.1
int palindromo(char str[]);                                  // 1.2
int decimal(char str[]);                                     // 1.3
int repetidos(int vec[], int size);                          // 1.4
void range(int vec[], int size, int inicio, int incr);       // 1.5
int filtrar_positivos(int vec[], int size);                  // 1.6
void ordenar(char str[]);                                    // 1.7
int anagramas(char str1[], char str2[]);                     // 1.8

int main(int argc,char* argv[]) {

  char str1[MAX];
  char str2[MAX];
  scanf("%s",str1);
  scanf("%s",str2);
  int a = anagramas(str1,str2);
  printf("%d\n",a);

  return 0;
}

int contar_maiores(int vec[], int size, int val){
  int count=0;

  for(int i=0;i<size;i++)
    if(vec[i]>val)
      count++;
  return count;
}

int palindromo(char str[]){
  int size = strlen(str);
  for(int i=0;i<(size/2);i++)
    if(str[i] != str[size-1-i])
      return 1;
  return 0;
}

int decimal(char str[]){
  return atoi(str);
}

int repetidos(int vec[], int size){
  for(int i=0;i<size-1;i++)
    for(int j=i+1;j<size;j++)
      if(vec[i]==vec[j])
        return 1;
  return 0;
}

void range(int vec[], int size, int inicio, int incr){
  int count = inicio;
  vec[0] = count;
  for(int i=1;i<size;i++){
    count += incr;
    vec[i] = count;
  }
}

int filtrar_positivos(int vec[], int size){
  int count = 0;

  for(int i=0;i<size;i++)
    if(vec[i]>0)
      count++;

  int new[count];
  int j=0;
  for(int i=0;i<size;i++)
    if(vec[i]>0){
      new[j] = vec[i];
      j++;
    }
  for(int i=0;i<count;i++)
    vec[i] = new[i];
  return count;
}

void ordenar(char str[]){
  int max = strlen(str);
  char change;

  for(int i=0;i<max-1;i++)
    for(int j=i+1;j<max;j++){
      if(str[j]<str[i]){
        change = str[i];
        str[i] = str[j];
        str[j] = change;
      }
    }
}

int anagramas(char str1[], char str2[]){
  ordenar(str1);
  ordenar(str2);
  int size = strlen(str1);
  int osize = strlen(str2);

  if(size != osize) return 0;

  for(int i=0;i<size;i++)
    if(str1[i] != str2[i]) return 0;
  return 1;
}
