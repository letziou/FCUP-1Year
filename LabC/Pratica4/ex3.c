#include <stdio.h>
#include <stdlib.h>


  int* readarray(int n){
   int i;
   int *v = (int *)malloc(n*sizeof(int));     // ao usar o malloc ele cai alocar a memoria para o programa todo


   for (i=0; i<n; i++){
     scanf("%d", v+i);
   }

   return v;
  }

  int* somaarrays(int *va, int *vb, int n) {
   int *v = malloc(n*sizeof(int));

   for(int i=0;i<n;i++)
    v[i] = va[i] + vb[i];

   return v;
  }

  void printarray(int *v, int n){
   for(int i=0;i<n;i++)
    printf("%d ",v[i]);

    printf("\n");
  }

  int main(){
   int n;
   int *va, *vb, *vr;


   scanf("%d", &n);
   va = readarray(n);
   vb = readarray(n);
   vr = somaarrays(va, vb, n);
   printarray(va, n);
   printarray(vb, n);
   printarray(vr, n);
   return 0;
}
