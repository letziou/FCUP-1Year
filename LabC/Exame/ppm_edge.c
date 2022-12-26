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

void contornar(PIXEL **array,PIXEL **copy, int rows, int cols, int maxcolor);
void copias(PIXEL **copy, PIXEL **array, int rows, int cols);

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
    PIXEL **copy;
    copy = malloc(m.compr * sizeof(struct Pixel*));
      if(copy == NULL){
        printf("Out of memory!\n");
      return 0;
      }
      for(int i=0;i<m.compr;i++){
        copy[i] = malloc(m.larg * sizeof(struct Pixel));
        if(copy[i] == NULL){
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

        contornar(array,copy,m.compr,m.larg,m.pixelmax);

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
void contornar(PIXEL **array,PIXEL **copy, int rows, int cols, int maxcolor){
  int px[] = {-1,-1,-1,0,0,0,1,1,1};
  int py[] = {-1,0,1,-1,0,1,-1,0,1};

  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if(i==0 || j==0 || i==rows-1 || j==cols-1){
        copy[i][j].red = 0;
        copy[i][j].green = 0;
        copy[i][j].blue = 0;
      }

      else{
         int count = 0;

        for(int k=0;k<9;k++){
          int a = i + px[k];
          int b = j + py[k];
          if(a==i && b==j) continue;
          count += array[a][b].red;
        }
        int maxcount = (8*array[i][j].red) - count;

        if(maxcount>maxcolor) maxcount = maxcolor;
        else if(maxcount<0) maxcount = 0;

        copy[i][j].red = maxcount;
        copy[i][j].green = maxcount;
        copy[i][j].blue = maxcount;
      }
    }
  }
  copias(copy,array,rows,cols);
}

void copias(PIXEL **copy, PIXEL **array, int rows, int cols){
  for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++){
      array[i][j].red = copy[i][j].red ;
      array[i][j].green = copy[i][j].green ;
      array[i][j].blue = copy[i][j].blue ;
    }
}
