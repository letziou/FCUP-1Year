#include <stdio.h>
#include <stdlib.h>
DEFINE NMAX 9999

void imprimeLinha(int mat[][NMAX],int k,int n);
int maximo(int mat[][NMAX],int m,int n);

int main(int argc, char const *argv[]) {
  return 0;
}

void imprimeLinha(int mat[][NMAX],int k,int n){
  printf("%d",mat[k][0]);
  for(int i=0;i<n;i++)
    printf(" %d"mat[k][i]);
    printf("\n");
}

int maximo(int mat[][NMAX],int m,int n){
  int max=0;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(mat[i][j]>max)
        max = mat[i][j];
    }
  }
  return max;
}
