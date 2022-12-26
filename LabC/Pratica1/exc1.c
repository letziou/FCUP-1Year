#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

void printarrays(int vec[], int size);                       // to print arrays
void printstrings(char str[]);                               // to print strings
void writestrings(char str[]);                               // to write strings
int contar_maiores(int vec[], int size, int val);            // 1.1
int palindromo(char str[]);                                  // 1.2
int decimal(char str[]);                                     // 1.3
int repetidos(int vec[], int size);                          // 1.4
void range(int vec[], int size, int start, int incr);        // 1.5
int filtrar_positivos(int vec[], int size);                  // 1.6
void ordenar(char str[]);                                    // 1.7
int anagramas(char str1[], char str2[]);                     // 1.8


int main() {
  
  char str1[MAX], str2[MAX];
  writestrings(str1);
  writestrings(str2);
  int val = anagramas(str1,str2);
  printf("%d\n",val);
  
return 0;
}

void printarrays(int vec[], int size){
  printf("{");
  int i;
  for(i = 0;i<size-1;i++)
    printf("%d, ",vec[i]);
  printf("%d}\n",vec[i]);
}

void printstrings(char str[]){
  int count = strlen(str);
  for(int i=0;i<count;i++)
    printf("%c",str[i]);
  printf("\n");
}

void writestrings(char str[]){
  int i;
  for(i=0; (str[i] = getchar()) != '\n';i++);
  str[i] = '\0';
}

int contar_maiores(int vec[], int size, int val){
  int count = 0;

  for (int i = 0; i < size; i++){
    if(vec[i] > val) count++;
  }

  return count;
}

int palindromo(char str[]){
  int size = strlen(str);
  for(int i = 0; i < (size+1/2); i++){
    if(str[i] != str[size-1-i])
      return 1;
  }
  return 0;
}

int decimal(char str[]){
  double size = strlen(str), count = 0, dez = 10;
  for(int i=0;i<size;i++){
    count += ((str[i] - '0') * pow(dez,(size-1-i))  ); 
  }
  return count;
}

int repetidos(int vec[], int size){
  for(int i=0;i<size-1;i++){
    for(int j = i+1;j<size;j++)
      if(vec[i] == vec[j]) return 1;
  }
  return 0;
}

void range(int vec[], int size, int start, int incr){
  for(int i=0;i<size;i++){
    vec[i] = start + incr*i;
  }
}

int filtrar_positivos(int vec[], int size){
  int count = 0, new[size], j = 0;
  for(int i=0;i<size;i++){
    if(vec[i]>0){
      new[j] = vec[i];
      j++;
      count++;
    }
  }
  for(int i = 0;i<j;i++){
    vec[i] = new[i];
  }
  return count;
}

void ordenar(char str[]){
  int size = strlen(str);
  for(int i=0;i<size-1;i++)
    for(int j=i;j<size;j++)
      if(str[i] > str[j]){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
}

int anagramas(char str1[], char str2[]){
  int size1 = strlen(str1);
  int size2 = strlen(str2);

  if(size1 != size2) return 0;
  ordenar(str1);
  ordenar(str2);

  for(int i=0;i<size1;i++){
    if(str1[i] != str2[i])
      return 0;
  }
  return 1;
}
