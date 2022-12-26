#include <stdio.h>
#include <stdlib.h>
#define NMAX 9999


void impr(int p[][NMAX],int m,int n,char c);
void repeteLinha(int p[][NMAX],int m,int n,int i);
void repeteColuna(int p[][NMAX],int m,int n,int j);
void dilatar(int p[][NMAX],int m,int n,int linha,int coluna);

int main(int argc, char const *argv[]) {

  int matrix[][NMAX] = {{0,1,1},{0,0,1},{0,0,0},{0,0,0},{0,0,0}};
  impr(matrix,6,4,'#');
  dilatar(matrix,6,4,1,1);
  impr(matrix,6,4,'#');
  return 0;
}

void impr(int p[][NMAX],int m,int n,char c){
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(p[i][j]==1)
        putchar(c);
      else putchar(' ');
    }
    putchar('\n');
  }
}

void repeteLinha(int p[][NMAX],int m,int n,int i){
  for(int k=m-1;k>=i;k--){
    for(int j=0;j<n;j++){
      p[k+1][j] = p[k][j];
    }
  }
}

void repeteColuna(int p[][NMAX],int m,int n,int j){
  for(int i=0;i<m;i++){
    for(int k=n-1;k>=j;k--){
      p[i][k+1] = p[i][k];
    }
  }
}

void dilatar(int p[][NMAX],int m,int n,int linha,int coluna){
  repeteLinha(p,m,n,linha);
  repeteColuna(p,m,n,coluna);
}
