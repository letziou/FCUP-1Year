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

void rotate(PIXEL **array, int rows, int cols,int bar, int red, int green, int blue, int pos);

int main(int argc, char* argv[]) {

    FILE* buf;
    FILE* end;

    int bar = atoi(argv[1]);
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
      // copia todos os elementos que estão em cada pixel para um array de arrays
       for(int i=0;i<m.compr;i++)
         for(int j=0;j<m.larg;j++){
           array[i][j].red = p[i][j].red;
           array[i][j].green = p[i][j].green;
           array[i][j].blue = p[i][j].blue;
         }

      int space = bar;

       for(int i=0;i<m.larg;i++){
         if(i==space){
           rotate(array,m.compr,m.larg,bar,red,green,blue,i);
           space += (2*bar);
        }
      }

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

// troca a posição de todos os pontos mais a esquerda do centro com os que estão mais a direita
void rotate(PIXEL **array, int rows, int cols,int bar, int red, int green, int blue, int pos){
  for(int i=0;i<rows;i++){
    for(int j=pos;j<(pos+bar);j++){
      if(j>=cols) break;
      array[i][j].red = red;
      array[i][j].green = green;
      array[i][j].blue = blue;
    }
  }
}
