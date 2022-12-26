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

    FILE* fir;
    FILE* sec;
    FILE* end;

    if(argc == 4){
      fir = fopen(argv[1],"r");
      sec = fopen(argv[2],"r");
      end = fopen(argv[3],"w");
    }

    if(argc == 3){
      fir = fopen(argv[1],"r");
      sec = fopen(argv[2],"r");
      end = stdout;
    }

    DATA f;
    DATA s;

    int c;
    fscanf(fir ,("%s") ,f.type);

    getc(fir); //para mudar para a nova linha

    // para remover quaisquer comentarios
    c = getc(fir);
    while (c == '#') {
    while (getc(fir) != '\n'){};
         c = getc(fir);
    }
    ungetc(c, fir);

    fscanf(sec ,("%s") ,s.type);

    getc(sec); //para mudar para a nova linha

    // para remover quaisquer comentarios
    c = getc(sec);
    while (c == '#') {
    while (getc(sec) != '\n'){};
         c = getc(sec);
    }
    ungetc(c, sec);

    fscanf(fir ,("%d %d %d"),&f.larg,&f.compr,&f.pixelmax);
    fscanf(sec ,("%d %d %d"),&s.larg,&s.compr,&s.pixelmax);

    int rows;

    if(f.compr>s.compr) rows = s.compr;
    else rows = f.compr;

    PIXEL p[f.compr][f.larg];
    PIXEL x[s.compr][s.larg];


    for(int i=0; i<f.compr ;i++)
      for(int j=0 ; j<f.larg ;j++)
        fscanf(fir ,"%d %d %d" ,&p[i][j].red,&p[i][j].green,&p[i][j].blue);

    for(int i=0; i<s.compr ;i++)
      for(int j=0 ; j<s.larg ;j++)
        fscanf(sec ,"%d %d %d" ,&x[i][j].red,&x[i][j].green,&x[i][j].blue);

    fprintf(end ,"%s\n%d %d\n%d\n",f.type,(f.larg+s.larg),rows,f.pixelmax);

    PIXEL **array;
    array = malloc(rows * sizeof(struct Pixel*));
      if(array == NULL){
        printf("Out of memory!\n");
      return 0;
      }
      for(int i=0;i<rows;i++){
        array[i] = malloc((f.larg+s.larg) * sizeof(struct Pixel));
        if(array[i] == NULL){
          printf("Out of memory!\n");
          return 0;
        }
      }

    for(int i=0;i<rows;i++){
      for(int j=0;j<f.larg;j++){
        array[i][j].red = p[i][j].red;
        array[i][j].green = p[i][j].green;
        array[i][j].blue = p[i][j].blue;
      }
    }

    for(int i=0;i<rows;i++){
      for(int j=0;j<s.larg;j++){
        array[i][f.larg+j].red = x[i][j].red;
        array[i][f.larg+j].green = x[i][j].green;
        array[i][f.larg+j].blue = x[i][j].blue;
      }
    }

    for(int i=0;i<rows;i++)
      for(int j=0;j<(f.larg+s.larg);j++){
        fprintf(end ,"%d %d %d\n",array[i][j].red,array[i][j].green,array[i][j].blue);
      }

    fclose(fir);
    fclose(sec);
    fclose(end);

    for(int i=0;i<rows;i++){
      free(array[i]);
    }
    free(array);

    return 0;
  }
