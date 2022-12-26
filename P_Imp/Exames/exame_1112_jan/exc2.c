#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 9999

void conta(int a,int b,int n,int fs[]);
int maxv(int v[],int nv);
void diagr(int fs[],int nfs,char s);

int main(int argc, char const *argv[]) {
  int n,a,b;
  scanf("%d %d %d",&a,&b,&n);

  int fs[NMAX];

  conta(a,b,n,fs);
  // for(int i=0;i<(b-a+1);i++){
  //   printf("%d -> %d\n",i,fs[i]);
  // }
  diagr(fs,(b-a+1),'*');

  return 0;
}

void conta(int a,int b,int n,int fs[]){
  int novo;
  for(int i=0;i<b-a+1;i++){
    fs[i]=0;
  }

  for(int i=0;i<n;i++){
    scanf("%d\n",&novo);

    if(novo<(b+1) && novo>(a-1)){
      fs[novo-a]++;
    }
  }
}

int maxv(int v[],int nv){
  int contmax = v[0];
  for(int i=1;i<nv;i++)
    if(v[i]>contmax)
      contmax = v[i];

  return contmax;
}

void diagr(int fs[],int nfs,char s){
  int max = maxv(fs,nfs);

  for(int i=max;i>0;i--){
    for(int j=0;j<nfs;j++){
      if(fs[j]>=i) {putchar (s);}
      else putchar (' ');
    }
    putchar ('\n');
  }

  for(int i=0;i<nfs;i++)
    putchar ('-');
  putchar ('\n');
}
