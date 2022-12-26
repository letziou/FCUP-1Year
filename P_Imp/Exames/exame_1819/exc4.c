#include <stdio.h>

int kmin(int k,int v[],int n);

int main(int argc, char const *argv[]) {

  return 0;
}

int kmin(int k,int v[],int n){
  int temp;
  for(int i=0;i<n;i++){                     // bubblesort method
    for(int j=0;j<n-i-1;j++){
        if(v[i]>v[i+1]){
          temp = v[i];
          v[i] = v[i+1];
          v[i+1] = temp;
      }
    }
  }
  return v[k];
}
