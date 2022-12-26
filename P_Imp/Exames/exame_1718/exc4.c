#include <stdio.h>

void bubblesort(int vec[],int n);

int main(int argc, char const *argv[]) {
  int vec[]={2,3,4,5,6,7,1};
  bubblesort(vec,7);
  for(int i=0;i<7;i++){
    printf("%d\n",vec[i]);
  }
  return 0;
}

void bubblesort(int vec[],int n){
  int i,temp;
  for(i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++)
    if(vec[j]>vec[j+1]){
      temp = vec[j];
      vec[j] = vec[j+1];
      vec[j+1] = temp;
    }
  }
}
