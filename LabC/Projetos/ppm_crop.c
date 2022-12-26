#include <stdio.h>
#include <stdlib.h>

struct Pixel{
  int red;
  int green;
  int blue;
};

typedef struct Pixel PIXEL;

struct Data{
  char type[2];
  int compr, larg;
  int pixelmax;
};

typedef struct Data DATA;

int main(int argc, char* argv[]) {

    FILE* buf;
    FILE* end;

  int cini = atoi(argv[1]);
  int lini = atoi(argv[2]);
  int cfim = atoi(argv[3]);
  int lfim = atoi(argv[4]);

  int comprfinal = cfim - cini;
  int largfinal = lfim - lini;


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


    fprintf(end ,"%s\n%d %d\n%d\n",m.type,comprfinal,largfinal,m.pixelmax);

    PIXEL **array;
    array = malloc( (largfinal) * sizeof(struct Pixel*) );
      if(array == NULL){
        printf("Out of memory!\n");
      return 0;
      }
      for(int i=0;i<largfinal;i++){
        array[i] = malloc( (comprfinal) * sizeof(struct Pixel) );
        if(array[i] == NULL){
          printf("Out of memory!\n");
          return 0;
        }
      }

      for(int i=0,k=lini;k<largfinal;i++,k++){
        for(int j=0,l=cini;l<comprfinal;j++,l++){
          array[i][j].red = p[k][l].red;
          array[i][j].green = p[k][l].green;
          array[i][j].blue = p[k][l].blue;
        }
      }

        for(int i=0;i<largfinal;i++)
          for(int j=0;j<comprfinal;j++){
            fprintf(end ,"%d %d %d\n",array[i][j].red,array[i][j].green,array[i][j].blue);
          }

    fclose(buf);
    fclose(end);
    // for (int i=0; i<comprfinal; i++) {
    //   free(array[i]);
    // }
    // free(array);


    return 0;
  }
