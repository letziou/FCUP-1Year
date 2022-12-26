#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* readarray(int n);
void printarray(int *v, int n);
int* sumarray(int *v1, int* v2, int n);

int main(int argc, char* argv[]){
  int size;
  int *v1, *v2, *vt;
  scanf("%d",&size);
  v1 = readarray(size);
  v2 = readarray(size);
  printarray(v1,size);
  printarray(v2,size);
  vt = sumarray(v1,v2,size);
  printarray(vt,size);
  return 0;
}

int* readarray(int n){
int i;
int *v = malloc(n*sizeof(int));
for (i=0; i<n; i++){
scanf("%d",v+i);
}
return v;
}

void printarray(int *v, int n){
  int i;
  printf("[");
  for(i=0;i<n-1;i++){
    printf("%d,",v[i]);
  }
  printf("%d]\n",v[i]);
}

int* sumarray(int *v1, int* v2, int n){
  int *vt = malloc(n*sizeof(int));
  for(int i=0;i<n;i++){
    vt[i] = v1[i] + v2[i];
  }
  return vt;
}