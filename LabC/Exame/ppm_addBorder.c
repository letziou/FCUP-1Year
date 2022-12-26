#include <stdio.h>
#include <stdlib.h>

struct Pixel{
  int red;
  int green;
  int blue;
};

typedef struct Pixel PIXEL;

struct Data{
  char type[42];
  int compr, larg;
  int pixelmax;
};

typedef struct Data DATA;

int main(int argc, char* argv[]) {

    FILE* buf;
    FILE* end;

    int border = atoi(argv[1]);
    int red = atoi(argv[2]);
    int green = atoi(argv[3]);
    int blue = atoi(argv[4]);

    if(argc == 7){
      buf = fopen(argv[5],"r");
      end = fopen(argv[6],"w");
    }

    if(argc == 5){
      buf = stdin;
      end = stdout;
    }

    if(argc == 6){
      buf = fopen(argv[5],"r");
      end = stdout;
    }

    int c;

    DATA m;

    fscanf(buf ,("%s") ,m.type);

    getc(buf); //para mudar para a nova linha

    // para remover quaisquer comentarios
    c = getc(buf);
    while (c == '#') {
    while (getc(buf) != '\n'){};
         c = getc(buf);
    }
    ungetc(c, buf);


    fscanf(buf ,("%d %d %d"),&m.larg,&m.compr,&m.pixelmax);


    PIXEL p[m.compr][m.larg];


    for(int i=0; i<m.compr ;i++)
      for(int j=0 ; j<m.larg ;j++)
        fscanf(buf ,"%d %d %d" ,&p[i][j].red,&p[i][j].green,&p[i][j].blue);


    fprintf(end ,"%s\n%d %d\n%d\n",m.type,(m.larg + (2*border)),(m.compr + (2*border)),m.pixelmax);

    PIXEL **array;
    array = malloc((m.compr + (2*border)) * sizeof(struct Pixel*));
      if(array == NULL){
        printf("Out of memory!\n");
      return 0;
      }
      for(int i=0;i<(m.compr + (2*border));i++){
        array[i] = malloc((m.larg + (2*border)) * sizeof(struct Pixel));
        if(array[i] == NULL){
          printf("Out of memory!\n");
          return 0;
        }
      }
      // copia todos os elementos que estão em cada pixel para um array de arrays
       for(int i=0;i<(m.compr + (2*border));i++)
         for(int j=0;j<(m.larg + (2*border));j++){
           array[i][j].red = red;
           array[i][j].green = green;
           array[i][j].blue = blue;
         }

       for(int i=0;i<m.compr;i++)
         for(int j=0;j<m.larg;j++){
           array[i+border][j+border].red=p[i][j].red;
           array[i+border][j+border].green=p[i][j].green;
           array[i+border][j+border].blue=p[i][j].blue; 
         }

        for(int i=0;i<(m.compr + (2*border));i++)
          for(int j=0;j<(m.larg + (2*border));j++){
            fprintf(end ,"%d %d %d\n",array[i][j].red,array[i][j].green,array[i][j].blue);
          }


    fclose(buf);
    fclose(end);
    for (int i=0; i<(m.compr + (2*border)); i++) {
      free(array[i]);
    }
    free(array);


    return 0;
  }
