#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  float x;
  float y;
} PONTO;

float distancia(PONTO p1, PONTO p2);
float distancia_total(PONTO percurso[], int size);
PONTO soma(PONTO p1, PONTO p2);

int main(int argc, char *argv[]) {
  PONTO p1, p2, p3;
  PONTO caminho[] = {{0,0},{0,1},{1,1},{4,5}};
  int size = 4;
  printf("Insere as coordenadas do p1:\n");
  scanf("%f %f",&p1.x, &p1.y);
  printf("Insere as coordenadas do p2:\n");
  scanf("%f %f",&p2.x, &p2.y);
  float dist = distancia(p1,p2);
  p3 = soma(p1,p2);
  printf("distancia entre p1 e p2 = %f\n",dist);
  printf("vetor soma de p1 e p2 = %f %f\n",p3.x, p3.y);
  dist = distancia_total(caminho,size);
  printf("total da distancia do caminho é = %f\n",dist);
  return 0;
}

float distancia(PONTO p1, PONTO p2){
  float x = p2.x - p1.x;
  float y = p2.y - p1.y;
  float total = sqrt(x*x + y*y);
  return total;
}

float distancia_total(PONTO percurso[], int size){
  int total = 0;
  for(int i=0;i<size-1;i++)
    total += distancia(percurso[i],percurso[i+1]);
  return total;
}

PONTO soma(PONTO p1, PONTO p2){
  PONTO p3;
  p3.x = p1.x + p2.x;
  p3.y = p1.y + p2.y;
  return p3;
}
