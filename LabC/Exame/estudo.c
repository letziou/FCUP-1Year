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
    FILE* sec;
    FILE* end;

    if(argc == 4){
      buf = fopen(argv[1],"r");
      sec = fopen(argv[2],"r");
      end = fopen(argv[3],"w");
    }

    if(argc == 3){
      buf = fopen(argv[5],"r");
      sec = stdin;
      end = stdout;
    }

    int c;

    DATA m;
    DATA s;

    fscanf(buf ,("%s") ,m.type);
    fscanf(sec ,("%s") ,s.type);

    getc(buf); //para mudar para a nova linha

    // para remover quaisquer comentarios
    c = getc(buf);
    while (c == '#') {
    while (getc(buf) != '\n'){};
         c = getc(buf);
    }
    ungetc(c, buf);

    getc(sec); //para mudar para a nova linha

    // para remover quaisquer comentarios
    c = getc(sec);
    while (c == '#') {
    while (getc(sec) != '\n'){};
         c = getc(sec);
    }
    ungetc(c, sec);

    fscanf(buf ,("%d %d %d"),&m.larg,&m.compr,&m.pixelmax);
    fscanf(sec ,("%d %d %d"),&s.larg,&s.compr,&s.pixelmax);


    PIXEL p[m.compr][m.larg];
    PIXEL a[s.compr][s.larg];

    int rows;

    if(m.compr>s.compr) rows = s.compr;
    else rows = m.compr;


    for(int i=0; i<m.compr ;i++)
      for(int j=0 ; j<m.larg ;j++)
        fscanf(buf ,"%d %d %d" ,&p[i][j].red,&p[i][j].green,&p[i][j].blue);

    for(int i=0; i<s.compr ;i++)
      for(int j=0 ; j<s.larg ;j++)
        fscanf(sec ,"%d %d %d" ,&a[i][j].red,&a[i][j].green,&a[i][j].blue);


    fprintf(end ,"%s\n%d %d\n%d\n",m.type,(m.larg+s.larg),rows,m.pixelmax);

    PIXEL **array;
    array = malloc(rows * sizeof(struct Pixel*));
      if(array == NULL){
        printf("Out of memory!\n");
      return 0;
      }
      for(int i=0;i<rows;i++){
        array[i] = malloc((m.larg+s.larg) * sizeof(struct Pixel));
        if(array[i] == NULL){
          printf("Out of memory!\n");
          return 0;
        }
      }
      // copia todos os elementos que estão em cada pixel para um array de arrays
      for(int i=0;i<rows;i++){
        for(int j=0;j<m.larg;j++){
          array[i][j].red = p[i][j].red;
          array[i][j].green = p[i][j].green;
          array[i][j].blue = p[i][j].blue;
        }
      }

      for(int i=0;i<rows;i++){
        for(int j=0;j<s.larg;j++){
          array[i][m.larg+j].red = a[i][j].red;
          array[i][m.larg+j].green = a[i][j].green;
          array[i][m.larg+j].blue = a[i][j].blue;
        }
      }

    for(int i=0;i<rows;i++)
      for(int j=0;j<(m.larg+s.larg);j++){
        fprintf(end ,"%d %d %d\n",array[i][j].red,array[i][j].green,array[i][j].blue);
      }


    fclose(buf);
    fclose(sec);
    fclose(end);
    for (int i=0; i<rows; i++) {
      free(array[i]);
    }
    free(array);

    return 0;
}
