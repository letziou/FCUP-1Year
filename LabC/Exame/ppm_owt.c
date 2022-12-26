#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    float percen = atof(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);


    if(argc == 7){
      fir = fopen(argv[4],"r");
      sec = fopen(argv[5],"r");
      end = fopen(argv[6],"w");
    }

    if(argc == 5){
      fir = fopen(argv[4],"r");
      sec = stdin;
      end = stdout;
    }

    if(argc == 6){
      fir = fopen(argv[4],"r");
      sec = fopen(argv[5],"r");
      end = stdout;
    }

    int c;

    DATA m;
    DATA y;

    fscanf(fir ,("%s") ,m.type);
    fscanf(sec ,("%s") ,y.type);

    getc(fir); //para mudar para a nova linha
    getc(sec); //para mudar para a nova linha

    // para remover quaisquer comentarios da primeira imagem
    c = getc(fir);
    while (c == '#') {
    while (getc(fir) != '\n'){};
         c = getc(fir);
    }
    ungetc(c, fir);

    // para remover quaisquer comentarios da segunda imagem
    c = getc(sec);
    while (c == '#') {
    while (getc(sec) != '\n'){};
         c = getc(sec);
    }
    ungetc(c, sec);


    fscanf(fir ,("%d %d %d"),&m.larg,&m.compr,&m.pixelmax);
    fscanf(sec ,("%d %d %d"),&y.larg,&y.compr,&y.pixelmax);


    PIXEL p[m.compr][m.larg];
    PIXEL s[y.compr][y.larg];


    for(int i=0; i<m.compr ;i++)
      for(int j=0 ; j<m.larg ;j++)
        fscanf(fir ,"%d %d %d" ,&p[i][j].red,&p[i][j].green,&p[i][j].blue);

    for(int i=0;i<y.compr;i++)
      for(int j=0;j<y.larg;j++)
        fscanf(sec ,"%d %d %d" ,&s[i][j].red,&s[i][j].green,&s[i][j].blue);

    fprintf(end ,"%s\n%d %d\n%d\n",m.type,y.larg,y.compr,m.pixelmax);

    PIXEL **array;
    array = malloc(y.compr * sizeof(struct Pixel*));
      if(array == NULL){
        printf("Out of memory!\n");
      return 0;
      }
      for(int i=0;i<y.compr;i++){
        array[i] = malloc(y.larg * sizeof(struct Pixel));
        if(array[i] == NULL){
          printf("Out of memory!\n");
          return 0;
        }
      }
      // copia todos os elementos que estão em cada pixel para um array de arrays
       for(int i=0;i<y.compr;i++)
         for(int j=0;j<y.larg;j++){
           array[i][j].red = s[i][j].red;
           array[i][j].green = s[i][j].green;
           array[i][j].blue = s[i][j].blue;
         }

       for(int i=0;i<m.compr;i++)
         for(int j=0;j<m.larg;j++){
           if((i+b)>=y.compr || (j+a)>=y.larg) continue;
           array[i+b][j+a].red = round( (float) percen*p[i][j].red + ((1-percen)*s[i+b][j+a].red));
           array[i+b][j+a].green = round( (float) percen*p[i][j].green + ((1-percen)*s[i+b][j+a].green));
           array[i+b][j+a].blue = round( (float) percen*p[i][j].blue + ((1-percen)*s[i+b][j+a].blue));
         }

        for(int i=0;i<y.compr;i++)
          for(int j=0;j<y.larg;j++){
            fprintf(end ,"%d %d %d\n",array[i][j].red,array[i][j].green,array[i][j].blue);
          }


    fclose(fir);
    fclose(sec);
    fclose(end);
    for (int i=0; i<y.compr; i++) {
      free(array[i]);
    }
    free(array);


    return 0;
  }
