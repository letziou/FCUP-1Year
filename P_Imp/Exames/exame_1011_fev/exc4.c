#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 9999

typedef struct {
  char eq1[NMAX];
  int golos1;
  char eq2[NMAX];
  int golos2;
} RESULTADO;

int eliminatoria(RESULTADO r1,RESULTADO r2);
int DifGolos(RESULTADO res[],int nj);
RESULTADO paraPassar(RESULTADO r);

int main(int argc, char const *argv[]) {
  RESULTADO r1 = {"Ases",2,"Tios",1};

  RESULTADO j = paraPassar(r1);
  printf("%d %d\n",j.golos1,j.golos2 );
  return 0;
}

int eliminatoria(RESULTADO r1,RESULTADO r2){
  int goloeq1 = (r1.golos1 + r2.golos2);
  int goloeq2 = (r1.golos2 + r2.golos1);

  if(goloeq1>goloeq2)
    return 1;
  if(goloeq1<goloeq2)
    return 2;
  if(goloeq1==goloeq2 && r1.golos2>r2.golos2)
    return 2;
  if(goloeq1==goloeq2 && r1.golos2<r2.golos2)
    return 1;

  return 0;
}

int DifGolos(RESULTADO res[],int nj){
  int contcasa=0,contfora=0;
  int diferenca;
  for(int i=0;i<nj;i++){
    contcasa += res[i].golos1;
    contfora += res[i].golos2;
  }
  diferenca = contcasa-contfora;
  return diferenca;
}

RESULTADO paraPassar(RESULTADO r){
  RESULTADO f = {"x",0,"y",0};

  if(r.golos2==0){
    f.golos1 = (r.golos1+1);
    f.golos2 = 0;
  }
  else if(r.golos2>r.golos1){
    f.golos1 = 0;
    f.golos2 = 0;
  }
  else{
    f.golos1 = (r.golos1-r.golos2);
    f.golos2 = 0;
  }
  return f;
}
