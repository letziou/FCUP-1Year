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

void red(PIXEL **array, int rows, int cols);
void green(PIXEL **array, int rows, int cols);
void blue(PIXEL **array, int rows, int cols);

int main(int argc, char* argv[]) {

    FILE* buf;
    FILE* end;


    if(argc == 3){
      buf = fopen(argv[1],"r");
      end = fopen(argv[2],"w");
    }

    if(argc == 1){
      buf = stdin;
      end = stdout;
    }

    if(argc == 2){
      buf = fopen(argv[1],"r");
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


    fprintf(end ,"%s\n%d %d\n%d\n",m.type,m.larg,m.compr,m.pixelmax);

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

      int fullred = 0;
      int fullgreen = 0;
      int fullblue = 0;
      int count = 0;

       for(int i=0;i<m.compr;i++)
         for(int j=0;j<m.larg;j++){
           array[i][j].red = p[i][j].red;
           array[i][j].green = p[i][j].green;
           array[i][j].blue = p[i][j].blue;
           fullred += p[i][j].red;
           fullgreen += p[i][j].green;
           fullblue += p[i][j].blue;
           count++;
         }

        int maxred = fullred/count;
        int maxgreen = fullgreen/count;
        int maxblue = fullblue/count;

        if(maxred>maxgreen && maxred>maxblue)
          red(array,m.compr,m.larg);
        else if(maxgreen>maxred && maxgreen>maxblue)
          green(array,m.compr,m.larg);
        else blue(array,m.compr,m.larg);

        for(int i=0;i<m.compr;i++)
          for(int j=0;j<m.larg;j++){
            fprintf(end ,"%d %d %d\n",array[i][j].red,array[i][j].green,array[i][j].blue);
          }


    fclose(buf);
    fclose(end);
    for (int i=0; i<m.compr; i++) {
      free(array[i]);
    }
    free(array);


    return 0;
  }

void red(PIXEL **array, int rows, int cols){
  for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++){
      array[i][j].green = 0;
      array[i][j].blue = 0;
    }
}

void green(PIXEL **array, int rows, int cols){
  for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++){
      array[i][j].red = 0;
      array[i][j].blue = 0;
    }
}

void blue(PIXEL **array, int rows, int cols){
  for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++){
      array[i][j].red = 0;
      array[i][j].green = 0;
    }
}
