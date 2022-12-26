#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
  float x;
  float y;
}POINT;

POINT scan();                                                // scanning the point
float Euclidean(POINT p1, POINT p2);
POINT sum(POINT p1, POINT p2);
int total_distance(POINT course[], int size);

int main(int argc, char* argv[]){
  POINT p1,p2;
  p1 = scan();  p2 = scan();
  float val = Euclidean(p1,p2);
  printf("%.3f\n",val);
  POINT p3 = sum(p1,p2);
  printf("%.3f %.3f\n",p3.x,p3.y);
  POINT course[] = {p1,p2,p3};
  printf("%d\n",total_distance(course,3));
  return 0;
}

POINT scan(){
  POINT px;
  scanf("%f %f",&px.x,&px.y);
  return px;
}
float Euclidean(POINT p1, POINT p2){
  float x = p1.x - p2.x;
  float y = p1.y - p2.y;
  return sqrt(x*x + y*y);
}

POINT sum(POINT p1, POINT p2){
  POINT p3;
  p3.x = p1.x + p2.x;
  p3.y = p1.y + p2.y;
  return p3;
}

int total_distance(POINT course[], int size){
  int count = 0;
  for(int i=0;i<size-1;i++)
    count += Euclidean(course[i], course[i+1]);
  return count;
}