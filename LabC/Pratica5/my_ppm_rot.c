#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Pixel{
  int red;
  int green;
  int blue;
};

typedef struct Pixel PIXEL;

int main (int argc ,char* argv[]){

  FILE* in;
  FILE* out;
  char* type = "P3";
  char ignore;
  int compr, larg;
  int pixelmax;
  int* red,green,blue;
  int total_pixel = compr*larg;

  in = fopen(argv[1],"r");
  out = fopen(argv[2],"w");

  fscanf(in ,("%s") ,&ignore);
  fscanf(in ,("%d %d"),&compr,&larg);
  fscanf(in ,("%d"),&pixelmax);


  PIXEL* p ;

  for(int i=0; i<compr*larg ;i++)
    fscanf(in ,("%d %d %d") ,&p[i].red,&p[i].green,&p[i].blue);


  fprintf(out ,"%s\n",type);
  fprintf(out ,"%d %d\n",compr,larg);
  fprintf(out ,"%d\n",pixelmax);

  //for(int i=0; i<compr*larg;i++)
    //fprintf(out, "%d %d %d\n",p[i].red,p[i].green,p[i].blue );





  fclose(in);
  fclose(out);
}
