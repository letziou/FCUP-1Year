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

  int border = atoi(argv[1]);
  int addred = atoi(argv[2]);
  int addgreen = atoi(argv[3]);
  int addblue = atoi(argv[4]);

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
    array = malloc( (m.compr + (4*border)) * sizeof(struct Pixel*) );
      if(array == NULL){
        printf("Out of memory!\n");
      return 0;
      }
      for(int i=0;i<(m.compr + (4*border));i++){
        array[i] = malloc( (m.larg + (4*border)) * sizeof(struct Pixel) );
        if(array[i] == NULL){
          printf("Out of memory!\n");
          return 0;
        }
      }

    // cria uma imagem que tem a cor da moldura
      for(int k=0;k<(m.compr + (4*border));k++){
        for(int l=0;l<(m.larg + (4*border));l++){
          array[k][l].red = addred;
          array[k][l].green = addgreen;
          array[k][l].blue = addblue;
        }
      }

      // copia a imagem original para cima da imagem da moldura
       for(int i=0;i<m.compr;i++)
         for(int j=0;j<m.larg;j++){
           array[i + border][j + border].red = p[i][j].red;
           array[i + border][j + border].green = p[i][j].green;
           array[i + border][j + border].blue = p[i][j].blue;
         }


        for(int i=0;i<m.compr;i++)
          for(int j=0;j<m.larg;j++){
            fprintf(end ,"%d %d %d\n",array[i][j].red,array[i][j].green,array[i][j].blue);
          }


    fclose(buf);
    fclose(end);
    for (int i=0; i<(m.compr + (4*border)); i++) {
      free(array[i]);
    }
    free(array);


    return 0;
  }
