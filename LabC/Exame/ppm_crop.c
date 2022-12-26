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

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);

    int larg = c-a+1;
    int compr = d-b+1;

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

    int e;

    DATA m;

    fscanf(buf ,("%s") ,m.type);
    getc(buf); //para mudar para a nova linha

    // para remover quaisquer comentarios
    e = getc(buf);
    while (e == '#') {
    while (getc(buf) != '\n'){};
         e = getc(buf);
    }
    ungetc(e, buf);


    fscanf(buf ,("%d %d %d"),&m.larg,&m.compr,&m.pixelmax);


    PIXEL p[m.compr][m.larg];


    for(int i=0; i<m.compr ;i++)
      for(int j=0 ; j<m.larg ;j++)
        fscanf(buf ,"%d %d %d" ,&p[i][j].red,&p[i][j].green,&p[i][j].blue);


    fprintf(end ,"%s\n%d %d\n%d\n",m.type,larg,compr,m.pixelmax);

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
       for(int i=0;i<m.compr;i++){
         for(int j=0;j<m.larg;j++){
           array[i][j].red = p[i][j].red;
           array[i][j].green = p[i][j].green;
           array[i][j].blue = p[i][j].blue;
         }}

        for(int i=b;i<=d;i++)
          for(int j=a;j<=c;j++){
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
