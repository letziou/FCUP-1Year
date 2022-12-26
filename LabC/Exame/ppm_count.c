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

    if(argc == 2){
      buf = fopen(argv[1],"r");
    }

    if(argc == 1){
      buf = stdin;
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

    PIXEL **array;
    array = malloc(m.compr * sizeof(struct Pixel*));
      if(array == NULL){
        printf("Out of memory!\n");
      return 0;
      }
      for(int i=0;i<m.compr;i++){
        array[i] = malloc(m.larg * sizeof(struct Pixel));
        if(array[i] == NULL){
          printf("Out of memory!\n");
          return 0;
        }
      }
      // copia todos os elementos que estão em cada pixel para um array de arrays
       for(int i=0;i<m.compr;i++)
         for(int j=0;j<m.larg;j++){
           array[i][j].red = p[i][j].red;
           array[i][j].green = p[i][j].green;
           array[i][j].blue = p[i][j].blue;
         }

      int maxred = 0;
      int maxgreen = 0;
      int maxblue = 0;
      int oldred = 0;
      int oldgreen = 0;
      int oldblue = 0;
      int count = 0;
      int maxcount = 0;

      for(int i=0;i<m.compr;i++){
        for(int j=0;j<m.larg;j++){
          if(array[i][j].red==oldred && array[i][j].green==oldgreen && array[i][j].blue==oldblue) continue;
          if(array[i][j].red==maxred && array[i][j].green==maxgreen && array[i][j].blue==maxblue) continue;
          for(int a=i;a<m.compr;a++){
            for(int b=j;b<m.larg;b++){
              if(array[a][b].red == array[i][j].red && array[a][b].green == array[i][j].green && array[a][b].blue == array[i][j].blue)
                count++;
            }
          }
          if(count>=maxcount){
            maxred = array[i][j].red;
            maxgreen = array[i][j].green;
            maxblue = array[i][j].blue;
            maxcount = count;
          }
          oldred = array[i][j].red;
          oldgreen = array[i][j].green;
          oldblue = array[i][j].blue;
          count = 0;
        }
      }

      printf("%d %d %d %d\n",maxcount,maxred,maxgreen,maxblue);

    fclose(buf);
    for (int i=0; i<m.compr; i++) {
      free(array[i]);
    }
    free(array);


    return 0;
  }
